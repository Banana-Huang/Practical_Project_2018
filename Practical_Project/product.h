#ifndef PRODUCT_H
#define PRODUCT_H
#include <QSet>
#include <QString>
class Component
{
public:
    Component( int classes, QString name, int top, int bottom, int left, int right ) {
        this->classes = classes;
        this->name = name;
        this->top = top;
        this->bottom = bottom;
        this->left = left;
        this->right = right;
    }

    ~Component() {}

    int getCenter_x() const
    {
        return ( right + left ) / 2;
    }

    int getCenter_y() const
    {
        return ( top + bottom ) / 2;
    }

    bool isBelongto( Component another ) const
    {
        if( left < another.getCenter_x() && another.getCenter_x() < right  && top < another.getCenter_y() && another.getCenter_y() < bottom )
            return true;
        else
            return false;
    }

    QString toString() const
    {
        return QString( name + " top:" + QString::number(top) + " left:" + QString::number(left) + " right:" + QString::number(right) + " bottom:" + QString::number(bottom));
    }

    QString getName() const
    {
        return name;
    }
private:
    int classes;
    QString name;
    int top, bottom, left, right;
};

class ComponentInfo
{
public:
    ComponentInfo() {
        this->cid = QString("Null");
        this->name = QString("Null");
        this->orderedQuantity = 0;
        producedQuantity = 0;
    }

    ComponentInfo( QString cid, QString name, int orderedQuantity ) {
        this->cid = cid;
        this->name = name;
        this->orderedQuantity = orderedQuantity;
        producedQuantity = 0;
    }

    void initInfo() {
        producedQuantity = 0;
        errorStatus.clear();
    }

    void increasePQ() {
        producedQuantity++;
    }

    void addErrorStatus( QString& status ) {
        errorStatus.insert(status);
    }
    QString getCid() const {
        return cid;
    }

    QString getName() const {
        return name;
    }

    int getOrdered() const {
        return orderedQuantity;
    }

    int getProduced() const {
        return producedQuantity;
    }

    QSet<QString> getErrorStatus() const {
        return errorStatus;
    }

private:
    QString cid;
    QString name;
    int orderedQuantity;
    int producedQuantity;
    QSet<QString> errorStatus;
};
#endif // PRODUCT_H
