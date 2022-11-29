#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void fill(int n, int m, int (*a)[m]);
int sum_of_element(int size_1, int size_2, int (*array)[size_2]);
int mux_of_element_in_array(int size_1, int size_2, int (*array)[size_2]);
int sum_of_element_2(int size_1, int size_2, int comparable_element, int (*array)[size_2]);
int sum_of_element_3(int size_2, int comparable_element, int counter_1, int counter_2, int (*array)[size_2]);

int main()
{
   int n;
   printf("Enter the number of lines -> ");
   scanf("%d", &n);
   int m;
   printf("Enter number of columns -> ");
   scanf("%d", &m);

   int A[n][m];

   fill(n, m, A);

   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
         printf("%4d", A[i][j]);
      printf("\n");
   };
   float max_element = mux_of_element_in_array(n, m, A);
   printf("max_element = %f\n", max_element);
   int counter_1 = 0;
   int counter_2 = 1;
   float sum_element = sum_of_element_3(m, m - 1, counter_1, counter_2, A) + sum_of_element_3(m, n, counter_2, counter_1, A) + sum_of_element(n, m, A) + sum_of_element_2(n, m, m - 1, A) + sum_of_element_2(n, m, m - 2, A) + sum_of_element_2(n, m, m, A);
   printf("sum_element = %f\n", sum_element);
   printf("resuel = %f\n", max_element / sum_element);
   return 0;
}

void fill(int size_1, int size_2, int (*a)[size_2])
{
   srand(time(NULL));
   int i;
   for (i = 0; i < size_1; i++)
      for (int j = 0; j < size_2; j++)
         a[i][j] = rand() % 101 - 50;
}

int mux_of_element_in_array(int size_1, int size_2, int (*array)[size_2])
{
   int max_element = 0;
   for (int i = 0; i < size_1; i++)
      for (int j = 0; j < size_2; j++)
         if (abs(array[i][j]) > abs(max_element))
            max_element = array[i][j];
   return max_element;
}

int sum_of_element(int size_1, int size_2, int (*array)[size_2])
{
   int sum_element = 0;
   for (int i = 0; i < size_1; i++)
      for (int j = 0; j < size_2; j++)
         if (i == j)
            sum_element += array[i][j];
   return sum_element;
}

int sum_of_element_3(int size_2, int comparable_element, int counter_1, int counter_2, int (*array)[size_2])
{
   int sum_element = 0;
   while (counter_1 < comparable_element)
   {
      sum_element += array[counter_1][counter_2];
      counter_1++;
      counter_2++;
   }
   return sum_element;
}

int sum_of_element_2(int size_1, int size_2, int comparable_element, int (*array)[size_2])
{
   int sum_element = 0;
   for (int i = 0; i < size_1; i++)
      for (int j = 0; j < size_2; j++)
         if (comparable_element == i + j)
            sum_element += array[i][j];
   return sum_element;
}