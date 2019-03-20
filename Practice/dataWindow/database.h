#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QMap>
#include <QtSql>
#include <QStringList>
#include <QStringListModel>
#include "datatablemodel.h"

class Database: public QObject
{
    Q_OBJECT
public:
    explicit Database(QObject *parent = nullptr);
    bool connectDB( QMap<QString, QString> &config );
    QStringList getProduct();
    dataTableModel* getProductDataModel();
signals:

public slots:
private:
    QSqlDatabase productDB;
    QStringListModel product;
    dataTableModel *stuffDataModel;
};

#endif // DATABASE_H
