// DATA STRUCTURE LAB SESI 3-4

// DOUBLE LINKED LIST

#include <stdio.h>
#include <stdlib.h>

struct tnode // pembuatan node-node
{
	int value; // akan menyimpan nilai sebuah node
	struct tnode *next; // akan menyimpan alamat node lain
	struct tnode *prev; // akan menyimpan alamat node lain
}*head = NULL, *tail = NULL, *curr, *del; // deklarasi node head, tail, dan curr

struct tnode *newNode(int x)
{
	struct tnode *node = (struct tnode*) malloc(sizeof(struct tnode));
	node->value = x;
	node->next = node->prev = NULL;
	
	return node;
}

void print()
{
	curr = head;
	
	if(!head) puts("NULL");
	else
	{
		printf("Head: %d, Tail = %d | ", head->value, tail->value);
		
		while(curr)
		{
			printf("%d ", curr->value);
			curr = curr->next;
		}
		puts("");
	}
}

void pushHead(int x)
{
	struct tnode *node = newNode(x);
	
	// jika tidak ada head dan == NULL
	if(!head) head = tail = node;
	else
	{
		node->next = head;
		head->prev = node;
		head = node;
	}
	print();
}

void pushTail(int x)
{
	struct tnode *node = newNode(x);
	
	if(!tail) head = tail = node;
	else
	{
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
	print();
}

void pushAfter(int x, int key)
{
	struct tnode *node = newNode(x);
	
	if(tail && tail->value == key) pushTail(x);
	else
	{
		curr = head;
		while(curr && curr->value != key) curr = curr->next;
	
		if(curr)
		{
			node->next = curr->next;
			node->prev = curr;
			curr->next->prev = node;
			curr->next = node;
			print();
		}
		else puts("key not found!!");
	}
}

void popHead()
{
	if(head)
	{
		curr = head;
		
		if(head == tail) head = tail = NULL;
		else
		{
			head = head->next;
			head->prev = NULL;
		}
		free(curr);
		print();
	}
}

void popTail()
{
	if(tail)
	{
		curr = tail;
		if(head == tail) head = tail = NULL;
		else
		{
			tail = tail->prev;
			tail->next = NULL;
		}
		free(curr);
		print();
	}
}

void popMid(int key)
{
	if(head)
	{
		if(key == head->value) popHead();
		else if(tail->value == key) popTail();
		else
		{
			curr = head;
			
			while(curr && curr->value != key) curr = curr->next;
			
			if(curr)
			{
				curr->prev->next = curr->next;
				curr->next->prev = curr->prev;
				
				free(curr);
				print();
			}
			else puts("key not found!!!");
		}
	}
	
}

int main()
{
	pushTail(80);
	pushHead(10);
	pushHead(20);
	popMid(10);
	popHead();
	pushHead(30);
	popTail();
	pushAfter(100, 120);
	popHead();
	pushTail(50);
	pushAfter(70, 50);
	pushHead(40);
	pushHead(60);
	pushTail(90);
	pushTail(110);
	popTail();
	
	return 0;
}
