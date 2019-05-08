/****************************************************************************
** Meta object code from reading C++ file 'datawindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Practical_Project/dataWindow/datawindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datawindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataWindow_t {
    QByteArrayData data[16];
    char stringdata0[329];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataWindow_t qt_meta_stringdata_DataWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "DataWindow"
QT_MOC_LITERAL(1, 11, 12), // "setStuffData"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 11), // "QModelIndex"
QT_MOC_LITERAL(4, 37, 11), // "setDBconfig"
QT_MOC_LITERAL(5, 49, 17), // "updateCurrentTime"
QT_MOC_LITERAL(6, 67, 24), // "on_actionabout_triggered"
QT_MOC_LITERAL(7, 92, 22), // "on_actionset_triggered"
QT_MOC_LITERAL(8, 115, 36), // "on_startDateTimeEdit_dateTime..."
QT_MOC_LITERAL(9, 152, 8), // "dateTime"
QT_MOC_LITERAL(10, 161, 34), // "on_endDateTimeEdit_dateTimeCh..."
QT_MOC_LITERAL(11, 196, 25), // "on_allRadioButton_clicked"
QT_MOC_LITERAL(12, 222, 26), // "on_goodRadioButton_clicked"
QT_MOC_LITERAL(13, 249, 28), // "on_defectRadioButton_clicked"
QT_MOC_LITERAL(14, 278, 22), // "on_imageChoser_clicked"
QT_MOC_LITERAL(15, 301, 27) // "on_statusPushButton_clicked"

    },
    "DataWindow\0setStuffData\0\0QModelIndex\0"
    "setDBconfig\0updateCurrentTime\0"
    "on_actionabout_triggered\0"
    "on_actionset_triggered\0"
    "on_startDateTimeEdit_dateTimeChanged\0"
    "dateTime\0on_endDateTimeEdit_dateTimeChanged\0"
    "on_allRadioButton_clicked\0"
    "on_goodRadioButton_clicked\0"
    "on_defectRadioButton_clicked\0"
    "on_imageChoser_clicked\0"
    "on_statusPushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x0a /* Public */,
       4,    0,   77,    2, 0x08 /* Private */,
       5,    0,   78,    2, 0x08 /* Private */,
       6,    0,   79,    2, 0x08 /* Private */,
       7,    0,   80,    2, 0x08 /* Private */,
       8,    1,   81,    2, 0x08 /* Private */,
      10,    1,   84,    2, 0x08 /* Private */,
      11,    0,   87,    2, 0x08 /* Private */,
      12,    0,   88,    2, 0x08 /* Private */,
      13,    0,   89,    2, 0x08 /* Private */,
      14,    0,   90,    2, 0x08 /* Private */,
      15,    0,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDateTime,    9,
    QMetaType::Void, QMetaType::QDateTime,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DataWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DataWindow *_t = static_cast<DataWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setStuffData((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 1: _t->setDBconfig(); break;
        case 2: _t->updateCurrentTime(); break;
        case 3: _t->on_actionabout_triggered(); break;
        case 4: _t->on_actionset_triggered(); break;
        case 5: _t->on_startDateTimeEdit_dateTimeChanged((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 6: _t->on_endDateTimeEdit_dateTimeChanged((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 7: _t->on_allRadioButton_clicked(); break;
        case 8: _t->on_goodRadioButton_clicked(); break;
        case 9: _t->on_defectRadioButton_clicked(); break;
        case 10: _t->on_imageChoser_clicked(); break;
        case 11: _t->on_statusPushButton_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DataWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_DataWindow.data,
      qt_meta_data_DataWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DataWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int DataWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
