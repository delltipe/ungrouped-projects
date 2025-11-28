#include<stdio.h>
#include<stdlib.h>

struct tnode{
	char key;
	struct tnode *left, *right;
}*root = NULL;

char prefix[] = "+*-*5+227+27-y*+68x";
int i = 0;

struct tnode *newNode(char key){
	struct tnode *node = (struct tnode*) malloc (sizeof(struct tnode));
	node->key = key;
	node->left = node->right = NULL;
	
	return node;
}

int isOperator(char key){
	if(key == '+' || key == '-' || key == '*' || key == '/') return 1;
	return 0;
}

void createNode(struct tnode *curr){
	if(isOperator(prefix[i])){ // bakal cek kalo operator akan bikin terus ke kiri, jika sudah habis di kiri, akan membuat di kanan
		i++;
		curr->left = newNode(prefix[i]);
		createNode(curr->left); // bekerja secara recursive
		
		i++;
		curr->right = newNode(prefix[i]);
		createNode(curr->right);
	}
}

void preOrder(struct tnode *curr){
	printf("%c ", curr->key);
	if(curr->left) preOrder(curr->left);
	if(curr->right) preOrder(curr->right);
}

void inOrder(struct tnode *curr){
	if(isOperator(curr->key)) printf("(");
	if(curr->left) preOrder(curr->left);
	printf("%c ", curr->key);
	if(curr->right) preOrder(curr->right);
	if(isOperator(curr->key)) printf(")");
}

void postOrder(struct tnode *curr){
	if(curr->left) preOrder(curr->left);
	if(curr->right) preOrder(curr->right);
	printf("%c ", curr->key);
}

int main(){
	root = newNode(prefix[i]);
	createNode(root);
	
	preOrder(root);
	puts("");
	
	inOrder(root);
	puts("");
	
	postOrder(root);
	puts("");
	
	return 0;
}
