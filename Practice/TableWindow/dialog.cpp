#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    initTableWidget();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::initTableWidget()
{
    QMap<int,QString> student;
    student.insert( 0, "Terry Huang" );
    student.insert( 4, "Tony Chen" );
    student.insert( 1, "Marry Chen" );
    student.insert( 5, "Linda Lin" );
    student.insert( 2, "Jacky Lin" );
    ui->tableWidget->setRowCount(student.count());
    int row = 0;
    foreach( int key, student.keys() ) {
        QString name = student.value(key);
        QTableWidgetItem *itemNum = new QTableWidgetItem();
        QTableWidgetItem *itemName = new QTableWidgetItem();
        itemNum->setText(QString::number(key));
        itemName->setText( name );

        ui->tableWidget->setItem( row, 0, itemNum );
        ui->tableWidget->setItem( itemNum->row(), 1, itemName );
        row++;
    }
}

void Dialog::on_tableWidget_clicked(const QModelIndex &index)
{
    int row = index.row();

    ui->lineEdit->setText(index.sibling(row,0).data().toString());
    ui->lineEdit_2->setText(index.sibling(row,1).data().toString());
}

void Dialog::on_insertButton_clicked()
{
    QTableWidgetItem *itemNum = new QTableWidgetItem();
    QTableWidgetItem *itemName = new QTableWidgetItem();

    int insertRow = ui->tableWidget->rowCount();
    itemNum->setText( ui->lineEdit->text() );
    itemName->setText( ui->lineEdit_2->text() );
    ui->tableWidget->insertRow(insertRow);
    ui->tableWidget->setItem( insertRow, 0, itemNum );
    ui->tableWidget->setItem( insertRow, 1, itemName );
}

void Dialog::on_pushButton_clicked()
{
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}

void Dialog::on_pushButton_2_clicked()
{
    QTableWidgetItem *itemNum = new QTableWidgetItem();
    QTableWidgetItem *itemName = new QTableWidgetItem();

    int modifyRow = ui->tableWidget->currentRow();
    itemNum->setText( ui->lineEdit->text() );
    itemName->setText( ui->lineEdit_2->text() );
    ui->tableWidget->setItem( modifyRow, 0, itemNum );
    ui->tableWidget->setItem( modifyRow, 1, itemName );
}
