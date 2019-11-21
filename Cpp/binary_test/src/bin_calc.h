#ifndef BIN_CALC_H
#define BIN_CALC_H
#include "binary.h"
#include <ctype.h>
#include <string>
#include <sstream>
using namespace std;
Binary CreateBinaryFromStringOfNumbers(string str, int nod)
{
  string st(str);
  int a[nod];
  stringstream ss(st);
  for (int i=0; i< nod; i++)
    ss >> a[i];
  return Binary(a, nod);
}

#endif
