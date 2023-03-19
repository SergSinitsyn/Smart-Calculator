#include "controller.h"

double Controller::CalculateMath(std::string &str_from_label, std::string &x) {
  return model_->CalcMath(str_from_label, x);
}

// void Controller::CalculateDataForCredit(
//     CreditCalc::DataForCredit &data_for_credit) {
//   this->model_->GetCreditCalc().CalculateCredit(data_for_credit);
// }
