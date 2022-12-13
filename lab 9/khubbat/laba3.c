#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>

void main()
{
setlocale(LC_ALL, "Ru");

double x;
printf("Введите значение x: ");
scanf("%lf",&x);
printf("%lf\tf(%lf)",x,x);
printf("\n----------------------------\n");
for (double i = 0; i <= 1; i+=x) {
printf("\n%lf\t%lf", i, cos(i + pow(i, 3)));
}
printf("\n\n%lf\tf(%lf)", x, x);
printf("\n----------------------------\n");
for (double i = 1; i <= 2; i+=x)
{
printf("\n%lf\t%lf",i,exp(-i*-i)-i*i+2*i);
}
}
