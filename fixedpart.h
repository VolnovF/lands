#ifndef FIXEDPART_H
#define FIXEDPART_H

#include <cmath>

#include "part.h"

class FixedPart : public Part
{
public:
    FixedPart() = default;
    FixedPart(double area);

    void setArea(double area);
};

#endif // FIXEDPART_H
