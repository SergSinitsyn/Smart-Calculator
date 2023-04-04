#ifndef DEPOSITWINDOW_H
#define DEPOSITWINDOW_H
#include <QVector>
#include <QWidget>

#include "../model/date.h"
#include "cell.h"
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
  std::multimap<Date, std::pair<int, double>> GetReplenishmentsList();
  std::multimap<Date, std::pair<int, double>> GetPartialWithdrawalsList();

  void SetAnswer(double deposit_amount_by_the_end_of_the_term,
                 double accrued_interest, double tax_amount);

 private slots:

  void on_pushButton_Calculate_clicked();
  void on_pushButton_AddReplenishment_clicked();

 private:
  Ui::DepositWindow *ui;

  void Calculate();
  void AddNewCell();
  void CloseCell(int CellNumber);

  void FillList(QVector<Cell *> vector,
                std::multimap<Date, std::pair<int, double>> map);
  void FillReplenishmentsList();
  void FillPartialWithdrawalsList();

  int CellNumberTotalReplenishment;
  int CellNumberTotalPartialWithdrawal;

  QVector<Cell *> AllCellReplenishmentPtr;
  QVector<Cell *> AllCellPartialWithdrawalPtr;

  std::multimap<Date, std::pair<int, double>> replenishments_list_;
  std::multimap<Date, std::pair<int, double>> partial_withdrawals_list_;

  Controller *controller_deposit_;
};

#endif  // DEPOSITWINDOW_H
