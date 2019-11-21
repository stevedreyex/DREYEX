#include<iostream>
#include<string>
#include "binary.h"
#include "bin_calc.h"
using namespace std;
int main(void)
{
  int NoD;
  string str1;
  string str2;
  cout << "Please enter the number of digits: ";
  cin >> NoD;
  cin.get();
  cout << "Enter a binary: ";
  getline(cin, str1);
  cout << "Enter another binary: ";
  getline(cin, str2);
  Binary bin1 = CreateBinaryFromStringOfNumbers(str1, nod);
  Binary bin2 = CreateBinaryFromStringOfNumbers(str2, nod);
  return 0;
}
