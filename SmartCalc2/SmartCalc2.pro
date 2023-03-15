QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    model/calculator.cc \
    model/check.cc \
    model/credit.cc \
    model/date.cc \
    model/deposit.cc \
    model/model.cc \
    model/token.cc \
     view/mainwindow.cpp

HEADERS += \
     model/calculator.h \
     model/check.h \
     model/credit.h \
     model/date.h \
     model/deposit.h \
     model/model.h \
     model/token.h \
     view/mainwindow.h

FORMS += \
   view/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target