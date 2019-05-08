#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QMap>
#include <QtSql>
#include <QStringList>
#include <QDateTime>
#include <QDebug>
#include <QStringListModel>
#include <QMessageBox>
#include "datatablemodel.h"

class Database: public QObject
{
    Q_OBJECT
public:
    explicit Database(QObject *parent = nullptr);
    bool isConnect();
    bool connectDB( QMap<QString, QString> &config );
    QStringList getProduct();
    QString getProductName( QString );
    QMap<QString,int> getStuffErrors( QString );
    dataTableModel* getProductDataModel();
    QSqlRecord getRecord( QModelIndex );
    QSqlQueryModel* getProductError( QString );
public slots:
    void setCondiction( QString ,QDateTime, QDateTime, QString );
private:
    QSqlDatabase productDB;
    QStringListModel product;
    dataTableModel *stuffDataModel;
    QSqlQueryModel *productErrorModel;
};

#endif // DATABASE_H
