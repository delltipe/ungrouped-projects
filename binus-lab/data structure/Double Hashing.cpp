#include<stdio.h>
#include<string.h>

const int tableSize = 97;

struct tdata{
	int avail, step;
	char str[10];
}hashTable[tableSize+1];

void view(){
	for(int i=0;i<tableSize;i++){
		if(hashTable[i].avail != 1) printf("[%d] %s | %d step(s)\n", i, hashTable[i].str, hashTable[i].step);
		else printf("[%d] NULL\n", i);
	}
}

int hashing(char str[10]){
	int key = 0;
	
	for(int i=0;str[i]!='\0';i++){
		key += str[i];
	}
	
	return key;
}

void insert(char str[10]){
	int key = hashing(str), step = 0, idx;
	int h1 = key % tableSize;
	int h2 = key % (tableSize - 1) != 0 ? (key % (tableSize - 1)) : (key % (tableSize - 2));
	//int h2 = key % (tableSize - 1);
	
	printf("%d %d %d %d\n", key % (tableSize - 1), key % (tableSize - 2), h1, h2);
	do{
		idx = (h1 + step * h2) % tableSize;
		step++;
	}while(hashTable[idx].avail != 1);
	
	strcpy(hashTable[idx].str, str);
	hashTable[idx].avail = 0;
	hashTable[idx].step = step;
}

int main(){
	for(int i=0;i<tableSize;i++){
		hashTable[i].avail = 1;
	}
	
	insert("COBB");
	insert("HIKE");
	insert("PPQQ");
	insert("ABCD");
	insert("HIKD");
	insert("HIDK");
	insert("HKID");
	view();
	
	return 0;
}
