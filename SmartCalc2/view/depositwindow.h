#ifndef DEPOSITWINDOW_H
#define DEPOSITWINDOW_H

#include <QWidget>

namespace Ui {
class DepositWindow;
}

class Controller;

class DepositWindow : public QWidget {
  Q_OBJECT

 public:
  explicit DepositWindow(QWidget *parent = nullptr);
  ~DepositWindow();
  void SetController(Controller *d);

 private slots:
  void on_pushButton_addReplenishment_clicked();

 private:
  Ui::DepositWindow *ui;

  Controller *controller_deposit_;
};

#endif  // DEPOSITWINDOW_H
