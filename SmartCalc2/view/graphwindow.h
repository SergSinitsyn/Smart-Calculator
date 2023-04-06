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

class GraphWindow : public QWidget {
  Q_OBJECT

 public:
  explicit GraphWindow(QWidget *parent = nullptr);
  ~GraphWindow();
  void SetController(Controller *g);
  std::string GetInputString();
  double GetMinX();
  double GetMaxX();
  void SetGraph(std::pair<QVector<double>, QVector<double>> graph);

 public slots:

  void TakeExpressionFromCalc(QString expression);

 private slots:
  void on_pushButton_Print_clicked();
  void on_pushButton_Crear_clicked();

  void on_doubleSpinBox_xMin_valueChanged();
  void on_doubleSpinBox_xMax_valueChanged();
  void on_doubleSpinBox_yMin_valueChanged();
  void on_doubleSpinBox_yMax_valueChanged();

  void SetupWidget();
  void SetupBox();

  void on_lineEdit_In_textChanged(const QString &arg1);

 private:
  void UpdateRange();

  Ui::GraphWindow *ui;
  unsigned int count_{0};
  std::array<QColor, 8> colours_ = {QColor("cyan"),     QColor("magenta"),
                                    QColor("red"),      QColor("darkRed"),
                                    QColor("darkCyan"), QColor("black"),
                                    QColor("orange"),   QColor("blue")};
  Controller *controller_graph_;

 signals:
  void SendExpressionToCalc(QString);
};

#endif  // GRAPHWINDOW_H
