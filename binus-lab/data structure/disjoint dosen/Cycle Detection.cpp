#include<stdio.h>

int parent[100];
int cycle = 0;

void makeSet(int v){
	parent[v] = v;
}

int findSet(int v){
	if(v == parent[v]) return v;
	else return parent[v] = findSet(parent[v]);
}

void UNION(int a, int b){
	a = findSet(a);
	b = findSet(b);
	
	if(a != b){
		parent[b] = a;
	}else cycle++;
	
}

int main(){
	int C, R;
	scanf("%d %d", &C, &R); getchar();
	
	for(int i=0;i<C;i++){
		makeSet(i);
	}
	
	for(int i=0;i<R;i++){
		int a, b;
		scanf("%d %d", &a, &b); getchar();
		UNION(a,b);
	}
	
	if(cycle>0) puts("Cycle detected");
	else puts("Perfect plan");
	
	return 0;
}
