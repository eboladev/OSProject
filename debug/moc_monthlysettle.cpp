/****************************************************************************
** Meta object code from reading C++ file 'monthlysettle.h'
**
** Created: Sat May 17 16:18:38 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../monthlysettle.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'monthlysettle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MonthlySettle[] = {

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
      63,   14,   14,   14, 0x08,
      86,   14,   14,   14, 0x08,
     110,   14,   14,   14, 0x08,
     141,   14,   14,   14, 0x08,
     163,   14,   14,   14, 0x08,
     187,   14,   14,   14, 0x08,
     213,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MonthlySettle[] = {
    "MonthlySettle\0\0closeMonthlySettlePage()\0"
    "on_btn_close_clicked()\0on_btn_clear_clicked()\0"
    "on_btn_search_clicked()\0"
    "doubleClickRecord(QModelIndex)\0"
    "on_btn_auto_clicked()\0on_toolButton_clicked()\0"
    "doubleClickElder(QString)\0"
    "on_btn_print_clicked()\0"
};

void MonthlySettle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MonthlySettle *_t = static_cast<MonthlySettle *>(_o);
        switch (_id) {
        case 0: _t->closeMonthlySettlePage(); break;
        case 1: _t->on_btn_close_clicked(); break;
        case 2: _t->on_btn_clear_clicked(); break;
        case 3: _t->on_btn_search_clicked(); break;
        case 4: _t->doubleClickRecord((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 5: _t->on_btn_auto_clicked(); break;
        case 6: _t->on_toolButton_clicked(); break;
        case 7: _t->doubleClickElder((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->on_btn_print_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MonthlySettle::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MonthlySettle::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MonthlySettle,
      qt_meta_data_MonthlySettle, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MonthlySettle::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MonthlySettle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MonthlySettle::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MonthlySettle))
        return static_cast<void*>(const_cast< MonthlySettle*>(this));
    return QWidget::qt_metacast(_clname);
}

int MonthlySettle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void MonthlySettle::closeMonthlySettlePage()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
