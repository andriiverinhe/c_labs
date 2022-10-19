#include <stdio.h>

int main()
{
   float d1, d2, d3;
   printf("Enter d1 -> ");
   scanf("%f", &d1);
   printf("Enter d2 -> ");
   scanf("%f", &d2);
   printf("Enter d3 -> ");
   scanf("%f", &d3);
   float max_element = 0;
   float min_element = 0;
   float difference = 0;
   float division = 0;
   if (d1 > d2 && d1 > d3)
   {
      max_element = d1;
      printf("max_element = %f\n", max_element);
      if (d2 > d3)
      {
         min_element = d3;
         printf("min_element = %f\n", min_element);
      }
      else
      {
         min_element = d2;
         printf("min_element = %f\n", min_element);
      };
      difference = max_element - min_element;
      printf("difference = %f \n", difference);
   }
   else if (d2 > d1 && d2 > d3)
   {
      max_element = d2;
      printf("max_element = %f\n", max_element);
      if (d1 > d3)
      {
         min_element = d3;
         printf("min_element = %f\n", min_element);
      }
      else
      {
         min_element = d1;
         printf("min_element = %f\n", min_element);
      };
      division = min_element / max_element;
      printf("division = %f \n", division);
   }
   else if (d3 > d1 && d3 > d2)
   {
      max_element = d3;
      printf("max_element = %f\n", max_element);
      if (d2 > d1)
      {
         min_element = d1;
         printf("min_element = %f\n", min_element);
      }
      else
      {
         min_element = d2;
         printf("min_element = %f\n", min_element);
      };
      difference = max_element - min_element;
      printf("difference = %f \n", difference);
   };

   return 0;
}