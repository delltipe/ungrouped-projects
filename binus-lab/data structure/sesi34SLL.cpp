// DATA STRUCTURE LAB SESI 3-4

// SINGLE LINKED LIST

#include <stdio.h>
#include <stdlib.h>

struct tnode // pembuatan node-node
{
	int value; // akan menyimpan nilai sebuah node
	struct tnode *next; // akan menyimpan alamat node lain
}*head = NULL, *tail = NULL, *curr, *del; // deklarasi node head, tail, dan curr

struct tnode *newNode(int x)
{
	struct tnode *node = (struct tnode*) malloc(sizeof(struct tnode));
	node->value = x;
	node->next = NULL;
	
	return node;
}

void print()
{
	curr = head;
	
	if(head) printf("Head: %d, Tail = %d | ", head->value, tail->value);
	
	while(curr)
	{
		printf("%d ", curr->value);
		curr = curr->next;
	}
	puts("");
}

void pushHead(int x)
{
	struct tnode *node = newNode(x);
	
	// jika tidak ada head dan == NULL
	if(!head) tail = node;
	
	node->next = head;
	head = node;
	
	print();
}

void pushTail(int x)
{
	struct tnode *node = newNode(x);
	
	if(!head) pushHead(x);
	else
	{
		curr = head;
		while(curr->next) curr = curr->next;
	
		curr->next = node;
		tail = node;

		print();
	}
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
			curr->next = node;
		}
		else
		{
			puts("key not found!!");
		}
	}
}

void popHead()
{
	if(head)
	{
		curr = head;
		
		if(head == tail) head = tail = NULL;
		else head = head->next;
		
		free(curr);
		print();
	}
}

void popTail()
{
	if(tail)
	{
		curr = head;
		
		if(head == tail)
		{
			free(curr);
			head = tail = NULL;
		}
		else
		{
			while(curr->next != tail)curr = curr->next; // berhenti di data terakhir sebelum NULL
		
			curr->next = NULL;
			free(tail);
			tail = curr;
		}
		print();
	}
}

void popMid(int key)
{
	if(head)
	{
		if(key == head->value) popHead();
		else if(key == tail->value) popTail();
		else
		{
			curr = head;
			
			while(curr->next && curr->next->value != key) curr = curr->next;
			
			if(curr->next)
			{
				del = curr->next;
				curr->next = del->next;
				free(del);
			}
			else puts("key not found!!!");
		}
		print();
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
