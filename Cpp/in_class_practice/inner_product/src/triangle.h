#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "dot.h"

class Triangle: public Shape
{
public:
  Triangle(Vector a[], int sides): Shape("Triangle"), _sides(sides)
  {
    _v = new Vector[_sides];
    for(int i = 0; i < _sides; i++){
      _v[i] = a[i];
    }
  }

  double area() const
  {
    return 0;
  }

  static Triangle * createTriangle(Vector a[], int sides)
  {
    double b = (a[0]-a[1]).length();
    double c = (a[1]-a[2]).length();
    double d = (a[2]-a[0]).length();
    if(b+c > d && b+d > c && c+d > b){
      return new Triangle(a, sides);
    }else{
      throw std::string("on the same line");
    }

  }

private:
  Vector * _v;
  int _sides;
};

//to commit
#endif
