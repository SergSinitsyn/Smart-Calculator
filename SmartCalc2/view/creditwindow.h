#ifndef CREDITWINDOW_H
#define CREDITWINDOW_H

#include <QDoubleSpinBox>
#include <QWidget>
#include <vector>

namespace Ui {
class CreditWindow;
}

class Controller;

class CreditWindow : public QWidget {
  Q_OBJECT

 public:
  explicit CreditWindow(QWidget* parent = nullptr);
  ~CreditWindow();
  void SetController(Controller* c);
  double GetTotalCreditAmount() const;
  double GetInterestRate() const;
  int GetTerm() const;
  int GetCreditType() const;
  void SetAnswer(double total_payment, double overpayment_on_credit,
                 std::vector<double> monthly_payment);

 private:
  Ui::CreditWindow* ui;
  Controller* controller_credit_;

  void SetDefault(QSpinBox& sb);
  void SetDefault(QDoubleSpinBox& sb);

 private slots:
  void on_pushButton_Calculate_clicked();
  void on_pushButton_Clear_clicked();
  void on_comboBox_Term_currentIndexChanged(int index);
};

#endif  // CREDITWINDOW_H
