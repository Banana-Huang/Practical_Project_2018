#include "database.h"

Database::Database(QObject *parent) : QObject(parent)
{
    productDB = QSqlDatabase::addDatabase("QMYSQL");
    stuffDataModel = new dataTableModel( this, productDB );
    productErrorModel = new QSqlRelationalTableModel( this, productDB );
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

        //productErrorModel->setJoinMode(QSqlRelationalTableModel::LeftJoin);
        productErrorModel->setHeaderData(0, Qt::Horizontal, "eid");
        productErrorModel->setHeaderData(1, Qt::Horizontal, "name");
        productErrorModel->setHeaderData(2, Qt::Horizontal, "describe");
        productErrorModel->setHeaderData(3, Qt::Horizontal, "image");
        productErrorModel->setHeaderData(4, Qt::Horizontal, "number");
        productErrorModel->setHeaderData(5, Qt::Horizontal, "checked");
        return true;
    } else
        return false;
}

bool Database::isConnect()
{
    if( productDB.isOpen() )
        return true;
    else
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

QMap<QString, int> Database::getStuffErrors( QString sid )
{
    QSqlQuery query("select eid, number from stuff_have_error where sid = '"+ sid +"';",productDB);
    QMap<QString, int> error;
    if(query.exec())
    {
        while( query.next() )
        {
            error.insert( query.value(0).toString(), query.value(1).toInt() );
        }
        return error;
    } else {
        return error;
    }
}

QSqlQueryModel* Database::getProductError( QString pid )
{
    if( productDB.isOpen() )
    {
        QString query("select error.eid as eid, name,describle,image from product_have_error, error where product_have_error.eid = error.eid and pid ='" + pid + "'");
        productErrorModel->setQuery( query, productDB );
        return productErrorModel;
    } else {
        return nullptr;
    }
}

QMap<QString, ComponentInfo> Database::getComponentSetting( QString pid  )
{
    QSqlQuery query("select component.cid as cid, component.name as name, product_have_component.number as number from component, product_have_component where product_have_component.cid = component.cid and product_have_component.pid = '"+ pid +"';",productDB);
    QMap<QString, ComponentInfo> Info;
    if(query.exec())
    {
        while( query.next() )
        {
            ComponentInfo temp(query.value(0).toString(),query.value(1).toString(),query.value(2).toInt());
            Info.insert( query.value(1).toString(), temp );
        }
        return Info;
    } else {
        return Info;
    }
}

QList<int> Database::getCounting( QDate currentDate, QString pid )
{
    int i = 0;
    QList<int> count;
    count << 0 << 0;
    QString str("select status,COUNT(status) from stuff where product_time between '%1 00:00:00.000' and '%1 23:59:59.999' and pid = '%2' group by status");
    str.arg(currentDate.toString("yyyy-MM-dd"),pid);
    QSqlQuery query(str,productDB);
    if(query.exec())
    {
        while( query.next() )
        {
            count[i] =  query.value(1).toInt();
            i++;
        }
        return count;
    } else {
        return count;
    }
}
