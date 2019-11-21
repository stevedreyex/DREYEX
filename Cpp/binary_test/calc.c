#include<stdio.h>
int main()
{
  int num = 89;
  int a[] = {0,0,0,0,0,0,0,0};
  for(int i = 1; i <= 8; i++)
  {
    a[8-i] = num % 2;
    num /= 2;
  }
  for (int i = 0; i < 8; i++) {
    printf("%d", a[i]);
  }
  return 0;
}
