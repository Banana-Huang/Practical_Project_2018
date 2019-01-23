#include "detectframe.h"

DetectFrame::DetectFrame( QLabel* view, QObject *parent) : QObject(parent),frame(view)
{
    cap.open(0);
    if( !cap.isOpened() ) {
        QMessageBox::critical(nullptr,"Fatal error","The cam is not avalible");
        cap.release();
    } else {
        timer = new QTimer;
        timer->start(15);
    }
}

DetectFrame::~DetectFrame()
{
    timer->stop();
    cap.release();
    frame = nullptr;
    delete timer;
}


void DetectFrame::updateView()
{
    cv::Mat img;
    cap >> img;
    cv::cvtColor(img, img, CV_BGR2RGB);
    cv::resize(img,img,cv::Size(frame->width(),frame->height()),0,0,cv::INTER_LINEAR);
    frame->setPixmap(QPixmap::fromImage(QImage(img.data, img.cols, img.rows, img.step, QImage::Format_RGB888)));
}


void DetectFrame::start()
{
    connect( timer, SIGNAL(timeout()), this, SLOT(updateView()));
}

void DetectFrame::stop()
{
    disconnect( timer, SIGNAL(timeout()), this, SLOT(updateView()));
}

