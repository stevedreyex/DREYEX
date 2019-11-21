#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <cmath>
class Vector {
public:
  Vector(double v[], int dim) 
  {
    _dim = dim;
    _v = new double[_dim];
    for (int i=0; i< _dim; i++)
    _v[i] = v[i];
  }

  int dim() 
  {
      return _dim;
  }

  bool isZero()
  {
      for(int i=0; i<_dim; i++)
    {
        if(_v[i] == 0)
        {
            return 1;
        }        
    }
    return 0;
  }

  double length()
  {
    int sum = 0;
    for(int i=0; i<_dim; i++)
    {
        sum = sum + _v[i]*_v[i];
    }
    return sqrt(sum);
  }

  double at(int i) 
  {
      return _v[i-1];
  }

private:
  int _dim;
  double * _v;
};

#endif
