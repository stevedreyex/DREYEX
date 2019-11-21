#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include "vector.h"
#include <cmath>

class Circle : public Shape
{
public:
  Circle():_r(-1)
  {
  }
  Circle(double r)
  {
    _r = r;
  }
  double area() const
  {
    return M_PI*_r*_r;
  }
  double perimeter() const
  {
    return 2*M_PI*_r;
  }
private:
  double _r;
};
#endif
