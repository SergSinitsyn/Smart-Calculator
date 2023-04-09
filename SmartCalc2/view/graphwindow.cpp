#include "graphwindow.h"

#include <QMessageBox>
#include <QVector>
#include <vector>

#include "../controller/controller.h"
#include "ui_graphwindow.h"

GraphWindow::GraphWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::GraphWindow) {
  ui->setupUi(this);
  SetupBox();
  SetupWidget();
  connect(ui->widget->xAxis, SIGNAL(rangeChanged(QCPRange)), this,
          SLOT(xAxisChanged(QCPRange)));
  connect(ui->widget->yAxis, SIGNAL(rangeChanged(QCPRange)), this,
          SLOT(yAxisChanged(QCPRange)));

  connect(ui->listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this,
          SLOT(DeleteGraph(QListWidgetItem *)));
}

GraphWindow::~GraphWindow() { delete ui; }

void GraphWindow::SetController(Controller *g) { controller_graph_ = g; }

std::string GraphWindow::GetInputString() {
  return ui->lineEdit_In->text().toStdString();
}

double GraphWindow::GetMinX() { return ui->doubleSpinBox_xMin->value(); }

double GraphWindow::GetMaxX() { return ui->doubleSpinBox_xMax->value(); }

int GraphWindow::GetResolution() {
  switch (ui->comboBox_resolution->currentIndex()) {
    case 0:
      return 512;
    case 1:
      return 2048;
    case 2:
      return 8192;
  }
  return 2048;
}

void GraphWindow::SetGraph(XYGraph graph) {
  ui->widget->addGraph();
  ui->widget->graph(count_)->setName(ui->lineEdit_In->text());
  ui->widget->graph(count_)->setLineStyle(QCPGraph::lsLine);
  ui->widget->graph(count_)->setPen(QPen(QColor(colours_[count_]), 1.5));
  ui->widget->graph(count_)->setData(graph.first, graph.second);
  ui->widget->legend->setVisible(1);
  ui->widget->axisRect()->insetLayout()->setInsetAlignment(
      0, Qt::AlignTop | Qt::AlignRight);
  ui->widget->replot();
  ui->listWidget->addItem(ui->lineEdit_In->text());
  ++count_;
}

void GraphWindow::TakeExpressionFromCalc(QString expression) {
  ui->lineEdit_In->blockSignals(true);
  ui->lineEdit_In->setText(expression);
  ui->lineEdit_In->blockSignals(false);
}

void GraphWindow::on_pushButton_Print_clicked() {
  if (count_ == colours_.size()) {
    QMessageBox::critical(this, "Warning",
                          "The maximum number of graphs has been reached");
    return;
  }
  try {
    controller_graph_->CalculateGraph(this);
  } catch (const std::exception &e) {
    QMessageBox::critical(this, "Warning", e.what());
  }
}

// void GraphWindow::on_pushButton_Delete_clicked() {
//   count_ = 0;
//   ui->widget->clearGraphs();
//   ui->widget->clearPlottables();
//   ui->widget->clearItems();
//   ui->widget->legend->setVisible(0);
//   ui->widget->replot();
// }

void GraphWindow::SetupWidget() {
  ui->widget->xAxis->setLabel("X");
  ui->widget->yAxis->setLabel("Y");
  ui->widget->setInteraction(QCP::iRangeZoom, true);
  ui->widget->setInteraction(QCP::iRangeDrag, true);
}

void GraphWindow::on_lineEdit_In_textChanged(const QString &arg) {
  emit SendExpressionToCalc(arg);
}

void GraphWindow::on_pushButton_default_axis_clicked() { SetupBox(); }

void GraphWindow::SetupBox() {
  ui->doubleSpinBox_xMin->setValue(-10);
  ui->doubleSpinBox_xMax->setValue(10);
  ui->doubleSpinBox_yMin->setValue(-10);
  ui->doubleSpinBox_yMax->setValue(10);
  UpdateRange();
}

void GraphWindow::on_doubleSpinBox_xMin_valueChanged() { UpdateRange(); }

void GraphWindow::on_doubleSpinBox_xMax_valueChanged() { UpdateRange(); }

void GraphWindow::on_doubleSpinBox_yMin_valueChanged() { UpdateRange(); }

void GraphWindow::on_doubleSpinBox_yMax_valueChanged() { UpdateRange(); }

void GraphWindow::UpdateRange() {
  ui->widget->xAxis->blockSignals(true);
  ui->widget->yAxis->blockSignals(true);
  ui->widget->xAxis->setRange(ui->doubleSpinBox_xMin->value(),
                              ui->doubleSpinBox_xMax->value());
  ui->widget->yAxis->setRange(ui->doubleSpinBox_yMin->value(),
                              ui->doubleSpinBox_yMax->value());
  ui->widget->replot();
  ui->widget->xAxis->blockSignals(false);
  ui->widget->yAxis->blockSignals(false);
}

void GraphWindow::xAxisChanged(QCPRange range) {
  ui->doubleSpinBox_xMin->setValue(range.lower);
  ui->doubleSpinBox_xMax->setValue(range.upper);
}

void GraphWindow::yAxisChanged(QCPRange range) {
  ui->doubleSpinBox_yMin->setValue(range.lower);
  ui->doubleSpinBox_yMax->setValue(range.upper);
}

void GraphWindow::DeleteGraph(QListWidgetItem *item) {
  QMessageBox::StandardButton reply;
  reply = QMessageBox::question(this, "Test", "Delete this graph?",
                                QMessageBox::Yes | QMessageBox::No);
  if (reply == QMessageBox::Yes) {
    ui->widget->removeGraph(ui->listWidget->currentRow());
    ui->widget->replot();
    delete ui->listWidget->takeItem(ui->listWidget->row(item));
    --count_;
  }
}
