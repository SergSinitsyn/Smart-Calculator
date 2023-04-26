QT       += core gui widgets printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += ./view

SOURCES += \
    controller/controller.cc \
    main.cc \
    model/math/check.cc \
    model/bank/creditcalculator.cc \
    model/bank/date.cc \
    model/bank/depositcalculator.cc \
    model/math/mathcalculator.cc \
    model/bank/round.cc \
    model/math/token.cc \
    view/cell.cc \
    view/creditwindow.cc \
    view/depositwindow.cc \
    view/graphwindow.cc \
    view/mainwindow.cc \
    view/qcustomplot.cc

HEADERS += \
    controller/controller.h \
    model/math/check.h \
    model/bank/creditcalculator.h \
    model/bank/date.h \
    model/bank/depositcalculator.h \
    model/math/mathcalculator.h \
    model/bank/round.h \
    model/math/token.h \
    view/cell.h \
    view/creditwindow.h \
    view/depositwindow.h \
    view/graphwindow.h \
    view/mainwindow.h \
    view/qcustomplot.h

FORMS += \
    view/cell.ui \
    view/creditwindow.ui \
    view/depositwindow.ui \
    view/graphwindow.ui \
    view/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
