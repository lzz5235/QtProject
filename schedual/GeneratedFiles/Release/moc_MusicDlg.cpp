/****************************************************************************
** Meta object code from reading C++ file 'MusicDlg.h'
**
** Created: Thu Dec 8 18:34:37 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MusicDlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MusicDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MusicDlg[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      21,    9,    9,    9, 0x08,
      47,   29,    9,    9, 0x08,
      94,   89,    9,    9, 0x08,
     114,  107,    9,    9, 0x08,
     149,   29,    9,    9, 0x08,
     195,    9,    9,    9, 0x08,
     222,  211,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MusicDlg[] = {
    "MusicDlg\0\0addFiles()\0about()\0"
    "newState,oldState\0"
    "stateChanged(Phonon::State,Phonon::State)\0"
    "time\0tick(qint64)\0source\0"
    "sourceChanged(Phonon::MediaSource)\0"
    "metaStateChanged(Phonon::State,Phonon::State)\0"
    "aboutToFinish()\0row,column\0"
    "tableClicked(int,int)\0"
};

const QMetaObject MusicDlg::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MusicDlg,
      qt_meta_data_MusicDlg, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MusicDlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MusicDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MusicDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MusicDlg))
        return static_cast<void*>(const_cast< MusicDlg*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MusicDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: addFiles(); break;
        case 1: about(); break;
        case 2: stateChanged((*reinterpret_cast< Phonon::State(*)>(_a[1])),(*reinterpret_cast< Phonon::State(*)>(_a[2]))); break;
        case 3: tick((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 4: sourceChanged((*reinterpret_cast< const Phonon::MediaSource(*)>(_a[1]))); break;
        case 5: metaStateChanged((*reinterpret_cast< Phonon::State(*)>(_a[1])),(*reinterpret_cast< Phonon::State(*)>(_a[2]))); break;
        case 6: aboutToFinish(); break;
        case 7: tableClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
