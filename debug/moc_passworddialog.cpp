/****************************************************************************
** Meta object code from reading C++ file 'passworddialog.h'
**
** Created: Sat May 17 16:18:47 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../passworddialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'passworddialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PasswordDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      38,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PasswordDialog[] = {
    "PasswordDialog\0\0on_btn_save_clicked()\0"
    "on_btn_cancel_clicked()\0"
};

void PasswordDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PasswordDialog *_t = static_cast<PasswordDialog *>(_o);
        switch (_id) {
        case 0: _t->on_btn_save_clicked(); break;
        case 1: _t->on_btn_cancel_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData PasswordDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PasswordDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_PasswordDialog,
      qt_meta_data_PasswordDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PasswordDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PasswordDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PasswordDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PasswordDialog))
        return static_cast<void*>(const_cast< PasswordDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int PasswordDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
