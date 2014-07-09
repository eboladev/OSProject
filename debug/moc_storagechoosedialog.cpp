/****************************************************************************
** Meta object code from reading C++ file 'storagechoosedialog.h'
**
** Created: Sat May 17 16:18:47 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../storagechoosedialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'storagechoosedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_StorageChooseDialog[] = {

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
      21,   20,   20,   20, 0x05,

 // slots: signature, parameters, type, tag, flags
      45,   20,   20,   20, 0x08,
      68,   20,   20,   20, 0x08,
      92,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_StorageChooseDialog[] = {
    "StorageChooseDialog\0\0sendStorageChoosed(int)\0"
    "on_btn_clear_clicked()\0on_btn_search_clicked()\0"
    "doubleClickRecord(QModelIndex)\0"
};

void StorageChooseDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        StorageChooseDialog *_t = static_cast<StorageChooseDialog *>(_o);
        switch (_id) {
        case 0: _t->sendStorageChoosed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_btn_clear_clicked(); break;
        case 2: _t->on_btn_search_clicked(); break;
        case 3: _t->doubleClickRecord((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData StorageChooseDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject StorageChooseDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_StorageChooseDialog,
      qt_meta_data_StorageChooseDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &StorageChooseDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *StorageChooseDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *StorageChooseDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StorageChooseDialog))
        return static_cast<void*>(const_cast< StorageChooseDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int StorageChooseDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void StorageChooseDialog::sendStorageChoosed(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
