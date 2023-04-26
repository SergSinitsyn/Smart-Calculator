#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QKeyEvent>
#include <QMainWindow>
#include <QMessageBox>
#include <QVector>

#include "creditwindow.h"
#include "depositwindow.h"
#include "graphwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace MyNamespace {

class Controller;
class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();
  void SetController(Controller* c);
  std::string GetInputString() const;
  std::string GetInputStringX() const;
  void SetAnswer(double x);

 private:
  Ui::MainWindow* ui;
  CreditWindow* credit_view_;
  DepositWindow* deposit_view_;
  GraphWindow* graph_view_;
  Controller* controller_;

  void ConnectInputButtons();
  void ConnectInputButtonsExtra();

  void HideAllWindows();
  QLineEdit* LineOnFocus();

 public slots:
  void TakeExpressionFromGraph(QString expression);

 private slots:
  void InputButtons();
  void InputButtonsWithBrakets();
  void on_toolButton_equal_clicked();
  void on_toolButton_all_clean_clicked();
  void on_toolButton_backspace_clicked();
  void on_actionEngineer_Calculator_triggered();
  void on_actionGraph_View_triggered();
  void on_actionCredit_Calculator_triggered();
  void on_actionDeposit_Calculator_triggered();
  void on_lineEdit_input_textChanged(const QString& arg);

 signals:
  void SendExpressionToGraph(QString);
};
};      // namespace MyNamespace
#endif  // MAINWINDOW_H
