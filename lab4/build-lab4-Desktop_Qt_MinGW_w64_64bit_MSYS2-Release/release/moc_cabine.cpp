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
    QByteArrayData data[16];
    char stringdata0[146];
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
QT_MOC_LITERAL(6, 37, 10), // "open_doors"
QT_MOC_LITERAL(7, 48, 12), // "_request_sig"
QT_MOC_LITERAL(8, 61, 11), // "_stoped_sig"
QT_MOC_LITERAL(9, 73, 12), // "_started_sig"
QT_MOC_LITERAL(10, 86, 9), // "_move_sig"
QT_MOC_LITERAL(11, 96, 15), // "request_waiting"
QT_MOC_LITERAL(12, 112, 13), // "doors_waiting"
QT_MOC_LITERAL(13, 126, 6), // "stoped"
QT_MOC_LITERAL(14, 133, 7), // "started"
QT_MOC_LITERAL(15, 141, 4) // "move"

    },
    "Cabine\0dest_get\0\0floor\0Direction\0dir\0"
    "open_doors\0_request_sig\0_stoped_sig\0"
    "_started_sig\0_move_sig\0request_waiting\0"
    "doors_waiting\0stoped\0started\0move"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Cabine[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   74,    2, 0x06 /* Public */,
       6,    0,   79,    2, 0x06 /* Public */,
       7,    0,   80,    2, 0x06 /* Public */,
       8,    0,   81,    2, 0x06 /* Public */,
       9,    0,   82,    2, 0x06 /* Public */,
      10,    0,   83,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,   84,    2, 0x0a /* Public */,
      11,    0,   87,    2, 0x2a /* Public | MethodCloned */,
      12,    1,   88,    2, 0x0a /* Public */,
      13,    0,   91,    2, 0x08 /* Private */,
      14,    0,   92,    2, 0x08 /* Private */,
      15,    0,   93,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
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
        case 1: _t->open_doors(); break;
        case 2: _t->_request_sig(); break;
        case 3: _t->_stoped_sig(); break;
        case 4: _t->_started_sig(); break;
        case 5: _t->_move_sig(); break;
        case 6: _t->request_waiting((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->request_waiting(); break;
        case 8: _t->doors_waiting((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->stoped(); break;
        case 10: _t->started(); break;
        case 11: _t->move(); break;
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
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Cabine::open_doors)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Cabine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Cabine::_request_sig)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Cabine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Cabine::_stoped_sig)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Cabine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Cabine::_started_sig)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Cabine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Cabine::_move_sig)) {
                *result = 5;
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

// SIGNAL 0
void Cabine::dest_get(int _t1, Direction _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Cabine::open_doors()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Cabine::_request_sig()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Cabine::_stoped_sig()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Cabine::_started_sig()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Cabine::_move_sig()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
