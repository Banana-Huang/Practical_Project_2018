#ifndef DEFECTWINDOW_H
#define DEFECTWINDOW_H

#include <QDialog>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QRadioButton>
#include <QSqlRelationalTableModel>
#include <QtSql>
#include <QStackedWidget>
#include <QTableView>
#include <QMap>

class DefectWindow: public QDialog
{
public:
    DefectWindow(QWidget* parent );
    void setStatus( int, QSqlQueryModel* );
private:
    QHBoxLayout *radioButtonLayout;
    QHBoxLayout *pushButtonLayout;
    QVBoxLayout *vLayout;
    QRadioButton *goodRadioButton;
    QRadioButton *defectRadioButton;
    QButtonGroup *buttonGroup;
    QTableView *tableView;
    QPushButton *submitButton;
    QPushButton *cancelButton;
};

#endif // DEFECTWINDOW_H
