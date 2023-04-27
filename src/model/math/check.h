#ifndef SMARTCALC_MODEL_MATH_CHECK_H_
#define SMARTCALC_MODEL_MATH_CHECK_H_

#include <cmath>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>

void CheckLength(std::string expression);
void CheckNumberOfPoints(int size);
void CheckRange(double x_start, double x_end);

#endif  // SMARTCALC_MODEL_MATH_CHECK_H_
