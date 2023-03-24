#include "graphwindow.h"

#include "qcustomplot.h"
#include "ui_graphwindow.h"

GraphWindow::GraphWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::GraphWindow) {
  ui->setupUi(this);
}

GraphWindow::~GraphWindow() { delete ui; }

void GraphWindow::SetExpression(QString expression) {
  ui->lineEdit_In->setText(expression);
}

void GraphWindow::on_pushButton_Print_clicked() {
  //  ui->widget->clearItems();
  if (count_ == colours_.size()) return;

  long double xMin = ui->doubleSpinBox_xMin->value();
  long double xMax = ui->doubleSpinBox_xMax->value();
  long double yMin = ui->doubleSpinBox_yMin->value();
  long double yMax = ui->doubleSpinBox_yMax->value();

  QVector<double> x(100), y(100);
  for (int i = 0; i < 100; i++) {
    x[i] = i;
    y[i] = rand() % 10;
  }

  // create graph and assign data to it:
  ui->widget->addGraph();

  ui->widget->graph(count_)->setPen(QColor(colours_[count_]));
  ui->widget->graph(count_)->setLineStyle(QCPGraph::lsLine);
  //  ui->widget->graph(count_)->setScatterStyle(
  //      QCPScatterStyle(QCPScatterStyle::ssDot, Qt::red, Qt::white, 0.1));
  ui->widget->graph(count_)->setData(x, y);

  // give the axes some labels:
  ui->widget->xAxis->setLabel("X");
  ui->widget->yAxis->setLabel("Y");
  // set axes ranges, so we see all data:
  ui->widget->xAxis->setRange(xMin, xMax);
  ui->widget->yAxis->setRange(yMin, yMax);
  //  ui->widget_plot->setBackground(Qt::GlobalColor::transparent);
  //  ui->widget_plot->setBackground(QColor(200, 200, 200, 0));  // !
  ui->widget->replot();

  //  //    ui->widget->removeGraph(0);

  //  //        int count = ui->widget_plot-> graphCount();

  ui->label->setText(QString::number(count_, 'g', 8));
  ++count_;
}

void GraphWindow::on_pushButton_Crear_clicked() {
  count_ = 0;
  ui->widget->clearPlottables();
  ui->widget->clearItems();
  ui->widget->replot();
}
