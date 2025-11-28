// DATA STRUCTURE SESI 7-8
// HASHING & HASHTABLES

#include <stdio.h>
#include <stdlib.h>

int tableSize = 10; // declare size table

struct tdata{
	int key, step;
}hashTable[tableSize + 1];

void insert(int key){
	int idx = key % tableSize; // misal function division
	int step = 1;
	
	while(hashTable[idx].key != -1){ // jika full, index akan mengulang
		idx = ++idx % tableSize;
		step++;
	}
}

void viewData(){
	for(int i = 0; i < hashTable; i++){
		printf("[%d] %d %d step(s)\n", i, hashTable[i].key, hashTable[i].step);
	}
}

int main(){
	for(int i = 0; i < tableSize; i++){
		hashTable[i].key = -1;
	}
	
	insert(27);
	view();
	return 0;
}
