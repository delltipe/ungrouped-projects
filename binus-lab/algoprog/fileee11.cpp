//	lab11filetest

#include <stdio.h>
#include <string.h>

struct Person
{
	char name[100];
	int age;
	float height;
};

FILE *filePointer;

void sortData(Person personArray[], int size)
{
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size - i; j++)
		{
			if(personArray[j].age < personArray[j + 1].age)
			{
				Person temp = personArray[j];
				personArray[j] = personArray[j + 1];
				personArray[j + 1] = temp;
			}
		}
	}
}

int main()
{
	//	scan semua isi
	
	filePointer = fopen("Sesi11.txt", "r");
	
	Person personArray[20];
	char name[100];
	int age;
	float height;
	
	int counter = 0;
	while(fscanf(filePointer, "%[^#]#%d#%f\n", &name, &age, &height) != EOF)
	{
		Person newPerson;
		strcpy(newPerson.name, name);
		newPerson.age = age;
		newPerson.height = height;
		
		personArray[counter] = newPerson;
		counter += 1;
	}
	
	fclose(filePointer);
	
	//	sorting
	
	sortData(personArray, 20 - 1);
	
	//	buat file baru, sudah di sorting
	
	filePointer = fopen("fileResult.txt", "w");
	
	for(int i = 0; i < 20; i++)
	{
		fprintf(filePointer, "Name: %s\nAge: %d\nHeight: %f\n\n",
		personArray[i].name, personArray[i].age, personArray[i].height);
	}
	
	return 0;
}
