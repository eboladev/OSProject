/****************************************************************************
** Meta object code from reading C++ file 'employeebaseinfochoosedialog.h'
**
** Created: Sat May 17 16:18:19 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../employeebaseinfochoosedialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'employeebaseinfochoosedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EmployeeBaseInfoChooseDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      30,   29,   29,   29, 0x05,

 // slots: signature, parameters, type, tag, flags
      59,   29,   29,   29, 0x08,
      82,   29,   29,   29, 0x08,
     106,   29,   29,   29, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_EmployeeBaseInfoChooseDialog[] = {
    "EmployeeBaseInfoChooseDialog\0\0"
    "sendEmployeeChoosed(QString)\0"
    "on_btn_clear_clicked()\0on_btn_search_clicked()\0"
    "doubleClickRecord(QModelIndex)\0"
};

void EmployeeBaseInfoChooseDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        EmployeeBaseInfoChooseDialog *_t = static_cast<EmployeeBaseInfoChooseDialog *>(_o);
        switch (_id) {
        case 0: _t->sendEmployeeChoosed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_btn_clear_clicked(); break;
        case 2: _t->on_btn_search_clicked(); break;
        case 3: _t->doubleClickRecord((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData EmployeeBaseInfoChooseDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject EmployeeBaseInfoChooseDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_EmployeeBaseInfoChooseDialog,
      qt_meta_data_EmployeeBaseInfoChooseDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EmployeeBaseInfoChooseDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EmployeeBaseInfoChooseDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EmployeeBaseInfoChooseDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EmployeeBaseInfoChooseDialog))
        return static_cast<void*>(const_cast< EmployeeBaseInfoChooseDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int EmployeeBaseInfoChooseDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void EmployeeBaseInfoChooseDialog::sendEmployeeChoosed(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
