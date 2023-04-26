#ifndef DEPOSITWINDOW_H
#define DEPOSITWINDOW_H
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QVBoxLayout>
#include <QVector>
#include <QWidget>

#include "cell.h"
namespace Ui {
class DepositWindow;
}

namespace MyNamespace {
class Controller;

using MultiMapQDate = std::multimap<QDate, std::pair<int, double>>;

class DepositWindow : public QWidget {
  Q_OBJECT

 public:
  explicit DepositWindow(QWidget *parent = nullptr);
  ~DepositWindow();
  void SetController(Controller *d);

  double GetDepositAmount() const;
  QDate GetStartOfTerm() const;
  int GetPlacementPeriod() const;
  int GetPlacementPeriodType() const;
  double GetInterestRate() const;
  double GetTaxRate() const;
  int GetPeriodicityOfPayments() const;
  bool GetCapitalisationOfInterest() const;
  double GetMinimumBalance() const;
  MultiMapQDate GetReplenishmentsList() const;
  MultiMapQDate GetPartialWithdrawalsList() const;
  void SetAnswer(double deposit_amount_by_the_end_of_the_term,
                 double accrued_interest, double tax_amount);

 private:
  Ui::DepositWindow *ui;
  Controller *controller_deposit_;

  int cell_number_total_replenishment_;
  int cell_number_total_partial_withdrawal_;
  static constexpr int kMaxCellNumber_ = 1024;
  QVector<Cell *> all_cell_replenishment_ptr_;
  QVector<Cell *> all_cell_partial_withdrawal_ptr_;
  MultiMapQDate replenishments_list_;
  MultiMapQDate partial_withdrawals_list_;

  void AddNewCellReplenishment();
  void AddNewCellPartialWithdrawal();
  void FillList(QVector<Cell *> vector,
                std::multimap<QDate, std::pair<int, double>> &map);
  void FillReplenishmentsList();
  void FillPartialWithdrawalsList();
  void SetGroupSeparators(QString &srt);
  void SetValueToLine(double value, QLineEdit *line);

 private slots:
  void on_pushButton_Calculate_clicked();
  void on_pushButton_AddReplenishment_clicked();
  void on_pushButton_AddPartialWithdrawal_clicked();
  void on_comboBox_PlacementPeriod_currentIndexChanged(int index);
  void on_dateEdit_StartOfTerm_userDateChanged(const QDate &date);
  void CloseCell(int CellNumber, int CellType);
};
};  // namespace MyNamespace

#endif  // DEPOSITWINDOW_H
