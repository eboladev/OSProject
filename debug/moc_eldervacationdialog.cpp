/****************************************************************************
** Meta object code from reading C++ file 'eldervacationdialog.h'
**
** Created: Sat May 17 16:18:34 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../eldervacationdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'eldervacationdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ElderVacationDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x08,
      43,   20,   20,   20, 0x08,
      67,   20,   20,   20, 0x08,
      98,   20,   20,   20, 0x08,
     130,   20,   20,   20, 0x08,
     157,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ElderVacationDialog[] = {
    "ElderVacationDialog\0\0on_btn_save_clicked()\0"
    "on_btn_cancel_clicked()\0"
    "on_toolButton_cardNo_clicked()\0"
    "on_toolButton_auditor_clicked()\0"
    "doubleClickRecord(QString)\0"
    "doubleClickEmployee(QString)\0"
};

void ElderVacationDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ElderVacationDialog *_t = static_cast<ElderVacationDialog *>(_o);
        switch (_id) {
        case 0: _t->on_btn_save_clicked(); break;
        case 1: _t->on_btn_cancel_clicked(); break;
        case 2: _t->on_toolButton_cardNo_clicked(); break;
        case 3: _t->on_toolButton_auditor_clicked(); break;
        case 4: _t->doubleClickRecord((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->doubleClickEmployee((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ElderVacationDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ElderVacationDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ElderVacationDialog,
      qt_meta_data_ElderVacationDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ElderVacationDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ElderVacationDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ElderVacationDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ElderVacationDialog))
        return static_cast<void*>(const_cast< ElderVacationDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ElderVacationDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
