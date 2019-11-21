/* hw15_11.c */
#include <stdio.h>
#include <stdlib.h>
int main(void)
{  
   int a=154,b=67;   
   
   printf("%d&%d=%d\n",a,b,a&b);
   printf("%d|%d=%d\n",a,b,a|b);
   printf("%d^%d=%d\n",a,b,a^b);
   
   system("pause");
   return 0;
}

/* output------
154&67=2
154|67=219
154^67=217
-------------*/
