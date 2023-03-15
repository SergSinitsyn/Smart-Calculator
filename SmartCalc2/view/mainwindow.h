#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "creditwindow.h"
#include "ui_creditwindow.h"


#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void input_buttons();
    void on_toolButton_equal_clicked();
    void on_toolButton_deleteAll_clicked();
    void on_toolButton_backspace_clicked();

    void on_actionCredit_Calculator_triggered();

    void on_actionEngineer_Calculator_triggered();

    void on_actionDeposit_Calculator_triggered();

private:
    Ui::MainWindow *ui;
   CreditWindow* Credit;


};
#endif // MAINWINDOW_H
