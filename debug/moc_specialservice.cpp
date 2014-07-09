/****************************************************************************
** Meta object code from reading C++ file 'specialservice.h'
**
** Created: Sat May 17 16:18:31 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../specialservice.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'specialservice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SpecialService[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      42,   15,   15,   15, 0x08,
      63,   15,   15,   15, 0x08,
      87,   15,   15,   15, 0x08,
     111,   15,   15,   15, 0x08,
     134,   15,   15,   15, 0x08,
     157,   15,   15,   15, 0x08,
     181,   15,   15,   15, 0x08,
     196,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SpecialService[] = {
    "SpecialService\0\0closeSpecialServicePage()\0"
    "on_btn_add_clicked()\0on_btn_change_clicked()\0"
    "on_btn_delete_clicked()\0on_btn_close_clicked()\0"
    "on_btn_clear_clicked()\0on_btn_search_clicked()\0"
    "refreshModel()\0doubleClickRecord(QModelIndex)\0"
};

void SpecialService::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SpecialService *_t = static_cast<SpecialService *>(_o);
        switch (_id) {
        case 0: _t->closeSpecialServicePage(); break;
        case 1: _t->on_btn_add_clicked(); break;
        case 2: _t->on_btn_change_clicked(); break;
        case 3: _t->on_btn_delete_clicked(); break;
        case 4: _t->on_btn_close_clicked(); break;
        case 5: _t->on_btn_clear_clicked(); break;
        case 6: _t->on_btn_search_clicked(); break;
        case 7: _t->refreshModel(); break;
        case 8: _t->doubleClickRecord((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SpecialService::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SpecialService::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SpecialService,
      qt_meta_data_SpecialService, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SpecialService::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SpecialService::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SpecialService::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SpecialService))
        return static_cast<void*>(const_cast< SpecialService*>(this));
    return QWidget::qt_metacast(_clname);
}

int SpecialService::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void SpecialService::closeSpecialServicePage()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
