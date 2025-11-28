#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tnode{
	char patient_name[25];
	int priorityLevel;
	int age;
	struct tnode *next, *prev;
}*head = NULL, *tail = NULL, *curr, *del;

struct tnode *newNode(char name[25], int prio, int age){
	struct tnode *node = (struct tnode*) malloc(sizeof(struct tnode));
	strcpy(node->patient_name, name);
	node->priorityLevel = prio;
	node->age = age;
	node->next = node->prev = NULL;
	
	return node;
}

void cls(){
	for(int i=0;i<50;i++) puts("");
}

char* st(int p){
	switch(p){
	case 1:
		return "Emergency";
		break;
	case 2:
		return "Super VIP";
		break;
	case 3:
		return "VIP";
		break;
	case 4:
		return "Basic";
		break;
	}
}

void print(){
	int i=1;
	if(head){
		printf("Quasar Hospital Queue\n");
		printf("-----------------------------------------------\n");
		curr = head;
		while(curr){
			printf("%d. %-10s | %30s (%d)\n", i, st(curr->priorityLevel), strupr(curr->patient_name), curr->age);
			curr = curr->next;
			i++;
		}
	}
	printf("\nPatient: %d people(s)\n\n", i-1);
}

int menu(){
	int ch;
	
	do{
		cls();
		print();
		puts("Quasar Queue 1.3");
		puts("=================");
		puts("1. Add Patient");
		puts("2. Call Patient");
		puts("3. Remove All Patient List");
		puts("4. Exit");
		printf("Select [1..4]: ");
		scanf("%d", &ch); getchar();
	}while(ch < 1 || ch > 4);
	
	return ch;
}

void pushHead(char name[25], int prio, int age){
	struct tnode *node = newNode(name, prio, age);
	
	if(!head) head = tail = node;
	else{
		head->prev = node;
		node->next = head;
		head = node;
	}
}

void pushTail(char name[25], int prio, int age){
	struct tnode *node = newNode(name, prio, age);
	
	if(!tail) head = tail = node;
	else{
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
}

void push(char name[25], int prio, int age){
	struct tnode *node = newNode(name, prio, age);
	
	if(!head || (head && head->priorityLevel > prio)) pushHead(name, prio, age);
	else if(tail && tail->priorityLevel <= prio) pushTail(name, prio, age);
	else{
		curr = head;
		
		//1 1 2 2 3 3 
		while(curr && curr->priorityLevel <= prio) curr = curr->next;
		
		if(curr){
			node->next = curr;
			node->prev = curr->prev;
			curr->prev->next = node;
			curr->prev = node;
		}
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
	}
}

void popAll(){
	while(head) popHead();
}

void add(){
	cls();
	
	char name[25];
	int prio, age;
	
	do{
		printf("Input Patient Name [1..25]:");
		gets(name);
	}while(strlen(name) < 1 || strlen(name) > 25);

	do{
		printf("1. Emergency\n");
		printf("2. Super VIP\n");
		printf("3. VIP\n");
		printf("4. Basic\n");
		printf("Select Class [1..4]:");
		scanf("%d", &prio); getchar();
	}while(prio < 1 || prio > 4);

	do{
		printf("Input Age [1..110]:");
		scanf("%d", &age); getchar();
	}while(age < 1 || age > 110);
	
	push(name, prio, age);
}

int main(){
	int ch;
	
	do{
		ch = menu();
		switch(ch){
			case 1:
				add();
				break;
			case 2:
				if(!head) printf("No Patient to be called..");
				else{
					printf("Attention Please!!\n\n");
					printf("Patient from %s Room,\n", st(head->priorityLevel));
					printf("With name %s, %d years\n", head->patient_name, head->age);
					printf("Please moving ahead to Administration Room..\n");
					popHead();
				}
				break;
			case 3:
				popAll();
				break;
		}
		getchar();
	}while(ch != 4);
	
	return 0;
}

