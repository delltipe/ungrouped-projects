#include<stdio.h>
#define MAX 9

int parent[MAX];

void makeSet(int v){
	parent[v] = v;
}

int findSet(int v){
	if(v == parent[v]) return v;
	else return parent[v] = findSet(parent[v]);
}

void print(){
	for(int i=0;i<MAX;i++){
		printf("%d ", parent[i]);
	}
	puts("");
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void UNION(int a, int b){
	a = findSet(a);
	b = findSet(b);
	
	if(a != b){
		parent[b] = a;
	}
	
	print();
}

int main(){
	for(int i=0;i<MAX;i++){
		makeSet(i);
	}
	
	parent[1] = 1;
	parent[2] = 1;
	parent[3] = 2;
	parent[4] = 2;
	parent[5] = 3;
	parent[6] = 3;
	parent[7] = 5;
	parent[8] = 6;
	
	print();
	findSet(7);
	print();
	
	return 0;
}
