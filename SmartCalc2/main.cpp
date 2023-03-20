#include "view/mainwindow.h"

#include "model/model.h"
#include "controller/controller.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window_main;




//    MathCalculator math_calc;
//    Credit credit_calc;
//    Deposit deposit_calc;

//    Model model(math_calc, credit_calc, deposit_calc);

//    Controller controller(&model);
//    window_main.SetController(&controller);


    Controller controller(MathCalculator);
    window_main.SetController(controller_);
    window_main.show();
    return a.exec();
}
