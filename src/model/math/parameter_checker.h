#ifndef SMARTCALC_MODEL_MATH_PARAMETER_CHECKER_H_
#define SMARTCALC_MODEL_MATH_PARAMETER_CHECKER_H_

#include <string>

namespace MyNamespace {

class ParameterChecker {
 public:
  void CheckLength(std::string expression);
  void CheckNumberOfPoints(int size);
  void CheckRange(double x_start, double x_end);
};

}  // namespace MyNamespace

#endif  // SMARTCALC_MODEL_MATH_PARAMETER_CHECKER_H_