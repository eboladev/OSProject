/****************************************************************************
** Meta object code from reading C++ file 'manualsettle.h'
**
** Created: Sat May 17 16:18:43 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../manualsettle.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'manualsettle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ManualSettle[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   14,   13,   13, 0x0a,
      57,   13,   51,   13, 0x0a,
      92,   90,   51,   13, 0x0a,
     131,   90,   51,   13, 0x0a,
     172,   90,   51,   13, 0x0a,
     205,   90,   51,   13, 0x0a,
     273,   90,  255,   13, 0x0a,
     318,   90,  255,   13, 0x0a,
     365,   90,   13,   13, 0x0a,
     409,   13,   13,   13, 0x0a,
     449,  445,   13,   13, 0x0a,
     506,  501,   13,   13, 0x0a,
     567,   13,  561,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ManualSettle[] = {
    "ManualSettle\0\0cardNo,\0"
    "expenseSettle(QString,QDate)\0float\0"
    "getElderAccountByCardNo(QString)\0,\0"
    "getElderBedCostByCardNo(QString,QDate)\0"
    "getElderNurseCostByCardNo(QString,QDate)\0"
    "getElderStageCost(QString,QDate)\0"
    "getElderSpecialServiceCostByCardNo(QString,QDate)\0"
    "QMap<QDate,float>\0"
    "getElderBedChangeInfoByCardNo(QString,QDate)\0"
    "getElderNurseChangeInfoByCardNo(QString,QDate)\0"
    "updateAccountByCardNoAndCost(QString,float)\0"
    "updateLevelChangedByCardNo(QString)\0"
    ",,,\0insertBedOrNurseCostInfo(QString,int,QString,float)\0"
    ",,,,\0insertSpecialCostInfo(QString,int,QString,float,QDate)\0"
    "QDate\0getElderResideDateByCardNo(QString)\0"
};

void ManualSettle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ManualSettle *_t = static_cast<ManualSettle *>(_o);
        switch (_id) {
        case 0: _t->expenseSettle((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QDate(*)>(_a[2]))); break;
        case 1: { float _r = _t->getElderAccountByCardNo((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 2: { float _r = _t->getElderBedCostByCardNo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QDate(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 3: { float _r = _t->getElderNurseCostByCardNo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QDate(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 4: { float _r = _t->getElderStageCost((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QDate(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 5: { float _r = _t->getElderSpecialServiceCostByCardNo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QDate(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 6: { QMap<QDate,float> _r = _t->getElderBedChangeInfoByCardNo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QDate(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QMap<QDate,float>*>(_a[0]) = _r; }  break;
        case 7: { QMap<QDate,float> _r = _t->getElderNurseChangeInfoByCardNo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QDate(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QMap<QDate,float>*>(_a[0]) = _r; }  break;
        case 8: _t->updateAccountByCardNoAndCost((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 9: _t->updateLevelChangedByCardNo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->insertBedOrNurseCostInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4]))); break;
        case 11: _t->insertSpecialCostInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< QDate(*)>(_a[5]))); break;
        case 12: { QDate _r = _t->getElderResideDateByCardNo((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDate*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ManualSettle::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ManualSettle::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ManualSettle,
      qt_meta_data_ManualSettle, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ManualSettle::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ManualSettle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ManualSettle::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ManualSettle))
        return static_cast<void*>(const_cast< ManualSettle*>(this));
    return QObject::qt_metacast(_clname);
}

int ManualSettle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
