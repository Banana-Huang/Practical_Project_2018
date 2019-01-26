#ifndef CHECKINGDIALOG_H
#define CHECKINGDIALOG_H

#include <QDialog>

namespace Ui {
class checkingDialog;
}

class checkingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit checkingDialog(QWidget *parent = nullptr);
    ~checkingDialog();

private:
    Ui::checkingDialog *ui;
};

#endif // CHECKINGDIALOG_H
