/****************************************************************************
** Meta object code from reading C++ file 'employeevacationdialog.h'
**
** Created: Sat May 17 16:18:18 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../employeevacationdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'employeevacationdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EmployeeVacationDialog[] = {

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
      24,   23,   23,   23, 0x08,
      46,   23,   23,   23, 0x08,
      70,   23,   23,   23, 0x08,
      97,   23,   23,   23, 0x08,
     121,   23,   23,   23, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_EmployeeVacationDialog[] = {
    "EmployeeVacationDialog\0\0on_btn_save_clicked()\0"
    "on_btn_cancel_clicked()\0"
    "doubleClickRecord(QString)\0"
    "on_toolButton_clicked()\0buttonJudge(int)\0"
};

void EmployeeVacationDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        EmployeeVacationDialog *_t = static_cast<EmployeeVacationDialog *>(_o);
        switch (_id) {
        case 0: _t->on_btn_save_clicked(); break;
        case 1: _t->on_btn_cancel_clicked(); break;
        case 2: _t->doubleClickRecord((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->on_toolButton_clicked(); break;
        case 4: _t->buttonJudge((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData EmployeeVacationDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject EmployeeVacationDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_EmployeeVacationDialog,
      qt_meta_data_EmployeeVacationDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EmployeeVacationDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EmployeeVacationDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EmployeeVacationDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EmployeeVacationDialog))
        return static_cast<void*>(const_cast< EmployeeVacationDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int EmployeeVacationDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
