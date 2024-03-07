QT       += core gui widgets printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17 

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += ./view/math

SOURCES += \
    controller/controller.cc \
    main.cc \
    model/bank/creditcalculator.cc \
    model/bank/date.cc \
    model/bank/depositcalculator.cc \
    model/bank/round.cc \
    model/math/math_calculator.cc \
    model/math/parser.cc \
    model/math/postfix_calculator.cc \
    model/math/validator.cc \
    model/math/parameter_checker.cc \
    model/math/token.cc \
    view/bank/cell.cc \
    view/bank/creditwindow.cc \
    view/bank/depositwindow.cc \
    view/math/graphwindow.cc \
    view/math/mainwindow.cc \
    view/math/qcustomplot.cc

HEADERS += \
    controller/controller.h \
    model/bank/creditcalculator.h \
    model/bank/date.h \
    model/bank/depositcalculator.h \
    model/bank/round.h \
    model/math/math_calculator.h \
    model/math/parser.h \
    model/math/postfix_calculator.h \
    model/math/validator.h \
    model/math/parameter_checker.h \
    model/math/token.h \
    view/bank/cell.h \
    view/bank/creditwindow.h \
    view/bank/depositwindow.h \
    view/math/graphwindow.h \
    view/math/mainwindow.h \
    view/math/qcustomplot.h

FORMS += \
    view/bank/cell.ui \
    view/bank/creditwindow.ui \
    view/bank/depositwindow.ui \
    view/math/graphwindow.ui \
    view/math/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
