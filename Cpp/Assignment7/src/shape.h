#ifndef SHAPE_H
#define SHAPE_H

#include "vector.h"
#include <vector>

class Shape
{
public:
  virtual double area() const = 0;
  virtual double perimeter() const = 0;
};

template <class RAI, class FIND>
std::vector<Shape *> findAll(RAI begin, RAI end, FIND find)
{
  std::vector<Shape *> arr;
  for(RAI i = begin; i != end; i++)
    if (find(*i))
    {
      arr.push_back(*i);
    }
  return arr;
}

#endif
