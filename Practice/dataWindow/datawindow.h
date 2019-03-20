#ifndef DATAWINDOW_H
#define DATAWINDOW_H

#include "database.h"
#include "databasesetdialog.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QDate>
#include <QDateTime>
#include <QTimer>
#include <QFile>
#include <QtXml>
#include <QStringListModel>
#include <QMap>


namespace Ui {
class DataWindow;
}

class DataWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DataWindow(QWidget *parent = nullptr);
    ~DataWindow();
    void resizeEvent(QResizeEvent *event );
private:
    void initDBConfig();
    void storeDBConfig();
    void connectDB();
    Ui::DataWindow *ui;
    QTimer *updateTimer;
    QMap<QString, QString> config;
    QStringListModel *product;
    DatabaseSetDialog* setDialog;
    Database *database;
    QSqlQuery sqlQuery;
private slots:
    void setDBconfig();
    void updateCurrentTime();
    void on_actionabout_triggered();
    void on_startDateEdit_userDateChanged(const QDate &date);
    void on_endDateEdit_userDateChanged(const QDate &date);
    void on_startTimeEdit_userTimeChanged(const QTime &time);
    void on_endTimeEdit_userTimeChanged(const QTime &time);
    void on_actionset_triggered();
};

#endif // DATAWINDOW_H
