/****************************************************************************
** Meta object code from reading C++ file 'checkin.h'
**
** Created: Sat May 17 16:18:20 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../checkin.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'checkin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CheckIn[] = {

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
       9,    8,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      28,    8,    8,    8, 0x08,
      51,    8,    8,    8, 0x08,
      75,    8,    8,    8, 0x08,
      96,    8,    8,    8, 0x08,
     119,    8,    8,    8, 0x08,
     134,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CheckIn[] = {
    "CheckIn\0\0closeCheckInPage()\0"
    "on_btn_clear_clicked()\0on_btn_search_clicked()\0"
    "on_btn_add_clicked()\0on_btn_close_clicked()\0"
    "refreshModel()\0doubleClickRecord(QModelIndex)\0"
};

void CheckIn::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CheckIn *_t = static_cast<CheckIn *>(_o);
        switch (_id) {
        case 0: _t->closeCheckInPage(); break;
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

const QMetaObjectExtraData CheckIn::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CheckIn::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CheckIn,
      qt_meta_data_CheckIn, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CheckIn::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CheckIn::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CheckIn::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CheckIn))
        return static_cast<void*>(const_cast< CheckIn*>(this));
    return QWidget::qt_metacast(_clname);
}

int CheckIn::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void CheckIn::closeCheckInPage()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
