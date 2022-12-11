#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void fill(int n, int m, float **array);
void sum_of_element(int size_1, int size_2, float **array, float max_element);
int mux_of_element_in_array(int size_1, int size_2, float **array);
void sum_of_element_2(int size_1, int size_2, int comparable_element, float **array, float max_element);
void sum_of_element_3(int size_2, int comparable_element, int counter_1, int counter_2, float **array, float max_element);

int main()
{
   int n;
   printf("Enter the number of lines -> ");
   scanf("%d", &n);
   int m;
   printf("Enter number of coluns -> ");
   scanf("%d", &m);

   float **A = (float **)malloc(n * sizeof(float *));
   for (int i = 0; i < n; i++)
   {
      A[i] = (float *)malloc(m * sizeof(float));
      //   if (!a[i])
      //      fail();
   }

   fill(n, m, A);

   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
         printf("%.2f    ", A[i][j]);
      printf("\n");
   };
   float max_element = mux_of_element_in_array(n, m, A);
   printf("max_element = %f\n", max_element);
   int counter_1 = 0;
   int counter_2 = 1;

   sum_of_element_3(m, m - 1, counter_1, counter_2, A, max_element);
   sum_of_element_3(m, n, counter_2, counter_1, A, max_element);
   sum_of_element(n, m, A, max_element);
   sum_of_element_2(n, m, m - 1, A, max_element);
   sum_of_element_2(n, m, m - 2, A, max_element);
   sum_of_element_2(n, m, m, A, max_element);

   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
         printf("    %.2f", A[i][j]);
      printf("\n");
   }

   for (int i = 0; i < n; i++)
      free(A[i]);
   free(A);
   return 0;
}
void fill(int size_1, int size_2, float **array)
{
   srand(time(NULL));
   int i;
   for (i = 0; i < size_1; i++)
      for (int j = 0; j < size_2; j++)
         array[i][j] = rand() % 101 - 50;
}

int mux_of_element_in_array(int size_1, int size_2, float **array)
{
   int max_element = 0;
   for (int i = 0; i < size_1; i++)
      for (int j = 0; j < size_2; j++)
         if (abs(array[i][j]) > abs(max_element))
            max_element = array[i][j];
   return max_element;
}

void sum_of_element(int size_1, int size_2, float **array, float max_element)
{
   for (int i = 0; i < size_1; i++)
      for (int j = 0; j < size_2; j++)
         if (i == j)
            array[i][j] /= max_element;
}

void sum_of_element_3(int size_2, int comparable_element, int counter_1, int counter_2, float **array, float max_element)
{
   while (counter_1 < comparable_element)
   {
      array[counter_1][counter_2] /= max_element;
      ;
      counter_1++;
      counter_2++;
   }
}

void sum_of_element_2(int size_1, int size_2, int comparable_element, float **array, float max_element)
{
   for (int i = 0; i < size_1; i++)
      for (int j = 0; j < size_2; j++)
         if (comparable_element == i + j)
            array[i][j] /= max_element;
}