/****************************************************************************
** Meta object code from reading C++ file 'udp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../udp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'udp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UDP_t {
    QByteArrayData data[17];
    char stringdata0[196];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UDP_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UDP_t qt_meta_stringdata_UDP = {
    {
QT_MOC_LITERAL(0, 0, 3), // "UDP"
QT_MOC_LITERAL(1, 4, 10), // "buttonLock"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 13), // "unlockButtons"
QT_MOC_LITERAL(4, 30, 15), // "choiceOfWhoTurn"
QT_MOC_LITERAL(5, 46, 17), // "changeCurrentMove"
QT_MOC_LITERAL(6, 64, 11), // "buttonClear"
QT_MOC_LITERAL(7, 76, 10), // "playerTurn"
QT_MOC_LITERAL(8, 87, 12), // "selectedCell"
QT_MOC_LITERAL(9, 100, 11), // "readingData"
QT_MOC_LITERAL(10, 112, 15), // "transmitMessage"
QT_MOC_LITERAL(11, 128, 6), // "comand"
QT_MOC_LITERAL(12, 135, 14), // "sendLanSetting"
QT_MOC_LITERAL(13, 150, 8), // "senderIp"
QT_MOC_LITERAL(14, 159, 10), // "senderPort"
QT_MOC_LITERAL(15, 170, 11), // "recipientIp"
QT_MOC_LITERAL(16, 182, 13) // "recipientPort"

    },
    "UDP\0buttonLock\0\0unlockButtons\0"
    "choiceOfWhoTurn\0changeCurrentMove\0"
    "buttonClear\0playerTurn\0selectedCell\0"
    "readingData\0transmitMessage\0comand\0"
    "sendLanSetting\0senderIp\0senderPort\0"
    "recipientIp\0recipientPort"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UDP[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,
       6,    0,   55,    2, 0x06 /* Public */,
       7,    1,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   59,    2, 0x0a /* Public */,
      10,    1,   60,    2, 0x0a /* Public */,
      12,    4,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Char,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   13,   14,   15,   16,

       0        // eod
};

void UDP::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UDP *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->buttonLock((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->choiceOfWhoTurn((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->buttonClear(); break;
        case 3: _t->playerTurn((*reinterpret_cast< char(*)>(_a[1]))); break;
        case 4: _t->readingData(); break;
        case 5: _t->transmitMessage((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 6: _t->sendLanSetting((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UDP::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UDP::buttonLock)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (UDP::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UDP::choiceOfWhoTurn)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (UDP::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UDP::buttonClear)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (UDP::*)(char );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UDP::playerTurn)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject UDP::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_UDP.data,
    qt_meta_data_UDP,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UDP::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UDP::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UDP.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int UDP::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void UDP::buttonLock(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UDP::choiceOfWhoTurn(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void UDP::buttonClear()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void UDP::playerTurn(char _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
