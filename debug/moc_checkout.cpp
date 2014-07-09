/****************************************************************************
** Meta object code from reading C++ file 'checkout.h'
**
** Created: Sat May 17 16:18:22 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../checkout.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'checkout.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CheckOut[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      30,    9,    9,    9, 0x08,
      53,    9,    9,    9, 0x08,
      77,    9,    9,    9, 0x08,
      98,    9,    9,    9, 0x08,
     121,    9,    9,    9, 0x08,
     136,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CheckOut[] = {
    "CheckOut\0\0closeCheckOutPage()\0"
    "on_btn_clear_clicked()\0on_btn_search_clicked()\0"
    "on_btn_add_clicked()\0on_btn_close_clicked()\0"
    "refreshModel()\0doubleClickRecord(QModelIndex)\0"
};

void CheckOut::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CheckOut *_t = static_cast<CheckOut *>(_o);
        switch (_id) {
        case 0: _t->closeCheckOutPage(); break;
        case 1: _t->on_btn_clear_clicked(); break;
        case 2: _t->on_btn_search_clicked(); break;
        case 3: _t->on_btn_add_clicked(); break;
        case 4: _t->on_btn_close_clicked(); break;
        case 5: _t->refreshModel(); break;
        case 6: _t->doubleClickRecord((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CheckOut::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CheckOut::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CheckOut,
      qt_meta_data_CheckOut, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CheckOut::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CheckOut::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CheckOut::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CheckOut))
        return static_cast<void*>(const_cast< CheckOut*>(this));
    return QWidget::qt_metacast(_clname);
}

int CheckOut::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void CheckOut::closeCheckOutPage()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
