#include "model.h"

#include "calculator.h"

std::pair<double, std::string> Model::Calculate(std::string str) {
  return Calculate(str, 0);
}

std::pair<double, std::string> Model::Calculate(std::string str, double x) {
  Calculator A;
  double result = 0;
  std::string error_message = "";
  try {
    A.LoadExpression(str);
    result = A.CalculateValue(x);
  } catch (const std::exception& e) {
    error_message = e.what();
  }
  return make_pair(result, error_message);
}

std::pair<XYGraph, std::string> Model::Calculate(std::string str, int size,
                                                 double start, double end) {
  Calculator A;
  XYGraph result{0, 0};
  std::string error_message = "";
  try {
    A.LoadExpression(str);
    result = A.CalculateGraph(size, start, end);
  } catch (const std::exception& e) {
    error_message = e.what();
  }
  return make_pair(result, error_message);
}
