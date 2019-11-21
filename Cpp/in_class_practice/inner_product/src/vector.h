#ifndef VECTOR_H
#define VECTOR_H
#include<iostream>
#include<cmath>
#include <sstream>

class Vector {
public:
  // default constructor
  Vector():_dim(-1), _v(nullptr)
  {

  }

  Vector(double v[], int dim): _dim(dim), _v(nullptr)
  {
    copy(v);
  }

  // copy constructor
  Vector(Vector const & v): _dim(v._dim), _v(nullptr)
  {
    copy(v._v);
  }

  // destructor
  ~Vector()
  {
    if (_v != nullptr)
      delete [] _v;
  }

// constant member function
  int dim() const{
    return _dim;
  }

double & at(int i) const
{
  return _v[i-1];
}

void subtract(Vector const & v)
{
  for(int i =1; i<= _dim; i++)
    at(i) -= v.at(i);
}

void add(Vector const & v)
{
  for(int i =1; i<= _dim; i++)
    at(i) += v.at(i);
}

Vector & operator = (Vector const & u)
{
  _dim = u.dim();
  copy(u._v);
  return *this;
}

double length() const
{
  double dist2 = 0;
  for (int i=1; i<= _dim; ++i)
    dist2 += at(i)*at(i);
  return sqrt (dist2);
}

std::string toString() const {
  std::stringstream ss;
  ss << "(";
  for (int i = 1; i < _dim; i++) {
    ss << at(i) << ", ";
  }
  ss << at(_dim) << ")" ;
  return ss.str();
}

private:
  int _dim;
  double * _v;

  void copy(double v[])
  {
    if(_v != nullptr)
      delete [] _v;
    _v = new double[_dim];
    for (int  i=0 ; i < _dim ;i++)
      _v[i]=v[i];
  }
};
#endif
