#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    sDialog = new settingDialog(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//jump to next page
void MainWindow::on_testingPushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

//back to homepage
void MainWindow::on_backToHomePagePushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//when click the settingPushButton
void MainWindow::on_settingPushButton_clicked()
{
    sDialog->show();
}

//when click the checkingPushButton
void MainWindow::on_checkingPushButton_clicked()
{

}
