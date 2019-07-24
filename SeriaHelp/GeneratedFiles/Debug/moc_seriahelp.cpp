/****************************************************************************
** Meta object code from reading C++ file 'seriahelp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../seriahelp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'seriahelp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SeriaHelp_t {
    QByteArrayData data[17];
    char stringdata0[218];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SeriaHelp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SeriaHelp_t qt_meta_stringdata_SeriaHelp = {
    {
QT_MOC_LITERAL(0, 0, 9), // "SeriaHelp"
QT_MOC_LITERAL(1, 10, 18), // "setSerialParameter"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 7), // "checked"
QT_MOC_LITERAL(4, 38, 18), // "refreshSerialInfos"
QT_MOC_LITERAL(5, 57, 10), // "readSerial"
QT_MOC_LITERAL(6, 68, 11), // "writeSerial"
QT_MOC_LITERAL(7, 80, 14), // "enterFormatSet"
QT_MOC_LITERAL(8, 95, 19), // "startOrEndReplySend"
QT_MOC_LITERAL(9, 115, 15), // "getCurrentDelay"
QT_MOC_LITERAL(10, 131, 5), // "value"
QT_MOC_LITERAL(11, 137, 17), // "resetCurrentDelay"
QT_MOC_LITERAL(12, 155, 5), // "clean"
QT_MOC_LITERAL(13, 161, 19), // "chooseShowSendCount"
QT_MOC_LITERAL(14, 181, 22), // "chooseShowRecieveCount"
QT_MOC_LITERAL(15, 204, 6), // "onSave"
QT_MOC_LITERAL(16, 211, 6) // "onOpen"

    },
    "SeriaHelp\0setSerialParameter\0\0checked\0"
    "refreshSerialInfos\0readSerial\0writeSerial\0"
    "enterFormatSet\0startOrEndReplySend\0"
    "getCurrentDelay\0value\0resetCurrentDelay\0"
    "clean\0chooseShowSendCount\0"
    "chooseShowRecieveCount\0onSave\0onOpen"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SeriaHelp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x08 /* Private */,
       4,    0,   82,    2, 0x08 /* Private */,
       5,    0,   83,    2, 0x08 /* Private */,
       6,    0,   84,    2, 0x08 /* Private */,
       7,    1,   85,    2, 0x08 /* Private */,
       8,    1,   88,    2, 0x08 /* Private */,
       9,    1,   91,    2, 0x08 /* Private */,
      11,    1,   94,    2, 0x08 /* Private */,
      12,    0,   97,    2, 0x08 /* Private */,
      13,    1,   98,    2, 0x08 /* Private */,
      14,    1,  101,    2, 0x08 /* Private */,
      15,    0,  104,    2, 0x08 /* Private */,
      16,    0,  105,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SeriaHelp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SeriaHelp *_t = static_cast<SeriaHelp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setSerialParameter((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->refreshSerialInfos(); break;
        case 2: _t->readSerial(); break;
        case 3: _t->writeSerial(); break;
        case 4: _t->enterFormatSet((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->startOrEndReplySend((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->getCurrentDelay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->resetCurrentDelay((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->clean(); break;
        case 9: _t->chooseShowSendCount((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->chooseShowRecieveCount((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->onSave(); break;
        case 12: _t->onOpen(); break;
        default: ;
        }
    }
}

const QMetaObject SeriaHelp::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SeriaHelp.data,
      qt_meta_data_SeriaHelp,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SeriaHelp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SeriaHelp::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SeriaHelp.stringdata0))
        return static_cast<void*>(const_cast< SeriaHelp*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SeriaHelp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
