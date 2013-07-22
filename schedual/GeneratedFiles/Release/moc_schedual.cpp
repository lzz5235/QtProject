/****************************************************************************
** Meta object code from reading C++ file 'schedual.h'
**
** Created: Mon Dec 12 21:22:25 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../schedual.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'schedual.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Schedual[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      22,    9,    9,    9, 0x08,
      29,    9,    9,    9, 0x08,
      37,    9,    9,    9, 0x08,
      48,    9,    9,    9, 0x08,
      59,    9,    9,    9, 0x08,
      70,    9,    9,    9, 0x08,
      85,   80,    9,    9, 0x08,
     130,  126,    9,    9, 0x08,
     166,    9,    9,    9, 0x08,
     180,    9,    9,    9, 0x08,
     190,    9,    9,    9, 0x08,
     213,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Schedual[] = {
    "Schedual\0\0BlueTooth()\0Exit()\0Aboub()\0"
    "AlertSet()\0MusicSet()\0DiarySet()\0"
    "TeleSet()\0item\0on_clicked_listWidget(QTableWidgetItem*)\0"
    "pos\0on_clicked_listWidget_Right(QPoint)\0"
    "ClockChange()\0AutoRun()\0SchedualHelpDocument()\0"
    "Flush()\0"
};

const QMetaObject Schedual::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Schedual,
      qt_meta_data_Schedual, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Schedual::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Schedual::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Schedual::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Schedual))
        return static_cast<void*>(const_cast< Schedual*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Schedual::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: BlueTooth(); break;
        case 1: Exit(); break;
        case 2: Aboub(); break;
        case 3: AlertSet(); break;
        case 4: MusicSet(); break;
        case 5: DiarySet(); break;
        case 6: TeleSet(); break;
        case 7: on_clicked_listWidget((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 8: on_clicked_listWidget_Right((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 9: ClockChange(); break;
        case 10: AutoRun(); break;
        case 11: SchedualHelpDocument(); break;
        case 12: Flush(); break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
