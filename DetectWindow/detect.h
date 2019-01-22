#ifndef DETECT_H
#define DETECT_H
#include "http_stream.h"
#include "network.h"
#include "detection_layer.h"
#include "region_layer.h"
#include "cost_layer.h"
#include "utils.h"
#include "parser.h"
#include "box.h"
#include "image.h"
#include "3rdparty/include/pthread.h"
#include "opencv2/opencv.hpp"
#include "opencv2/core/types_c.h"
#include "opencv2/videoio/videoio_c.h"
#define FRAMES 3
extern void draw_detections_cv_v3(IplImage* show_img, detection *dets, int num, float thresh, char **names, image **alphabet, int classes, int ext_output);
extern image get_image_from_stream_resize(CvCapture *cap, int w, int h, int c, IplImage** in_img, int cpp_video_capture, int dont_close);
extern image get_image_from_stream_letterbox(CvCapture *cap, int w, int h, int c, IplImage** in_img, int cpp_video_capture, int dont_close);
class detect{
public:
    detect(char*, char *, float, float, int, const char *, char **, int,
           int, char *, char *, int, int, int );
    ~detect();
    cv::Mat getImage();
    static void *fetch_in_thread(void *ptr);
    static void *detect_in_thread(void *ptr);
    static double get_wall_time();
private:
    static char **demo_names;
    static image **demo_alphabet;
    static int demo_classes;
    static float **probs;
    static box *boxes;
    static network net;
    static image in_s ;
    static image det_s;
    static CvCapture * cap;
    static int cpp_video_capture;
    static float fps;
    static float demo_thresh;
    static int demo_ext_output;
    static float *predictions[FRAMES];
    static int demo_index;
    static image images[FRAMES];
    static image **alphabet;
    static int delay;
    static IplImage* ipl_images[FRAMES];
    static float *avg;
    static IplImage* in_img;
    static IplImage* det_img;
    static IplImage* show_img;
    static int flag_exit;
    static int letter_box;
    static pthread_t fetch_thread;
    static pthread_t detect_thread;
};
#endif // DETECT_H
