#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_testingPushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_backToHomePagePushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_settingPushButton_clicked()
{
    sDialog = new settingDialog(this);
    sDialog->show();
}
