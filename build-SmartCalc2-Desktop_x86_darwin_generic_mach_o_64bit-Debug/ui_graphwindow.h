/********************************************************************************
** Form generated from reading UI file 'graphwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHWINDOW_H
#define UI_GRAPHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphWindow {
 public:
  QGridLayout *gridLayout;
  QCustomPlot *widget;
  QPushButton *pushButton_Print;
  QLabel *label_xMin;
  QDoubleSpinBox *doubleSpinBox_xMin;
  QLabel *label_xMax;
  QDoubleSpinBox *doubleSpinBox_xMax;
  QSpacerItem *horizontalSpacer;
  QPushButton *pushButton_Crear;
  QLabel *label_yMin;
  QDoubleSpinBox *doubleSpinBox_yMin;
  QLabel *label_yMax;
  QDoubleSpinBox *doubleSpinBox_yMax;
  QLineEdit *lineEdit_In;
  QLabel *label;

  void setupUi(QWidget *GraphWindow) {
    if (GraphWindow->objectName().isEmpty())
      GraphWindow->setObjectName(QString::fromUtf8("GraphWindow"));
    GraphWindow->resize(607, 496);
    gridLayout = new QGridLayout(GraphWindow);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    widget = new QCustomPlot(GraphWindow);
    widget->setObjectName(QString::fromUtf8("widget"));

    gridLayout->addWidget(widget, 0, 0, 1, 6);

    pushButton_Print = new QPushButton(GraphWindow);
    pushButton_Print->setObjectName(QString::fromUtf8("pushButton_Print"));

    gridLayout->addWidget(pushButton_Print, 2, 0, 1, 1);

    label_xMin = new QLabel(GraphWindow);
    label_xMin->setObjectName(QString::fromUtf8("label_xMin"));
    label_xMin->setLayoutDirection(Qt::RightToLeft);
    label_xMin->setAlignment(Qt::AlignRight | Qt::AlignTrailing |
                             Qt::AlignVCenter);

    gridLayout->addWidget(label_xMin, 2, 1, 1, 1);

    doubleSpinBox_xMin = new QDoubleSpinBox(GraphWindow);
    doubleSpinBox_xMin->setObjectName(QString::fromUtf8("doubleSpinBox_xMin"));
    doubleSpinBox_xMin->setMinimum(-1000000.000000000000000);
    doubleSpinBox_xMin->setMaximum(1000000.000000000000000);
    doubleSpinBox_xMin->setValue(0.000000000000000);

    gridLayout->addWidget(doubleSpinBox_xMin, 2, 2, 1, 1);

    label_xMax = new QLabel(GraphWindow);
    label_xMax->setObjectName(QString::fromUtf8("label_xMax"));
    label_xMax->setLayoutDirection(Qt::RightToLeft);
    label_xMax->setAlignment(Qt::AlignRight | Qt::AlignTrailing |
                             Qt::AlignVCenter);

    gridLayout->addWidget(label_xMax, 2, 3, 1, 1);

    doubleSpinBox_xMax = new QDoubleSpinBox(GraphWindow);
    doubleSpinBox_xMax->setObjectName(QString::fromUtf8("doubleSpinBox_xMax"));
    doubleSpinBox_xMax->setLayoutDirection(Qt::LeftToRight);
    doubleSpinBox_xMax->setMinimum(-1000000.000000000000000);
    doubleSpinBox_xMax->setMaximum(1000000.000000000000000);

    gridLayout->addWidget(doubleSpinBox_xMax, 2, 4, 1, 1);

    horizontalSpacer =
        new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout->addItem(horizontalSpacer, 2, 5, 1, 1);

    pushButton_Crear = new QPushButton(GraphWindow);
    pushButton_Crear->setObjectName(QString::fromUtf8("pushButton_Crear"));

    gridLayout->addWidget(pushButton_Crear, 3, 0, 1, 1);

    label_yMin = new QLabel(GraphWindow);
    label_yMin->setObjectName(QString::fromUtf8("label_yMin"));
    label_yMin->setLayoutDirection(Qt::RightToLeft);
    label_yMin->setAlignment(Qt::AlignRight | Qt::AlignTrailing |
                             Qt::AlignVCenter);

    gridLayout->addWidget(label_yMin, 3, 1, 1, 1);

    doubleSpinBox_yMin = new QDoubleSpinBox(GraphWindow);
    doubleSpinBox_yMin->setObjectName(QString::fromUtf8("doubleSpinBox_yMin"));
    doubleSpinBox_yMin->setMinimum(-1000000.000000000000000);
    doubleSpinBox_yMin->setMaximum(1000000.000000000000000);

    gridLayout->addWidget(doubleSpinBox_yMin, 3, 2, 1, 1);

    label_yMax = new QLabel(GraphWindow);
    label_yMax->setObjectName(QString::fromUtf8("label_yMax"));
    label_yMax->setLayoutDirection(Qt::RightToLeft);
    label_yMax->setAlignment(Qt::AlignRight | Qt::AlignTrailing |
                             Qt::AlignVCenter);

    gridLayout->addWidget(label_yMax, 3, 3, 1, 1);

    doubleSpinBox_yMax = new QDoubleSpinBox(GraphWindow);
    doubleSpinBox_yMax->setObjectName(QString::fromUtf8("doubleSpinBox_yMax"));
    doubleSpinBox_yMax->setMinimum(-1000000.000000000000000);
    doubleSpinBox_yMax->setMaximum(1000000.000000000000000);

    gridLayout->addWidget(doubleSpinBox_yMax, 3, 4, 1, 1);

    lineEdit_In = new QLineEdit(GraphWindow);
    lineEdit_In->setObjectName(QString::fromUtf8("lineEdit_In"));

    gridLayout->addWidget(lineEdit_In, 1, 0, 1, 5);

    label = new QLabel(GraphWindow);
    label->setObjectName(QString::fromUtf8("label"));

    gridLayout->addWidget(label, 1, 5, 1, 1);

    retranslateUi(GraphWindow);

    QMetaObject::connectSlotsByName(GraphWindow);
  }  // setupUi

  void retranslateUi(QWidget *GraphWindow) {
    GraphWindow->setWindowTitle(
        QCoreApplication::translate("GraphWindow", "Graph", nullptr));
    pushButton_Print->setText(
        QCoreApplication::translate("GraphWindow", "Print Graph", nullptr));
    label_xMin->setText(
        QCoreApplication::translate("GraphWindow", "x from", nullptr));
    label_xMax->setText(
        QCoreApplication::translate("GraphWindow", "x to", nullptr));
    pushButton_Crear->setText(
        QCoreApplication::translate("GraphWindow", "Crear All", nullptr));
    label_yMin->setText(
        QCoreApplication::translate("GraphWindow", "y from", nullptr));
    label_yMax->setText(
        QCoreApplication::translate("GraphWindow", "y to", nullptr));
    label->setText(
        QCoreApplication::translate("GraphWindow", "TextLabel", nullptr));
  }  // retranslateUi
};

namespace Ui {
class GraphWindow : public Ui_GraphWindow {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_GRAPHWINDOW_H
