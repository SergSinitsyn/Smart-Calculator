#ifndef _CONTROLLER_CONTROLLER_H_
#define _CONTROLLER_CONTROLLER_H_

#include "../model/model.h"

class Controller {
public:
  explicit Controller(Model *model) : model_{model} {};
  double CalculateMath(std::string &str_from_label, double &x);

  void CalculateCredit();

private:
  Model *model_;
};

#endif // _CONTROLLER_CONTROLLER_H_
