/****************************************************************************
** Meta object code from reading C++ file 'bedchoosedialog.h'
**
** Created: Mon Jun 30 15:39:38 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../bedchoosedialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bedchoosedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BedChooseDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   17,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_BedChooseDialog[] = {
    "BedChooseDialog\0\0index\0"
    "on_treeView_clicked(QModelIndex)\0"
};

void BedChooseDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BedChooseDialog *_t = static_cast<BedChooseDialog *>(_o);
        switch (_id) {
        case 0: _t->on_treeView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData BedChooseDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BedChooseDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_BedChooseDialog,
      qt_meta_data_BedChooseDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BedChooseDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BedChooseDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BedChooseDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BedChooseDialog))
        return static_cast<void*>(const_cast< BedChooseDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int BedChooseDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
