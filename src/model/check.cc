#include "check.h"

#include <cmath>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

void CheckLength(std::string expression) {
  if (expression.size() > 255)
    throw std::invalid_argument("character limit exceeded");

  if (expression.size() == 0) throw std::invalid_argument("empty expression");
}

void CheckVariable(double x) {
  if (x != x) throw std::invalid_argument("x is NAN");
}

void CheckNumberOfPoints(int number_of_points) {
  if (number_of_points < 1)
    throw std::invalid_argument("invalid number of points for plot");

  std::vector<double> x;
  if (number_of_points > x.max_size() / 2.)
    throw std::invalid_argument("invalid number of points for plot");
}

void CheckRange(double x_start, double x_end) {
  if (!(std::isfinite(x_start) && std::isfinite(x_start)))
    throw std::invalid_argument("invalid start or end for plot");

  if (x_start == x_end) throw std::invalid_argument("x_start equals x_end");
}