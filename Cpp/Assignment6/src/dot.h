#ifndef DOT_H
#define DOT_H
#include "vector.h"
#include "bubblesort.h"
#include <ctype.h>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

void sameDim(Vector u, Vector v)
{
  if(u.dim() != v.dim())
  {
    throw "Invalid Input";
  }
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

Vector centroid(Vector vec[], int sides)
{
  double arr[vec[0].dim()];
  for(int i = 0; i<vec[0].dim(); i++)
  {
    arr[i] = 0;
  }
  Vector scen(arr, vec[0].dim());

  for(int i = 0; i < sides; i++)
  {
    scen = scen + vec[i];
  }
  for(int i = 1; i<=scen.dim(); i++)
  {
    scen.at(i) /= sides;
  }
  return scen;
}

double dim2_cross(Vector u, Vector v)
{
  sameDim(u, v);
  return u.at(1)*v.at(2)-u.at(2)*v.at(1);
}

double angle(Vector const & u, Vector const & v)
{
  if(u.length() == 0 || v.length() == 0)
  {
    throw "There's no such an angle";
  }
  else if(asin(dim2_cross(u, v)/(u.length()*v.length()))>=0)
  {
    return acos(dot(u,v)/(u.length()*v.length()));
  }
  else
  {
    return -2*M_PI + acos(dot(u,v)/(u.length()*v.length()));
  }
}

void move_centroid_to_zero(Vector * arr, int sides)
{
  Vector cent = centroid(arr, sides);
  for(int i = 0; i<sides; i++)
  {
    arr[i] = arr[i] - cent;
  }
}

// double angle_with_starter(Vector vec[], int sides, int side)
// {
//   Vec
//   for(int i = 0; i<sides; i++)
//   {
//
//   }
//   return angle(vec[0], vec[side-1]);
// }

double convexPolygonArea(Vector vec[],int sides)
{
  move_centroid_to_zero(vec, sides);
  bubbleSort(vec, vec + sides, [vec](Vector u, Vector v){return angle(*vec, u) < angle(*vec, v);});
  return area(vec, sides);
}

#endif
