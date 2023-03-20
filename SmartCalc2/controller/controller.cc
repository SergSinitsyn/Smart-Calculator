#include "controller.h"

double Controller::CalculateMath(std::string &str_from_label, std::string &x) {
     math_model_.CalculateAnswer(str_from_label, x);
  return math_model_.GetAnswer();
}
