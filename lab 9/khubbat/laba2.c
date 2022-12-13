#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>

void main()
{
setlocale(LC_ALL, "Ru");
double x;
again:
printf("Введите значение x { -1.0 <= x <= 1.0 }: ");
scanf("%lf",&x);
if (-1 <= x && x <= 1) {
double y = log((1+x)/(1-x));
double z = (y * y) / (1 + y);
printf("y(x) = %lf\nz(y) = %lf",y,z);
}
else {
printf("Значение x некорректно.\n");
goto again;
}
}