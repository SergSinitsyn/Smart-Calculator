#include "check.h"

#include <cmath>
#include <string>
#define MAX 256

void CheckLength(std::string expression) {
  if (expression.size() > MAX) {
    error_code_ = character_limit_exceeded;
    return;
  }
  if (expression.size() == 0) {
    error_code_ = empty_input_string;
    return;
  }
}

void CheckVariable(double x) {
  if (x != x) {
    error_code_ = x_is_nan;
    return;
  }
}

void CheckNumberOfPoints(int number_of_points) {
  if (number_of_points < 1) {
    error_code_ = not_a_plot;
    return;
  }
  std::vector<double> x;
  if (number_of_points > x.max_size() / 2.) {  //! ? ?
    error_code_ = exceeded_max_size_of_vector;
    return;
  }
}

void CheckRange(double x_start, double x_end) {
  if (!(std::isfinite(x_start) && std::isfinite(x_start))) {
    error_code_ = sss;
    return;
  }
  if (x_start == x_end) {
    error_code_ = x_start_equals_x_end;
    return;
  }
}