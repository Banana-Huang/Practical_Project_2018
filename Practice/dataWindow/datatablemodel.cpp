#include "datatablemodel.h"
#include <QColor>
#include <QBrush>
#include <QDebug>
#include <QDateTime>

dataTableModel::dataTableModel(QObject *parent, QSqlDatabase db)
    :QSqlTableModel (parent, db)
{
}

QVariant dataTableModel::data(const QModelIndex& index, int role )const{

    if( index.column() == 4 && role == Qt::BackgroundRole )
    {
        if( !QSqlTableModel::data(index, role).toInt() )
            return QColor(Qt::red);
    }

    if( index.column() == 4 && role == Qt::DisplayRole )
    {
        if( QSqlTableModel::data(index, role).toInt() )
            return QVariant("Good");
        else
            return QVariant("Defect");
    }

    if( index.column() == 2 && role == Qt::DisplayRole )
    {
        QDateTime dateTime = QSqlTableModel::data(index, role).toDateTime();
        return QVariant(dateTime.toString("yyyy/MM/dd hh:mm:ss.zzz"));
    }
    return QSqlTableModel::data(index, role);
}
