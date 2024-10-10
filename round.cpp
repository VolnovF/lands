#include "round.h"

double Floor(double decimal, int countDigits)
{
    return std::floor(decimal * std::pow(10, countDigits)) / std::pow(10, countDigits);
}

double Round(double decimal, int countDigits)
{
    return std::round(decimal * std::pow(10, countDigits)) / std::pow(10, countDigits);
}
