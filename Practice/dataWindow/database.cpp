#include "database.h"

Database::Database(QObject *parent) : QObject(parent)
{
    productDB = QSqlDatabase::addDatabase("QMYSQL");
    stuffDataModel = new dataTableModel( this, productDB );
}

bool Database::connectDB(QMap<QString, QString> &config)
{
    if( productDB.isOpen() )
        productDB.close();
    productDB.setHostName(config["host"]);
    productDB.setDatabaseName(config["database"]);
    productDB.setUserName(config["user"]);
    productDB.setPassword(config["password"]);

    if( productDB.open() ) {
        stuffDataModel->setTable("stuff");
        stuffDataModel->setHeaderData(0, Qt::Horizontal, "serial number");
        stuffDataModel->setHeaderData(1, Qt::Horizontal, "product id");
        stuffDataModel->setHeaderData(2, Qt::Horizontal, "product time");
        stuffDataModel->setHeaderData(3, Qt::Horizontal, "image");
        stuffDataModel->setHeaderData(4, Qt::Horizontal, "status");
        return true;
    } else
        return false;
}

QStringList Database::getProduct()
{
    QStringList stringList;
    if( productDB.isOpen() )
    {
        QSqlQuery sqlQuery;
        if(sqlQuery.exec("select * from product"))
        {
            while( sqlQuery.next() )
            {
                stringList.append(sqlQuery.value(0).toString());
            }
        }
    } else {
        stringList.append("None");
    }
    return stringList;
}

dataTableModel* Database::getProductDataModel()
{
    if( productDB.isOpen() )
    {
        stuffDataModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
        stuffDataModel->select();
        return stuffDataModel;
    } else {
        return nullptr;
    }
}
