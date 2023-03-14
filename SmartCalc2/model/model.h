#ifndef _MODEL_MODEL_H_
#define _MODEL_MODEL_H_

#include "calculator.h"
#include "credit.h"

class Model {
 public:
  Model() = default;
  ~Model() = default;

  std::pair<double, std::string> Calculate(std::string str);
  std::pair<double, std::string> Calculate(std::string str, double x);
  std::pair<XYGraph, std::string> Calculate(std::string str, int size,
                                            double start, double end);

  //   std::tuple<double, double, double> CalculateCreditA();
  //   std::tuple<std::vector<double>, double, double> CalculateCreditD();
};

#endif  // _MODEL_MODEL_H_
