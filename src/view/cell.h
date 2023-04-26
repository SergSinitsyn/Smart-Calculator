#ifndef CELL_H
#define CELL_H

#include <QWidget>

namespace Ui {
class Cell;
}
namespace MyNamespace {
class Cell : public QWidget {
  Q_OBJECT

 public:
  explicit Cell(QWidget *parent = nullptr);
  ~Cell();
  int GetPeriodicity() const;
  QDate GetDate() const;
  double GetValue() const;
  int GetNumber() const;
  int GetType() const;
  void SetNumber(int newNumber);
  void SetType(int newType);
  void SetMinimumDate(QDate date);

 private:
  Ui::Cell *ui;
  int number_;
  int type_;

 private slots:
  void on_toolButton_delete_clicked();

 signals:
  void CloseThisCell(int, int);
};
};  // namespace MyNamespace

#endif  // CELL_H
