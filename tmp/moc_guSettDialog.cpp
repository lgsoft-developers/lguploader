/****************************************************************************
** Meta object code from reading C++ file 'guSettDialog.h'
**
** Created: Sun 28. Apr 10:51:38 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/guSettDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'guSettDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_guSettDialog[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      27,   14,   13,   13, 0x08,
      56,   13,   13,   13, 0x08,
      73,   13,   13,   13, 0x08,
      98,   13,   13,   13, 0x08,
     118,   13,   13,   13, 0x08,
     140,   13,   13,   13, 0x08,
     162,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_guSettDialog[] = {
    "guSettDialog\0\0currentIndex\0"
    "currentSettGroupChanged(int)\0"
    "onSaveSettings()\0onChangeDublicateColor()\0"
    "onChangeIsbnColor()\0onChangeBiblioColor()\0"
    "onChangeUploadColor()\0onChangeCategoryColor()\0"
};

const QMetaObject guSettDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_guSettDialog,
      qt_meta_data_guSettDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &guSettDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *guSettDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *guSettDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_guSettDialog))
        return static_cast<void*>(const_cast< guSettDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int guSettDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: currentSettGroupChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: onSaveSettings(); break;
        case 2: onChangeDublicateColor(); break;
        case 3: onChangeIsbnColor(); break;
        case 4: onChangeBiblioColor(); break;
        case 5: onChangeUploadColor(); break;
        case 6: onChangeCategoryColor(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
