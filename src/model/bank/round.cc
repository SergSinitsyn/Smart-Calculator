#include "round.h"

#include <cmath>

double RoundToTwoDecimalPlaces(double value) {
  return round(value * 100.) / 100.;
}
