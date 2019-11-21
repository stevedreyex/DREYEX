#include <string>
#include <cmath>
int dot(int u[], int v[], int m, int n) {
  if (m != n) {
    throw std::string("Can't do");
  }
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += u[i] * v[i];
  return sum;
}
int getDim(Vector vec)
{
    return vec._dim;
}

bool isZero(Vector vec)
{
    for(int i=0; i<vec._dim; i++)
    {
        if(vec._v[i] == 0)
        {
            return 1;
        }        
    }
    return 0;
}

double length(Vector vec)
{
    int sum = 0;
    for(int i=0; i<vec._dim; i++)
    {
        sum = sum + vec._v[i]*vec._v[i];
    }
    return sqrt(sum);
}
//the rest of function should be written below