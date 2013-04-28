/****************************************************************************
** Meta object code from reading C++ file 'guBookUploader.h'
**
** Created: Sun 28. Apr 10:51:50 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/guBookUploader.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'guBookUploader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_uploadEbookReply[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      30,   18,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      85,   64,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_uploadEbookReply[] = {
    "uploadEbookReply\0\0MD5,percent\0"
    "onUploadEbookProcess(QString,int)\0"
    "bytesSent,bytesTotal\0"
    "onUploadProgress(qint64,qint64)\0"
};

const QMetaObject uploadEbookReply::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_uploadEbookReply,
      qt_meta_data_uploadEbookReply, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &uploadEbookReply::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *uploadEbookReply::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *uploadEbookReply::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_uploadEbookReply))
        return static_cast<void*>(const_cast< uploadEbookReply*>(this));
    return QObject::qt_metacast(_clname);
}

int uploadEbookReply::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onUploadEbookProcess((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: onUploadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void uploadEbookReply::onUploadEbookProcess(QString _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_guBookUploader[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      36,   16,   15,   15, 0x05,
      82,   68,   15,   15, 0x05,
     131,  111,   15,   15, 0x05,
     161,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
     181,   15,   15,   15, 0x0a,
     207,  201,   15,   15, 0x0a,
     259,  247,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_guBookUploader[] = {
    "guBookUploader\0\0MD5ofUpload,percent\0"
    "ebookUploadProcess(QString,int)\0"
    "MD5ofUploaded\0uploadEbookFinished(QString)\0"
    "MD5ofUploaded,error\0uploadEbookError(QString,int)\0"
    "allEbooksUploaded()\0uplEbookFromQueue()\0"
    "reply\0processUploadEbookReply(QNetworkReply*)\0"
    "MD5,percent\0onUploadProgress(QString,int)\0"
};

const QMetaObject guBookUploader::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_guBookUploader,
      qt_meta_data_guBookUploader, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &guBookUploader::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *guBookUploader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *guBookUploader::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_guBookUploader))
        return static_cast<void*>(const_cast< guBookUploader*>(this));
    return QObject::qt_metacast(_clname);
}

int guBookUploader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: ebookUploadProcess((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: uploadEbookFinished((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: uploadEbookError((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: allEbooksUploaded(); break;
        case 4: uplEbookFromQueue(); break;
        case 5: processUploadEbookReply((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 6: onUploadProgress((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void guBookUploader::ebookUploadProcess(QString _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void guBookUploader::uploadEbookFinished(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void guBookUploader::uploadEbookError(QString _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void guBookUploader::allEbooksUploaded()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
