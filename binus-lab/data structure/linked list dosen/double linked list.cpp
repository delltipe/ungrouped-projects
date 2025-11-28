#include<stdio.h>
#include<stdlib.h>

struct tnode{
	int value;
	struct tnode *next, *prev;
}*head = NULL, *tail = NULL, *curr, *del;

struct tnode *newNode(int x){
	struct tnode *node = (struct tnode*) malloc(sizeof(struct tnode));
	node->value = x;
	node->next = node->prev = NULL;
	
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
	
	if(!head) head = tail = node;
	else{
		node->next = head;
		head->prev = node;
		head = node;
	}
	print();
}

void pushTail(int x){
	struct tnode *node = newNode(x);
	
	if(!tail) head = tail = node;
	else{
		tail->next = node;
		node->prev = tail;
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
			node->prev = curr;
			curr->next->prev = node;
			curr->next = node;
			print();
		}else puts("Key not found !!!");
	}
}

void popHead(){
	if(head){
		curr = head;
		if(head == tail) head = tail = NULL;
		else{
			head = head->next;
			head->prev = NULL;
		} 
		free(curr);
		print();
	}
}

void popTail(){
	if(tail){
		curr = tail;
		if(head == tail) head = tail = NULL;
		else{
			tail = tail->prev;
			tail->next = NULL;
		}
		free(curr);
		print();
	}
}

void popMid(int key){
	if(head){
		if(head->value == key) popHead();
		else if(tail->value == key) popTail();
		else{
			curr = head;
			
			while(curr && curr->value != key) curr = curr->next;
			
			if(curr){
				curr->prev->next = curr->next;
				curr->next->prev = curr->prev;
				free(curr);
				print();
			}else puts("Key not found !!!");
		}
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
	popMid(40);
	popMid(60);
	popMid(70);
	pushTail(80);
	pushHead(90);
	popHead();
	popTail();
	pushAfter(110,80);
	pushTail(120);
	popMid(70);
	pushAfter(1000,500);
	return 0;
	return 0;
}
