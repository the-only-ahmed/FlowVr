/****************************************************************************
** Meta object code from reading C++ file 'NodeDataModel.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/NodeDataModel.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NodeDataModel.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtNodes__NodeDataModel_t {
    QByteArrayData data[8];
    char stringdata0[103];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtNodes__NodeDataModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtNodes__NodeDataModel_t qt_meta_stringdata_QtNodes__NodeDataModel = {
    {
QT_MOC_LITERAL(0, 0, 22), // "QtNodes::NodeDataModel"
QT_MOC_LITERAL(1, 23, 11), // "dataUpdated"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 9), // "PortIndex"
QT_MOC_LITERAL(4, 46, 5), // "index"
QT_MOC_LITERAL(5, 52, 15), // "dataInvalidated"
QT_MOC_LITERAL(6, 68, 16), // "computingStarted"
QT_MOC_LITERAL(7, 85, 17) // "computingFinished"

    },
    "QtNodes::NodeDataModel\0dataUpdated\0\0"
    "PortIndex\0index\0dataInvalidated\0"
    "computingStarted\0computingFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtNodes__NodeDataModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       5,    1,   37,    2, 0x06 /* Public */,
       6,    0,   40,    2, 0x06 /* Public */,
       7,    0,   41,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QtNodes::NodeDataModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NodeDataModel *_t = static_cast<NodeDataModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dataUpdated((*reinterpret_cast< PortIndex(*)>(_a[1]))); break;
        case 1: _t->dataInvalidated((*reinterpret_cast< PortIndex(*)>(_a[1]))); break;
        case 2: _t->computingStarted(); break;
        case 3: _t->computingFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NodeDataModel::*_t)(PortIndex );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NodeDataModel::dataUpdated)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (NodeDataModel::*_t)(PortIndex );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NodeDataModel::dataInvalidated)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (NodeDataModel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NodeDataModel::computingStarted)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (NodeDataModel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NodeDataModel::computingFinished)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject QtNodes::NodeDataModel::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QtNodes__NodeDataModel.data,
      qt_meta_data_QtNodes__NodeDataModel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QtNodes::NodeDataModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtNodes::NodeDataModel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QtNodes__NodeDataModel.stringdata0))
        return static_cast<void*>(const_cast< NodeDataModel*>(this));
    if (!strcmp(_clname, "Serializable"))
        return static_cast< Serializable*>(const_cast< NodeDataModel*>(this));
    return QObject::qt_metacast(_clname);
}

int QtNodes::NodeDataModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QtNodes::NodeDataModel::dataUpdated(PortIndex _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QtNodes::NodeDataModel::dataInvalidated(PortIndex _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QtNodes::NodeDataModel::computingStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void QtNodes::NodeDataModel::computingFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
