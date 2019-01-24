#include "settingdialog.h"
#include "ui_settingdialog.h"

settingDialog::settingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settingDialog)
{
    ui->setupUi(this);

    //set lineEdit readOnly
    ui->productNumberLineEdit->setReadOnly(1);
    ui->weightLineEdit->setReadOnly(1);
    ui->settingLineEdit->setReadOnly(1);
    ui->dataLineEdit->setReadOnly(1);
}

settingDialog::~settingDialog()
{
    delete ui;
}

//close this dialog
void settingDialog::on_cancelPushButton_clicked()
{
    close();
}
