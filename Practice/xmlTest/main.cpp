#include <QCoreApplication>
#include <QFile>
#include <QDir>
#include <QtXml>
#include <QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFile xmlFile("dbcfg.xml");
    if( xmlFile.exists() ) {
        qDebug() << "The file exist!";
        if( !xmlFile.open(QIODevice::ReadOnly) )
            qDebug() << "Open file error";
        else {
            QDomDocument xml;
            xml.setContent(&xmlFile);
            QDomElement docElem = xml.documentElement();
            QDomNode n = docElem.firstChild();
            while(!n.isNull())
            {
               if (n.isElement())  //如果节点是元素
               {
                  QDomElement e = n.toElement();  //将其转换为元素
                  qDebug() << qPrintable(e.tagName())   //返回元素标记
                     << qPrintable(e.text());  //返回元素id属性的值
                }
                  n = n.nextSibling();  //下一个兄弟节点
            }
        }
    }
    else {
        qDebug() << "The file doesn't exist";
    }

    xmlFile.close();
    return a.exec();
}
