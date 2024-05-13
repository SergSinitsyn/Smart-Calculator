#include "graphwindow.h"

#include "../../controller/controller.h"
#include "ui_graphwindow.h"

namespace MyNamespace {
GraphWindow::GraphWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::GraphWindow) {
  ui->setupUi(this);
  SetupBox();
  SetupWidget();
  connect(ui->widget->xAxis, SIGNAL(rangeChanged(QCPRange)), this,
          SLOT(xAxisChanged(QCPRange)));
  connect(ui->widget->yAxis, SIGNAL(rangeChanged(QCPRange)), this,
          SLOT(yAxisChanged(QCPRange)));
}

GraphWindow::~GraphWindow() { delete ui; }

void GraphWindow::SetController(Controller *g) { controller_graph_ = g; }

std::string GraphWindow::GetInputString() {
  return ui->lineEdit_In->text().toStdString();
}

int GraphWindow::GetResolution() {
  switch (ui->comboBox_resolution->currentIndex()) {
  case 0:
    return 128;
  case 1:
    return 1024;
  case 2:
    return 8192;
  }
  return 1024;
}

double GraphWindow::GetMinX() { return ui->doubleSpinBox_xMin->value(); }

double GraphWindow::GetMaxX() { return ui->doubleSpinBox_xMax->value(); }

double GraphWindow::GetMinY() { return ui->doubleSpinBox_yMin->value(); }

double GraphWindow::GetMaxY() { return ui->doubleSpinBox_yMax->value(); }

void GraphWindow::SetGraph(XYGraph graph) {
  QVector<double> x(graph.first.begin(), graph.first.end());
  QVector<double> y(graph.second.begin(), graph.second.end());
  ui->widget->addGraph();
  ui->widget->graph(count_)->setName(ui->lineEdit_In->text());
  ui->widget->graph(count_)->setLineStyle(QCPGraph::lsLine);
  ui->widget->graph(count_)->setPen(QPen(QColor(colors_[SetColor()]), 1.5));
  ui->widget->graph(count_)->setData(x, y);
  ui->widget->legend->setVisible(1);
  ui->widget->axisRect()->insetLayout()->setInsetAlignment(
      0, Qt::AlignTop | Qt::AlignRight);
  ui->widget->replot();
  ui->listWidget->addItem(ui->lineEdit_In->text());
  ++count_;
}

int GraphWindow::SetColor() { return (arc4random() % colors_.size()); }

void GraphWindow::SetupWidget() {
  ui->widget->xAxis->setLabel("X");
  ui->widget->yAxis->setLabel("Y");
  ui->widget->setInteraction(QCP::iRangeZoom, true);
  ui->widget->setInteraction(QCP::iRangeDrag, true);
}

void GraphWindow::SetupBox() {
  ui->doubleSpinBox_xMin->setValue(-10);
  ui->doubleSpinBox_xMax->setValue(10);
  ui->doubleSpinBox_yMin->setValue(-10);
  ui->doubleSpinBox_yMax->setValue(10);
}

void GraphWindow::UpdateXAxisRange() {
  ui->widget->xAxis->blockSignals(true);
  ui->widget->xAxis->setRange(ui->doubleSpinBox_xMin->value(),
                              ui->doubleSpinBox_xMax->value());
  ui->widget->replot();
  ui->widget->xAxis->blockSignals(false);
}

void GraphWindow::UpdateYAxisRange() {
  ui->widget->yAxis->blockSignals(true);
  ui->widget->yAxis->setRange(ui->doubleSpinBox_yMin->value(),
                              ui->doubleSpinBox_yMax->value());
  ui->widget->replot();
  ui->widget->yAxis->blockSignals(false);
}

void GraphWindow::TakeExpressionFromCalc(QString expression) {
  ui->lineEdit_In->blockSignals(true);
  ui->lineEdit_In->setText(expression);
  ui->lineEdit_In->blockSignals(false);
}

void GraphWindow::on_lineEdit_In_textChanged(const QString &arg) {
  emit SendExpressionToCalc(arg);
}

void GraphWindow::on_pushButton_Print_clicked() {
  if (count_ == kMaxGraphs_) {
    QMessageBox::warning(this, "Warning",
                         "The maximum number of graphs has been reached");
    return;
  }
  try {
    controller_graph_->CalculateGraph(this);
  } catch (const std::exception &e) {
    QMessageBox::critical(this, "Warning", e.what());
  }
}

void GraphWindow::on_pushButton_Color_clicked() {
  int selected = ui->listWidget->currentRow();
  if (selected < 0)
    return;

  QColor ColorValue = QColorDialog::getColor(Qt::white, this, "Select color");
  ui->widget->graph(selected)->setPen(QPen(QColor(ColorValue), 1.5));
  ui->widget->replot();
}

void GraphWindow::on_pushButton_Delete_clicked() {
  int selected = ui->listWidget->currentRow();
  if (selected < 0)
    return;

  QMessageBox::StandardButton reply;
  reply = QMessageBox::question(this, "Test",
                                "Delete this graph?\n" +
                                    ui->listWidget->currentItem()->text(),
                                QMessageBox::Yes | QMessageBox::No);
  if (reply == QMessageBox::Yes) {
    ui->widget->removeGraph(selected);
    delete ui->listWidget->takeItem(selected);
    --count_;
    ui->widget->legend->setVisible(count_);
    ui->widget->replot();
  }
}

void GraphWindow::on_pushButton_default_axis_clicked() { SetupBox(); }

void GraphWindow::on_doubleSpinBox_xMin_valueChanged() { UpdateXAxisRange(); }

void GraphWindow::on_doubleSpinBox_xMax_valueChanged() { UpdateXAxisRange(); }

void GraphWindow::on_doubleSpinBox_yMin_valueChanged() { UpdateYAxisRange(); }

void GraphWindow::on_doubleSpinBox_yMax_valueChanged() { UpdateYAxisRange(); }

void GraphWindow::xAxisChanged(QCPRange range) {
  ui->doubleSpinBox_xMin->setValue(range.lower);
  ui->doubleSpinBox_xMax->setValue(range.upper);
}

void GraphWindow::yAxisChanged(QCPRange range) {
  ui->doubleSpinBox_yMin->setValue(range.lower);
  ui->doubleSpinBox_yMax->setValue(range.upper);
}
}; // namespace MyNamespace
