// DATA STRUCTURE SESI 5-6

// STACK AND QUEUE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode
{
	char name[25];
	int priority;
	int age;
	struct tnode *next, *prev;
}*head = NULL, *tail = NULL;

void queue(char *name, int priority, int age)
{
	tnode *newNode = (tnode*) malloc(sizeof(tnode));
	strcpy(newNode->name, name);
	newNode->priority = priority;
	newNode->age = age;
	newNode->next = newNode->prev = NULL;
	
	if(head == NULL) head = tail = newNode;
	else
	{
		tnode *curr = head;
		while(curr != NULL && curr->priority)
	}
}

void mainMenu(int n)
{
	if(head == NULL)
	{
		printf("Patient: 0 people(s)\n\n");
	}
	else
	{
		printf("Patient: %d people(s)\n\n");
	}
	
	puts("Quasar Queue 1.3");
	puts("================");
	puts("1. Add Patient");
	puts("2. Call Patient");
	puts("3. Remove All Patient List");
	puts("4. Exit");
	printf("Select [1..4]: ");
}

void menu1()
{
	
	char name[25];
	printf("Input Patient Name [1..25]: ");
	scanf("%s", name); getchar();
	
	int priority;
	puts("1. Emergency");
	puts("2. Super VIP");
	puts("3. VIP");
	puts("4. Basic");
	printf("Select Class [1..4]: ");
	scanf("%d", &priority);
	puts("");
	
	int age;
	printf("Input Age [1..110]: ");
	scanf("%d", &age);
	puts("");
	
	puts("Quasar Hospital Queue");
	puts("----------------------------------------------------");
	
	switch(priority)
	{
		case 1:
		{
			printf("Emergency | %s <%d>\n", name, age);
			break;
		}
		case 2:
		{
			printf("Super VIP | %s <%d>\n", name, age);
			break;
		}
		case 3:
		{
			printf("VIP | %s <%d>\n", name, age);
			break;
		}
		case 4:
		{
			printf("Basic | %s <%d>\n", name, age);
			break;
		}
	}
}

void menu2()
{
	int patient = 0;
	if(patient == 0)
	{
		puts("No Patient to be Called");
		puts("");
	}
	else
	{
		puts("Attention Please!!!");
		puts("");
		puts("Patient from <priorityLevel>,");
		puts("With name <patientName>, <age> years");
		puts("Please moving ahead to Aministration Room");
		puts("");
	}
}

void menu3()
{
	puts("All patient list has been purged");
	puts("");
}

int main()
{
	int choice;
	do
	{
		int n = 0;
		mainMenu(n);
		
		scanf("%d", &choice); getchar();
		
		switch(choice)
		{
			case 1:
			{
				puts("");
				menu1();
				break;
			}
			case 2:
			{
				puts("");
				menu2();
				break;
			}
			case 3:
			{
				puts("");
				menu3();
				break;
			}
		}
	}
	while(choice != 4);
	
	puts("");
	puts("Thank you for using this program!");
	
	return 0;
}
