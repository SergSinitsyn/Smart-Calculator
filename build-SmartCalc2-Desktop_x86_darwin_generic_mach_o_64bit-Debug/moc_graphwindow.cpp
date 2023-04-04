/****************************************************************************
** Meta object code from reading C++ file 'graphwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../SmartCalc2/view/graphwindow.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GraphWindow_t {
    const uint offsetsAndSize[20];
    char stringdata0[230];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_GraphWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_GraphWindow_t qt_meta_stringdata_GraphWindow = {
    {
QT_MOC_LITERAL(0, 11), // "GraphWindow"
QT_MOC_LITERAL(12, 27), // "on_pushButton_Print_clicked"
QT_MOC_LITERAL(40, 0), // ""
QT_MOC_LITERAL(41, 27), // "on_pushButton_Crear_clicked"
QT_MOC_LITERAL(69, 34), // "on_doubleSpinBox_xMin_valueCh..."
QT_MOC_LITERAL(104, 34), // "on_doubleSpinBox_xMax_valueCh..."
QT_MOC_LITERAL(139, 34), // "on_doubleSpinBox_yMin_valueCh..."
QT_MOC_LITERAL(174, 34), // "on_doubleSpinBox_yMax_valueCh..."
QT_MOC_LITERAL(209, 11), // "SetupWidget"
QT_MOC_LITERAL(221, 8) // "SetupBox"

    },
    "GraphWindow\0on_pushButton_Print_clicked\0"
    "\0on_pushButton_Crear_clicked\0"
    "on_doubleSpinBox_xMin_valueChanged\0"
    "on_doubleSpinBox_xMax_valueChanged\0"
    "on_doubleSpinBox_yMin_valueChanged\0"
    "on_doubleSpinBox_yMax_valueChanged\0"
    "SetupWidget\0SetupBox"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GraphWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x08,    1 /* Private */,
       3,    0,   63,    2, 0x08,    2 /* Private */,
       4,    0,   64,    2, 0x08,    3 /* Private */,
       5,    0,   65,    2, 0x08,    4 /* Private */,
       6,    0,   66,    2, 0x08,    5 /* Private */,
       7,    0,   67,    2, 0x08,    6 /* Private */,
       8,    0,   68,    2, 0x08,    7 /* Private */,
       9,    0,   69,    2, 0x08,    8 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GraphWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GraphWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButton_Print_clicked(); break;
        case 1: _t->on_pushButton_Crear_clicked(); break;
        case 2: _t->on_doubleSpinBox_xMin_valueChanged(); break;
        case 3: _t->on_doubleSpinBox_xMax_valueChanged(); break;
        case 4: _t->on_doubleSpinBox_yMin_valueChanged(); break;
        case 5: _t->on_doubleSpinBox_yMax_valueChanged(); break;
        case 6: _t->SetupWidget(); break;
        case 7: _t->SetupBox(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject GraphWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_GraphWindow.offsetsAndSize,
    qt_meta_data_GraphWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_GraphWindow_t
, QtPrivate::TypeAndForceComplete<GraphWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *GraphWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GraphWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GraphWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GraphWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
