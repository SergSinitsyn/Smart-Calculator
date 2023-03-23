#ifndef CREDITWINDOW_H
#define CREDITWINDOW_H

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
  double GetTotalCreditAmount();
  double GetInterestRate();
  int GetTerm();
  int GetCreditType();
  void SetAnswer(double total_payment, double overpayment_on_credit,
                 std::vector<double> monthly_payment);

 private slots:
  void on_pushButton_Calculate_clicked();

  void on_comboBox_Term_currentIndexChanged(int index);

 private:
  Ui::CreditWindow* ui;
  void Calculate();

  Controller* controller_credit_;
};

#endif  // CREDITWINDOW_H
