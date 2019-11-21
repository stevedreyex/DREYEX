#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include <cmath>

class Circle : public Shape{
public:
  Circle (double r): _r(r), Shape("Circle")
  {

  }
  double area() const
  {
    return M_PI*_r*_r;
  }

  ~Circle()
  {

  }
private:
  const double _r;
};


#endif
