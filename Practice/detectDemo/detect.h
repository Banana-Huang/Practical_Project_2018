#ifndef DETECT_H
#define DETECT_H
#define FRAMES 3
#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QLabel>
#include <QImage>
#include <QMessageBox>
#include <QList>
#include <QQueue>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui_c.h"
#include "opencv2/imgproc/imgproc_c.h"
#include "opencv2/core/version.hpp"
#include "opencv2/videoio/videoio_c.h"

#ifdef WIN32
#include <time.h>
#include <winsock.h>
#include "gettimeofday.h"
#else
#include <sys/time.h>
#endif

#include "yolo_src/cuda.h"
#include "yolo_src/data.h"
#include "yolo_src/option_list.h"
#include "yolo_src/network.h"
#include "yolo_src/detection_layer.h"
#include "yolo_src/region_layer.h"
#include "yolo_src/cost_layer.h"
#include "yolo_src/utils.h"
#include "yolo_src/parser.h"
#include "yolo_src/box.h"
#include "yolo_src/image.h"
#include "yolo_src/layer.h"
#include "yolo_src/http_stream.h"
class Component
{
public:
    Component( int classes, QString name, int top, int bottom, int left, int right ) {
        this->classes = classes;
        this->name = name;
        this->top = top;
        this->bottom = bottom;
        this->left = left;
        this->right = right;
    }

    ~Component() {}

    int getCenter_x() const
    {
        return ( right + left ) / 2;
    }

    int getCenter_y() const
    {
        return ( top + bottom ) / 2;
    }

    bool isBelongto( Component another ) const
    {
        if( left < another.getCenter_x() && another.getCenter_x() < right  && top < another.getCenter_y() && another.getCenter_y() < bottom )
            return true;
        else
            return false;
    }

    QString toString() const
    {
        return QString( name + " top:" + QString::number(top) + " left:" + QString::number(left) + " right:" + QString::number(right) + " bottom:" + QString::number(bottom));
    }
private:
    int classes;
    QString name;
    int top, bottom, left, right;
};

class Detect : public QObject
{
    Q_OBJECT
public:
    explicit Detect( QLabel* view, QObject *parent = nullptr);
    ~Detect();
    bool fetch();
    bool detect();
    double get_wall_time();  
    void loadConfig( QString, QString, QString, float, int );
    void freeConfig();
    void getDetections( IplImage* show_img, detection *dets, int num, float thresh, char **names, image **alphabet, int classes, int container_num  );
private:
    bool counted = false;
    int product_count;
    QTimer *timer;
    char **demo_names;
    image **demo_alphabet;
    int demo_classes;
    float **probs;
    box *boxes;
    network net;
    image in_s ;
    image det_s;
    CvCapture * cap;
    int cpp_video_capture = 0;
    float fps = 0;
    float demo_thresh = 0;
    int demo_ext_output = 0;
    float *predictions[FRAMES];
    int demo_index = 0;
    image images[FRAMES];
    IplImage* ipl_images[FRAMES];
    float *avg;
    IplImage* in_img;
    IplImage* det_img;
    IplImage* show_img;
    int flag_exit;
    int letter_box = 0;
    int gpu_index = 0;
    int count;
    int delay;
    int frame_skip;
    double before;
    QLabel *frame;
    bool stop;
signals:

public slots:
    void updateView();
    void process();
    void Start();
    void Stop();
};

#endif // DETECT_H
