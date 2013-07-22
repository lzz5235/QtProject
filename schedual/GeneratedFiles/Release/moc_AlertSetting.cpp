/****************************************************************************
** Meta object code from reading C++ file 'AlertSetting.h'
**
** Created: Thu Dec 8 18:34:39 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AlertSetting.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AlertSetting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AlertSetting[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      23,   13,   13,   13, 0x08,
      35,   13,   13,   13, 0x08,
      47,   13,   13,   13, 0x08,
      62,   13,   13,   13, 0x08,
     103,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AlertSetting[] = {
    "AlertSetting\0\0on_Add()\0on_Modify()\0"
    "on_Delete()\0on_DeleteAll()\0"
    "on_clicked_listWidget(QTableWidgetItem*)\0"
    "on_clicked_listWidget_Right(QPoint)\0"
};

const QMetaObject AlertSetting::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AlertSetting,
      qt_meta_data_AlertSetting, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AlertSetting::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AlertSetting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AlertSetting::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AlertSetting))
        return static_cast<void*>(const_cast< AlertSetting*>(this));
    return QDialog::qt_metacast(_clname);
}

int AlertSetting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_Add(); break;
        case 1: on_Modify(); break;
        case 2: on_Delete(); break;
        case 3: on_DeleteAll(); break;
        case 4: on_clicked_listWidget((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 5: on_clicked_listWidget_Right((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
