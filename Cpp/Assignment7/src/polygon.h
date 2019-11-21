#ifndef POLYGON_H
#define POLYGON_H

#include "shape.h"
#include "dot.h"
#include "bubble_sort.h"
#include "vector.h"

void organizeVectorPoint(Vector * vec, int sides)
{
  bubbleSort(vec + 1, vec + sides, [vec](Vector u, Vector v){return angle(*vec, u) < angle(*vec, v);});
}

class Polygon : public Shape
{
public:
  Polygon():_sides(-1), _v(nullptr)
  {

  }
  Polygon(Vector * v, int sides)
  {
    _sides = sides;
    _v = new Vector[_sides];
    for(int i = 0; i < _sides; i++)
    {
      _v[i] = v[i];
    }
  }
  double area() const
  {
    return convexPolygonArea(_v, _sides);
  }
  double perimeter() const
  {
    organizeVectorPoint(_v, _sides);
    return ::perimeter(_v, _sides);
  }
private:
  Vector * _v;
  int _sides;
};
#endif
