#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "settingdialog.h"
#include "checkingdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_testingPushButton_clicked();

    void on_backToHomePagePushButton_clicked();

    void on_settingPushButton_clicked();

    void on_checkingPushButton_clicked();

private:
    Ui::MainWindow *ui;
    settingDialog *sDialog;
    checkingDialog *cDialag;
};

#endif // MAINWINDOW_H
