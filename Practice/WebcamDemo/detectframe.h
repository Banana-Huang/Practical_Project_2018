#ifndef DETECTFRAME_H
#define DETECTFRAME_H

#include <QObject>
#include <QLabel>
#include <QImage>
#include <QTimer>
#include <opencv2/opencv.hpp>
#include <QMessageBox>
class DetectFrame : public QObject
{
    Q_OBJECT
public:
    explicit DetectFrame( QLabel *view, QObject *parent = nullptr );
    ~DetectFrame();
private:
    QLabel *frame;
    cv::VideoCapture cap;
    QTimer *timer;
signals:

public slots:
    void updateView();
    void start();
    void stop();
};

#endif // DETECTFRAME_H
