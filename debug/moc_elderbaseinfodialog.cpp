/****************************************************************************
** Meta object code from reading C++ file 'elderbaseinfodialog.h'
**
** Created: Sat May 17 16:18:13 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../elderbaseinfodialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'elderbaseinfodialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ElderBaseInfoDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x0a,
      37,   20,   20,   20, 0x08,
      59,   20,   20,   20, 0x08,
      83,   20,   20,   20, 0x08,
     107,  105,   20,   20, 0x08,
     140,   20,   20,   20, 0x08,
     171,   20,   20,   20, 0x08,
     206,  201,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ElderBaseInfoDialog[] = {
    "ElderBaseInfoDialog\0\0viewRecord(int)\0"
    "on_btn_save_clicked()\0on_btn_cancel_clicked()\0"
    "on_btn_open_clicked()\0,\0"
    "updateNameByElderId(int,QString)\0"
    "on_lineEdit_cardNo_lostFocus()\0"
    "on_checkBox_isLunar_clicked()\0date\0"
    "on_dateEdit_birthday_dateChanged(QDate)\0"
};

void ElderBaseInfoDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ElderBaseInfoDialog *_t = static_cast<ElderBaseInfoDialog *>(_o);
        switch (_id) {
        case 0: _t->viewRecord((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_btn_save_clicked(); break;
        case 2: _t->on_btn_cancel_clicked(); break;
        case 3: _t->on_btn_open_clicked(); break;
        case 4: _t->updateNameByElderId((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->on_lineEdit_cardNo_lostFocus(); break;
        case 6: _t->on_checkBox_isLunar_clicked(); break;
        case 7: _t->on_dateEdit_birthday_dateChanged((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ElderBaseInfoDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ElderBaseInfoDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ElderBaseInfoDialog,
      qt_meta_data_ElderBaseInfoDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ElderBaseInfoDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ElderBaseInfoDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ElderBaseInfoDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ElderBaseInfoDialog))
        return static_cast<void*>(const_cast< ElderBaseInfoDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ElderBaseInfoDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
