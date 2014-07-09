/****************************************************************************
** Meta object code from reading C++ file 'operationlog.h'
**
** Created: Sat May 17 16:18:45 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../operationlog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'operationlog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_OperationLog[] = {

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
      14,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      38,   13,   13,   13, 0x08,
      61,   13,   13,   13, 0x08,
      85,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_OperationLog[] = {
    "OperationLog\0\0closeOperationLogPage()\0"
    "on_btn_clear_clicked()\0on_btn_search_clicked()\0"
    "on_btn_close_clicked()\0"
};

void OperationLog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        OperationLog *_t = static_cast<OperationLog *>(_o);
        switch (_id) {
        case 0: _t->closeOperationLogPage(); break;
        case 1: _t->on_btn_clear_clicked(); break;
        case 2: _t->on_btn_search_clicked(); break;
        case 3: _t->on_btn_close_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData OperationLog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject OperationLog::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_OperationLog,
      qt_meta_data_OperationLog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &OperationLog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *OperationLog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *OperationLog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OperationLog))
        return static_cast<void*>(const_cast< OperationLog*>(this));
    return QWidget::qt_metacast(_clname);
}

int OperationLog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void OperationLog::closeOperationLogPage()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
