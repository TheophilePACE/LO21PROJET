/****************************************************************************
** Meta object code from reading C++ file 'qvareditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../LO21ProjetCode/qvareditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qvareditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QvarEditor_t {
    QByteArrayData data[7];
    char stringdata[75];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QvarEditor_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QvarEditor_t qt_meta_stringdata_QvarEditor = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 7),
QT_MOC_LITERAL(2, 19, 0),
QT_MOC_LITERAL(3, 20, 14),
QT_MOC_LITERAL(4, 35, 23),
QT_MOC_LITERAL(5, 59, 12),
QT_MOC_LITERAL(6, 72, 1)
    },
    "QvarEditor\0refresh\0\0getNextCommand\0"
    "validationButtonPressed\0QPushButton*\0"
    "g\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QvarEditor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a,
       3,    0,   30,    2, 0x0a,
       4,    1,   31,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,

       0        // eod
};

void QvarEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QvarEditor *_t = static_cast<QvarEditor *>(_o);
        switch (_id) {
        case 0: _t->refresh(); break;
        case 1: _t->getNextCommand(); break;
        case 2: _t->validationButtonPressed((*reinterpret_cast< QPushButton*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QPushButton* >(); break;
            }
            break;
        }
    }
}

const QMetaObject QvarEditor::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QvarEditor.data,
      qt_meta_data_QvarEditor,  qt_static_metacall, 0, 0}
};


const QMetaObject *QvarEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QvarEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QvarEditor.stringdata))
        return static_cast<void*>(const_cast< QvarEditor*>(this));
    return QWidget::qt_metacast(_clname);
}

int QvarEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
