#ifndef DOT_H
#define DOT_H

#include <string>
#include "vector.h"

int dot(int u[], int v[], int m, int n) {
  if (m != n) {
    // std::cout << "Can't do\n";
    // exit (1);
    throw std::string("Can't do");
  }
  int sum = 0;
  for (int i =0; i<n; i++)
    sum += u[i]*v[i];
  return sum;
}

// int dot(Vector u, Vector v) // call by value
int dot(Vector const & u, Vector const & v) // call by reference
{
  int sum = 0;
  // for (int i =0; i<v._dim; i++)
  for (int i =1; i<=v.dim(); i++)
    sum += u.at(i)*v.at(i);
  return sum;
}

Vector operator -(Vector const & u, Vector const & v){
  // int dim = u.dim();
  // double vv[dim];
  // for(int i =1; i<=u.dim();i++)
  //   vv[i-1] = u.at(i) - v.at(i);
  // return Vector(vv, dim);
  Vector r(u);
  r.subtract(v);
  return r;
}

Vector operator +(Vector const & u, Vector const & v){
  Vector r(u);
  r.add(v);
  return r;
}

double distance(Vector const & u, Vector const & v)
{
  return (u-v).length();
}

double area(Vector const & u, Vector const & v, Vector const & w) {
  double a = (v-u).length();
  double b = (w-v).length();
  double c = (u-w).length();

  double s = (a+b+c)/2;

  return sqrt(s*(s-a)*(s-b)*(s-c));

}

double area(Vector a[], int sides){
  double sum = 0;
  for(int i = 1; i <= sides-2; i++){
    sum += area(a[0], a[i], a[i+1]);
  }

  return sum;
}

size_t stripDecorators(std::string & st)
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

Vector createVectorFromStringOfNumbers(std::string const & s){
  std::string st(s);
  size_t dim = stripDecorators(st);
  std::stringstream ss(st);
  double a[dim];
  for (int i=0; i< dim; i++)
    ss >> a[i];

  return Vector(a,dim);

}

Vector centroid(Vector vec[], int sides)
{
  double arr[vec[0].dim()];
  for(int i = 0; i < vec[0].dim(); i++)
  {
    arr[i] = 0;
  }
  Vector scen(arr, vec[0].dim());

    for(int i = 0; i< sides; i++)
    {
      scen = scen + vec[i];
    }

  for(int i = 1; i <= scen.dim(); i++)
  {
    scen.at(i) /= sides;
  }
  return scen;
}
double angle(Vector const & u, Vector const & v)
{
  return acos(dot(u,v)/(u.length()*v.length()));
}

#endif
