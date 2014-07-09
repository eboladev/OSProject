/****************************************************************************
** Meta object code from reading C++ file 'autosettle.h'
**
** Created: Sat May 17 16:18:41 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../autosettle.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'autosettle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AutoSettle[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      40,   11,   28,   11, 0x0a,
      67,   11,   61,   11, 0x0a,
     100,   11,   61,   11, 0x0a,
     133,   11,   61,   11, 0x0a,
     168,   11,   61,   11, 0x0a,
     195,   11,   61,   11, 0x0a,
     243,   11,  239,   11, 0x0a,
     303,   11,  285,   11, 0x0a,
     342,   11,  285,   11, 0x0a,
     385,  383,   11,   11, 0x0a,
     429,   11,   11,   11, 0x0a,
     469,  465,   11,   11, 0x0a,
     526,  521,   11,   11, 0x0a,
     587,   11,  581,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_AutoSettle[] = {
    "AutoSettle\0\0expenseSettle()\0QStringList\0"
    "getElderCardNoList()\0float\0"
    "getElderAccountByCardNo(QString)\0"
    "getElderBedCostByCardNo(QString)\0"
    "getElderNurseCostByCardNo(QString)\0"
    "getElderStageCost(QString)\0"
    "getElderSpecialServiceCostByCardNo(QString)\0"
    "int\0getElderNurseChangeTimesByCardNo(QString)\0"
    "QMap<QDate,float>\0"
    "getElderBedChangeInfoByCardNo(QString)\0"
    "getElderNurseChangeInfoByCardNo(QString)\0"
    ",\0updateAccountByCardNoAndCost(QString,float)\0"
    "updateLevelChangedByCardNo(QString)\0"
    ",,,\0insertBedOrNurseCostInfo(QString,int,QString,float)\0"
    ",,,,\0insertSpecialCostInfo(QString,int,QString,float,QDate)\0"
    "QDate\0getElderResideDateByCardNo(QString)\0"
};

void AutoSettle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AutoSettle *_t = static_cast<AutoSettle *>(_o);
        switch (_id) {
        case 0: _t->expenseSettle(); break;
        case 1: { QStringList _r = _t->getElderCardNoList();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 2: { float _r = _t->getElderAccountByCardNo((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 3: { float _r = _t->getElderBedCostByCardNo((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 4: { float _r = _t->getElderNurseCostByCardNo((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 5: { float _r = _t->getElderStageCost((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 6: { float _r = _t->getElderSpecialServiceCostByCardNo((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 7: { int _r = _t->getElderNurseChangeTimesByCardNo((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 8: { QMap<QDate,float> _r = _t->getElderBedChangeInfoByCardNo((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QMap<QDate,float>*>(_a[0]) = _r; }  break;
        case 9: { QMap<QDate,float> _r = _t->getElderNurseChangeInfoByCardNo((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QMap<QDate,float>*>(_a[0]) = _r; }  break;
        case 10: _t->updateAccountByCardNoAndCost((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 11: _t->updateLevelChangedByCardNo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->insertBedOrNurseCostInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4]))); break;
        case 13: _t->insertSpecialCostInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< QDate(*)>(_a[5]))); break;
        case 14: { QDate _r = _t->getElderResideDateByCardNo((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDate*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AutoSettle::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AutoSettle::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_AutoSettle,
      qt_meta_data_AutoSettle, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AutoSettle::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AutoSettle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AutoSettle::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AutoSettle))
        return static_cast<void*>(const_cast< AutoSettle*>(this));
    return QObject::qt_metacast(_clname);
}

int AutoSettle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
