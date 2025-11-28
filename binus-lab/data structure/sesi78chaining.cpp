// DATA STRUCTURE SESI 7-8
// HASHING & HASHTABLES

#include <stdio.h>
#include <stdlib.h>

const int tableSize = 10; // declare size table

struct tdata
{
	int key;
	struct tdata *next;
}*head[tableSize + 1], *curr;

void viewData()
{
	for(int i = 0; i < tableSize; i++)
	{
		curr = head[i];
		
		if(!curr) printf("[%d] NULL", i);
		else
		{
			while(curr)
			{
				if(curr == head[i]) printf("[%d] %d", i, head[i]->key);
				else
				{
					printf(" -> %d", curr->key);
				}
				
				curr = curr->next;
			}
		}
		puts("");
	}
}

void insert(int key)
{
	struct tdata *node = (struct tdata*) malloc (sizeof(struct tdata));
	node->key = key;
	node->next = NULL;
	
	int idx = key % tableSize;
	
	// jika sudah ada data,
	if(head[idx])
	{
		curr = head[idx];
		
		while(curr->next) curr = curr->next;
		
		curr->next = node;
	}
	else
	{
		head[idx] = node;
	}
}

int main()
{
	for(int i = 0; i < tableSize; i++)
	{
		head[i] = NULL;
	}
	insert(27);
	insert(72);
	insert(63);
	insert(42);
	insert(36);
	insert(18);
	insert(29);
	insert(101);
	insert(39);
	insert(6);
	insert(16);
	insert(26);
	insert(46);
	insert(56);
	insert(66);
	viewData();
	return 0;
}
