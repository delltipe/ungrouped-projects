#include<stdio.h>
#define MAX 5

int parent[MAX];
int rank[MAX];

void makeSet(int v){
	parent[v] = v;
	rank[v] = 0;
}

int findSet(int v){
	if(v == parent[v]) return v;
	else return findSet(parent[v]);
}

void print(){
	for(int i=0;i<MAX;i++){
		printf("%d ", rank[i]);
	}
	puts("");
	for(int i=0;i<MAX;i++){
		printf("%d ", parent[i]);
	}
	puts("");
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
		if(rank[a] < rank[b]) swap(&a, &b);
		
		parent[b] = a;
		
		if(rank[a] == rank[b]) rank[a]++;
	}
	
	print();
}

int main(){
	for(int i=0;i<MAX;i++){
		makeSet(i);
	}
	
	print();
	UNION(4,3);
	UNION(2,1);
	UNION(3,1);
	UNION(0,1);
	
	return 0;
}
