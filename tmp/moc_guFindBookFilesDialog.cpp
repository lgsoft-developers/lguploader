/****************************************************************************
** Meta object code from reading C++ file 'guFindBookFilesDialog.h'
**
** Created: Sun 28. Apr 10:51:55 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/guFindBookFilesDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'guFindBookFilesDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_guFindBookFilesDialog[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   22,   22,   22, 0x0a,
      47,   22,   22,   22, 0x0a,
      64,   22,   22,   22, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_guFindBookFilesDialog[] = {
    "guFindBookFilesDialog\0\0onSelectFolderClicked()\0"
    "onSaveSettings()\0loadSettings()\0"
};

const QMetaObject guFindBookFilesDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_guFindBookFilesDialog,
      qt_meta_data_guFindBookFilesDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &guFindBookFilesDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *guFindBookFilesDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *guFindBookFilesDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_guFindBookFilesDialog))
        return static_cast<void*>(const_cast< guFindBookFilesDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int guFindBookFilesDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onSelectFolderClicked(); break;
        case 1: onSaveSettings(); break;
        case 2: loadSettings(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
