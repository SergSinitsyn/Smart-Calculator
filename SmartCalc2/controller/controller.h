
#ifndef _CONTROLLER_CONTROLLER_H_
#define _CONTROLLER_CONTROLLER_H_

#include "../model/mathcalculator.h"
#include "../model/credit.h"
#include "../model/deposit.h"

class Controller {
public:
  Controller(MathCalculator math_model) : math_model_{math_model}  {};


  double CalculateMath(std::string &str_from_label, std::string &x);
//  XYGraph CalculateGraph(std::string &str_from_label, int size, double min_x, double max_x);
//  void CalculateCredit();

private:
    MathCalculator math_model_;
};




//XYGraph Controller::CalculateGraph(std::string &str_from_label, int size, double min_x, double max_x) {
//    return model_->Calc

//}

// void Controller::CalculateDataForCredit(
//     CreditCalc::DataForCredit &data_for_credit) {
//   this->model_->GetCreditCalc().CalculateCredit(data_for_credit);
// }



#endif // _CONTROLLER_CONTROLLER_H_
