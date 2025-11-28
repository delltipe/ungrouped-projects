#include<stdio.h>

const int tableSize = 10;

struct tdata{
	int key, step;
}hashTable[tableSize+1];

void view(){
	for(int i=0;i<tableSize;i++){
		if(hashTable[i].key != -1) printf("[%d] %d | %d step(s)\n", i, hashTable[i].key, hashTable[i].step);
		else printf("[%d] NULL\n", i);
	}
}

void insert(int key){
	int idx = key % tableSize;
	int step = 1;
	
	while(hashTable[idx].key != -1){
		idx = ++idx % tableSize;
		step++;
	}
	
	hashTable[idx].key = key;
	hashTable[idx].step = step;
}

int main(){
	for(int i=0;i<tableSize;i++){
		hashTable[i].key = -1;
	}
	
	insert(27);
	insert(72);
	insert(63);
	insert(42);
	insert(36);
	insert(18);
	insert(29);
	insert(101);
	insert(39);
	insert(6);
	view();
	return 0;
}
