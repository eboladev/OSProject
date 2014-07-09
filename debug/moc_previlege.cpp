/****************************************************************************
** Meta object code from reading C++ file 'previlege.h'
**
** Created: Sat May 17 16:18:45 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../previlege.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'previlege.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Previlege[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      32,   10,   10,   10, 0x08,
      54,   10,   10,   10, 0x08,
      77,   10,   10,   10, 0x08,
     108,   10,  100,   10, 0x08,
     151,   10,  133,   10, 0x08,
     164,   10,  133,   10, 0x08,
     188,   10,  133,   10, 0x08,
     212,   10,   10,   10, 0x08,
     252,  250,  246,   10, 0x08,
     296,   10,  246,   10, 0x08,
     324,  250,   10,   10, 0x08,
     369,   10,  358,   10, 0x08,
     396,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Previlege[] = {
    "Previlege\0\0closePrevilegePage()\0"
    "on_btn_save_clicked()\0on_btn_close_clicked()\0"
    "createModelPrevilege()\0QString\0"
    "getMenuTextNameById(int)\0QMap<int,QString>\0"
    "getBarInfo()\0getMenuInfoByBarId(int)\0"
    "getBtnInfoByMenuId(int)\0"
    "on_tableView_clicked(QModelIndex)\0int\0"
    ",\0getMenuIdByParentIdAndTextName(int,QString)\0"
    "getMenuIdByBarName(QString)\0"
    "insertRoleAndMenu(int,QList<int>)\0"
    "QList<int>\0getMenuIdListByRoleId(int)\0"
    "deelteMenuByRoleId(int)\0"
};

void Previlege::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Previlege *_t = static_cast<Previlege *>(_o);
        switch (_id) {
        case 0: _t->closePrevilegePage(); break;
        case 1: _t->on_btn_save_clicked(); break;
        case 2: _t->on_btn_close_clicked(); break;
        case 3: _t->createModelPrevilege(); break;
        case 4: { QString _r = _t->getMenuTextNameById((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 5: { QMap<int,QString> _r = _t->getBarInfo();
            if (_a[0]) *reinterpret_cast< QMap<int,QString>*>(_a[0]) = _r; }  break;
        case 6: { QMap<int,QString> _r = _t->getMenuInfoByBarId((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QMap<int,QString>*>(_a[0]) = _r; }  break;
        case 7: { QMap<int,QString> _r = _t->getBtnInfoByMenuId((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QMap<int,QString>*>(_a[0]) = _r; }  break;
        case 8: _t->on_tableView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 9: { int _r = _t->getMenuIdByParentIdAndTextName((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 10: { int _r = _t->getMenuIdByBarName((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 11: _t->insertRoleAndMenu((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QList<int>(*)>(_a[2]))); break;
        case 12: { QList<int> _r = _t->getMenuIdListByRoleId((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<int>*>(_a[0]) = _r; }  break;
        case 13: _t->deelteMenuByRoleId((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Previlege::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Previlege::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Previlege,
      qt_meta_data_Previlege, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Previlege::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Previlege::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Previlege::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Previlege))
        return static_cast<void*>(const_cast< Previlege*>(this));
    return QWidget::qt_metacast(_clname);
}

int Previlege::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void Previlege::closePrevilegePage()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
