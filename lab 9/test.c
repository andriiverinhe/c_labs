#include <stdio.h>
#include <string.h>

int size_str(char *str);
void rozb_strok(char * p, char ** p2, int size, char *delim);
void choise_words(char ** p2,int * size_new_string,int * letters_in_word, int size);
void new_string_func(char *new_string,char ** p2,int size_new_string,int letters_in_word,int size);


int main()
{   
    char str[1000];
    scanf("%100[^\n\r]", str);
    

    int size = size_str(str);

    char delim[] = " "; 
    char *p = strtok(str, delim);

    char *p2[size];
    rozb_strok(p, p2, size, delim);


    int size_new_string = 1;
    int letters_in_word = 0;
    int * ps = &size_new_string;
    int * pl = &letters_in_word;
    choise_words(p2, ps, pl, size);


    printf("size_new_string %d\n", size_new_string);
    printf("letters_in_word %d\n", letters_in_word);


    
    char new_string[100] = {0};
    new_string_func(new_string, p2, size_new_string, letters_in_word, size);

    printf("%s.\n", new_string);
    printf("%ld.\n", strlen(new_string));



return 0;
}

int size_str(char *str)
{
    int i = 0;
    int size = 0;
    while(str[i] != '\0')
    {
        i++;
        if(str[i] == ' ' && str[i] != '\0')
        size++;
    }
    return size + 1;
}

void rozb_strok(char * p, char ** p2, int size, char *delim)
{
    for(int i = 0; i < size;i++)
    {
        if(p != NULL)
        {
            printf("p = %s\n", p);
            p2[i] = p;
            printf("p2 = %s \n",p2[i]);
            p = strtok(NULL, delim);
        }
    }
}

void choise_words(char ** p2,int * size_new_string,int * letters_in_word, int size)
{
    int perem1 = 0;
    int A[size];
    for(int i = 0; i < size;i++)
        A[i] = strlen(p2[i]);


    for(int i = 0; i < size;i++)
        {
        perem1 = 0;
        for(int k = 0; k < size + 1;k++)
            if(A[i] == A[k])
                perem1 += 1;

        perem1 -= 1;
        if(perem1 > *size_new_string)
            {
            *letters_in_word = A[i];
            *size_new_string = perem1;
            }
        }
} 

void new_string_func(char *new_string,char ** p2,int size_new_string,int letters_in_word,int size)
{
            for(int i = 0; i < size;i++)
            {
                if(strlen(p2[i]) != letters_in_word)
                    {

                            strcat(new_string, p2[i]);
                            strcat(new_string, " ");
                          
                    }
            }

        new_string[strlen(new_string) - 1] = '\0';

}