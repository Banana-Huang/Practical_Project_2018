#include "detect.h"

Detect::Detect( QLabel* view, char* datacfg, char * cfgfile, char * weightfile,
               float thresh, float hier_thresh, int cam_index, QObject *parent ): QObject(parent)
{
    stop = false;
    frame = view;
#ifndef GPU
    gpu_index = -1;
#else
    if(gpu_index >= 0){
        cuda_set_device(gpu_index);
        check_error(cudaSetDeviceFlags(cudaDeviceScheduleBlockingSync));
    }
#endif
    char c_name[8] = "classes";
    char n_name[6] = "names";
    char d_name[16] = "data/names.list";
    list *options = read_data_cfg(datacfg);
    int classes = option_find_int(options, c_name, 20);
    char *name_list = option_find_str(options, n_name, d_name );
    free_list_contents_kvp(options);
    free_list(options);
    delay = 0;
    demo_names = get_labels(name_list);
    demo_alphabet = (image**)load_alphabet();
    demo_classes = classes;
    demo_thresh = thresh;
    demo_ext_output = 1;
    frame_skip = 0;
    printf("Demo\n");
    net = parse_network_cfg_custom(cfgfile, 1);    // set batch=1
    if(weightfile){
       load_weights(&net, weightfile);
    }
    //set_batch_network(&net, 1);
    fuse_conv_batchnorm(net);
    calculate_binary_weights(net);
    srand(2222222);

    printf("Webcam index: %d\n", cam_index);
    cpp_video_capture = 1;
    cap = get_capture_webcam(cam_index);
    if (!cap) {
    #ifdef WIN32
        printf("Check that you have copied file opencv_ffmpeg340_64.dll to the same directory where is darknet.exe \n");
    #endif
    }

    layer l = net.layers[net.n-1];
    int j;

    avg = (float *) calloc(l.outputs, sizeof(float));
    for(j = 0; j < FRAMES; ++j) predictions[j] = (float *) calloc(l.outputs, sizeof(float));
    for(j = 0; j < FRAMES; ++j) images[j] = make_image(1,1,3);

    boxes = (box *)calloc(l.w*l.h*l.n, sizeof(box));
    probs = (float **)calloc(l.w*l.h*l.n, sizeof(float *));
    for(j = 0; j < l.w*l.h*l.n; ++j) probs[j] = (float *)calloc(l.classes, sizeof(float *));

    if (l.classes != demo_classes) {
       printf("Parameters don't match: in cfg-file classes=%d, in data-file classes=%d \n", l.classes, demo_classes);
       getchar();
       exit(0);
    }
    flag_exit = 0;

    fetch();
    det_img = in_img;
    det_s = in_s;

    fetch();
    detect();
    det_img = in_img;
    det_s = in_s;

    for(j = 0; j < FRAMES/2; ++j){
        fetch();
        detect();
        det_img = in_img;
        det_s = in_s;
    }

    count = 0;
    before = get_wall_time();
    timer = new QTimer;
    connect( timer,SIGNAL(timeout()),this,SLOT(process()));
    timer->start(33);
}

Detect::~Detect()
{
    int i, j;
    layer l = net.layers[net.n-1];
    cvReleaseImage(&show_img);
    cvReleaseImage(&in_img);
    free_image(in_s);

    free(avg);
    for (j = 0; j < FRAMES; ++j) free(predictions[j]);
    for (j = 0; j < FRAMES; ++j) free_image(images[j]);

    for (j = 0; j < l.w*l.h*l.n; ++j) free(probs[j]);
    free(boxes);
    free(probs);

    free_ptrs((void**)demo_names, net.layers[net.n - 1].classes);

    const int nsize = 8;
    for (j = 0; j < nsize; ++j) {
        for (i = 32; i < 127; ++i) {
            free_image(demo_alphabet[j][i]);
        }
        free(demo_alphabet[j]);
    }
    free(demo_alphabet);

    free_network(net);
}

bool Detect::fetch()
{
    //in = get_image_from_stream(cap);
    int dont_close_stream = 0;    // set 1 if your IP-camera periodically turns off and turns on video-stream
    if(letter_box)
        in_s = get_image_from_stream_letterbox(cap, net.w, net.h, net.c, &in_img, cpp_video_capture, dont_close_stream);
    else
        in_s = get_image_from_stream_resize(cap, net.w, net.h, net.c, &in_img, cpp_video_capture, dont_close_stream);
    if(!in_s.data){
        //error("Stream closed.");
        qDebug() << "Stream closed.";
        flag_exit = 1;
        return false;
    }
    //in_s = resize_image(in, net.w, net.h);

    return true;
}

bool Detect::detect()
{
    float nms = .45;    // 0.4F

    layer l = net.layers[net.n-1];
    float *X = det_s.data;
    float *prediction = network_predict(net, X);

    memcpy(predictions[demo_index], prediction, l.outputs*sizeof(float));
    mean_arrays(predictions, FRAMES, l.outputs, avg);
    l.output = avg;

    free_image(det_s);

    int nboxes = 0;
    detection *dets = nullptr;
    if (letter_box)
        dets = get_network_boxes(&net, in_img->width, in_img->height, demo_thresh, demo_thresh, 0, 1, &nboxes, 1); // letter box
    else
         dets = get_network_boxes(&net, det_s.w, det_s.h, demo_thresh, demo_thresh, 0, 1, &nboxes, 0); // resized
        //if (nms) do_nms_obj(dets, nboxes, l.classes, nms);    // bad results
    if (nms) do_nms_sort(dets, nboxes, l.classes, nms);


    printf("\033[2J");
    printf("\033[1;1H");
    printf("\nFPS: %.1f", fps );
    printf("Objects:\n\n");

    ipl_images[demo_index] = det_img;
    det_img = ipl_images[(demo_index + FRAMES / 2 + 1) % FRAMES];
    demo_index = (demo_index + 1)%FRAMES;
    draw_detections_cv_v3(det_img, dets, nboxes, demo_thresh, demo_names, demo_alphabet, demo_classes, demo_ext_output);
    free_detections(dets, nboxes);

    return true;
}

double Detect::get_wall_time()
{
    struct timeval time;
    if (gettimeofday(&time,NULL)){
        return 0;
    }
    return (double)time.tv_sec + (double)time.tv_usec * .000001;
}

void Detect::updateView() {
    cv::Mat img = cv::cvarrToMat(show_img);
    cv::cvtColor(img, img, CV_BGR2RGB);
    cv::resize(img,img,cv::Size(frame->width(),frame->height()),0,0,cv::INTER_LINEAR);
    frame->setPixmap(QPixmap::fromImage(QImage(img.data, img.cols, img.rows, img.step, QImage::Format_RGB888)));
}

void Detect::process() {
    while( !stop ) {
        ++count;
        fetch();
        detect();
        cvReleaseImage(&show_img);
        if( delay == 0 )
            show_img = det_img;
        det_img = in_img;
        det_s = in_s;
        updateView();
        --delay;
        if(delay < 0){
            delay = frame_skip;

            double after = get_wall_time();
            float curr = 1./(after - before);
            fps = curr;
            before = after;
        }
    }
}

void Detect::Stop()
{
    stop = true;
}
