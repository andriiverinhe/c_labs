#include <stdio.h>
int func_addition(int a, int b);
int func_recurs_addirion(int a, int b);

int main()
{
   int a;
   printf("Enter number: ");
   scanf("%d", &a);
   int b;
   printf("Enter number: ");
   scanf("%d", &b);

   int multiplication_func = func_addition(a, b);
   printf("multiplication_func = %d\n", multiplication_func);

   int multiplication_recurs = func_recurs_addirion(a, b);
   printf("multiplication_recurs = %d\n", multiplication_recurs);

   return 0;
}

int func_addition(int a, int b)
{
   int sum = 0;
   if (b >= 0)
   {
      for (int k = 0; k < b; k++)
         sum += a;
   }
   else
   {
      for (int k = 0; k < -b; k++)
         sum += a;
      sum *= -1;
   }
   return sum;
}

int func_recurs_addirion(int a, int b)
{
   if (b == 1)
      return a;
   else if (b == -1)
      return -a;
   else if (b < 0)
      return -a + func_recurs_addirion(a, b + 1);
   else
      return a + func_recurs_addirion(a, b - 1);
}
