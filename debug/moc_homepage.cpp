/****************************************************************************
** Meta object code from reading C++ file 'homepage.h'
**
** Created: Sat Jun 28 16:05:42 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../homepage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'homepage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_HomePage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      30,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      55,   49,    9,    9, 0x0a,
      96,   75,    9,    9, 0x0a,
     119,   49,    9,    9, 0x0a,
     155,  142,    9,    9, 0x0a,
     176,   49,    9,    9, 0x0a,
     220,  193,    9,    9, 0x0a,
     260,  242,    9,    9, 0x0a,
     305,  278,    9,    9, 0x0a,
     330,  278,    9,    9, 0x0a,
     355,   49,    9,    9, 0x0a,
     386,    9,  377,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_HomePage[] = {
    "HomePage\0\0openViewSignal(int)\0"
    "alarmLightSignal()\0index\0highlightFloor(int)\0"
    "parentindex,curindex\0scrollToFloor(int,int)\0"
    "expandingBuilding(int)\0buildingname\0"
    "addBuilding(QString)\0delBuilding(int)\0"
    "parentindex,floornum,index\0"
    "addFloor(int,int,int)\0parentindex,index\0"
    "delFloor(int,int)\0parentindex,index,roomname\0"
    "addRoom(int,int,QString)\0"
    "delRoom(int,int,QString)\0onCurrentChanged(int)\0"
    "QObject*\0mySender()\0"
};

void HomePage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        HomePage *_t = static_cast<HomePage *>(_o);
        switch (_id) {
        case 0: _t->openViewSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->alarmLightSignal(); break;
        case 2: _t->highlightFloor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->scrollToFloor((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->expandingBuilding((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->addBuilding((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->delBuilding((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->addFloor((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 8: _t->delFloor((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->addRoom((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 10: _t->delRoom((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 11: _t->onCurrentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: { QObject* _r = _t->mySender();
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData HomePage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject HomePage::staticMetaObject = {
    { &QToolBox::staticMetaObject, qt_meta_stringdata_HomePage,
      qt_meta_data_HomePage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &HomePage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *HomePage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *HomePage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HomePage))
        return static_cast<void*>(const_cast< HomePage*>(this));
    return QToolBox::qt_metacast(_clname);
}

int HomePage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QToolBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void HomePage::openViewSignal(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void HomePage::alarmLightSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
static const uint qt_meta_data_BuildingToolBox[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_BuildingToolBox[] = {
    "BuildingToolBox\0"
};

void BuildingToolBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData BuildingToolBox::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BuildingToolBox::staticMetaObject = {
    { &QToolBox::staticMetaObject, qt_meta_stringdata_BuildingToolBox,
      qt_meta_data_BuildingToolBox, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BuildingToolBox::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BuildingToolBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BuildingToolBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BuildingToolBox))
        return static_cast<void*>(const_cast< BuildingToolBox*>(this));
    return QToolBox::qt_metacast(_clname);
}

int BuildingToolBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QToolBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_BuildingSpliter[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_BuildingSpliter[] = {
    "BuildingSpliter\0\0openViewSignal(int)\0"
};

void BuildingSpliter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BuildingSpliter *_t = static_cast<BuildingSpliter *>(_o);
        switch (_id) {
        case 0: _t->openViewSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData BuildingSpliter::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BuildingSpliter::staticMetaObject = {
    { &QSplitter::staticMetaObject, qt_meta_stringdata_BuildingSpliter,
      qt_meta_data_BuildingSpliter, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BuildingSpliter::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BuildingSpliter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BuildingSpliter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BuildingSpliter))
        return static_cast<void*>(const_cast< BuildingSpliter*>(this));
    return QSplitter::qt_metacast(_clname);
}

int BuildingSpliter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSplitter::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void BuildingSpliter::openViewSignal(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_FloorFrameWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_FloorFrameWidget[] = {
    "FloorFrameWidget\0"
};

void FloorFrameWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData FloorFrameWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FloorFrameWidget::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_FloorFrameWidget,
      qt_meta_data_FloorFrameWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FloorFrameWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FloorFrameWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FloorFrameWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FloorFrameWidget))
        return static_cast<void*>(const_cast< FloorFrameWidget*>(this));
    return QFrame::qt_metacast(_clname);
}

int FloorFrameWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_RoomStateWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_RoomStateWidget[] = {
    "RoomStateWidget\0"
};

void RoomStateWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData RoomStateWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RoomStateWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RoomStateWidget,
      qt_meta_data_RoomStateWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RoomStateWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RoomStateWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RoomStateWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RoomStateWidget))
        return static_cast<void*>(const_cast< RoomStateWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int RoomStateWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_BedWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_BedWidget[] = {
    "BedWidget\0"
};

void BedWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData BedWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BedWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BedWidget,
      qt_meta_data_BedWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BedWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BedWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BedWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BedWidget))
        return static_cast<void*>(const_cast< BedWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int BedWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_GeneralViewWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_GeneralViewWidget[] = {
    "GeneralViewWidget\0"
};

void GeneralViewWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData GeneralViewWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GeneralViewWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GeneralViewWidget,
      qt_meta_data_GeneralViewWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GeneralViewWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GeneralViewWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GeneralViewWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GeneralViewWidget))
        return static_cast<void*>(const_cast< GeneralViewWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int GeneralViewWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
