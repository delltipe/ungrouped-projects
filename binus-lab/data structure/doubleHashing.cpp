// double hashing

#include <stdio.h>
#include <string.h>

//const int tableSize = 10;
//
//struct tdata{
//	char* key;
//}hashTable[tableSize + 1];

int sumASCII(const char* str){
	int sum = 0;
	
	while(*str != '/0'){
		sum += (int)(*str);
		str++;
	}
	
	return sum;
}

int main(){
	const char* myString = "trying";
	
	int sum = sumASCII(myString);
	
	printf("sum = %d\n", sum);
	
	return 0;
}
