/****************************************************************************
** Meta object code from reading C++ file 'roledialog.h'
**
** Created: Sat May 17 16:18:43 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../roledialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'roledialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RoleDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      33,   11,   11,   11, 0x08,
      57,   11,   11,   11, 0x08,
      79,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_RoleDialog[] = {
    "RoleDialog\0\0on_btn_add_clicked()\0"
    "on_btn_delete_clicked()\0on_btn_save_clicked()\0"
    "on_btn_cancel_clicked()\0"
};

void RoleDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RoleDialog *_t = static_cast<RoleDialog *>(_o);
        switch (_id) {
        case 0: _t->on_btn_add_clicked(); break;
        case 1: _t->on_btn_delete_clicked(); break;
        case 2: _t->on_btn_save_clicked(); break;
        case 3: _t->on_btn_cancel_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData RoleDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RoleDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_RoleDialog,
      qt_meta_data_RoleDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RoleDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RoleDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RoleDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RoleDialog))
        return static_cast<void*>(const_cast< RoleDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int RoleDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
