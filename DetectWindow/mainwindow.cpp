#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "option_list.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int gpu_index = 0;
#ifndef GPU
    gpu_index = -1;
#else
if(gpu_index >= 0){
    cuda_set_device(gpu_index);
    check_error(cudaSetDeviceFlags(cudaDeviceScheduleBlockingSync));
}
#endif
int dont_show = 0;
    int http_stream_port = -1;
    char *out_filename = nullptr;
    char *prefix = nullptr;
    char *filename = nullptr;
    float thresh = .25;    // 0.24
    float hier_thresh = .5;
    int cam_index = 0;
    int frame_skip = 0;
    int ext_output = 0;
    list *options = read_data_cfg(const_cast<char*>(std::string("E:\\dataset\\Project\\cfg\\project.data").c_str()));
    int classes = option_find_int(options, const_cast<char*>(std::string("classes").c_str()), 20);
    char *name_list = option_find_str(options, const_cast<char*>(std::string("names").c_str()), const_cast<char*>(std::string("data\names.list").c_str()));
    char **names = get_labels(name_list);

    video = new detect(const_cast<char*>(std::string("E:\\dataset\\Project\\cfg\\yolov3-tiny.cfg").c_str()), const_cast<char*>(std::string("E:\\dataset\\Project\\weights\\yolov3-tiny_103500.weights").c_str()), thresh, hier_thresh, cam_index, filename, names, classes, frame_skip, prefix, out_filename,
        http_stream_port, dont_show, ext_output);
    free_list_contents_kvp(options);
    free_list(options);

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateView()));
    timer->start(33);
}

MainWindow::~MainWindow()
{
    delete video;
    delete ui;
}

void MainWindow::updateView() {
    cv::Mat img = video->getImage();
    cv::cvtColor(img, img, CV_BGR2RGB);
    cv::resize(img,img,cv::Size(ui->label->x(),ui->label->y()),0,0,cv::INTER_LINEAR);
    ui->label->setPixmap(QPixmap::fromImage(QImage(img.data, img.cols, img.rows, img.step, QImage::Format_RGB888)));
}
