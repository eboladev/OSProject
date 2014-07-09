/****************************************************************************
** Meta object code from reading C++ file 'eldervacation.h'
**
** Created: Sat May 17 16:18:33 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../eldervacation.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'eldervacation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ElderVacation[] = {

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
      15,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      40,   14,   14,   14, 0x08,
      61,   14,   14,   14, 0x08,
      85,   14,   14,   14, 0x08,
     109,   14,   14,   14, 0x08,
     132,   14,   14,   14, 0x08,
     155,   14,   14,   14, 0x08,
     179,   14,   14,   14, 0x08,
     194,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ElderVacation[] = {
    "ElderVacation\0\0closeElderVacationPage()\0"
    "on_btn_add_clicked()\0on_btn_change_clicked()\0"
    "on_btn_delete_clicked()\0on_btn_close_clicked()\0"
    "on_btn_clear_clicked()\0on_btn_search_clicked()\0"
    "refreshModel()\0doubleClickRecord(QModelIndex)\0"
};

void ElderVacation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ElderVacation *_t = static_cast<ElderVacation *>(_o);
        switch (_id) {
        case 0: _t->closeElderVacationPage(); break;
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

const QMetaObjectExtraData ElderVacation::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ElderVacation::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ElderVacation,
      qt_meta_data_ElderVacation, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ElderVacation::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ElderVacation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ElderVacation::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ElderVacation))
        return static_cast<void*>(const_cast< ElderVacation*>(this));
    return QWidget::qt_metacast(_clname);
}

int ElderVacation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ElderVacation::closeElderVacationPage()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
