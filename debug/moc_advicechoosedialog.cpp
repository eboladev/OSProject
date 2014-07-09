/****************************************************************************
** Meta object code from reading C++ file 'advicechoosedialog.h'
**
** Created: Sat May 17 16:18:36 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../advicechoosedialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'advicechoosedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AdviceChooseDialog[] = {

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
      20,   19,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
      43,   19,   19,   19, 0x08,
      66,   19,   19,   19, 0x08,
      90,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AdviceChooseDialog[] = {
    "AdviceChooseDialog\0\0sendAdviceChoosed(int)\0"
    "on_btn_clear_clicked()\0on_btn_search_clicked()\0"
    "doubleClickRecord(QModelIndex)\0"
};

void AdviceChooseDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AdviceChooseDialog *_t = static_cast<AdviceChooseDialog *>(_o);
        switch (_id) {
        case 0: _t->sendAdviceChoosed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_btn_clear_clicked(); break;
        case 2: _t->on_btn_search_clicked(); break;
        case 3: _t->doubleClickRecord((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AdviceChooseDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AdviceChooseDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AdviceChooseDialog,
      qt_meta_data_AdviceChooseDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AdviceChooseDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AdviceChooseDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AdviceChooseDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AdviceChooseDialog))
        return static_cast<void*>(const_cast< AdviceChooseDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int AdviceChooseDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void AdviceChooseDialog::sendAdviceChoosed(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
