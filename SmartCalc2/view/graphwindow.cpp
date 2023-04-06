#include "graphwindow.h"

#include <QVector>
#include <vector>

#include "../controller/controller.h"
#include "qcustomplot.h"
#include "ui_graphwindow.h"

GraphWindow::GraphWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::GraphWindow) {
  ui->setupUi(this);
  SetupBox();
  SetupWidget();
}

GraphWindow::~GraphWindow() { delete ui; }

void GraphWindow::SetController(Controller *g) { controller_graph_ = g; }

std::string GraphWindow::GetInputString() {
  return ui->lineEdit_In->text().toStdString();
}

double GraphWindow::GetMinX() { return ui->doubleSpinBox_xMin->value(); }

double GraphWindow::GetMaxX() { return ui->doubleSpinBox_xMax->value(); }

void GraphWindow::SetGraph(std::pair<QVector<double>, QVector<double>> graph) {
  if (count_ == colours_.size()) return;
  // create graph and assign data to it:
  ui->widget->addGraph();
  ui->widget->graph(count_)->setName(ui->lineEdit_In->text());

  ui->widget->graph(count_)->setLineStyle(QCPGraph::lsLine);
  ui->widget->graph(count_)->setPen(QPen(QColor(colours_[count_]), 1.5));

  //  ui->widget->graph(count_)->setScatterStyle(
  //      QCPScatterStyle(QCPScatterStyle::ssDot, Qt::red, Qt::white, 0.1));
  ui->widget->graph(count_)->setData(graph.first, graph.second);

  ui->widget->legend->setVisible(count_ + 1);
  ui->widget->axisRect()->insetLayout()->setInsetAlignment(
      0, Qt::AlignTop | Qt::AlignRight);

  ui->widget->replot();
  ++count_;
}

void GraphWindow::TakeExpressionFromCalc(QString expression) {
  ui->lineEdit_In->setText(expression);
}

void GraphWindow::on_pushButton_Print_clicked() {
  try {
    controller_graph_->CalculateGraph(this);
  } catch (const std::exception &e) {
    QMessageBox::critical(this, "Warning", e.what());
  }
}

void GraphWindow::on_pushButton_Crear_clicked() {
  count_ = 0;
  ui->widget->clearPlottables();
  ui->widget->clearItems();
  ui->widget->replot();
}

void GraphWindow::UpdateRange() {
  // set axes ranges, so we see all data:
  ui->widget->xAxis->setRange(ui->doubleSpinBox_xMin->value(),
                              ui->doubleSpinBox_xMax->value());
  ui->widget->yAxis->setRange(ui->doubleSpinBox_yMin->value(),
                              ui->doubleSpinBox_yMax->value());
  ui->widget->replot();
}

void GraphWindow::on_doubleSpinBox_xMin_valueChanged() { UpdateRange(); }

void GraphWindow::on_doubleSpinBox_xMax_valueChanged() { UpdateRange(); }

void GraphWindow::on_doubleSpinBox_yMin_valueChanged() { UpdateRange(); }

void GraphWindow::on_doubleSpinBox_yMax_valueChanged() { UpdateRange(); }

void GraphWindow::SetupWidget() {
  // give the axes some labels:
  ui->widget->xAxis->setLabel("X");
  ui->widget->yAxis->setLabel("Y");

  UpdateRange();
  //  ui->widget_plot->setBackground(Qt::GlobalColor::transparent);
  //  ui->widget_plot->setBackground(QColor(200, 200, 200, 0));  // !
}

void GraphWindow::SetupBox() {
  ui->doubleSpinBox_xMin->setValue(0);
  ui->doubleSpinBox_xMax->setValue(100);
  ui->doubleSpinBox_yMin->setValue(0);
  ui->doubleSpinBox_yMax->setValue(100);
}

void GraphWindow::on_lineEdit_In_textChanged(const QString &arg1) {
  emit SendExpressionToCalc(arg1);
}
