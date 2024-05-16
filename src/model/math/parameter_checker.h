#ifndef SMARTCALC_MODEL_MATH_PARAMETER_CHECKER_H_
#define SMARTCALC_MODEL_MATH_PARAMETER_CHECKER_H_

#include <string>

namespace MyNamespace {

class ParameterChecker {
 public:
  void CheckLength(const std::string &, size_t);
  void CheckNumberOfPoints(int);
  void CheckRange(double, double);
};

}  // namespace MyNamespace

#endif  // SMARTCALC_MODEL_MATH_PARAMETER_CHECKER_H_