#include "detect.h"

Detect::Detect( QLabel* view, char* datacfg, char * cfgfile, char * weightfile,
               float thresh, float hier_thresh, int cam_index, QObject *parent ): QObject(parent)
{
    product_count = 0;
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
    // printf("Demo\n");
    net = parse_network_cfg_custom(cfgfile, 1);    // set batch=1
    if(weightfile){
       load_weights(&net, weightfile);
    }
    //set_batch_network(&net, 1);
    fuse_conv_batchnorm(net);
    calculate_binary_weights(net);
    srand(2222222);

    // printf("Webcam index: %d\n", cam_index);
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
        // qDebug() << "Stream closed.";
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


    // printf("\033[2J");
    // printf("\033[1;1H");
    // printf("\nFPS: %.1f", fps );
    // printf("Objects:\n\n");

    ipl_images[demo_index] = det_img;
    det_img = ipl_images[(demo_index + FRAMES / 2 + 1) % FRAMES];
    demo_index = (demo_index + 1)%FRAMES;
    draw_detections_cv_v3(det_img, dets, nboxes, demo_thresh, demo_names, demo_alphabet, demo_classes, demo_ext_output);
    countDetections( det_img ,dets, nboxes, demo_thresh, demo_names, demo_classes  );
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

void Detect::countDetections( IplImage* show_img ,detection* dets, int num, float thresh, char **names, int classes )
{
    int i, j;
    for (i = 0; i < num; ++i) {
        char labelstr[4096] = { 0 };
        int class_id = -1;
        for (j = 0; j < classes; ++j) {
            if (dets[i].prob[j] > thresh) {
                if (class_id < 0) {
                    class_id = j;
                }
            }
        }
        if (class_id >= 0) {
            int width = show_img->height * .006;

            //if(0){
            //width = pow(prob, 1./2.)*10+1;
            //alphabet = 0;
            //}

            //printf("%d %s: %.0f%%\n", i, names[class_id], prob*100);

            box b = dets[i].bbox;
            b.w = (b.w < 1) ? b.w : 1;
            b.h = (b.h < 1) ? b.h : 1;
            b.x = (b.x < 1) ? b.x : 1;
            b.y = (b.y < 1) ? b.y : 1;
            //printf("%f %f %f %f\n", b.x, b.y, b.w, b.h);

            int left = (b.x - b.w / 2.)*show_img->width;
            int right = (b.x + b.w / 2.)*show_img->width;
            int top = (b.y - b.h / 2.)*show_img->height;
            int bot = (b.y + b.h / 2.)*show_img->height;

            if (left < 0) left = 0;
            if (right > show_img->width - 1) right = show_img->width - 1;
            if (top < 0) top = 0;
            if (bot > show_img->height - 1) bot = show_img->height - 1;

            int b_x_center = (left + right) / 2;
            int b_y_center = (top + bot) / 2;
            //int b_width = right - left;
            //int b_height = bot - top;
            //sprintf(labelstr, "%d x %d - w: %d, h: %d", b_x_center, b_y_center, b_width, b_height);


            // you should create directory: result_img
            //static int copied_frame_id = -1;
            //static IplImage* copy_img = NULL;
            //if (copied_frame_id != frame_id) {
            //    copied_frame_id = frame_id;
            //    if(copy_img == NULL) copy_img = cvCreateImage(cvSize(show_img->width, show_img->height), show_img->depth, show_img->nChannels);
            //    cvCopy(show_img, copy_img, 0);
            //}
            //static int img_id = 0;
            //img_id++;
            //char image_name[1024];
            //sprintf(image_name, "result_img/img_%d_%d_%d.jpg", frame_id, img_id, class_id);
            //CvRect rect = cvRect(pt1.x, pt1.y, pt2.x - pt1.x, pt2.y - pt1.y);
            //cvSetImageROI(copy_img, rect);
            //cvSaveImage(image_name, copy_img, 0);
            //cvResetImageROI(copy_img);
            if( class_id == 1 ) {
                cvCircle(show_img, cvPoint(b_x_center,b_y_center), 5, CV_RGB(255,0,0), 3, CV_FILLED, 0 );
                if( show_img->width/2 - 5 < b_x_center && b_x_center < show_img->width/2 + 5) {
                    cvLine(show_img,cvPoint(show_img->width/2,0),cvPoint(show_img->width/2,show_img->height),CV_RGB(255,0,0),3,8,0);
                    product_count++;
                    printf("\nCurrent Product count: %d", product_count );
                } else {
                    cvLine(show_img,cvPoint(show_img->width/2,0),cvPoint(show_img->width/2,show_img->height),CV_RGB(0,255,0),3,8,0);
                }
            }

        }
    }

}
