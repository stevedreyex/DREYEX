#ifndef DOT_H
#define DOT_H
#include "vector.h"
#include <ctype.h>
#include <string>
#include <sstream>
using namespace std;

size_t stripDecos(std::string & st)
{
  size_t numCommas = 0;
  size_t t = st.find_first_of("(");
  st.replace(t,1, "");
  t = st.find_first_of(")");
  st.replace(t,1, "");
  t = st.find_first_of(",");
  while (t!=std::string::npos)
  {
    st.replace(t,1, " ");
    t = st.find_first_of(",");
    numCommas ++;
  }

  return numCommas+1;

}

void checkString(std::string s)
{
  size_t t = s.find_first_of(" ");
  while (t!=std::string::npos)
  {
    s.replace(t,1, "");
    t = s.find_first_of(" ");
  }
  t = s.find_first_of(",");
  while(t!=std::string::npos)
  {
    if((isdigit(s.at(t-1))==0)||(isdigit(s.at(t+1))==0))
    {
      throw "invaild input";
    }
    s.replace(t, 1, "");
    t = s.find_first_of(",");
  }
  
  
  if (s.compare(0,1,"(") != 0)
  {
    throw "invaild input";
  }
  if (s.compare(s.size()-1,1,")") != 0)
  {
    throw "invaild input";
  }
  if (s.compare(0,1,"[") == 0)
  {
    throw "invaild input";
  }
  if (s.compare(s.size()-1,1,"]") == 0)
  {
    throw "invaild input";
  }
  if (s.compare(1,1,",") == 0)
  {
    throw "invaild input";
  }
  if (s.compare(s.size()-2,1,",") == 0)
  {
    throw "invaild input";
  }
  if (isdigit(s.at(s.find_first_of("(")+1))==0)
  {
    throw "invaild input";
  }
  if (isdigit(s.at(s.find_first_of(")")-1))==0)
  {
    throw "invaild input";
  }
}

Vector createVectorFromStringOfNumbers(std::string s, int dimension)
{
  checkString(s);
  std::string st(s);
  size_t dim = stripDecos(st);
  if(dim != dimension)
  {
    throw "invaild input";
  }
  std::stringstream ss(st);
  double a[dim];
  for (int i=0; i< dim; i++)
    ss >> a[i];

  return Vector(a,dim);

}

std::string toString(Vector v)
{
  std::stringstream ss;
  ss <<"(";
  for(int i = 0; i < v.dim()-1; i++)
  {
    ss << v.at(i+1) << ",";
  }
  ss << v.at(v.dim()) << ")";
  return ss.str();
}

void sameDim(Vector u, Vector v)
{
  if(u.dim() != v.dim())
  {
    throw "Invalid Input";
  }
}

std::string addAns(Vector u, Vector v)
{
  sameDim(u, v);
  Vector s = u + v;
  return toString(s);
}

std::string subtractAns(Vector u, Vector v)
{
  sameDim(u, v);
  Vector s = u - v;
  return toString(s);
}

double dot(Vector u, Vector v)
{
  sameDim(u, v);
  double dot_sum = 0;
  for(int i = 0; i < u.dim(); i++)
  {
    dot_sum += u.at(i+1)*v.at(i+1);
  }
  return dot_sum;
}

std::string dotAns(Vector u, Vector v, int dim)
{
  std::stringstream ss;
  ss << dot(u, v);
  std::string str = ss.str();
  return str;
}

#endif