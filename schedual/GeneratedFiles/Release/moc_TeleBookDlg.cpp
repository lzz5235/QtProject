/****************************************************************************
** Meta object code from reading C++ file 'TeleBookDlg.h'
**
** Created: Thu Dec 8 18:34:35 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TeleBookDlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TeleBookDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TeleBookDlg[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      22,   12,   12,   12, 0x08,
      34,   12,   12,   12, 0x08,
      53,   48,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TeleBookDlg[] = {
    "TeleBookDlg\0\0on_Add()\0on_Delete()\0"
    "on_AddPhoto()\0item\0"
    "on_clicked_listWidget(QListWidgetItem*)\0"
};

const QMetaObject TeleBookDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_TeleBookDlg,
      qt_meta_data_TeleBookDlg, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TeleBookDlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TeleBookDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TeleBookDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TeleBookDlg))
        return static_cast<void*>(const_cast< TeleBookDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int TeleBookDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_Add(); break;
        case 1: on_Delete(); break;
        case 2: on_AddPhoto(); break;
        case 3: on_clicked_listWidget((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
