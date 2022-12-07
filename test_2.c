#include <stdio.h>
#include <termios.h>
#include <unistd.h>
int main()
{
    char str[] = {0};
    scanf("%s", str);
    printf("%s", str);
}
