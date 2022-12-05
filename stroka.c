#include <stdio.h>
#include <string.h>
int main()
{

    char str[] = "Vicariously I live while the whole world";
    char delim[] = " "; 
    char *p = strtok(str, delim);
 //   int i;
    char **p2[7];
    int j = 0;
while(p != NULL)
{
    p2[j] = &p;
    printf("%p \n",&p2[j]);
    j++;

    
//    printf("%s \n",p);
//    i = strlen(p);
//    printf("%p",&p);

//    printf("i = %d\n", i);
    p = strtok(NULL, delim);
    
};

    return 0;
}