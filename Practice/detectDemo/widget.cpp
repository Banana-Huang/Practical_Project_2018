#include "widget.h"
#include "ui_widget.h"
#include <QList>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    foreach( const QCameraInfo &info, cameras )
    {
        ui->comboBox->addItem(info.description());
    }
    ui->comboBox->setCurrentIndex(0);
    QString datacfg = "E:/dataset/Project/cfg/project.data";
    QString cfgfile = "E:/dataset/Project/cfg/yolov3-tiny.cfg";
    QString weightfile = "E:/dataset/Project/weights/yolov3-tiny_127100.weights";
    detector = new Detect( ui->labelView );
    detector->loadConfig(datacfg,cfgfile,weightfile,0.8,ui->comboBox->currentIndex());
    thread = new QThread(this);

    detector->moveToThread(thread);
    thread->start();
    ui->pushButton_2->setEnabled(false);
}

Widget::~Widget()
{
    detector->Stop();
    thread->quit();
    delete detector;
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    detector->Start();
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(true);
    ui->reloadPushButton->setEnabled(false);
}



void Widget::on_pushButton_2_clicked()
{
    detector->Stop();
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(false);
    ui->reloadPushButton->setEnabled(true);
}

void Widget::on_reloadPushButton_clicked()
{
    detector->freeConfig();
    QString datacfg = "E:/dataset/Project/cfg/project.data";
    QString cfgfile = "E:/dataset/Project/cfg/yolov3-tiny.cfg";
    QString weightfile = "E:/dataset/Project/weights/yolov3-tiny_127100.weights";
    detector->loadConfig(datacfg,cfgfile,weightfile,0.8,ui->comboBox->currentIndex());
}
