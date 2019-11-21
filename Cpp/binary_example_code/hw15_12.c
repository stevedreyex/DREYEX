/* hw15_12.c */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 8
void show_binary(int);
int main(void)
{   
   int a;
   a=(89>>2);
   
   printf("89二進位的值為: ");
   show_binary(89);
   printf("右移二個位元後: ");
   show_binary(a);
   printf("右移二個位元後的值為: %d\n",a);
      
   system("pause");
   return 0;
}
void show_binary(int num)
{
   int i,b[SIZE]={0};
   for(i=1;i<=SIZE;i++)
   {
      b[SIZE-i]=num%2;
      num/=2;
   }
   for(i=0;i<SIZE;i++)
      printf("%d",b[i]);
   printf("\n");
}

/* output-----------------
89二進位的值為: 01011001
右移二個位元後: 00010110
右移二個位元後的值為: 22
------------------------*/
