#ifndef SHAPE_H
#define SHAPE_H


class IShape
{
protected:
    IShape() = default;

public:
    virtual double getArea() const = 0;

    virtual ~IShape() = default;
};

#endif // SHAPE_H
