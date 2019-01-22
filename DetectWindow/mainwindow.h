#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "detect.h"
#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void updateView();
private:
    Ui::MainWindow *ui;
    QTimer* timer;
    detect *video;
};

#endif // MAINWINDOW_H
