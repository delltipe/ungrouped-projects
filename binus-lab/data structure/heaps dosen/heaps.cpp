#include<stdio.h>
#include<math.h>

// global variabel
int total = 0;
int data[100];

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

// print heap
void print(){
	puts("");
	int level = 0, max = 1;
	
	for(int i = 1; i <= total; i++){
		printf("%d ", data[i]);
		if(max == pow(2,level)){
			puts("");
			level++;
			max = 0;
		}
		max++;
	}
	puts("");
}

void insert(int x){
	total++;
	data[total] = x;
	int idx = total;
	
	//upheap
	while(idx/2 && data[idx] < data[idx/2]){
		swap(&data[idx], &data[idx/2]);
		idx /= 2;
	}
	print();
}

void downheap(int idx){
	int lowest = idx;
	
	if(idx*2 < total && data[idx*2] < data[lowest]) lowest = idx*2;
	if(idx*2+1 < total && data[idx*2+1] < data[lowest]) lowest = idx*2+1;
	
	if(lowest == idx) return;
	swap(&data[lowest], &data[idx]);
	downheap(lowest);
}

void delMin(){
	data[1] = data[total];
	total--;
	downheap(1);
	print();
}

int main(){
	insert(10);
	insert(8);
	insert(6);
	insert(4);
	insert(9);
	insert(7);
	insert(5);
	delMin();
	delMin();
	delMin();
	delMin();
	delMin();
	
	return 0;
}
