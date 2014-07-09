/****************************************************************************
** Meta object code from reading C++ file 'elderbaseinfo.h'
**
** Created: Sat May 17 16:18:12 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../elderbaseinfo.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'elderbaseinfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ElderBaseInfo[] = {

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
      15,   14,   14,   14, 0x05,
      40,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      58,   14,   14,   14, 0x08,
      81,   14,   14,   14, 0x08,
     102,   14,   14,   14, 0x08,
     117,   14,   14,   14, 0x08,
     141,   14,   14,   14, 0x08,
     165,   14,   14,   14, 0x08,
     188,   14,   14,   14, 0x08,
     212,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ElderBaseInfo[] = {
    "ElderBaseInfo\0\0closeElderBaseInfoPage()\0"
    "changeRecord(int)\0on_btn_close_clicked()\0"
    "on_btn_add_clicked()\0refreshModel()\0"
    "on_btn_change_clicked()\0on_btn_delete_clicked()\0"
    "on_btn_clear_clicked()\0on_btn_search_clicked()\0"
    "doubleClickRecord(QModelIndex)\0"
};

void ElderBaseInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ElderBaseInfo *_t = static_cast<ElderBaseInfo *>(_o);
        switch (_id) {
        case 0: _t->closeElderBaseInfoPage(); break;
        case 1: _t->changeRecord((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_btn_close_clicked(); break;
        case 3: _t->on_btn_add_clicked(); break;
        case 4: _t->refreshModel(); break;
        case 5: _t->on_btn_change_clicked(); break;
        case 6: _t->on_btn_delete_clicked(); break;
        case 7: _t->on_btn_clear_clicked(); break;
        case 8: _t->on_btn_search_clicked(); break;
        case 9: _t->doubleClickRecord((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ElderBaseInfo::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ElderBaseInfo::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ElderBaseInfo,
      qt_meta_data_ElderBaseInfo, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ElderBaseInfo::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ElderBaseInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ElderBaseInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ElderBaseInfo))
        return static_cast<void*>(const_cast< ElderBaseInfo*>(this));
    return QWidget::qt_metacast(_clname);
}

int ElderBaseInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ElderBaseInfo::closeElderBaseInfoPage()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ElderBaseInfo::changeRecord(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
