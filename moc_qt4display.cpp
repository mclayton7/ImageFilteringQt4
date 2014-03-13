/****************************************************************************
** Meta object code from reading C++ file 'qt4display.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qt4display.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qt4display.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QDisplay[] = {

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
       9,   21,   21,   21, 0x0a,
      22,   21,   21,   21, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QDisplay[] = {
    "QDisplay\0timerDone()\0\0mainClosed()\0"
};

void QDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QDisplay *_t = static_cast<QDisplay *>(_o);
        switch (_id) {
        case 0: _t->timerDone(); break;
        case 1: _t->mainClosed(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData QDisplay::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QDisplay::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_QDisplay,
      qt_meta_data_QDisplay, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QDisplay::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QDisplay))
        return static_cast<void*>(const_cast< QDisplay*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int QDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
