/****************************************************************************
** Meta object code from reading C++ file 'basecostdialog.h'
**
** Created: Sat May 17 16:18:23 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../basecostdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'basecostdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BaseCostDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      37,   15,   15,   15, 0x08,
      61,   15,   15,   15, 0x08,
      81,   15,   15,   15, 0x08,
     105,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_BaseCostDialog[] = {
    "BaseCostDialog\0\0on_btn_add_clicked()\0"
    "on_btn_delete_clicked()\0on_btn_ok_clicked()\0"
    "on_btn_cancel_clicked()\0"
    "attributeClicked(QModelIndex)\0"
};

void BaseCostDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BaseCostDialog *_t = static_cast<BaseCostDialog *>(_o);
        switch (_id) {
        case 0: _t->on_btn_add_clicked(); break;
        case 1: _t->on_btn_delete_clicked(); break;
        case 2: _t->on_btn_ok_clicked(); break;
        case 3: _t->on_btn_cancel_clicked(); break;
        case 4: _t->attributeClicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData BaseCostDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BaseCostDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_BaseCostDialog,
      qt_meta_data_BaseCostDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BaseCostDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BaseCostDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BaseCostDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BaseCostDialog))
        return static_cast<void*>(const_cast< BaseCostDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int BaseCostDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
