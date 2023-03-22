#ifndef _MODEL_MODEL_H_
#define _MODEL_MODEL_H_

#include "credit.h"
#include "deposit.h"
#include "mathcalculator.h"

class Model {
 public:
  Model() {};


 private:
  MathCalculator math_calc_;
  Credit credit_calc_;
  Deposit deposit_calc_;

};

#endif  // _MODEL_MODEL_H_
