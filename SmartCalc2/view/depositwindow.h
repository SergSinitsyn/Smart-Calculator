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

  double GetDepositAmount();
  QDate GetStartOfTerm();
  int GetPlacementPeriod();
  int GetPlacementPeriodType();
  double GetInterestRate();
  double GetTaxRate();
  int GetPeriodicityOfPayments();
  bool GetCapitalisationOfInterest();

  void SetAnswer(double deposit_amount_by_the_end_of_the_term,
                 double accrued_interest, double tax_amount);
  //  void SetAccruedInterest();
  //  void SetTaxAmount();
  //  void SetDepositAmountByTheEndOfTheTerm();

 private slots:
  void on_pushButton_addReplenishment_clicked();

  void on_pushButton_Calculate_clicked();

 private:
  Ui::DepositWindow *ui;

  void Calculate();

  Controller *controller_deposit_;
};

#endif  // DEPOSITWINDOW_H
