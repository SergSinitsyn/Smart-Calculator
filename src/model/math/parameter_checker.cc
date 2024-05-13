#include "parameter_checker.h"

#include <cmath>
#include <exception>
#include <stdexcept>
#include <string>

namespace MyNamespace {

void ParameterChecker::CheckLength(std::string const &expression) {
  if (expression.size() > 255)
    throw std::invalid_argument("Character limit exceeded");
  if (expression.size() == 0) throw std::invalid_argument("Empty input");
}

void ParameterChecker::CheckNumberOfPoints(int number_of_points) {
  if (!(std::isfinite(number_of_points) || std::isnan(number_of_points))) {
    throw std::invalid_argument("Invalid number of points for plot");
  }
  if (number_of_points < 2)
    throw std::invalid_argument("Invalid number of points for plot");
}

void ParameterChecker::CheckRange(double x_start, double x_end) {
  if (!(std::isfinite(x_start) && std::isfinite(x_start)))
    throw std::invalid_argument("Invalid start or end for plot");
  if (x_start == x_end)
    throw std::invalid_argument("Start of plot equals end of plot");
}

};  // namespace MyNamespace
