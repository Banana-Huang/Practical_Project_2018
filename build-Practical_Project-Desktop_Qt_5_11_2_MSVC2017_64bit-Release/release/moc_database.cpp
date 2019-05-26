/****************************************************************************
** Meta object code from reading C++ file 'database.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Practical_Project/dataWindow/database.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'database.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Database_t {
    QByteArrayData data[17];
    char stringdata0[194];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Database_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Database_t qt_meta_stringdata_Database = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Database"
QT_MOC_LITERAL(1, 9, 13), // "deleteRecords"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 15), // "QModelIndexList"
QT_MOC_LITERAL(4, 40, 12), // "modifyRecord"
QT_MOC_LITERAL(5, 53, 3), // "row"
QT_MOC_LITERAL(6, 57, 11), // "QSqlRecord&"
QT_MOC_LITERAL(7, 69, 6), // "record"
QT_MOC_LITERAL(8, 76, 17), // "QMap<QString,int>"
QT_MOC_LITERAL(9, 94, 6), // "errors"
QT_MOC_LITERAL(10, 101, 6), // "preSid"
QT_MOC_LITERAL(11, 108, 12), // "createRecord"
QT_MOC_LITERAL(12, 121, 27), // "QMap<QString,ComponentInfo>"
QT_MOC_LITERAL(13, 149, 13), // "componentInfo"
QT_MOC_LITERAL(14, 163, 12), // "insertErrors"
QT_MOC_LITERAL(15, 176, 3), // "sid"
QT_MOC_LITERAL(16, 180, 13) // "setCondiction"

    },
    "Database\0deleteRecords\0\0QModelIndexList\0"
    "modifyRecord\0row\0QSqlRecord&\0record\0"
    "QMap<QString,int>\0errors\0preSid\0"
    "createRecord\0QMap<QString,ComponentInfo>\0"
    "componentInfo\0insertErrors\0sid\0"
    "setCondiction"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Database[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x0a /* Public */,
       4,    4,   47,    2, 0x0a /* Public */,
      11,    2,   56,    2, 0x0a /* Public */,
      11,    2,   61,    2, 0x0a /* Public */,
      14,    2,   66,    2, 0x0a /* Public */,
      16,    4,   71,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Bool, 0x80000000 | 3,    2,
    QMetaType::Bool, QMetaType::Int, 0x80000000 | 6, 0x80000000 | 8, QMetaType::QString,    5,    7,    9,   10,
    QMetaType::Bool, 0x80000000 | 6, 0x80000000 | 8,    7,    9,
    QMetaType::Bool, 0x80000000 | 6, 0x80000000 | 12,    7,   13,
    QMetaType::Bool, QMetaType::QString, 0x80000000 | 8,   15,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QDateTime, QMetaType::QDateTime, QMetaType::QString,    2,    2,    2,    2,

       0        // eod
};

void Database::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Database *_t = static_cast<Database *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->deleteRecords((*reinterpret_cast< QModelIndexList(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: { bool _r = _t->modifyRecord((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QSqlRecord(*)>(_a[2])),(*reinterpret_cast< QMap<QString,int>(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: { bool _r = _t->createRecord((*reinterpret_cast< QSqlRecord(*)>(_a[1])),(*reinterpret_cast< QMap<QString,int>(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->createRecord((*reinterpret_cast< QSqlRecord(*)>(_a[1])),(*reinterpret_cast< QMap<QString,ComponentInfo>(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->insertErrors((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QMap<QString,int>(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->setCondiction((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QDateTime(*)>(_a[2])),(*reinterpret_cast< QDateTime(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QModelIndexList >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Database::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Database.data,
      qt_meta_data_Database,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Database::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Database::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Database.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Database::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
