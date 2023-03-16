/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionEngineer_Calculator;
    QAction *actionCredit_Calculator;
    QAction *actionDeposit_Calculator;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QToolButton *toolButton_div;
    QToolButton *toolButton_backspace;
    QToolButton *toolButton_E;
    QToolButton *toolButton_number_6;
    QToolButton *toolButton_mod;
    QLineEdit *lineEdit_iuput;
    QToolButton *toolButton_deleteAll;
    QToolButton *toolButton_pi;
    QToolButton *toolButton_number_9;
    QToolButton *toolButton_asin;
    QToolButton *toolButton_sin;
    QToolButton *toolButton_number_5;
    QToolButton *toolButton_number_2;
    QToolButton *toolButton_add;
    QToolButton *toolButton_cos;
    QToolButton *toolButton_log;
    QToolButton *toolButton_acos;
    QToolButton *toolButton_closeBracket;
    QToolButton *toolButton_power;
    QToolButton *toolButton_openBracket;
    QToolButton *toolButton_mult;
    QToolButton *toolButton_qbrt;
    QLineEdit *lineEdit_input_x;
    QToolButton *toolButton_number_4;
    QToolButton *toolButton_equal;
    QToolButton *toolButton_number_8;
    QToolButton *toolButton_ln;
    QLineEdit *lineEdit_output;
    QToolButton *toolButton_point;
    QToolButton *toolButton_x;
    QToolButton *toolButton_atan;
    QToolButton *toolButton_number_3;
    QToolButton *toolButton_tan;
    QToolButton *toolButton_sub;
    QToolButton *toolButton_exp;
    QToolButton *toolButton_number_0;
    QToolButton *toolButton_number_1;
    QToolButton *toolButton_sqrt;
    QToolButton *toolButton_number_7;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(672, 642);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(672, 642));
        MainWindow->setMaximumSize(QSize(672, 642));
        QFont font;
        font.setPointSize(24);
        MainWindow->setFont(font);
        actionEngineer_Calculator = new QAction(MainWindow);
        actionEngineer_Calculator->setObjectName(QString::fromUtf8("actionEngineer_Calculator"));
        actionCredit_Calculator = new QAction(MainWindow);
        actionCredit_Calculator->setObjectName(QString::fromUtf8("actionCredit_Calculator"));
        actionDeposit_Calculator = new QAction(MainWindow);
        actionDeposit_Calculator->setObjectName(QString::fromUtf8("actionDeposit_Calculator"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(672, 591));
        centralwidget->setMaximumSize(QSize(672, 16777215));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        toolButton_div = new QToolButton(centralwidget);
        toolButton_div->setObjectName(QString::fromUtf8("toolButton_div"));
        sizePolicy.setHeightForWidth(toolButton_div->sizePolicy().hasHeightForWidth());
        toolButton_div->setSizePolicy(sizePolicy);
        toolButton_div->setMinimumSize(QSize(40, 40));

        gridLayout->addWidget(toolButton_div, 3, 7, 1, 1);

        toolButton_backspace = new QToolButton(centralwidget);
        toolButton_backspace->setObjectName(QString::fromUtf8("toolButton_backspace"));
        sizePolicy.setHeightForWidth(toolButton_backspace->sizePolicy().hasHeightForWidth());
        toolButton_backspace->setSizePolicy(sizePolicy);
        toolButton_backspace->setMinimumSize(QSize(40, 40));

        gridLayout->addWidget(toolButton_backspace, 2, 5, 1, 1);

        toolButton_E = new QToolButton(centralwidget);
        toolButton_E->setObjectName(QString::fromUtf8("toolButton_E"));
        sizePolicy.setHeightForWidth(toolButton_E->sizePolicy().hasHeightForWidth());
        toolButton_E->setSizePolicy(sizePolicy);
        toolButton_E->setMinimumSize(QSize(40, 40));

        gridLayout->addWidget(toolButton_E, 6, 6, 1, 1);

        toolButton_number_6 = new QToolButton(centralwidget);
        toolButton_number_6->setObjectName(QString::fromUtf8("toolButton_number_6"));
        sizePolicy.setHeightForWidth(toolButton_number_6->sizePolicy().hasHeightForWidth());
        toolButton_number_6->setSizePolicy(sizePolicy);
        toolButton_number_6->setMinimumSize(QSize(40, 40));

        gridLayout->addWidget(toolButton_number_6, 4, 6, 1, 1);

        toolButton_mod = new QToolButton(centralwidget);
        toolButton_mod->setObjectName(QString::fromUtf8("toolButton_mod"));
        sizePolicy.setHeightForWidth(toolButton_mod->sizePolicy().hasHeightForWidth());
        toolButton_mod->setSizePolicy(sizePolicy);
        toolButton_mod->setMinimumSize(QSize(40, 40));

        gridLayout->addWidget(toolButton_mod, 3, 1, 1, 1);

        lineEdit_iuput = new QLineEdit(centralwidget);
        lineEdit_iuput->setObjectName(QString::fromUtf8("lineEdit_iuput"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_iuput->sizePolicy().hasHeightForWidth());
        lineEdit_iuput->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(lineEdit_iuput, 0, 0, 1, 8);

        toolButton_deleteAll = new QToolButton(centralwidget);
        toolButton_deleteAll->setObjectName(QString::fromUtf8("toolButton_deleteAll"));
        sizePolicy.setHeightForWidth(toolButton_deleteAll->sizePolicy().hasHeightForWidth());
        toolButton_deleteAll->setSizePolicy(sizePolicy);
        toolButton_deleteAll->setMinimumSize(QSize(40, 40));

        gridLayout->addWidget(toolButton_deleteAll, 2, 4, 1, 1);

        toolButton_pi = new QToolButton(centralwidget);
        toolButton_pi->setObjectName(QString::fromUtf8("toolButton_pi"));
        sizePolicy.setHeightForWidth(toolButton_pi->sizePolicy().hasHeightForWidth());
        toolButton_pi->setSizePolicy(sizePolicy);
        toolButton_pi->setMinimumSize(QSize(40, 40));

        gridLayout->addWidget(toolButton_pi, 3, 0, 1, 1);

        toolButton_number_9 = new QToolButton(centralwidget);
        toolButton_number_9->setObjectName(QString::fromUtf8("toolButton_number_9"));
        sizePolicy.setHeightForWidth(toolButton_number_9->sizePolicy().hasHeightForWidth());
        toolButton_number_9->setSizePolicy(sizePolicy);
        toolButton_number_9->setMinimumSize(QSize(40, 40));

        gridLayout->addWidget(toolButton_number_9, 3, 6, 1, 1);

        toolButton_asin = new QToolButton(centralwidget);
        toolButton_asin->setObjectName(QString::fromUtf8("toolButton_asin"));
        sizePolicy.setHeightForWidth(toolButton_asin->sizePolicy().hasHeightForWidth());
        toolButton_asin->setSizePolicy(sizePolicy);
        toolButton_asin->setMinimumSize(QSize(40, 40));

        gridLayout->addWidget(toolButton_asin, 4, 1, 1, 1);

        toolButton_sin = new QToolButton(centralwidget);
        toolButton_sin->setObjectName(QString::fromUtf8("toolButton_sin"));
        sizePolicy.setHeightForWidth(toolButton_sin->sizePolicy().hasHeightForWidth());
        toolButton_sin->setSizePolicy(sizePolicy);
        toolButton_sin->setMinimumSize(QSize(40, 40));

        gridLayout->addWidget(toolButton_sin, 4, 0, 1, 1);

        toolButton_number_5 = new QToolButton(centralwidget);
        toolButton_number_5->setObjectName(QString::fromUtf8("toolButton_number_5"));
        sizePolicy.setHeightForWidth(toolButton_number_5->sizePolicy().hasHeightForWidth());
        toolButton_number_5->setSizePolicy(sizePolicy);
        toolButton_number_5->setMinimumSize(QSize(40, 40));

        gridLayout->addWidget(toolButton_number_5, 4, 5, 1, 1);

        toolButton_number_2 = new QToolButton(centralwidget);
        toolButton_number_2->setObjectName(QString::fromUtf8("toolButton_number_2"));
        sizePolicy.setHeightForWidth(toolButton_number_2->sizePolicy().hasHeightForWidth());
        toolButton_number_2->setSizePolicy(sizePolicy);
        toolButton_number_2->setMinimumSize(QSize(40, 40));

        gridLayout->addWidget(toolButton_number_2, 5, 5, 1, 1);

        toolButton_add = new QToolButton(centralwidget);
        toolButton_add->setObjectName(QString::fromUtf8("toolButton_add"));
        sizePolicy.setHeightForWidth(toolButton_add->sizePolicy().hasHeightForWidth());
        toolButton_add->setSizePolicy(sizePolicy);
        toolButton_add->setMinimumSize(QSize(40, 40));

        gridLayout->addWidget(toolButton_add, 6, 7, 1, 1);

        toolButton_cos = new QToolButton(centralwidget);
        toolButton_cos->setObjectName(QString::fromUtf8("toolButton_cos"));
        sizePolicy.setHeightForWidth(toolButton_cos->sizePolicy().hasHeightForWidth());
        toolButton_cos->setSizePolicy(sizePolicy);
        toolButton_cos->setMinimumSize(QSize(40, 40));

        gridLayout->addWidget(toolButton_cos, 5, 0, 1, 1);

        toolButton_log = new QToolButton(centralwidget);
        toolButton_log->setObjectName(QString::fromUtf8("toolButton_log"));
        sizePolicy.setHeightForWidth(toolButton_log->sizePolicy().hasHeightForWidth());
        toolButton_log->setSizePolicy(sizePolicy);
        toolButton_log->setMinimumSize(QSize(40, 40));

        gridLayout->addWidget(toolButton_log, 6, 2, 1, 1);

        toolButton_acos = new QToolButton(centralwidget);
        toolButton_acos->setObjectName(QString::fromUtf8("toolButton_acos"));
        sizePolicy.setHeightForWidth(toolButton_acos->sizePolicy().hasHeightForWidth());
        toolButton_acos->setSizePolicy(sizePolicy);
        toolButton_acos->setMinimumSize(QSize(40, 40));

        gridLayout->addWidget(toolButton_acos, 5, 1, 1, 1);

        toolButton_closeBracket = new QToolButton(centralwidget);
        toolButton_closeBracket->setObjectName(QString::fromUtf8("toolButton_closeBracket"));
        sizePolicy.setHeightForWidth(toolButton_closeBracket->sizePolicy().hasHeightForWidth());
        toolButton_closeBracket->setSizePolicy(sizePolicy);
        toolButton_closeBracket->setMinimumSize(QSize(40, 40));

        gridLayout->addWidget(toolButton_closeBracket, 3, 3, 1, 1);

        toolButton_power = new QToolButton(centralwidget);
        toolButton_power->setObjectName(QString::fromUtf8("toolButton_power"));
        sizePolicy.setHeightForWidth(toolButton_power->sizePolicy().hasHeightForWidth());
        toolButton_power->setSizePolicy(sizePolicy);
        toolButton_power->setMinimumSize(QSize(40, 40));

        gridLayout->addWidget(toolButton_power, 4, 3, 1, 1);

        toolButton_openBracket = new QToolButton(centralwidget);
        toolButton_openBracket->setObjectName(QString::fromUtf8("toolButton_openBracket"));
        sizePolicy.setHeightForWidth(toolButton_openBracket->sizePolicy().hasHeightForWidth());
        toolButton_openBracket->setSizePolicy(sizePolicy);
        toolButton_openBracket->setMinimumSize(QSize(40, 40));

        gridLayout->addWidget(toolButton_openBracket, 3, 2, 1, 1);

        toolButton_mult = new QToolButton(centralwidget);
        toolButton_mult->setObjectName(QString::fromUtf8("toolButton_mult"));
        sizePolicy.setHeightForWidth(toolButton_mult->sizePolicy().hasHeightForWidth());
        toolButton_mult->setSizePolicy(sizePolicy);
        toolButton_mult->setMinimumSize(QSize(40, 40));

        gridLayout->addWidget(toolButton_mult, 4, 7, 1, 1);

        toolButton_qbrt = new QToolButton(centralwidget);
        toolButton_qbrt->setObjectName(QString::fromUtf8("toolButton_qbrt"));
        sizePolicy.setHeightForWidth(toolButton_qbrt->sizePolicy().hasHeightForWidth());
        toolButton_qbrt->setSizePolicy(sizePolicy);
        toolButton_qbrt->setMinimumSize(QSize(40, 40));

        gridLayout->addWidget(toolButton_qbrt, 6, 3, 1, 1);

        lineEdit_input_x = new QLineEdit(centralwidget);
        lineEdit_input_x->setObjectName(QString::fromUtf8("lineEdit_input_x"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit_input_x->sizePolicy().hasHeightForWidth());
        lineEdit_input_x->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(lineEdit_input_x, 2, 1, 1, 3);

        toolButton_number_4 = new QToolButton(centralwidget);
        toolButton_number_4->setObjectName(QString::fromUtf8("toolButton_number_4"));
        sizePolicy.setHeightForWidth(toolButton_number_4->sizePolicy().hasHeightForWidth());
        toolButton_number_4->setSizePolicy(sizePolicy);
        toolButton_number_4->setMinimumSize(QSize(40, 40));

        gridLayout->addWidget(toolButton_number_4, 4, 4, 1, 1);

        toolButton_equal = new QToolButton(centralwidget);
        toolButton_equal->setObjectName(QString::fromUtf8("toolButton_equal"));
        sizePolicy.setHeightForWidth(toolButton_equal->sizePolicy().hasHeightForWidth());
        toolButton_equal->setSizePolicy(sizePolicy);
        toolButton_equal->setMinimumSize(QSize(40, 40));

        gridLayout->addWidget(toolButton_equal, 2, 6, 1, 2);

        toolButton_number_8 = new QToolButton(centralwidget);
        toolButton_number_8->setObjectName(QString::fromUtf8("toolButton_number_8"));
        sizePolicy.setHeightForWidth(toolButton_number_8->sizePolicy().hasHeightForWidth());
        toolButton_number_8->setSizePolicy(sizePolicy);
        toolButton_number_8->setMinimumSize(QSize(40, 40));

        gridLayout->addWidget(toolButton_number_8, 3, 5, 1, 1);

        toolButton_ln = new QToolButton(centralwidget);
        toolButton_ln->setObjectName(QString::fromUtf8("toolButton_ln"));
        sizePolicy.setHeightForWidth(toolButton_ln->sizePolicy().hasHeightForWidth());
        toolButton_ln->setSizePolicy(sizePolicy);
        toolButton_ln->setMinimumSize(QSize(40, 40));

        gridLayout->addWidget(toolButton_ln, 5, 2, 1, 1);

        lineEdit_output = new QLineEdit(centralwidget);
        lineEdit_output->setObjectName(QString::fromUtf8("lineEdit_output"));
        sizePolicy.setHeightForWidth(lineEdit_output->sizePolicy().hasHeightForWidth());
        lineEdit_output->setSizePolicy(sizePolicy);
        lineEdit_output->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_output->setReadOnly(true);

        gridLayout->addWidget(lineEdit_output, 1, 0, 1, 8);

        toolButton_point = new QToolButton(centralwidget);
        toolButton_point->setObjectName(QString::fromUtf8("toolButton_point"));
        sizePolicy.setHeightForWidth(toolButton_point->sizePolicy().hasHeightForWidth());
        toolButton_point->setSizePolicy(sizePolicy);
        toolButton_point->setMinimumSize(QSize(40, 40));

        gridLayout->addWidget(toolButton_point, 6, 5, 1, 1);

        toolButton_x = new QToolButton(centralwidget);
        toolButton_x->setObjectName(QString::fromUtf8("toolButton_x"));
        sizePolicy.setHeightForWidth(toolButton_x->sizePolicy().hasHeightForWidth());
        toolButton_x->setSizePolicy(sizePolicy);
        toolButton_x->setMinimumSize(QSize(40, 40));

        gridLayout->addWidget(toolButton_x, 2, 0, 1, 1);

        toolButton_atan = new QToolButton(centralwidget);
        toolButton_atan->setObjectName(QString::fromUtf8("toolButton_atan"));
        sizePolicy.setHeightForWidth(toolButton_atan->sizePolicy().hasHeightForWidth());
        toolButton_atan->setSizePolicy(sizePolicy);
        toolButton_atan->setMinimumSize(QSize(40, 40));

        gridLayout->addWidget(toolButton_atan, 6, 1, 1, 1);

        toolButton_number_3 = new QToolButton(centralwidget);
        toolButton_number_3->setObjectName(QString::fromUtf8("toolButton_number_3"));
        sizePolicy.setHeightForWidth(toolButton_number_3->sizePolicy().hasHeightForWidth());
        toolButton_number_3->setSizePolicy(sizePolicy);
        toolButton_number_3->setMinimumSize(QSize(40, 40));

        gridLayout->addWidget(toolButton_number_3, 5, 6, 1, 1);

        toolButton_tan = new QToolButton(centralwidget);
        toolButton_tan->setObjectName(QString::fromUtf8("toolButton_tan"));
        sizePolicy.setHeightForWidth(toolButton_tan->sizePolicy().hasHeightForWidth());
        toolButton_tan->setSizePolicy(sizePolicy);
        toolButton_tan->setMinimumSize(QSize(40, 40));

        gridLayout->addWidget(toolButton_tan, 6, 0, 1, 1);

        toolButton_sub = new QToolButton(centralwidget);
        toolButton_sub->setObjectName(QString::fromUtf8("toolButton_sub"));
        sizePolicy.setHeightForWidth(toolButton_sub->sizePolicy().hasHeightForWidth());
        toolButton_sub->setSizePolicy(sizePolicy);
        toolButton_sub->setMinimumSize(QSize(40, 40));

        gridLayout->addWidget(toolButton_sub, 5, 7, 1, 1);

        toolButton_exp = new QToolButton(centralwidget);
        toolButton_exp->setObjectName(QString::fromUtf8("toolButton_exp"));
        sizePolicy.setHeightForWidth(toolButton_exp->sizePolicy().hasHeightForWidth());
        toolButton_exp->setSizePolicy(sizePolicy);
        toolButton_exp->setMinimumSize(QSize(40, 40));

        gridLayout->addWidget(toolButton_exp, 4, 2, 1, 1);

        toolButton_number_0 = new QToolButton(centralwidget);
        toolButton_number_0->setObjectName(QString::fromUtf8("toolButton_number_0"));
        sizePolicy.setHeightForWidth(toolButton_number_0->sizePolicy().hasHeightForWidth());
        toolButton_number_0->setSizePolicy(sizePolicy);
        toolButton_number_0->setMinimumSize(QSize(40, 40));

        gridLayout->addWidget(toolButton_number_0, 6, 4, 1, 1);

        toolButton_number_1 = new QToolButton(centralwidget);
        toolButton_number_1->setObjectName(QString::fromUtf8("toolButton_number_1"));
        sizePolicy.setHeightForWidth(toolButton_number_1->sizePolicy().hasHeightForWidth());
        toolButton_number_1->setSizePolicy(sizePolicy);
        toolButton_number_1->setMinimumSize(QSize(40, 40));

        gridLayout->addWidget(toolButton_number_1, 5, 4, 1, 1);

        toolButton_sqrt = new QToolButton(centralwidget);
        toolButton_sqrt->setObjectName(QString::fromUtf8("toolButton_sqrt"));
        sizePolicy.setHeightForWidth(toolButton_sqrt->sizePolicy().hasHeightForWidth());
        toolButton_sqrt->setSizePolicy(sizePolicy);
        toolButton_sqrt->setMinimumSize(QSize(40, 40));

        gridLayout->addWidget(toolButton_sqrt, 5, 3, 1, 1);

        toolButton_number_7 = new QToolButton(centralwidget);
        toolButton_number_7->setObjectName(QString::fromUtf8("toolButton_number_7"));
        sizePolicy.setHeightForWidth(toolButton_number_7->sizePolicy().hasHeightForWidth());
        toolButton_number_7->setSizePolicy(sizePolicy);
        toolButton_number_7->setMinimumSize(QSize(40, 40));

        gridLayout->addWidget(toolButton_number_7, 3, 4, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 672, 24));
        QFont font1;
        font1.setPointSize(13);
        menubar->setFont(font1);
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        QFont font2;
        font2.setPointSize(16);
        statusbar->setFont(font2);
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionEngineer_Calculator);
        menu->addSeparator();
        menu->addAction(actionCredit_Calculator);
        menu->addAction(actionDeposit_Calculator);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Engineer Calculator", nullptr));
        actionEngineer_Calculator->setText(QCoreApplication::translate("MainWindow", "Engineer Calculator", nullptr));
        actionCredit_Calculator->setText(QCoreApplication::translate("MainWindow", "Credit Calculator", nullptr));
        actionDeposit_Calculator->setText(QCoreApplication::translate("MainWindow", "Deposit Calculator", nullptr));
        toolButton_div->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        toolButton_backspace->setText(QCoreApplication::translate("MainWindow", "\342\214\253", nullptr));
#if QT_CONFIG(whatsthis)
        toolButton_E->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        toolButton_E->setText(QCoreApplication::translate("MainWindow", "E", nullptr));
        toolButton_number_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        toolButton_mod->setText(QCoreApplication::translate("MainWindow", "mod", nullptr));
        toolButton_deleteAll->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        toolButton_pi->setText(QCoreApplication::translate("MainWindow", "pi", nullptr));
        toolButton_number_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        toolButton_asin->setText(QCoreApplication::translate("MainWindow", "asin", nullptr));
        toolButton_sin->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        toolButton_number_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        toolButton_number_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        toolButton_add->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        toolButton_cos->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        toolButton_log->setText(QCoreApplication::translate("MainWindow", "log", nullptr));
        toolButton_acos->setText(QCoreApplication::translate("MainWindow", "acos", nullptr));
        toolButton_closeBracket->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        toolButton_power->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        toolButton_openBracket->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        toolButton_mult->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        toolButton_qbrt->setText(QCoreApplication::translate("MainWindow", "qbrt", nullptr));
        toolButton_number_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        toolButton_equal->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        toolButton_number_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        toolButton_ln->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        toolButton_point->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        toolButton_x->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        toolButton_atan->setText(QCoreApplication::translate("MainWindow", "atan", nullptr));
        toolButton_number_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        toolButton_tan->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
        toolButton_sub->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        toolButton_exp->setText(QCoreApplication::translate("MainWindow", "exp", nullptr));
        toolButton_number_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        toolButton_number_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        toolButton_sqrt->setText(QCoreApplication::translate("MainWindow", "sqrt", nullptr));
        toolButton_number_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "Mode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
