/****************************************************************************
** Meta object code from reading C++ file 'nursechangedialog.h'
**
** Created: Sat May 17 16:18:36 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../nursechangedialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nursechangedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NurseChangeDialog[] = {

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
      19,   18,   18,   18, 0x08,
      41,   18,   18,   18, 0x08,
      65,   18,   18,   18, 0x08,
      96,   18,   18,   18, 0x08,
     129,   18,   18,   18, 0x08,
     156,   18,   18,   18, 0x08,
     212,   18,   18,   18, 0x08,
     273,  270,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_NurseChangeDialog[] = {
    "NurseChangeDialog\0\0on_btn_save_clicked()\0"
    "on_btn_cancel_clicked()\0"
    "on_toolButton_cardNo_clicked()\0"
    "on_toolButton_building_clicked()\0"
    "doubleClickRecord(QString)\0"
    "on_comboBox_latterBedLevel_currentIndexChanged(QString)\0"
    "on_comboBox_latterNurseLevel_currentIndexChanged(QString)\0"
    ",,\0updateManageInfo(QString,float,float)\0"
};

void NurseChangeDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        NurseChangeDialog *_t = static_cast<NurseChangeDialog *>(_o);
        switch (_id) {
        case 0: _t->on_btn_save_clicked(); break;
        case 1: _t->on_btn_cancel_clicked(); break;
        case 2: _t->on_toolButton_cardNo_clicked(); break;
        case 3: _t->on_toolButton_building_clicked(); break;
        case 4: _t->doubleClickRecord((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->on_comboBox_latterBedLevel_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_comboBox_latterNurseLevel_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->updateManageInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData NurseChangeDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject NurseChangeDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NurseChangeDialog,
      qt_meta_data_NurseChangeDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NurseChangeDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NurseChangeDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NurseChangeDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NurseChangeDialog))
        return static_cast<void*>(const_cast< NurseChangeDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int NurseChangeDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
