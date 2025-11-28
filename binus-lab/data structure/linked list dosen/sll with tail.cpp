#include<stdio.h>
#include<stdlib.h>

struct tnode{
	int value;
	struct tnode *next;
}*head = NULL, *tail = NULL, *curr;

struct tnode *newNode(int x){
	struct tnode *node = (struct tnode*) malloc(sizeof(struct tnode));
	node->value = x;
	node->next = NULL;
	
	return node;
}

void print(){
	curr = head;
	
	if(!head) puts("NULL");
	else{
		printf("Head: %d, tail: %d | ", head->value, tail->value);
		
		while(curr){
			printf("%d ", curr->value);
			curr = curr->next;
		}
		puts("");
	}
}

void pushHead(int x){
	struct tnode *node = newNode(x);
	
	//!head dan head ==NULL sama
	if(!head) head = tail = node;
	else{
		node->next = head;
		head = node;
	}
	
	print();
}

void pushTail(int x){
	struct tnode *node = newNode(x);
	
	if(!tail) head = tail = node;
	else{
		tail->next = node;
		tail = node;
	}
	
	print();
}

void pushAfter(int x, int key){
	struct tnode *node = newNode(x);
	
	if(tail && tail->value == key) pushTail(x);
	else{
		curr = head;
		while(curr && curr->value != key) curr = curr->next;
		
		if(curr){
			node->next = curr->next;
			curr->next = node;
			print();
		}else{
			puts("Key not found !!!");
		}
	}
}

void popHead(){
	if(head){
		curr = head;
		
		if(head == tail) head = tail = NULL; //kalau cuma 1 data, langsung set NULL
		else head = head->next;
		
		free(curr);
		print();
	}
}

void popTail(){
	if(tail){
		curr = head;
		if(head == tail){
			free(curr);
			head = tail = NULL;
		}else{
			//curr berhenti sebelum tail
			while(curr->next != tail) curr = curr->next;
			
			//curr -> tail -> NULL
			curr->next = NULL;
			free(tail);
			tail = curr;
		}	
		print();
	}
}

int main(){
	pushTail(10);
	popHead();
	popTail();
	pushHead(20);
	popTail();
	popHead();	
	pushTail(30);
	pushHead(40);
	pushHead(50);
	pushAfter(100,20);
	popHead();
	popTail();
	pushTail(60);
	pushHead(70);
	pushTail(80);
	pushHead(90);
	popHead();
	popTail();
	pushAfter(110,80);
	pushTail(120);
	pushAfter(1000,500);
	return 0;
}
