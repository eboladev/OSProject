/****************************************************************************
** Meta object code from reading C++ file 'visitrecorddialog.h'
**
** Created: Sat May 17 16:18:11 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../visitrecorddialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'visitrecorddialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VisitRecordDialog[] = {

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
      19,   18,   18,   18, 0x0a,
      35,   18,   18,   18, 0x08,
      57,   18,   18,   18, 0x08,
      81,   18,   18,   18, 0x08,
     128,   18,   18,   18, 0x08,
     152,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_VisitRecordDialog[] = {
    "VisitRecordDialog\0\0viewRecord(int)\0"
    "on_btn_save_clicked()\0on_btn_cancel_clicked()\0"
    "on_combox_purpose_currentIndexChanged(QString)\0"
    "on_toolButton_clicked()\0"
    "doubleClickRecord(QString)\0"
};

void VisitRecordDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        VisitRecordDialog *_t = static_cast<VisitRecordDialog *>(_o);
        switch (_id) {
        case 0: _t->viewRecord((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_btn_save_clicked(); break;
        case 2: _t->on_btn_cancel_clicked(); break;
        case 3: _t->on_combox_purpose_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_toolButton_clicked(); break;
        case 5: _t->doubleClickRecord((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData VisitRecordDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VisitRecordDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_VisitRecordDialog,
      qt_meta_data_VisitRecordDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VisitRecordDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VisitRecordDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VisitRecordDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VisitRecordDialog))
        return static_cast<void*>(const_cast< VisitRecordDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int VisitRecordDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
