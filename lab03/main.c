#include <stdio.h>
#include <math.h>

int main()
{
   double x = 0;
   double h = 0;
   printf("Enter h -> ");
   scanf("%lf", &h);
  

   while (0 <= x && x <= 2)
   {
      if (0 <= x && x <= 1)
      {
         printf("______________\n");
         printf("x = %lf \n", x);
         double f = -cos(x) * exp(x);
         printf("f(x) = %lf \n", f);
         x += h;
      }
      else if (1 < x && x <= 2)
      {
         printf("______________\n");
         printf("x = %lf \n", x);
         double f = log(2 * x + sin(x * x));
         printf("f(x) = %lf \n", f);
         x += h;
      };
   }
/*
   for (int x = 0; 0 <= x && x <= 2; x += h)
   {
      if (0 <= x && x <= 1)
      {
         printf("x = %lf \n", x);
         double f = -cos(x) * exp(x);
         printf("f(x) = %lf \n", f);
      }
      else if (1 < x && x <= 2)
      {
         printf("x = %lf \n", x);
         double f = log(2 * x + sin(x * x));
         printf("f(x) = %lf \n", f);
      };
   };
*/
   return 0;
}
