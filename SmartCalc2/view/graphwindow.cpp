#include "graphwindow.h"

#include "ui_graphwindow.h"

GraphWindow::GraphWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::GraphWindow) {
  ui->setupUi(this);
}

GraphWindow::~GraphWindow() { delete ui; }

void GraphWindow::on_pushButton_Print_clicked() {
  /*
  int count_=0;
      ui->widget->clearPlottables();
  //    ui->widget->clearItems();

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
      ui->widget->graph(count_)->setPen(QColor(Qt::black));
      ui->widget->graph(count_)->setLineStyle(QCPGraph::lsLine);
      ui->widget->graph(count_)->setScatterStyle(
                  QCPScatterStyle(QCPScatterStyle::ssDot, Qt::red, Qt::white,
  0.1)); ui->widget->graph(count_)->setData(x, y);


      // give the axes some labels:
      ui->widget->xAxis->setLabel("X");
      ui->widget->yAxis->setLabel("Y");
      // set axes ranges, so we see all data:
      ui->widget->xAxis->setRange(xMin, xMax);
      ui->widget->yAxis->setRange(yMin, yMax);
      //        ui->widget_plot->setBackground(Qt::GlobalColor::transparent);
      //        ui->widget_plot->setBackground(QColor(200, 200, 200,0)); // !
      ui->widget->replot();
  //    ui->widget->removeGraph(0);
  //    x.clear();
  //    y.clear();


      //        int count = ui->widget_plot-> graphCount();
      //        QString q_count = QString::number(count);
      //        ui->statusbar_error->showMessage(q_count);
      //        ui->widget_plot->clearItems();*/
}
