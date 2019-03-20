#include "widget.h"
#include "ui_widget.h"
#include <string>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    std::string datacfg = "E:/dataset/Project/cfg/project.data";
    std::string cfgfile = "E:/dataset/Project/cfg/yolov3-tiny.cfg";
    std::string weightfile = "E:/dataset/Project/weights/yolov3-tiny_127100.weights";
    detector = new Detect( ui->labelView, const_cast<char*>(datacfg.c_str()), const_cast<char*>(cfgfile.c_str()),
        const_cast<char*>(weightfile.c_str()), 0.8, 0.5, 0 );
    thread = new QThread(this);
    connect( thread, SIGNAL(started()), detector, SLOT(process()));
    detector->moveToThread(thread);
    thread->start();
}

Widget::~Widget()
{
    detector->Stop();
    thread->quit();
    delete detector;
    delete ui;
}
