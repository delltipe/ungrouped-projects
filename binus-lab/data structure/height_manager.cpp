// HEIGHT MANAGER [UNFINISHED]

#include <stdio.h>

struct Data
{
	char nim[10];
	int foot;
	int inch;
	float cm = (foot * 12 * 2.54) + (inch * 2.54);
};

void printMenu(int *choice)
{
	puts("Please select a menu:");
	puts("1. Add New Height");
	puts("2. Print All Height");
	puts("3. Exit");
	printf("Your choice: ");
	
	scanf("%d", &*choice);
}

int main()
{
	Data height[100];
	int i = 0;
	
	puts("Welcome to Height Manager!");
	
	int choice = 0;
	
	do
	{
		do
		{
			printMenu(&choice);
//			printf("%d\n", choice);
		}
		while(choice > 3);
		
		switch(choice)
		{
			case 1:
				printf("Input NIM [must be 10 numeric characters]: ");
				scanf("%s", height[i].nim); getchar();
		
				do
				{
					printf("Input foot [0 - 7]: ");
					scanf("%d", &height[i].foot); getchar();
				}
				while(height[i].foot > 7 || height[i].foot < 0);
		
				do
				{
					printf("Input inch [0 - 11]: ");
					scanf("%d", &height[i].inch); getchar();
				}
				while(height[i].inch > 11 || height[i].inch < 0);
		
				printf("%s Height Updated\n\n", height[i].nim);
				i++;
				break;
			case 2:
				if(i == 0)
				{
					puts("No Data");
					puts("");
				}
				for(int j = 0; j < i; j++)
				{
					printf("%s %d\' %d\" %.2fcm\n", height[j].nim, height[j].foot, height[j].inch, height[j].cm);
				}
				break;
			case 3:
				break;
		}
	}
	while(choice < 3);
	
	return 0;
}
