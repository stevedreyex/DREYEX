/* hw15_8.c */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void show_decimal(char *,int);
int main(void)
{  
   char arr[7]={'1','0','1','1','0','1','1'};
   
   show_decimal(arr,7);
    
   system("pause");
   return 0;
}
void show_decimal(char arr[],int n)
{
   int i,dec=0;

   for(i=0;i<n;i++)
      dec=dec+(arr[i]-48)*pow(2,n-i-1);
      
   printf("1011011的十進位為%d\n",dec);
}

/* output-------------
1011011的十進位為91
--------------------*/
