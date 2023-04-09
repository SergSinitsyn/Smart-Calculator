#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QLineEdit>
#include <QVector>
#include <QWidget>

#include "qcustomplot.h"

namespace Ui {
class GraphWindow;
}

class Controller;

using XYGraph = std::pair<QVector<double>, QVector<double>>;

class GraphWindow : public QWidget {
  Q_OBJECT

 public:
  explicit GraphWindow(QWidget *parent = nullptr);
  ~GraphWindow();
  void SetController(Controller *g);
  std::string GetInputString();
  int GetResolution();
  double GetMinX();
  double GetMaxX();
  void SetGraph(XYGraph graph);

 private:
  void UpdateRange();
  void SetupWidget();
  void SetupBox();

  Ui::GraphWindow *ui;
  unsigned int count_{0};
  Controller *controller_graph_;
  std::array<QColor, 8> colours_ = {QColor("cyan"),     QColor("magenta"),
                                    QColor("red"),      QColor("darkRed"),
                                    QColor("darkCyan"), QColor("black"),
                                    QColor("orange"),   QColor("blue")};

 public slots:
  void TakeExpressionFromCalc(QString expression);

 private slots:
  void on_pushButton_Print_clicked();
  void on_lineEdit_In_textChanged(const QString &arg);
  void DeleteGraph(QListWidgetItem *item);

  void on_pushButton_default_axis_clicked();
  void on_doubleSpinBox_xMin_valueChanged();
  void on_doubleSpinBox_xMax_valueChanged();
  void on_doubleSpinBox_yMin_valueChanged();
  void on_doubleSpinBox_yMax_valueChanged();
  void xAxisChanged(QCPRange);
  void yAxisChanged(QCPRange);

 signals:
  void SendExpressionToCalc(QString);
};

#endif  // GRAPHWINDOW_H
