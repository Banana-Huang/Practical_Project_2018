#include "checkingdialog.h"
#include "ui_checkingdialog.h"

checkingDialog::checkingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checkingDialog)
{
    ui->setupUi(this);
}

checkingDialog::~checkingDialog()
{
    delete ui;
}
