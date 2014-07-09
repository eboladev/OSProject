/****************************************************************************
** Meta object code from reading C++ file 'accountdetail.h'
**
** Created: Sat May 17 16:18:41 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../accountdetail.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'accountdetail.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AccountDetail[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
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
     134,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AccountDetail[] = {
    "AccountDetail\0\0closeAccountDetailPage()\0"
    "on_btn_close_clicked()\0on_btn_clear_clicked()\0"
    "on_btn_search_clicked()\0on_toolButton_clicked()\0"
    "doubleClickRecord(QString)\0"
};

void AccountDetail::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AccountDetail *_t = static_cast<AccountDetail *>(_o);
        switch (_id) {
        case 0: _t->closeAccountDetailPage(); break;
        case 1: _t->on_btn_close_clicked(); break;
        case 2: _t->on_btn_clear_clicked(); break;
        case 3: _t->on_btn_search_clicked(); break;
        case 4: _t->on_toolButton_clicked(); break;
        case 5: _t->doubleClickRecord((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AccountDetail::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AccountDetail::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AccountDetail,
      qt_meta_data_AccountDetail, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AccountDetail::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AccountDetail::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AccountDetail::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AccountDetail))
        return static_cast<void*>(const_cast< AccountDetail*>(this));
    return QWidget::qt_metacast(_clname);
}

int AccountDetail::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void AccountDetail::closeAccountDetailPage()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
