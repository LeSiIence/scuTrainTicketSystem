/****************************************************************************
** Meta object code from reading C++ file 'journey.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "journey.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'journey.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Journey_t {
    QByteArrayData data[10];
    char stringdata0[180];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Journey_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Journey_t qt_meta_stringdata_Journey = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Journey"
QT_MOC_LITERAL(1, 8, 7), // "mytimer"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 23), // "on_actionQuit_triggered"
QT_MOC_LITERAL(4, 41, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(5, 66, 27), // "on_actionAbout_Qt_triggered"
QT_MOC_LITERAL(6, 94, 23), // "on_actionHome_triggered"
QT_MOC_LITERAL(7, 118, 32), // "on_pushButton_bookTicket_clicked"
QT_MOC_LITERAL(8, 151, 23), // "on_dateEdit_dateChanged"
QT_MOC_LITERAL(9, 175, 4) // "date"

    },
    "Journey\0mytimer\0\0on_actionQuit_triggered\0"
    "on_actionAbout_triggered\0"
    "on_actionAbout_Qt_triggered\0"
    "on_actionHome_triggered\0"
    "on_pushButton_bookTicket_clicked\0"
    "on_dateEdit_dateChanged\0date"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Journey[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    1,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDate,    9,

       0        // eod
};

void Journey::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Journey *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->mytimer(); break;
        case 1: _t->on_actionQuit_triggered(); break;
        case 2: _t->on_actionAbout_triggered(); break;
        case 3: _t->on_actionAbout_Qt_triggered(); break;
        case 4: _t->on_actionHome_triggered(); break;
        case 5: _t->on_pushButton_bookTicket_clicked(); break;
        case 6: _t->on_dateEdit_dateChanged((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Journey::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Journey.data,
    qt_meta_data_Journey,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Journey::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Journey::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Journey.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Journey::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
