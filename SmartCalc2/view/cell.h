#ifndef CELL_H
#define CELL_H

#include <QWidget>

namespace Ui {
class Cell;
}

class Cell : public QWidget {
  Q_OBJECT

 public:
  explicit Cell(QWidget *parent = nullptr);
  ~Cell();
  int CellNumber;
  int CellType;
  int GetType();
  QDate GetDate();
  double GetValue();

 private:
  Ui::Cell *ui;

 private slots:
  void on_toolButton_delete_clicked();

 signals:
  void CloseThisCell(int, int);
};

#endif  // CELL_H
