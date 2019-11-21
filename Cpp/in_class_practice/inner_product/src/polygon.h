#ifndef POLYGON_H
#define POLYGON_H

#include "shape.h"
#include "vector.h"
#include "dot.h"

class Polygon : public Shape
{
public:
  Polygon(Vector v[], int sides): Shape("Polygon")
  {
    _sides = sides;
    _v = new Vector[_sides];
    for (int  i=0 ; i < _sides ;i++)
      _v[i]=v[i];
  }

  double area() const
  {
    return ::area(_v, _sides);
  }

  ~Polygon()
  {
    delete [] _v;
  }
private:
  Vector *_v;
  int _sides;
};
#endif
