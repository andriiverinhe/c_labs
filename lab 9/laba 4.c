#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
int Fib(int a) {
if (a < 1) return 0;
if (a == 1) return 1;
return Fib(a - 1) + Fib(a - 2);
}
void main()
{
//Настройка боярышника
int adrs;
setlocale(LC_ALL, "Ru");
srand(time(NULL) + &adrs);
//Сам код
int a;
printf("Введите кол-во итераций: ");
scanf("%d",&a);
printf("Число Фибоначчи в %d итераций равно %d",a,Fib(a));
}