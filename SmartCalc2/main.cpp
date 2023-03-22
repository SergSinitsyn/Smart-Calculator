#include "view/mainwindow.h"
#include "model/mathcalculator.h"
#include "model/credit.h"
#include "model/deposit.h"
#include "controller/controller.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MathCalculator model_math;
    Credit model_credit;
    Deposit model_deposit;
    Controller ctrl(&model_math, &model_credit, &model_deposit);
    MainWindow main_window;
    main_window.SetController(&ctrl);
    main_window.show();
    return a.exec();
}
