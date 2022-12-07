#include <stdio.h>
#include <string.h>
int main()
{
    char str[] = "Vicariously I live while the whole world";
    int m = 0;
    int size = 0; 
    while(str[m] != '\0')
    {
        m++;
        if(str[m] == ' ' && str[m] != '\0')
            size++;  
    }
    char delim[] = " "; 
    char *p = strtok(str, delim);
    //int j;
    char *p2[size + 1];
    for(int i = 0; i <= size;i++)
    {
        if(p != NULL)
        {
            p2[i] = p;
            printf("%s \n",p2[i]);
            p = strtok(NULL, delim);
        }
    }
    int perem = 0;
    int perem1 = 0;
    int word = 0;
    int A[size + 1];
    for(int i = 0; i <= size;i++)
        A[i] = strlen(p2[i]);
    for(int i = 0; i <= size;i++)
        {
        perem1 = 0;
        for(int k = 0; k <= size;k++)
            {
                if(A[i] == A[k])
                    perem1 += 1;
            }
        if(perem1 > perem)
            {
            word = A[i];
            perem = perem1;
            }
        }


    printf("peremen %d\n", perem);
    printf("word %d\n", word);

        char new_string[4] = "";
        for(int i = 0; i <= size;i++)
            {
                if(strlen(p2[i]) != word)
                    {
                    strcat(new_string, p2[i]);
                    strcat(new_string, " ");
                    }
            }

        new_string[strlen(new_string) - 1] = '\0';
        printf("%s.\n", new_string);
        printf("%ld.\n", strlen(new_string));
        
    return 0;
}







//    printf("%s \n",p);
//    i = strlen(p);
//    printf("%p",&p);
//    printf("i = %d\n", i);