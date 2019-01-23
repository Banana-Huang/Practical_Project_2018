#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    workThread = new QThread(this);
    detectFrame = new DetectFrame( ui->labelView, nullptr );
    connect( ui->startButton, SIGNAL(clicked()), detectFrame,SLOT(start()));
    connect( ui->stopButton, SIGNAL(clicked()), detectFrame,SLOT(stop()));
    detectFrame->moveToThread( workThread );
    workThread->start();
    workThread->setPriority(QThread::HighestPriority);
}

Dialog::~Dialog()
{
    disconnect( ui->startButton, SIGNAL(clicked()), detectFrame,SLOT(start()));
    disconnect( ui->stopButton, SIGNAL(clicked()), detectFrame,SLOT(stop()));
    if( workThread->isRunning() )
        workThread->quit();
    qDebug() << "I'm first";
    delete detectFrame;
    qDebug() << "I'm second";
    delete ui;
}

