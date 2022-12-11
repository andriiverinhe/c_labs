#include <malloc.h>
#include <stdio.h>
#define n 10
#define m 10

void pipu(float **a)
{
   for (int k = 0; k < n; k++)
   {
      for (int l = 0; l < m; l++)
         printf("%.2f   ", a[k][l]);
      printf("\n");
   }
}
int main()
{

   float **a = (float **)malloc(n * sizeof(float *));
   // if (!a)
   //    fail();
   int i, j;

   for (i = 0; i < n; i++)
   {
      a[i] = (float *)malloc(m * sizeof(float));
      //   if (!a[i])
      //      fail();
   }
   for (i = 0; i < n; i++)
      for (j = 0; j < m; j++)
         a[i][j] = i * m + j + 1.1;

   pipu(a);

   for (i = 0; i < n; i++)
      free(a[i]);
   free(a);

   return 0;
}