#include "controller.h"

double Controller::CalculateMath(std::string &str_from_label, double &x) {
  return model_->GetResultMathExpression(str_from_label, x);
}

//void Controller::CalculateDataForCredit(
//    CreditCalc::DataForCredit &data_for_credit) {
//  this->model_->GetCreditCalc().CalculateCredit(data_for_credit);
//}
