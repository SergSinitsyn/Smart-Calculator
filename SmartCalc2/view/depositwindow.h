#ifndef DEPOSITWINDOW_H
#define DEPOSITWINDOW_H

#include <QWidget>

namespace Ui {
class DepositWindow;
}

class DepositWindow : public QWidget {
  Q_OBJECT

 public:
  explicit DepositWindow(QWidget *parent = nullptr);
  ~DepositWindow();

 private slots:
  void on_pushButton_addReplenishment_clicked();

 private:
  Ui::DepositWindow *ui;
};

#endif  // DEPOSITWINDOW_H
