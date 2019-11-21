#ifndef BINARY_H
#define BINARY_H
#include<iostream>
#include<cmath>
#include<sstream>
#include <string>
#define BYTE 8
using namespace std;
class Binary {
public:
  Binary(int a[], int bit)
  {
    _bit = bit;
    _a = new int[_bit-1];
    for(int i=0; i < _bit; i++)
    {
      _a[i] = a[i];
    }
  }
  int at(int n)
  {
    return _a[_bit-n];
  }

  Binary(Binary const & bin)
  {
    _bit = bin._bit;
    _a = new int[_bit];
    for(int i=0; i<_bit; i++)
    {
      _a[i] = bin._a[i];
    }
  }
  ~Binary()
  {
    delete [] _a;
  }

  Binary(int dec)
  {
    int temp = dec;
    while(temp != 0)
    {
      temp /= 2;
      _bit++;
    }
    _a = new int[_bit];
    for(int i = _bit - 1; i>= 0; i--)
    {
      if(dec % 2 ==0)
      {
        _a[i] = 0;
      }
      else
      {
        _a[i] = 1;
      }
      dec /= 2;
    }
  }

  int numbersOfBit()
  {
    return _bit;
  }

  int BinaryToDecimal()
  {
      int sum = 0;
      for(int i = _bit-1; i >=0; i--)
      {
        if(_a[i] == 1)
          sum += pow(2, (_bit -1 - i));
      }
      return sum;
  }

  int add(Binary u)
  {
    int dec1 = BinaryToDecimal();
    int dec2 = u.BinaryToDecimal();
    int sum = dec1 + dec2;
    return sum;
  }

  Binary operator + (Binary const & v)
  {
    Binary x(*this);
    int sum = x.add(v);
    Binary z(sum);
    return z;
  }

  int subtract(Binary u)
  {
    int dec1 = BinaryToDecimal();
    int dec2 = u.BinaryToDecimal();
    int sum = dec1 - dec2;
    return sum;
  }

  Binary operator - (Binary const & v)
  {
    Binary x(*this);
    int sum = x.subtract(v);
    Binary z(sum);
    return z;
  }

  std::string output()
  {
    stringstream ss;
    for(size_t i = 0; i <= _bit-1 ; i++)
    {
      ss << _a[i];
    }
    return ss.str();
  }

private:
  int * _a;
  int _bit;
};

#endif
