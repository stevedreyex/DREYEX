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

#endif
