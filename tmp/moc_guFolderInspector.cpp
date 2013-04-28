/****************************************************************************
** Meta object code from reading C++ file 'guFolderInspector.h'
**
** Created: Sun 28. Apr 10:51:46 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/guFolderInspector.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'guFolderInspector.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_guFolderInspector[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      32,   19,   18,   18, 0x05,
      59,   18,   18,   18, 0x05,
      77,   18,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      95,   18,   18,   18, 0x0a,
     217,  112,   18,   18, 0x0a,
     290,  267,   18,   18, 0x0a,
     362,  344,   18,   18, 0x0a,
     408,  344,   18,   18, 0x0a,
     453,  344,   18,   18, 0x0a,
     514,  498,   18,   18, 0x0a,
     558,  544,   18,   18, 0x0a,
     597,  588,   18,   18, 0x0a,
     641,  624,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_guFolderInspector[] = {
    "guFolderInspector\0\0MD5,newEbook\0"
    "addNewEbook(QString,ebook)\0dublicateFinded()\0"
    "inspectFinished()\0onAbortInspect()\0"
    "path,searchFileExtensions,searchInSubFolders,extractIdentifiersFromFil"
    "es,extractIdentifiersFromFileNames\0"
    "inspectFolder(QString,QStringList,bool,bool,bool)\0"
    "fileName,ISBNList,type\0"
    "extractIsbnsFromFile(QString,QList<QString>&,QString)\0"
    "fileName,ISBNList\0"
    "extractIsbnsFromDjvu(QString,QList<QString>&)\0"
    "extractIsbnsFromChm(QString,QList<QString>&)\0"
    "extractIsbnsFromPdf(QString,QList<QString>&)\0"
    "fileNameFilters\0onSetNameFilters(QStringList)\0"
    "searchPathStr\0onSetSearchDirectory(QString)\0"
    "toSearch\0onSetSearchInSubdirs(bool)\0"
    "databaseFilePath\0onSetDbFilePath(QString)\0"
};

const QMetaObject guFolderInspector::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_guFolderInspector,
      qt_meta_data_guFolderInspector, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &guFolderInspector::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *guFolderInspector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *guFolderInspector::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_guFolderInspector))
        return static_cast<void*>(const_cast< guFolderInspector*>(this));
    return QThread::qt_metacast(_clname);
}

int guFolderInspector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: addNewEbook((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< ebook(*)>(_a[2]))); break;
        case 1: dublicateFinded(); break;
        case 2: inspectFinished(); break;
        case 3: onAbortInspect(); break;
        case 4: inspectFolder((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 5: extractIsbnsFromFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QString>(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 6: extractIsbnsFromDjvu((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QString>(*)>(_a[2]))); break;
        case 7: extractIsbnsFromChm((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QString>(*)>(_a[2]))); break;
        case 8: extractIsbnsFromPdf((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QString>(*)>(_a[2]))); break;
        case 9: onSetNameFilters((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 10: onSetSearchDirectory((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: onSetSearchInSubdirs((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: onSetDbFilePath((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void guFolderInspector::addNewEbook(QString _t1, ebook _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void guFolderInspector::dublicateFinded()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void guFolderInspector::inspectFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
