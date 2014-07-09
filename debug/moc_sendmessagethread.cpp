/****************************************************************************
** Meta object code from reading C++ file 'sendmessagethread.h'
**
** Created: Thu Jun 19 09:13:17 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../sendmessagethread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sendmessagethread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SendMessageThread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   19,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      38,   18,   18,   18, 0x08,
      54,   18,   18,   18, 0x08,
      65,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SendMessageThread[] = {
    "SendMessageThread\0\0flag\0delRoom(bool)\0"
    "newConnection()\0readData()\0"
    "socketDisconnected()\0"
};

void SendMessageThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SendMessageThread *_t = static_cast<SendMessageThread *>(_o);
        switch (_id) {
        case 0: _t->delRoom((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->newConnection(); break;
        case 2: _t->readData(); break;
        case 3: _t->socketDisconnected(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SendMessageThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SendMessageThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_SendMessageThread,
      qt_meta_data_SendMessageThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SendMessageThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SendMessageThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SendMessageThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SendMessageThread))
        return static_cast<void*>(const_cast< SendMessageThread*>(this));
    return QThread::qt_metacast(_clname);
}

int SendMessageThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void SendMessageThread::delRoom(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
