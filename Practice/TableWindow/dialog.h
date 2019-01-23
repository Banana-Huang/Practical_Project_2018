#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMap>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void initTableWidget();
private slots:
    void on_tableWidget_clicked(const QModelIndex &index);

    void on_insertButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
