/****************************************************************************
** Meta object code from reading C++ file 'elderinfo.h'
**
** Created: Sat May 17 16:18:08 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../management/elderinfo.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'elderinfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ElderInfo[] = {

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
      11,   10,   10,   10, 0x05,
      50,   21,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      93,   10,   10,   10, 0x0a,
     106,   10,   10,   10, 0x0a,
     124,   10,   10,   10, 0x0a,
     139,   10,   10,   10, 0x0a,
     153,   10,   10,   10, 0x0a,
     167,   10,   10,   10, 0x0a,
     179,   10,   10,   10, 0x0a,
     192,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ElderInfo[] = {
    "ElderInfo\0\0refresh()\0buildname,floorname,roomname\0"
    "locateAndOpenRoom(QString,QString,QString)\0"
    "dialogInit()\0buildingChanged()\0"
    "floorChanged()\0roomChanged()\0modifyImage()\0"
    "saveElder()\0onRoomView()\0dynamicSetBirthDate()\0"
};

void ElderInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ElderInfo *_t = static_cast<ElderInfo *>(_o);
        switch (_id) {
        case 0: _t->refresh(); break;
        case 1: _t->locateAndOpenRoom((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 2: _t->dialogInit(); break;
        case 3: _t->buildingChanged(); break;
        case 4: _t->floorChanged(); break;
        case 5: _t->roomChanged(); break;
        case 6: _t->modifyImage(); break;
        case 7: _t->saveElder(); break;
        case 8: _t->onRoomView(); break;
        case 9: _t->dynamicSetBirthDate(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ElderInfo::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ElderInfo::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ElderInfo,
      qt_meta_data_ElderInfo, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ElderInfo::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ElderInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ElderInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ElderInfo))
        return static_cast<void*>(const_cast< ElderInfo*>(this));
    return QDialog::qt_metacast(_clname);
}

int ElderInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void ElderInfo::refresh()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ElderInfo::locateAndOpenRoom(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
