#include <stdio.h>
#include <math.h>

float func(double h, double n, double f, double a, double b);

int main()
{
   // Границы промежутка
   double a = 0;
   double b = 2;
   double f = 0;
   // n - количество итераций
   int n = 1;
   int n2 = 1;

   double integral_1 = 0;
   double integral_2 = 0;
   // h - шаг
   double h = 0;
   double h2 = 0;

   double accuracy = 0;
   printf("Enter accuracy: ");
   scanf("%lf", &accuracy);
   double delta_integral = 1;
   do
   {
      n = n2;
      n2 = n * 2;

      h = (b - a) / n;
      h2 = (b - a) / n2;
      integral_1 = func(h, n, f, a, b);
      integral_2 = func(h2, n2, f, a, b);

      delta_integral = (integral_2 - integral_1) / 3;

   } while (delta_integral >= accuracy || -delta_integral >= accuracy);
   printf("delta_integral = %lf\n", delta_integral);
   printf("integral_1 = %lf\n", integral_1);
   printf("integral_2 = %lf\n", integral_2);

   return 0;
}

float func(double h, double n, double f, double a, double b)
{

   double I = 0;

   double x = 0;

   for (int k = 0; k <= n; k++)
   {
      x += h;

      if (x > a && x <= (b / 2))
         f = -cos(exp(x));
      else if (x > (b / 2) && x <= b)
         f = log(2 * x + sin(x * x));
      I = I + f * h;
   }

   return I;
}