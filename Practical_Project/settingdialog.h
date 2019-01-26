#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QDialog>

namespace Ui {
class settingDialog;
}

class settingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit settingDialog(QWidget *parent = nullptr);
    ~settingDialog();

private slots:
    void on_cancelPushButton_clicked();

private:
    Ui::settingDialog *ui;
};

#endif // DIALOG_H
