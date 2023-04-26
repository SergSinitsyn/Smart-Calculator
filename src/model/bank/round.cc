#include "round.h"

double RoundToTwoDecimalPlaces(double value) {
  return round(value * 100.) / 100.;
}
