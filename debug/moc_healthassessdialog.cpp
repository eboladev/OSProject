/****************************************************************************
** Meta object code from reading C++ file 'healthassessdialog.h'
**
** Created: Sat May 17 16:18:14 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../healthassessdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'healthassessdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_HealthAssessDialog[] = {

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
      66,   19,   19,   19, 0x08,
      90,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_HealthAssessDialog[] = {
    "HealthAssessDialog\0\0on_btn_save_clicked()\0"
    "on_btn_calcel_clicked()\0on_toolButton_clicked()\0"
    "doubleClickRecord(int)\0"
};

void HealthAssessDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        HealthAssessDialog *_t = static_cast<HealthAssessDialog *>(_o);
        switch (_id) {
        case 0: _t->on_btn_save_clicked(); break;
        case 1: _t->on_btn_calcel_clicked(); break;
        case 2: _t->on_toolButton_clicked(); break;
        case 3: _t->doubleClickRecord((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData HealthAssessDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject HealthAssessDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_HealthAssessDialog,
      qt_meta_data_HealthAssessDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &HealthAssessDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *HealthAssessDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *HealthAssessDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HealthAssessDialog))
        return static_cast<void*>(const_cast< HealthAssessDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int HealthAssessDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
