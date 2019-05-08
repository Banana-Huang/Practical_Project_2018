/****************************************************************************
** Meta object code from reading C++ file 'settingdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Practical_Project/settingdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settingdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_settingDialog_t {
    QByteArrayData data[9];
    char stringdata0[190];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_settingDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_settingDialog_t qt_meta_stringdata_settingDialog = {
    {
QT_MOC_LITERAL(0, 0, 13), // "settingDialog"
QT_MOC_LITERAL(1, 14, 12), // "submitConfig"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 21), // "QMap<QString,QString>"
QT_MOC_LITERAL(4, 50, 27), // "on_cancelPushButton_clicked"
QT_MOC_LITERAL(5, 78, 27), // "on_weightPushButton_clicked"
QT_MOC_LITERAL(6, 106, 28), // "on_settingPushButton_clicked"
QT_MOC_LITERAL(7, 135, 25), // "on_dataPushButton_clicked"
QT_MOC_LITERAL(8, 161, 28) // "on_confirmPushButton_clicked"

    },
    "settingDialog\0submitConfig\0\0"
    "QMap<QString,QString>\0on_cancelPushButton_clicked\0"
    "on_weightPushButton_clicked\0"
    "on_settingPushButton_clicked\0"
    "on_dataPushButton_clicked\0"
    "on_confirmPushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_settingDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   47,    2, 0x08 /* Private */,
       5,    0,   48,    2, 0x08 /* Private */,
       6,    0,   49,    2, 0x08 /* Private */,
       7,    0,   50,    2, 0x08 /* Private */,
       8,    0,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void settingDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        settingDialog *_t = static_cast<settingDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->submitConfig((*reinterpret_cast< QMap<QString,QString>(*)>(_a[1]))); break;
        case 1: _t->on_cancelPushButton_clicked(); break;
        case 2: _t->on_weightPushButton_clicked(); break;
        case 3: _t->on_settingPushButton_clicked(); break;
        case 4: _t->on_dataPushButton_clicked(); break;
        case 5: _t->on_confirmPushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (settingDialog::*)(QMap<QString,QString> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&settingDialog::submitConfig)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject settingDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_settingDialog.data,
      qt_meta_data_settingDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *settingDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *settingDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_settingDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int settingDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void settingDialog::submitConfig(QMap<QString,QString> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
