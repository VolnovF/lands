#ifndef SHAPE_H
#define SHAPE_H


class Shape
{
protected:
    Shape() = default;

public:
    virtual double getArea() const;

    virtual ~Shape() = default;
};

#endif // SHAPE_H
