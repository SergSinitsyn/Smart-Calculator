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

using XYGraph = std::pair<std::vector<double>, std::vector<double>>;

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
  double GetMinY();
  double GetMaxY();
  void SetGraph(XYGraph graph);

 private:
  int SetColor();
  void SetupWidget();
  void SetupBox();
  void UpdateXAxisRange();
  void UpdateYAxisRange();

  Ui::GraphWindow *ui;
  Controller *controller_graph_;
  unsigned int count_{0};
  constexpr static unsigned int kMaxGraphs_ = 8;
  std::vector<QColor> colors_ = {
      QColor("black"),  QColor("red"),    QColor("green"),
      QColor("blue"),   QColor("cyan"),   QColor("magenta"),
      QColor("grey"),   QColor("orange"), QColor("brown"),
      QColor("coral"),  QColor("gold"),   QColor("coral"),
      QColor("ingigo"), QColor("teal"),   QColor("yellowgreen"),
      QColor("tan")};

 public slots:
  void TakeExpressionFromCalc(QString expression);

 private slots:
  void on_lineEdit_In_textChanged(const QString &arg);
  void on_pushButton_Print_clicked();
  void on_pushButton_Color_clicked();
  void on_pushButton_Delete_clicked();
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
