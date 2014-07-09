/****************************************************************************
** Meta object code from reading C++ file 'resideregister.h'
**
** Created: Mon Jun 30 15:39:36 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../resideregister.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'resideregister.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ResideRegister[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
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
     232,  227,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ResideRegister[] = {
    "ResideRegister\0\0closeResideRegisterPage()\0"
    "on_btn_add_clicked()\0on_btn_change_clicked()\0"
    "on_btn_delete_clicked()\0on_btn_close_clicked()\0"
    "on_btn_clear_clicked()\0on_btn_search_clicked()\0"
    "refreshModel()\0doubleClickRecord(QModelIndex)\0"
    ",,,,\0updateMattressState(bool,QString,int,QString,int)\0"
};

void ResideRegister::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ResideRegister *_t = static_cast<ResideRegister *>(_o);
        switch (_id) {
        case 0: _t->closeResideRegisterPage(); break;
        case 1: _t->on_btn_add_clicked(); break;
        case 2: _t->on_btn_change_clicked(); break;
        case 3: _t->on_btn_delete_clicked(); break;
        case 4: _t->on_btn_close_clicked(); break;
        case 5: _t->on_btn_clear_clicked(); break;
        case 6: _t->on_btn_search_clicked(); break;
        case 7: _t->refreshModel(); break;
        case 8: _t->doubleClickRecord((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 9: _t->updateMattressState((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ResideRegister::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ResideRegister::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ResideRegister,
      qt_meta_data_ResideRegister, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ResideRegister::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ResideRegister::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ResideRegister::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ResideRegister))
        return static_cast<void*>(const_cast< ResideRegister*>(this));
    return QWidget::qt_metacast(_clname);
}

int ResideRegister::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ResideRegister::closeResideRegisterPage()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
