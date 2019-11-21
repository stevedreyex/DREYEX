#ifndef VECTOR_H
#define VECTOR_H
#include<iostream>
#include<cmath>
#include<sstream>
class Vector {
public:
  Vector(double v[], int dim)
  {
    copy(dim, v);
  }

  Vector(Vector const & v)
  {
    copy(v._dim, v._v);
  }

  // destructor
  ~Vector()
  {
    delete [] _v;
  }

  // constant member function
  int dim() const
  {
    return _dim;
  }

  double & at(int i) const
  {
    if(i>_dim)
    {
        throw "bigger than vector";
    }
    if(i<0)
    {
      throw "can't smaller than 0";
    }
    return _v[i-1];
  }

  void subtract(Vector const & v)
  {
    if(this->_dim != v._dim)
        throw "not at the same dimension";
    else
    {
        for(int i = 1; i <=_dim; i++)
        {
            at(i) -= v.at(i);
         }
    }
  }

  void add(Vector const & v)
  {
    if(this->_dim != v._dim)
        throw "not at the same dimension";
    else
    {
        for(int i = 1; i <=_dim; i++)
        {
            at(i) += v.at(i);
        }
    }
  }

  Vector & operator = (Vector const & u)
  {
    copy(u._dim, u._v);
    return *this;
  }

  Vector operator - (Vector const & v) const{
    Vector x(*this);
    x.subtract(v);
    return x;
  }

  Vector operator + (Vector const & v) const{
    Vector x(*this);
    x.add(v);
    return x;
  }

  double length() const
  {
    double temp = 0;
    for(int i = 1; i <= _dim; i++)
    {
        temp += at(i)*at(i);
    }
    return sqrt(temp);
  }

private:
  int _dim;
  double * _v;
  void copy(int dim, double v[]){
    _dim = dim;
    _v = new double[_dim];
    for(int i = 0; i < _dim; i++)
    {
        _v[i] = v[i];
    }
  }
};

double distance(Vector const & u, Vector const & v)
{
    return (u-v).length();
}

double area(Vector const & u, Vector const & v, Vector const & w)
{
   double a = distance(u,v);
   double b = distance(u,w);
   double c = distance(w,v);
   double s = (a + b + c)/2;
   return sqrt(s*(s-a)*(s-b)*(s-c));
}

double area(Vector a[], int sides)
{
    double sum = 0;
  for(int i=1; i <= sides-2; i++)
  {
    sum += area(a[0], a[i], a[i+1]);
  }
  return sum;
}

double perimeter(Vector a[], int sides)
{
    double sum = 0;
  for(int i=0; i<=sides-2; i++)
  {
    sum += distance(a[i], a[i+1]);
  }
  sum += distance(a[sides-1], a[0]);
  return sum;
}

#endif
