/****************************************************************************
** Meta object code from reading C++ file 'FlowScene.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/FlowScene.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FlowScene.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtNodes__FlowScene_t {
    QByteArrayData data[18];
    char stringdata0[216];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtNodes__FlowScene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtNodes__FlowScene_t qt_meta_stringdata_QtNodes__FlowScene = {
    {
QT_MOC_LITERAL(0, 0, 18), // "QtNodes::FlowScene"
QT_MOC_LITERAL(1, 19, 11), // "nodeCreated"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 5), // "Node&"
QT_MOC_LITERAL(4, 38, 1), // "n"
QT_MOC_LITERAL(5, 40, 11), // "nodeDeleted"
QT_MOC_LITERAL(6, 52, 17), // "connectionCreated"
QT_MOC_LITERAL(7, 70, 11), // "Connection&"
QT_MOC_LITERAL(8, 82, 1), // "c"
QT_MOC_LITERAL(9, 84, 17), // "connectionDeleted"
QT_MOC_LITERAL(10, 102, 9), // "nodeMoved"
QT_MOC_LITERAL(11, 112, 11), // "newLocation"
QT_MOC_LITERAL(12, 124, 17), // "nodeDoubleClicked"
QT_MOC_LITERAL(13, 142, 17), // "connectionHovered"
QT_MOC_LITERAL(14, 160, 9), // "screenPos"
QT_MOC_LITERAL(15, 170, 11), // "nodeHovered"
QT_MOC_LITERAL(16, 182, 19), // "connectionHoverLeft"
QT_MOC_LITERAL(17, 202, 13) // "nodeHoverLeft"

    },
    "QtNodes::FlowScene\0nodeCreated\0\0Node&\0"
    "n\0nodeDeleted\0connectionCreated\0"
    "Connection&\0c\0connectionDeleted\0"
    "nodeMoved\0newLocation\0nodeDoubleClicked\0"
    "connectionHovered\0screenPos\0nodeHovered\0"
    "connectionHoverLeft\0nodeHoverLeft"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtNodes__FlowScene[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       5,    1,   67,    2, 0x06 /* Public */,
       6,    1,   70,    2, 0x06 /* Public */,
       9,    1,   73,    2, 0x06 /* Public */,
      10,    2,   76,    2, 0x06 /* Public */,
      12,    1,   81,    2, 0x06 /* Public */,
      13,    2,   84,    2, 0x06 /* Public */,
      15,    2,   89,    2, 0x06 /* Public */,
      16,    1,   94,    2, 0x06 /* Public */,
      17,    1,   97,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QPointF,    4,   11,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 7, QMetaType::QPoint,    8,   14,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QPoint,    4,   14,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void QtNodes::FlowScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FlowScene *_t = static_cast<FlowScene *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->nodeCreated((*reinterpret_cast< Node(*)>(_a[1]))); break;
        case 1: _t->nodeDeleted((*reinterpret_cast< Node(*)>(_a[1]))); break;
        case 2: _t->connectionCreated((*reinterpret_cast< Connection(*)>(_a[1]))); break;
        case 3: _t->connectionDeleted((*reinterpret_cast< Connection(*)>(_a[1]))); break;
        case 4: _t->nodeMoved((*reinterpret_cast< Node(*)>(_a[1])),(*reinterpret_cast< const QPointF(*)>(_a[2]))); break;
        case 5: _t->nodeDoubleClicked((*reinterpret_cast< Node(*)>(_a[1]))); break;
        case 6: _t->connectionHovered((*reinterpret_cast< Connection(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2]))); break;
        case 7: _t->nodeHovered((*reinterpret_cast< Node(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2]))); break;
        case 8: _t->connectionHoverLeft((*reinterpret_cast< Connection(*)>(_a[1]))); break;
        case 9: _t->nodeHoverLeft((*reinterpret_cast< Node(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FlowScene::*_t)(Node & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FlowScene::nodeCreated)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (FlowScene::*_t)(Node & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FlowScene::nodeDeleted)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (FlowScene::*_t)(Connection & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FlowScene::connectionCreated)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (FlowScene::*_t)(Connection & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FlowScene::connectionDeleted)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (FlowScene::*_t)(Node & , const QPointF & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FlowScene::nodeMoved)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (FlowScene::*_t)(Node & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FlowScene::nodeDoubleClicked)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (FlowScene::*_t)(Connection & , QPoint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FlowScene::connectionHovered)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (FlowScene::*_t)(Node & , QPoint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FlowScene::nodeHovered)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (FlowScene::*_t)(Connection & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FlowScene::connectionHoverLeft)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (FlowScene::*_t)(Node & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FlowScene::nodeHoverLeft)) {
                *result = 9;
                return;
            }
        }
    }
}

const QMetaObject QtNodes::FlowScene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_QtNodes__FlowScene.data,
      qt_meta_data_QtNodes__FlowScene,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QtNodes::FlowScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtNodes::FlowScene::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QtNodes__FlowScene.stringdata0))
        return static_cast<void*>(const_cast< FlowScene*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int QtNodes::FlowScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void QtNodes::FlowScene::nodeCreated(Node & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QtNodes::FlowScene::nodeDeleted(Node & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QtNodes::FlowScene::connectionCreated(Connection & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QtNodes::FlowScene::connectionDeleted(Connection & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QtNodes::FlowScene::nodeMoved(Node & _t1, const QPointF & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QtNodes::FlowScene::nodeDoubleClicked(Node & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void QtNodes::FlowScene::connectionHovered(Connection & _t1, QPoint _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void QtNodes::FlowScene::nodeHovered(Node & _t1, QPoint _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void QtNodes::FlowScene::connectionHoverLeft(Connection & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void QtNodes::FlowScene::nodeHoverLeft(Node & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
