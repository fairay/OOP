/****************************************************************************
** Meta object code from reading C++ file 'cabine.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lab4/elevator/cabine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cabine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Cabine_t {
    QByteArrayData data[11];
    char stringdata0[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Cabine_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Cabine_t qt_meta_stringdata_Cabine = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Cabine"
QT_MOC_LITERAL(1, 7, 8), // "dest_get"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 5), // "floor"
QT_MOC_LITERAL(4, 23, 9), // "Direction"
QT_MOC_LITERAL(5, 33, 3), // "dir"
QT_MOC_LITERAL(6, 37, 10), // "get_signal"
QT_MOC_LITERAL(7, 48, 12), // "doors_closed"
QT_MOC_LITERAL(8, 61, 6), // "stoped"
QT_MOC_LITERAL(9, 68, 7), // "started"
QT_MOC_LITERAL(10, 76, 4) // "move"

    },
    "Cabine\0dest_get\0\0floor\0Direction\0dir\0"
    "get_signal\0doors_closed\0stoped\0started\0"
    "move"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Cabine[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,
       1,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   55,    2, 0x0a /* Public */,
       7,    0,   58,    2, 0x0a /* Public */,
       8,    0,   59,    2, 0x08 /* Private */,
       9,    0,   60,    2, 0x08 /* Private */,
      10,    0,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Cabine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Cabine *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dest_get((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Direction(*)>(_a[2]))); break;
        case 1: _t->dest_get(); break;
        case 2: _t->get_signal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->doors_closed(); break;
        case 4: _t->stoped(); break;
        case 5: _t->started(); break;
        case 6: _t->move(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Cabine::*)(int , Direction );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Cabine::dest_get)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Cabine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Cabine::dest_get)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Cabine::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Cabine.data,
    qt_meta_data_Cabine,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Cabine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Cabine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Cabine.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Cabine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void Cabine::dest_get(int _t1, Direction _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Cabine::dest_get()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
