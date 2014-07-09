/****************************************************************************
** Meta object code from reading C++ file 'roomtreewidget.h'
**
** Created: Wed Jun 25 15:57:56 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../roomtreewidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'roomtreewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RoomTreeWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      50,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      14,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   16,   15,   15, 0x05,
      44,   15,   15,   15, 0x05,
      91,   59,   15,   15, 0x05,
     133,   16,   15,   15, 0x05,
     174,  153,   15,   15, 0x05,
     210,  197,   15,   15, 0x05,
     245,  231,   15,   15, 0x05,
     294,  262,   15,   15, 0x05,
     339,  316,   15,   15, 0x05,
     388,  357,   15,   15, 0x05,
     413,  357,   15,   15, 0x05,
     438,   16,   15,   15, 0x05,
     473,  460,   15,   15, 0x05,
     509,  506,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
     544,  540,   15,   15, 0x0a,
     566,   15,   15,   15, 0x0a,
     580,   15,   15,   15, 0x0a,
     594,   15,   15,   15, 0x0a,
     605,   15,   15,   15, 0x0a,
     619,   15,   15,   15, 0x0a,
     642,   15,   15,   15, 0x0a,
     652,   15,   15,   15, 0x0a,
     674,   15,   15,   15, 0x0a,
     685,   15,   15,   15, 0x0a,
     710,  705,   15,   15, 0x0a,
     732,  705,   15,   15, 0x0a,
     749,  705,   15,   15, 0x0a,
     770,   15,   15,   15, 0x0a,
     780,   15,   15,   15, 0x0a,
     797,  705,   15,   15, 0x0a,
     811,   15,   15,   15, 0x0a,
     822,   15,   15,   15, 0x0a,
     835,   15,   15,   15, 0x0a,
     853,   15,   15,   15, 0x0a,
     862,   15,   15,   15, 0x0a,
     873,   15,   15,   15, 0x0a,
     889,   15,   15,   15, 0x0a,
     900,   15,   15,   15, 0x0a,
     920,  909,   15,   15, 0x0a,
    1004,  954,   15,   15, 0x0a,
    1047,   59,   15,   15, 0x0a,
    1102, 1090,   15,   15, 0x0a,
    1157, 1140,   15,   15, 0x0a,
    1213, 1090,   15,   15, 0x0a,
    1249, 1090,   15,   15, 0x0a,
    1290, 1285,   15,   15, 0x0a,
    1324, 1090,   15,   15, 0x0a,
    1366, 1090,   15,   15, 0x0a,
    1402, 1285,   15,   15, 0x0a,
    1435, 1090,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_RoomTreeWidget[] = {
    "RoomTreeWidget\0\0index\0lookuoViewSignal(int)\0"
    "showHomepage()\0buildingname,floorname,roomname\0"
    "lookuoViewSignal(QString,QString,QString)\0"
    "expandbuilding(int)\0parentindex,curindex\0"
    "scrolltofloor(int,int)\0buildingname\0"
    "addBuilding(QString)\0buildingindex\0"
    "delBuilding(int)\0buildingindex,floornum,curindex\0"
    "addFloor(int,int,int)\0buildingindex,curindex\0"
    "delFloor(int,int)\0buildingindex,curindex,rooname\0"
    "addRoom(int,int,QString)\0"
    "delRoom(int,int,QString)\0delRequestSignal(int)\0"
    "roomviewname\0deleteRoomRequestSignal(QString)\0"
    "id\0refreshVernierTableWidget(int)\0pos\0"
    "showRightMenu(QPoint)\0addBuilding()\0"
    "delBuilding()\0addFloor()\0deleteFloor()\0"
    "lookupFloorOlderInfo()\0addRoom()\0"
    "lookupRoomOlderInfo()\0editRoom()\0"
    "deleteRoomRequest()\0flag\0deleteRoomCanbe(bool)\0"
    "deleteRoom(bool)\0setRoomMonitor(bool)\0"
    "addView()\0delViewRequest()\0delView(bool)\0"
    "editView()\0lookupView()\0lookupOlderInfo()\0"
    "addBed()\0addOlder()\0editOlderInfo()\0"
    "delOlder()\0delBed()\0modelindex\0"
    "defaultDoubleClicked(QModelIndex)\0"
    "tarbuildingname,tarfloorname,tarroomname,viewname\0"
    "addViewTo(QString,QString,QString,QString)\0"
    "locateAndOpenRoom(QString,QString,QString)\0"
    "item,column\0onItemActivated(QTreeWidgetItem*,int)\0"
    "current,previous\0"
    "onCurrentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)\0"
    "onItemChanged(QTreeWidgetItem*,int)\0"
    "onItemClicked(QTreeWidgetItem*,int)\0"
    "item\0onItemCollapsed(QTreeWidgetItem*)\0"
    "onItemDoubleClicked(QTreeWidgetItem*,int)\0"
    "onItemEntered(QTreeWidgetItem*,int)\0"
    "onItemExpanded(QTreeWidgetItem*)\0"
    "onItemPressed(QTreeWidgetItem*,int)\0"
};

void RoomTreeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RoomTreeWidget *_t = static_cast<RoomTreeWidget *>(_o);
        switch (_id) {
        case 0: _t->lookuoViewSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->showHomepage(); break;
        case 2: _t->lookuoViewSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 3: _t->expandbuilding((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->scrolltofloor((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->addBuilding((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->delBuilding((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->addFloor((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 8: _t->delFloor((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->addRoom((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 10: _t->delRoom((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 11: _t->delRequestSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->deleteRoomRequestSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->refreshVernierTableWidget((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->showRightMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 15: _t->addBuilding(); break;
        case 16: _t->delBuilding(); break;
        case 17: _t->addFloor(); break;
        case 18: _t->deleteFloor(); break;
        case 19: _t->lookupFloorOlderInfo(); break;
        case 20: _t->addRoom(); break;
        case 21: _t->lookupRoomOlderInfo(); break;
        case 22: _t->editRoom(); break;
        case 23: _t->deleteRoomRequest(); break;
        case 24: _t->deleteRoomCanbe((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: _t->deleteRoom((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: _t->setRoomMonitor((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 27: _t->addView(); break;
        case 28: _t->delViewRequest(); break;
        case 29: _t->delView((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 30: _t->editView(); break;
        case 31: _t->lookupView(); break;
        case 32: _t->lookupOlderInfo(); break;
        case 33: _t->addBed(); break;
        case 34: _t->addOlder(); break;
        case 35: _t->editOlderInfo(); break;
        case 36: _t->delOlder(); break;
        case 37: _t->delBed(); break;
        case 38: _t->defaultDoubleClicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 39: _t->addViewTo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 40: _t->locateAndOpenRoom((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 41: _t->onItemActivated((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 42: _t->onCurrentItemChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[2]))); break;
        case 43: _t->onItemChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 44: _t->onItemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 45: _t->onItemCollapsed((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 46: _t->onItemDoubleClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 47: _t->onItemEntered((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 48: _t->onItemExpanded((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 49: _t->onItemPressed((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RoomTreeWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RoomTreeWidget::staticMetaObject = {
    { &QTreeWidget::staticMetaObject, qt_meta_stringdata_RoomTreeWidget,
      qt_meta_data_RoomTreeWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RoomTreeWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RoomTreeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RoomTreeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RoomTreeWidget))
        return static_cast<void*>(const_cast< RoomTreeWidget*>(this));
    return QTreeWidget::qt_metacast(_clname);
}

int RoomTreeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 50)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 50;
    }
    return _id;
}

// SIGNAL 0
void RoomTreeWidget::lookuoViewSignal(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RoomTreeWidget::showHomepage()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void RoomTreeWidget::lookuoViewSignal(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void RoomTreeWidget::expandbuilding(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void RoomTreeWidget::scrolltofloor(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void RoomTreeWidget::addBuilding(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void RoomTreeWidget::delBuilding(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void RoomTreeWidget::addFloor(int _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void RoomTreeWidget::delFloor(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void RoomTreeWidget::addRoom(int _t1, int _t2, QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void RoomTreeWidget::delRoom(int _t1, int _t2, QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void RoomTreeWidget::delRequestSignal(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void RoomTreeWidget::deleteRoomRequestSignal(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void RoomTreeWidget::refreshVernierTableWidget(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}
static const uint qt_meta_data_NameSelectDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      47,   18,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      98,   90,   17,   17, 0x0a,
     123,   17,   17,   17, 0x0a,
     141,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_NameSelectDialog[] = {
    "NameSelectDialog\0\0buildname,floorname,roomname\0"
    "locateAndOpenRoom(QString,QString,QString)\0"
    "row,col\0onShowOlderInfo(int,int)\0"
    "onShowOlderInfo()\0showRightMenu(QPoint)\0"
};

void NameSelectDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        NameSelectDialog *_t = static_cast<NameSelectDialog *>(_o);
        switch (_id) {
        case 0: _t->locateAndOpenRoom((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->onShowOlderInfo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->onShowOlderInfo(); break;
        case 3: _t->showRightMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData NameSelectDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject NameSelectDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NameSelectDialog,
      qt_meta_data_NameSelectDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NameSelectDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NameSelectDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NameSelectDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NameSelectDialog))
        return static_cast<void*>(const_cast< NameSelectDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int NameSelectDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void NameSelectDialog::locateAndOpenRoom(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_OlderInfoWidget[] = {

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

static const char qt_meta_stringdata_OlderInfoWidget[] = {
    "OlderInfoWidget\0"
};

void OlderInfoWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData OlderInfoWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject OlderInfoWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_OlderInfoWidget,
      qt_meta_data_OlderInfoWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &OlderInfoWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *OlderInfoWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *OlderInfoWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OlderInfoWidget))
        return static_cast<void*>(const_cast< OlderInfoWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int OlderInfoWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_AddBuildingDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      32,   19,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      53,   18,   18,   18, 0x0a,
      75,   18,   18,   18, 0x0a,
     113,   96,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_AddBuildingDialog[] = {
    "AddBuildingDialog\0\0buildingname\0"
    "addBuilding(QString)\0onConfirmPushButton()\0"
    "onCancelPushButton()\0tempbuildingname\0"
    "onBuildingNameChanged(QString)\0"
};

void AddBuildingDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AddBuildingDialog *_t = static_cast<AddBuildingDialog *>(_o);
        switch (_id) {
        case 0: _t->addBuilding((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->onConfirmPushButton(); break;
        case 2: _t->onCancelPushButton(); break;
        case 3: _t->onBuildingNameChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AddBuildingDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AddBuildingDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AddBuildingDialog,
      qt_meta_data_AddBuildingDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AddBuildingDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AddBuildingDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AddBuildingDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AddBuildingDialog))
        return static_cast<void*>(const_cast< AddBuildingDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int AddBuildingDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void AddBuildingDialog::addBuilding(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_AddFloorDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      48,   16,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      70,   15,   15,   15, 0x0a,
      92,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_AddFloorDialog[] = {
    "AddFloorDialog\0\0buildingindex,floornum,curindex\0"
    "addFloor(int,int,int)\0onConfirmPushButton()\0"
    "onCancelPushButton()\0"
};

void AddFloorDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AddFloorDialog *_t = static_cast<AddFloorDialog *>(_o);
        switch (_id) {
        case 0: _t->addFloor((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->onConfirmPushButton(); break;
        case 2: _t->onCancelPushButton(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AddFloorDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AddFloorDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AddFloorDialog,
      qt_meta_data_AddFloorDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AddFloorDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AddFloorDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AddFloorDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AddFloorDialog))
        return static_cast<void*>(const_cast< AddFloorDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int AddFloorDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void AddFloorDialog::addFloor(int _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_AddRoomDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      46,   15,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      71,   14,   14,   14, 0x0a,
      93,   14,   14,   14, 0x0a,
     127,  114,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_AddRoomDialog[] = {
    "AddRoomDialog\0\0buildingindex,curindex,rooname\0"
    "addRoom(int,int,QString)\0onConfirmPushButton()\0"
    "onCancelPushButton()\0temproomname\0"
    "onRoomNameChanged(QString)\0"
};

void AddRoomDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AddRoomDialog *_t = static_cast<AddRoomDialog *>(_o);
        switch (_id) {
        case 0: _t->addRoom((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->onConfirmPushButton(); break;
        case 2: _t->onCancelPushButton(); break;
        case 3: _t->onRoomNameChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AddRoomDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AddRoomDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AddRoomDialog,
      qt_meta_data_AddRoomDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AddRoomDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AddRoomDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AddRoomDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AddRoomDialog))
        return static_cast<void*>(const_cast< AddRoomDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int AddRoomDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void AddRoomDialog::addRoom(int _t1, int _t2, QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_DelRoomProcessDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DelRoomProcessDialog[] = {
    "DelRoomProcessDialog\0\0onTimer()\0"
};

void DelRoomProcessDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DelRoomProcessDialog *_t = static_cast<DelRoomProcessDialog *>(_o);
        switch (_id) {
        case 0: _t->onTimer(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData DelRoomProcessDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DelRoomProcessDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DelRoomProcessDialog,
      qt_meta_data_DelRoomProcessDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DelRoomProcessDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DelRoomProcessDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DelRoomProcessDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DelRoomProcessDialog))
        return static_cast<void*>(const_cast< DelRoomProcessDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int DelRoomProcessDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
static const uint qt_meta_data_AddBedDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      36,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_AddBedDialog[] = {
    "AddBedDialog\0\0onConfirmPushButton()\0"
    "onCancelPushButton()\0"
};

void AddBedDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AddBedDialog *_t = static_cast<AddBedDialog *>(_o);
        switch (_id) {
        case 0: _t->onConfirmPushButton(); break;
        case 1: _t->onCancelPushButton(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData AddBedDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AddBedDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AddBedDialog,
      qt_meta_data_AddBedDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AddBedDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AddBedDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AddBedDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AddBedDialog))
        return static_cast<void*>(const_cast< AddBedDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int AddBedDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
static const uint qt_meta_data_AddOlderDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x0a,
      38,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_AddOlderDialog[] = {
    "AddOlderDialog\0\0onConfirmPushButton()\0"
    "onCancelPushButton()\0"
};

void AddOlderDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AddOlderDialog *_t = static_cast<AddOlderDialog *>(_o);
        switch (_id) {
        case 0: _t->onConfirmPushButton(); break;
        case 1: _t->onCancelPushButton(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData AddOlderDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AddOlderDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AddOlderDialog,
      qt_meta_data_AddOlderDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AddOlderDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AddOlderDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AddOlderDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AddOlderDialog))
        return static_cast<void*>(const_cast< AddOlderDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int AddOlderDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
static const uint qt_meta_data_DelOlderDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x0a,
      38,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DelOlderDialog[] = {
    "DelOlderDialog\0\0onConfirmPushButton()\0"
    "onCancelPushButton()\0"
};

void DelOlderDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DelOlderDialog *_t = static_cast<DelOlderDialog *>(_o);
        switch (_id) {
        case 0: _t->onConfirmPushButton(); break;
        case 1: _t->onCancelPushButton(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData DelOlderDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DelOlderDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DelOlderDialog,
      qt_meta_data_DelOlderDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DelOlderDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DelOlderDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DelOlderDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DelOlderDialog))
        return static_cast<void*>(const_cast< DelOlderDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int DelOlderDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
