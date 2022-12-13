#include <stdio.h>
#include <locale.h>

void main()
    {
    setlocale(LC_ALL, "Ru");

    int a = 0, b = 0, acc = 0;
    int i = 1;
    printf("Введите a = ");
    scanf("%i",&a);
    printf("Введите b = ");
    scanf("%i", &b);

    while (a != 0)
    {
        acc += a%10;
        a /= 10;
    }
    a = acc;
    acc = 0;

    if(a == b){
        printf("Сумма цифр = b");
    }
    else {
    if (a>b) {
        printf("Сумма цифр числа a = %d", a);
    }
    else
    {
         printf("Сумма цифр числа a + b = %d",a+b);
}}}
