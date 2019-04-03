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
        stuffDataModel->setSort(2, Qt::DescendingOrder);
        stuffDataModel->select();
        return stuffDataModel;
    } else {
        return nullptr;
    }
}

void Database::setCondiction( QString productSid,QDateTime start, QDateTime end, QString status )
{
    QString format("yyyy-MM-dd hh:mm:ss");
    QString filter = QString("pid = '%1' and product_time between '%2' and '%3'")
            .arg(productSid).arg(start.toString(format)).arg(end.toString(format));
    if( status == "Good" ) {
        QString statusFilter = QString("and status = '%1'").arg("1");
        filter.append(statusFilter);
    } else if( status == "Defect" ) {
        QString statusFilter = QString("and status = '%1'").arg("0");
        filter.append(statusFilter);
    }
    stuffDataModel->setFilter(filter);

    if(!stuffDataModel->select()) {
        QMessageBox::critical(nullptr, "Unable to initialize Database",
                    "Error initializing database: " + stuffDataModel->lastError().text());
    }
}

QSqlRecord Database::getRecord( QModelIndex index )
{
    return stuffDataModel->record(index.row());
}

QString Database::getProductName( QString pid )
{
    QSqlQuery query("select name from product where pid = '"+ pid +"';",productDB);
    if(query.exec())
    {
        query.next();
        return query.value(0).toString();
    } else {
        return QString("None");
    }
}
