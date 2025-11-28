//sesi 5
#include <stdio.h>
#include <string.h>
int main()
{
//	arrays!!!
	
//	variabel ini cuma bisa simpan 1 value
//	int number = 0;
	
//	<data type> <nama>[];
//	int numberArray[10];
	
//	deklarasi + inisialisasi
//	int numberArray[] = {1, 2, 3};
//	valuenya = 1, 2, 3

//	bakal ngeprint memorynya
//	printf("%d\n", numberArray2);

//	HARUSNYA <nama>[<data ke berapa/index>]
//	printf("%d\n", numberArray2[2]);

//	int numberArray[] = {1, 2, 3};
//	for(int i=0;i<3;i++){
//		printf("%d ", numberArray[i]);
//	}
	
//	BIKIN ARRAY JANGAN KOSONGGG!, begini aja
//	int numberArray1[20] = {};
//	for(int i=0;i<20;i++){
//		printf("%d ", numberArray1[i]);
//	}

//	string! 2 options
//	char string[20] = {'h', 'a', 'i', ':', ')'}
//	char string[20] = "hai:)";
//	for(int i=0;i<20;i++){
//		printf("%c", string[i]);
//	}
//	puts("");
//	printf("%s", string);
	
//	char string1[10] = "hai";
//	char string2[10][10] = "hai", "helo";

//	int = 4 byte
//	4x7 = 28
//	int numberArray[]={3, 9, 39, 93, 69, 96};
//	printf("%d\n", sizeof(numberArray)/sizeof(numberArray[0]));
//	printf("%d\n", sizeof(numberArray)/sizeof(int));
//	cara untuk print angka sesuai array nya

//	int length = sizeof(numberArray)/sizeof(int);
//	for(int i=0;i<)

//	biasakan isi array (untuk string)!
//	char array1[100]="hai brow";
//	char array2[100];
//	
//	for(int i=0;i<sizeof(array1)/sizeof(char);i++){
//		array2[i]=array1[i];
//	}
//	printf("%s", array2);

//	int array1[]={1, 2, 3};
//	int array2[100];
//	
//	for(int i=0;i<sizeof(array1)/sizeof(int);i++){
//		array2[i]=array1[i];
//	}
//	for(int i=0;i<sizeof(array1)/sizeof(int);i++){
//		printf("%d", array2[i]);
//	}

//	char array1[100]="hai brow";
//	char array2[100];

//	strlen(<string>)=untuk mengetahui panjang string

//	for(int i=0;i<strlen(array1);i++){
//		array2[i]=array1[i];
//	}
//	printf("%s", array2);
//	return 0;

//	char array1[100]="hai brow";
//	char array2[100];

//	strcpy(<string destinasi>);

//	strcpy(array2, array1);
//	printf("%s", array2);

//	char string1[100]="haiii";
//	char string2[100]="hello1";

//	strcmp(<string1>, <string2>) = memperbandingkan string sesuai ASCII

//	//CASE SENSITIVE
//	printf("%d", strcmp(string1, string2));

//	strcmpi = sama kayak strcmp, tapi gak case sensitive

//	printf("%d", strcmpi(string1, string2));

//	strcat(<string destinasi>, <stringnyang mau ditambah>)

//	strcat(string1, string2);
//	strcat(string1, "nama gue dave");
//	printf("%s", string1);
//	//string1 < string2 = -1
//	//string1 > string2 = 1
//	//string1 == string2 = 0

//	sprintf(<string destinasi>, "format", <isi>);

//	char string[100];
//	sprintf(string, "Angka: %d", 100);
//	printf("%s", string);

////	variabel biasa
//	int number = 2;
////	variabel pointer = ngasih address ke variabel yg ditunjuk
////	pointer int
//	int* numberPtr = &number;
////	memori
//	printf("%d\n", &number);
//	printf("%d\n", numberPtr);
////	value sebelum
//	printf("%d\n", number);
//	printf("%d\n", *numberPtr);
//	
//	number=100;
////	value sesudah
//	printf("%d\n", number);
//	printf("%d\n", *numberPtr);

//	int array[10];
//	for(int i=0;i<sizeof(array)/sizeof(array[0]);i++){
//		printf("%d ", &array1);
//	}
	
//	//HAFALLL!!
//	//strtok(<string>, <pembagi>); =string token
//	char string[100]="Nama aku Bedul";
//	//array = pointer yang berurutan
//	char* token=strtok(string, " ");
//	
//	while(token != NULL){
//		printf("%s\n", token);
//		token=strtok(NULL, " ");	
//	}

//	MULTIDIMENSIONAL ARRAY
//	
//	int numberArray[2][2];
//	for(int i=0;i<4;i++){
//		for(int j=0;j<2;j++){
//			scanf("%d", &numberArray[i][j]);
//		}
//	}
//	
//	int numbeArray[2][2];
//	for(int i=0;i<4;i++){
//		for(int j=0;j<2;j++){
//			printf("%d ", numberArray[i][j]);
//		}
//	}
	
	return 0;
}
