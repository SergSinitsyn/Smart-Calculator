#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QLineEdit>
#include <QVector>
#include <QWidget>

#include "qcustomplot.h"

namespace Ui {
class GraphWindow;
}

class GraphWindow : public QWidget {
  Q_OBJECT

 public:
  explicit GraphWindow(QWidget *parent = nullptr);
  ~GraphWindow();
  void SetExpression(QString expression);

 private slots:
  void on_pushButton_Print_clicked();

  void on_pushButton_Crear_clicked();

 private:
  Ui::GraphWindow *ui;
  unsigned int count_{0};
  std::array<QColor, 10> colours_ = {QColor("cyan"),     QColor("magenta"),
                                     QColor("red"),      QColor("darkRed"),
                                     QColor("darkCyan"), QColor("darkMagenta"),
                                     QColor("green"),    QColor("darkGreen"),
                                     QColor("yellow"),   QColor("blue")};
};

#endif  // GRAPHWINDOW_H
