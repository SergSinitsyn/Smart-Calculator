QT       += core gui widgets printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += ./view

SOURCES += \
    controller/controller.cc \
    main.cpp \
    model/check.cc \
    model/credit.cc \
    model/date.cc \
    model/deposit.cc \
    model/mathcalculator.cc \
    model/token.cc \
    view/cell.cpp \
    view/creditwindow.cpp \
    view/depositwindow.cpp \
    view/graphwindow.cpp \
    view/mainwindow.cpp \
    view/qcustomplot.cpp

HEADERS += \
     controller/controller.h \
     model/check.h \
     model/credit.h \
     model/date.h \
     model/deposit.h \
     model/mathcalculator.h \
     model/token.h \
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
