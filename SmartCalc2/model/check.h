#ifndef _MODEL_CHECK_H_
#define _MODEL_CHECK_H_

#include <exception>
#include <string>

void CheckLength(std::string expression);
void CheckNumberOfPoints(int size);
void CheckRange(double x_start, double x_end);

#endif  // _MODEL_CHECK_H_
