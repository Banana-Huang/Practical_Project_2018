#ifndef DEFECTWINDOW_H
#define DEFECTWINDOW_H

#include <QDialog>
#include <QPushButton>
#include <QHBoxLayout>
#include <QButtonGroup>
#include <QRadioButton>
#include <QSqlRelationalTableModel>
#include <QSql>
#include <QStackedWidget>
#include <QTableView>
#include <QMap>

class DefectWindow: public QDialog
{
public:
    DefectWindow(QWidget* parent, QString pid );
private:
    QHBoxLayout *hLayout;


};

#endif // DEFECTWINDOW_H
