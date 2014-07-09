/****************************************************************************
** Meta object code from reading C++ file 'recedesettledialog.h'
**
** Created: Sat May 17 16:18:40 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../recedesettledialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'recedesettledialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RecedeSettleDialog[] = {

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
      20,   19,   19,   19, 0x08,
      42,   19,   19,   19, 0x08,
      72,   19,   66,   19, 0x08,
     105,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_RecedeSettleDialog[] = {
    "RecedeSettleDialog\0\0on_btn_save_clicked()\0"
    "on_btn_cancel_clicked()\0float\0"
    "getElderAccountByCardNo(QString)\0"
    "btnJudge(int)\0"
};

void RecedeSettleDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RecedeSettleDialog *_t = static_cast<RecedeSettleDialog *>(_o);
        switch (_id) {
        case 0: _t->on_btn_save_clicked(); break;
        case 1: _t->on_btn_cancel_clicked(); break;
        case 2: { float _r = _t->getElderAccountByCardNo((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 3: _t->btnJudge((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RecedeSettleDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RecedeSettleDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_RecedeSettleDialog,
      qt_meta_data_RecedeSettleDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RecedeSettleDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RecedeSettleDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RecedeSettleDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RecedeSettleDialog))
        return static_cast<void*>(const_cast< RecedeSettleDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int RecedeSettleDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
