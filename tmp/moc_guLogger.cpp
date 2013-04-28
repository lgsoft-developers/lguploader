/****************************************************************************
** Meta object code from reading C++ file 'guLogger.h'
**
** Created: Sun 28. Apr 10:51:52 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/guLogger.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'guLogger.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_guLogger[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      28,   10,    9,    9, 0x0a,
      55,   45,    9,    9, 0x2a,

       0        // eod
};

static const char qt_meta_stringdata_guLogger[] = {
    "guLogger\0\0logString,logType\0"
    "log(QString,int)\0logString\0log(QString)\0"
};

const QMetaObject guLogger::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_guLogger,
      qt_meta_data_guLogger, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &guLogger::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *guLogger::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *guLogger::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_guLogger))
        return static_cast<void*>(const_cast< guLogger*>(this));
    return QObject::qt_metacast(_clname);
}

int guLogger::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: log((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
