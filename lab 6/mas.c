#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill(int n, int a[])
{
   int i;
   for (i = 0; i < n; i++)
      a[i] = rand() % 40 - 19;
}

int main()
{
   srand(time(NULL));
   int n;
   printf("dly 1 mas -> ");
   scanf("%d", &n);
   int A[n];
   fill(n, A);
   int i;
   for (i = 0; i < n; i++)
      printf("%4d", A[i]);
   printf("\n");

   srand(time(NULL));
   int n1;
   printf("dly 2 mas -> ");
   scanf("%d", &n1);
   int B[n1];
   fill(n1, B);
   int i1;
   for (i1 = 0; i1 < n1; i1++)
      printf("%4d", B[i1]);
   printf("\n");

   int l = 0;
   for (int k = 0; k < n; k++)
      for (int u = 0; u < n1; u++)
         if (A[k] == B[u])
         {
            l++;
            break;
         };
   for (int k = 0; k < n1; k++)
      for (int u = 0; u < n; u++)
         if (B[k] == A[u])
         {
            l++;
            break;
         };
   int yup = (n + n1) - l;
   printf("yup = %d \n", yup);

   int C[yup];
   int k = 0;
   do
   {
      for (int y = 0; y < n; y++)
      {
         for (int u = 0; u < n1; u++)
         {
            if (A[y] != B[u])
               C[k] = A[y];
            else
            {
               k--;
               u = n1;
            };
         };
         k++;
      };
      for (int y = 0; y < n1; y++)
      {
         for (int u = 0; u < n; u++)
         {
            if (B[y] != A[u])
            {
               C[k] = B[y];
            }
            else
            {
               k--;
               u = n;
            };
         };
         k++;
      };
   } while (k < yup);

   for (int k = 0; k < yup; k++)
      printf("C[%d]: %d     ", k, C[k]);
   printf("\n");

   return 0;
}
