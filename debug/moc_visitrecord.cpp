/****************************************************************************
** Meta object code from reading C++ file 'visitrecord.h'
**
** Created: Sat May 17 16:18:11 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../visitrecord.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'visitrecord.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VisitRecord[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      32,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      50,   12,   12,   12, 0x08,
      78,   12,   12,   12, 0x08,
     101,   12,   12,   12, 0x08,
     132,   12,   12,   12, 0x08,
     147,   12,   12,   12, 0x08,
     178,   12,   12,   12, 0x08,
     201,   12,   12,   12, 0x08,
     225,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_VisitRecord[] = {
    "VisitRecord\0\0closeVisitRecord()\0"
    "changeRecord(int)\0on_btn_add_record_clicked()\0"
    "on_btn_close_clicked()\0"
    "on_btn_change_record_clicked()\0"
    "refreshModel()\0on_btn_delete_record_clicked()\0"
    "on_btn_clear_clicked()\0on_btn_search_clicked()\0"
    "doubleClickRecord(QModelIndex)\0"
};

void VisitRecord::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        VisitRecord *_t = static_cast<VisitRecord *>(_o);
        switch (_id) {
        case 0: _t->closeVisitRecord(); break;
        case 1: _t->changeRecord((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_btn_add_record_clicked(); break;
        case 3: _t->on_btn_close_clicked(); break;
        case 4: _t->on_btn_change_record_clicked(); break;
        case 5: _t->refreshModel(); break;
        case 6: _t->on_btn_delete_record_clicked(); break;
        case 7: _t->on_btn_clear_clicked(); break;
        case 8: _t->on_btn_search_clicked(); break;
        case 9: _t->doubleClickRecord((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData VisitRecord::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VisitRecord::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_VisitRecord,
      qt_meta_data_VisitRecord, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VisitRecord::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VisitRecord::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VisitRecord::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VisitRecord))
        return static_cast<void*>(const_cast< VisitRecord*>(this));
    return QWidget::qt_metacast(_clname);
}

int VisitRecord::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void VisitRecord::closeVisitRecord()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void VisitRecord::changeRecord(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
