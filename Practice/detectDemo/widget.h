#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QThread>
#include "detect.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QThread *thread;
    Detect *detector;
};

#endif // WIDGET_H
