#include<stdio.h>
#define MAX 5

int parent[MAX];

void makeSet(int v){
	parent[v] = v;
}

int findSet(int v){
	if(v == parent[v]) return v;
	else return findSet(parent[v]);
}

void print(){
	for(int i=0;i<MAX;i++){
		printf("%d ", parent[i]);
	}
	puts("");
}

void UNION(int a, int b){
	a = findSet(a);
	b = findSet(b);
	
	if(a != b) parent[b] = a;
	
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
	UNION(1,0);
	
	return 0;
}
