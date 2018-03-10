#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

#define NAME 15
#define SEX 5
#define PHONE 15
#define ADDRESS 30
#define MAX 1000

typedef struct people
{
	char name[NAME];
	char sex[SEX];
	int age;
	char phone[PHONE];
	char address[ADDRESS];
}PeopleList;

typedef struct Book
{
	PeopleList people[MAX];
	int count;
}PBook,*PB;

void menu();
void ExitBook();		
void ShownBook(PB pbook);
void AddBook(PB pbook);
void Delate(PB pbook);
int SearchName(PB pbook, const char* name);
void FindBook(PB pbook);
void Empty(PB pbook);
void ModifyBook(PB pbook);
void SortBook(PB pbook);
void Load(PB pbook);