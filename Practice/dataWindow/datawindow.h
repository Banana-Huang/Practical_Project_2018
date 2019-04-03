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
#include <QFileDialog>


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
public slots:
    void setStuffData( QModelIndex );
private:
    void initDBConfig();
    void storeDBConfig();
    void connectDB();
    QString getStatusRadioButton();
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
    void on_actionset_triggered();
    void on_startDateTimeEdit_dateTimeChanged(const QDateTime &dateTime);
    void on_endDateTimeEdit_dateTimeChanged(const QDateTime &dateTime);
    void on_allRadioButton_clicked();
    void on_goodRadioButton_clicked();
    void on_defectRadioButton_clicked();
    void on_imageChoser_clicked();
    void on_statusPushButton_clicked();
};

#endif // DATAWINDOW_H
