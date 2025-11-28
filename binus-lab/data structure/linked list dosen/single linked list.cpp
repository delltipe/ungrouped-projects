#include<stdio.h>
#include<stdlib.h>

struct tnode{
	int value;
	struct tnode *next;
}*head = NULL, *curr;

struct tnode *newNode(int x){
	struct tnode *node = (struct tnode*) malloc(sizeof(struct tnode));
	node->value = x;
	node->next = NULL;
	
	return node;
}

void print(){
	curr = head;
	
	if(head) printf("Head: %d | ", head->value);
	
	while(curr){
		printf("%d ", curr->value);
		curr = curr->next;
	}
	puts("");
}

void pushHead(int x){
	struct tnode *node = newNode(x);
	node->next = head;
	head = node;
	
	print();
}

int main(){
	pushHead(10);
	pushHead(20);
	pushHead(30);
	pushHead(40);
	pushHead(50);
	return 0;
}
