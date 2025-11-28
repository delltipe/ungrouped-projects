//	DATA STRUCTURES SESI 1

//	INTRODUCTION TO DATA STRUCTURE

#include <stdio.h>
#include <string.h>

// STRUCT
struct profile
{
	char name[20];
};

struct sData
{		
	char nim[10];
	float score;
	profile pro;
};

struct lData
{		
	char nim[10];
	profile pro;
};

int main()
{
	sData student1;
	strcpy(student1.nim, "1111111111");
	strcpy(student1.pro.name, "Bedul");
	student1.score = 3.65;
	
	printf("%s %s %.2f\n", student1.nim, student1.pro.name, student1.score);
	
	return 0;
}
