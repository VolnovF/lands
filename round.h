#ifndef ROUND_H
#define ROUND_H

#include <cmath>

constexpr int countDigitsAfterPoint {2};

double Floor(double decimal, int countDigits = countDigitsAfterPoint);

double Round(double decimal, int countDigits = countDigitsAfterPoint);


#endif // ROUND_H
