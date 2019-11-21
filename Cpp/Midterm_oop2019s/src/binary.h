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
  Binary()
  {
    int _bit;
    _a = new int[_bit];
  }
  Binary(int input[], int s)
  {
    copy(input, s);
  }

  int at(int n) const
  {
    return _a[_bit-n];
  }

  Binary(Binary const & b)
  {
    copy(b._a, b._bit);
  }

  Binary(int dec)
  {
    _bit = 0;
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

  ~Binary()
  {
    delete [] _a;
  }

  int numbersOfBit()
  {
    return _bit;
  }

  void checkIfIsInitialized() const
  {
    if((_bit<0)||(_bit >256))
    {
      throw "Wasn't initialized";
    }
  }

  int toInt() const
  {
    this->checkIfIsInitialized();
      int sum = 0;
      for(int i = _bit-1; i >=0; i--)
      {
        if(_a[i] == 1)
          sum += pow(2, (_bit -1 - i));
      }
      return sum;
  }

  Binary operator + (Binary const & b)
  {
    this->checkIfIsInitialized();
    b.checkIfIsInitialized();
    Binary x(*this);
    int num1 = x.toInt();
    int num2 = b.toInt();
    int sum = num1 + num2;
    Binary z(sum);
    return z;
  }

  Binary operator - (Binary const & b)
  {
    this->checkIfIsInitialized();
    b.checkIfIsInitialized();
    Binary x(*this);
    int num1 = x.toInt();
    int num2 = b.toInt();
    if(num2 > num1)
    {
      throw "smaller than zero";
    }
    int sum = num1 - num2;
    Binary z(sum);
    return z;
  }

  void setBit(int pos, int data)
  {
    if(pos>_bit)
    {
      throw "not in range";
    }
    if((data!=0)&&(data!=1))
    {
      throw "can't be not 0 or 1";
    }
    _a[pos] = data;
  }

  void resize(int new_size)
  {
    this->checkIfIsInitialized();
    int size = new_size - 1;
    int temp [size];
    for(int i = 0; i < size; i++)
    {
      temp[i] = 0;
    }
    for(int i = 0; i < _bit; i++)
    {
      temp[new_size - _bit + i] = _a[i];
    }
    delete [] _a;
    copy(temp, new_size);
  }

  Binary & operator = (Binary const & b  )
  {
    b.checkIfIsInitialized();
    copy(b._a, b._bit);
  }


  std::string toString() const
  {
    this->checkIfIsInitialized();
    stringstream ss;
    for(size_t i = 0; i <= _bit-1 ; i++)
    {
      ss << _a[i];
    }
    return ss.str();
  }

 // Binary operator << (int a)
 // {
 //   int temp[_bit];
 //   int size = _bit;
 //   for(int i = 0; i < _bit; i++)
 //   {
 //     temp[i]  = 0;
 //   }
 //   for(int i = 0; i < a; i++)
 //   {
 //     temp[i] = _a[a+i];
 //   }
 //   for(int i = 0; i<_bit; i++)
 //   {
 //     temp[i+a] = 0;
 //   }
 //   delete [] _a;
 //   copy(temp, size);
 // }

 Binary operator << (int a)
 {
   Binary x(*this);
   int num = x.toInt();
   int mvnum = (num<<a);
   Binary z(mvnum);
   return z;
 }

 Binary operator >> (int a)
 {
   Binary x(*this);
   int num = x.toInt();
   int mvnum = (num>>a);
   Binary z(mvnum);
   return z;
 }

private:
  int * _a;
  int _bit;
  void copy(int input[], int s)
  {
    _bit = s;
    _a = new int[_bit-1];
    for(int i=0; i < _bit; i++)
    {
      _a[i] = input[i];
    }
  }
};

#endif
