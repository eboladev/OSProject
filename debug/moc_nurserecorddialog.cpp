/****************************************************************************
** Meta object code from reading C++ file 'nurserecorddialog.h'
**
** Created: Sat May 17 16:18:28 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../nurserecorddialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nurserecorddialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NurseRecordDialog[] = {

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
      19,   18,   18,   18, 0x08,
      41,   18,   18,   18, 0x08,
      65,   18,   18,   18, 0x08,
      96,   18,   18,   18, 0x08,
     129,   18,   18,   18, 0x08,
     156,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_NurseRecordDialog[] = {
    "NurseRecordDialog\0\0on_btn_save_clicked()\0"
    "on_btn_cancel_clicked()\0"
    "on_toolButton_cardNo_clicked()\0"
    "on_toolButton_adviceId_clicked()\0"
    "doubleClickRecord(QString)\0"
    "doubleClickAdvice(int)\0"
};

void NurseRecordDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        NurseRecordDialog *_t = static_cast<NurseRecordDialog *>(_o);
        switch (_id) {
        case 0: _t->on_btn_save_clicked(); break;
        case 1: _t->on_btn_cancel_clicked(); break;
        case 2: _t->on_toolButton_cardNo_clicked(); break;
        case 3: _t->on_toolButton_adviceId_clicked(); break;
        case 4: _t->doubleClickRecord((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->doubleClickAdvice((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData NurseRecordDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject NurseRecordDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NurseRecordDialog,
      qt_meta_data_NurseRecordDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NurseRecordDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NurseRecordDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NurseRecordDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NurseRecordDialog))
        return static_cast<void*>(const_cast< NurseRecordDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int NurseRecordDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
