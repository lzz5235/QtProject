/****************************************************************************
** Meta object code from reading C++ file 'weather.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../weather.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'weather.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CWeatherWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      32,   15,   15,   15, 0x08,
      48,   15,   15,   15, 0x08,
      61,   15,   15,   15, 0x08,
      72,   15,   15,   15, 0x08,
      88,   15,   15,   15, 0x08,
     106,   15,   15,   15, 0x08,
     132,  128,   15,   15, 0x08,
     165,   15,   15,   15, 0x08,
     198,   15,  190,   15, 0x08,
     209,  128,  190,   15, 0x08,
     227,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CWeatherWidget[] = {
    "CWeatherWidget\0\0slotNetworkIP()\0"
    "slotBootStart()\0switchCtiy()\0showTime()\0"
    "slotReadyRead()\0slotWeatherInfo()\0"
    "slotPublicNetworkIP()\0str\0"
    "slotPublicNetworkLocal(QString&)\0"
    "slotPublicNetworkLocal()\0QString\0"
    "FindCode()\0showPic(QString*)\0InitPic()\0"
};

void CWeatherWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CWeatherWidget *_t = static_cast<CWeatherWidget *>(_o);
        switch (_id) {
        case 0: _t->slotNetworkIP(); break;
        case 1: _t->slotBootStart(); break;
        case 2: _t->switchCtiy(); break;
        case 3: _t->showTime(); break;
        case 4: _t->slotReadyRead(); break;
        case 5: _t->slotWeatherInfo(); break;
        case 6: _t->slotPublicNetworkIP(); break;
        case 7: _t->slotPublicNetworkLocal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->slotPublicNetworkLocal(); break;
        case 9: { QString _r = _t->FindCode();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 10: { QString _r = _t->showPic((*reinterpret_cast< QString*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 11: _t->InitPic(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CWeatherWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CWeatherWidget::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_CWeatherWidget,
      qt_meta_data_CWeatherWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CWeatherWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CWeatherWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CWeatherWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CWeatherWidget))
        return static_cast<void*>(const_cast< CWeatherWidget*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int CWeatherWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
