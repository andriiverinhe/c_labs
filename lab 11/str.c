#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
// element settings:
char* year;
char* Title;
char* Director;
char* Country;
char* Actors;

// list settings:
struct node* next;
struct node* prev;
};

struct node struct node *head;
struct node *KillbyName (struct node *head, char name[]);
struct node *KillTail (struct node *head);
void ChecktheClaws(struct node *head);
void ActorsMovies (struct node *head, char name[]);
struct node char title[, char director[, char country[, char actr[, char year[;
struct node struct node *head, char title[, char director[, char country[, char actr[, char year[;
struct node struct node *head;

struct node char title[, char director[, char country[, char actr[, char year[
{
struct node *Movie1 = malloc(sizeof(struct node));
Movie1->Actors = actr;
Movie1->Director = director;
Movie1->Country = country;
Movie1->Title = title;
Movie1->year = year;
Movie1->next = NULL;
Movie1->prev = NULL;
return Movie1;
}

struct node struct node *head, char title[, char director[, char country[, char actr[, char year[
{
if(head == NULL) return SetonFire(title, director, country, actr, year);

struct node *Movie1 = malloc(sizeof(struct node));

while(head->next != NULL)
{
head = head->next;
}

Movie1->Actors = actr;
Movie1->Director = director;
Movie1->Country = country;
Movie1->Title = title;
Movie1->year = year;
Movie1->next = NULL;
Movie1->prev = head;
head->next = Movie1;

while(head->prev != NULL)
{
head = head->prev;
}

return head;
}

struct node *KillbyName(struct node *head, char name[])
{
do
{
if (strcmp(head->Title, name) == 0)
{
if (head->next == NULL && head->prev == NULL)
{
return FreeList(head);
}
if (head->next == NULL)
{
head->prev->next = NULL;
free(head);
}
if (head->prev == NULL)
{
return KillHead(head);
}
head->prev->next = head->next;
head = head->prev;
free(head->next->prev);
head->next->prev = head;
while(head->prev != NULL)
head = head->prev;
return head;
}
head = head->next;
}
while(head->next != NULL);

printf("There is no such movie in our list\n");

while(head->prev != NULL)
head = head->prev;

return head;
}

struct node struct node *head
{
head = head->next;

free(head->prev);

head->prev = NULL;

return head;
}

struct node *KillTail(struct node *head)
{
if(head->next == NULL)
{
free(head);
return NULL;
}
while(head->next != NULL)
head = head->next;

head = head->prev;

free(head->next);

head->next = NULL;

while(head->prev != NULL)
head = head->prev;

return head;
}

struct node struct node *head
{
while(head->next != NULL)
{
head = head->next;
}

while(head->prev != NULL)
{
head = head->prev;
free(head->next);
}

free(head);
return NULL;
}

void ChecktheClaws(struct node *head)
{
printf("Movie:\t %s\nYear:\t %s\nCountry: %s\nDirector: %s\nStars:\t %s\n\n", head->Title, head->year, head->Country, head->Director, head->Actors);
while(1)
{
if (head->next == NULL)
{
break;
}
head = head->next;
printf("Movie:\t %s\nYear:\t %s\nCountry: %s\nDirector: %s\nStars:\t %s\n\n", head->Title, head->year, head->Country, head->Director, head->Actors);
}
}

void ActorsMovies(struct node *head, char name[])
{
int i = 0;
while(1)
{
if(strstr(head->Actors, name) != NULL)
{
i++;
printf("Movie:\t %s\nYear:\t %s\nCountry: %s\nDirector: %s\nStars:\t %s\n\n", head->Title, head->year, head->Country, head->Director, head->Actors);
}
if (head->next == NULL) break;
head = head->next;
}
if(i == 0) printf("No such actor in our data base\n");
}

int main()
{
struct node *Head = SetonFire("Django Unchained", "Quentin Tarantino", "USA", "Jamie Foxx, Christoph Waltz, Leonardo DiCaprio, Kerry Washington, Samuel L. Jackson", "2012");
Head = Append(Head, "February", "Oz Perkins", "USA", "Emma Roberts, Kiernan Shipka, Lucy Boynton, James Remar, Lauren Holly", "2015");
Head = Append(Head, "Terminator 2: Judgment Day", "James Cameron", "USA","ArnoldSchwarzenegger, Linda Hamilton, Edward Furlong, Robert Patrick", "1991");
Head = Append(Head, "Terminator", "James Cameron", "USA", "Arnold Schwarzenegger, Michael Biehn, Linda Hamilton", "1984");
Head = Append(Head, "Fate/stay night Movie: Heaven's Feel - I. Presage Flower", "Tomonori Sudou", "Japan", "Noriaki Sugiyama, Noriko Shitaya, Ayako Kawasumi, Kana Ueda", "2018");
Head = Append(Head, "Deftones - My Own Summer (Official Music Video)", "Dean Karr", "USA", "Chino Moreno, Stephen Carpenter, Chi Cheng, Abe Cunningham", "1997");

printf("BASE\n");

ChecktheClaws(Head);

getchar();

printf("ACTOR Arnold Schwarzenegger\n");

ActorsMovies(Head, "Arnold Schwarzenegger");

getchar();

printf("Tail got Killed\n");

Head = KillTail(Head);

ChecktheClaws(Head);

getchar();

printf("February got Killed\n");

Head = KillbyName(Head, "February");

ChecktheClaws(Head);

getchar();

printf("Head got Killed\n");

Head = KillHead(Head);

ChecktheClaws(Head);

FreeList(Head);

return 1;
}