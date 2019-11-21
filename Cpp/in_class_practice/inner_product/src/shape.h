#ifndef SHAPE_H
#define SHAPE_H
#include <string>
using std::string;

class Shape{
protected:
  Shape(string name): _name(name)
  {

  }
public:
  virtual double area() const = 0;
  string name()
  {
    return _name;
  }
  virtual ~Shape()
  {

  }
private:
  string _name;
};

#endif
