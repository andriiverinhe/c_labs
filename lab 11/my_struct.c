#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct cp {
    char name[256];
    char Processor[100];
    unsigned int RAM;
    unsigned int HDD;
    char video_adapter[100];
    unsigned int price;
    unsigned int year_purchases;
};

void add_note(struct cp computer[], int n)
{
    int HDD;
    int price;
    int RAM;
    int year_purchases;


    char* note = (char *)malloc(sizeof(char)* 100);
    
    printf("Enter name: ");
    fgets(note, 100, stdin);
    note[strlen(note) - 1] = 0;
    sprintf(computer[n].name, "%s", note);

    printf("Enter Processor: ");
    fgets(note, 100, stdin);
    note[strlen(note) - 1] = 0;
    sprintf(computer[n].Processor, "%s", note);

    printf("Enter RAM: ");
    scanf("%d", &RAM);
    fgets(note, 10, stdin);
    computer[n].RAM = RAM;

    printf("Enter HDD: ");
    scanf("%d", &HDD);
    fgets(note, 10, stdin);
    computer[n].HDD = HDD;

    printf("Enter video_adapter: ");
    fgets(note, 100, stdin);
    note[strlen(note) - 1] = 0;
    sprintf(computer[n].video_adapter, "%s", note);

    printf("Enter price: ");
    scanf("%d", &price);
    fgets(note, 10, stdin);
    computer[n].price = price;

    printf("Enter year_purchases: ");
    scanf("%d", &year_purchases);
    fgets(note, 10, stdin);
    computer[n].year_purchases = year_purchases;
    


}

void all_notes(struct cp computer[], int n)
{

    for (int i = 0; i < n; i++)
        printf("%d note: name: %s, Proccesor: %s, RAM: %d, HDD: %d, video_adapter: %s, price: %d, year_purchases: %d,\n", i + 1, computer[i].name, computer[i].Processor, computer[i].RAM, computer[i].HDD, computer[i].video_adapter, computer[i].price, computer[i].year_purchases);
}



void del_note(struct cp computer[], int n, int del)
{
    for (int i = del; i < n - 1; i++)
    {
        struct cp temp = computer[i];
        computer[i] = computer[i + 1];
        computer[i + 1] = temp;
    }
}


int main() {
    int count = 2;
    int del;
    char* query = (char*)malloc(sizeof(char) * 100);
    struct cp computer[20];

    sprintf(computer[0].name, "%s", "Apple");
    sprintf(computer[0].Processor, "%s", "Intel Core i7");
    sprintf(computer[0].video_adapter, "%s", "est");
    computer[0].RAM = 8;
    computer[0].HDD = 5;
    computer[0].price = 40000;
    computer[0].year_purchases = 2015;

    sprintf(computer[1].name, "%s", "Asuse");
    sprintf(computer[1].Processor, "%s", "Intel Core i9");
    sprintf(computer[1].video_adapter, "%s", "est");
    computer[1].RAM = 16;
    computer[1].HDD = 8;
    computer[1].price = 70000;
    computer[1].year_purchases = 2019;

    printf("________________________________________________________\n\nEnter \"q\" if you watn to quit\n");
    printf("Enter \"add\" if you want to add a new note\n");
    printf("Enter \"del (number note)\" if you want to delete a note\n");
    printf("Enter \"ls\" if you want to see all notes\n_________________________________________________________\n\n");

        while (strcmp(query, "q"))
    {
        for(int i =0; i < count;i++)
            if (computer[i].year_purchases < 2020)
                printf("update comp from %s\n", computer[i].name);
                
        
        printf("-> ");
        fgets(query, 100, stdin);
        query[strlen(query) - 1] = 0;
        if (!strcmp(query, "add"))
        {
            add_note(computer, count);
            count++;
        }
        else if (!strcmp(query, "ls"))
            all_notes(computer, count);
        else if (!strcmp(query, "del"))
        {
            printf("Enter a number of note you want to delete -> ");
            scanf("%d", &del);
            fgets(query, 10, stdin);
            del_note(computer, count, del - 1);
            count--;
        }
    }



    return 0;
}
