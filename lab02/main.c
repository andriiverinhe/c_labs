#include <stdio.h>
#include <math.h>

int main()
{
#define pi 3.14
   double x;
   printf("Enter x (x > 0) -> ");
   scanf("%lf", &x);
   if (x > 0)
   {
      {
         double y = sqrt(x) / sin(pi * x);
         printf("y = %lf ", y);
         //         Отсутствует:
         //         double z = sign(y);
         //         printf("y = %lf ", z);
      };
   }
   else
      printf("x value is incorrect!\n");

   return 0;
}
