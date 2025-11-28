#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tnode{
	char key;
	struct tnode *left, *right;
}*root = NULL;

char postfix[] = "522+*7-27+*Y68+X*-+";
int i = strlen(postfix) - 1;

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
	if(isOperator(postfix[i])){
		i--;
		curr->right = newNode(postfix[i]);
		createNode(curr->right);
		i--;
		curr->left = newNode(postfix[i]);
		createNode(curr->left);
	}
}

void preOrder(struct tnode *curr){
	printf("%c ", curr->key);
	if(curr->left) preOrder(curr->left);
	if(curr->right) preOrder(curr->right);
}

void inOrder(struct tnode *curr){
	if(isOperator(curr->key)) printf("( ");
	if(curr->left) inOrder(curr->left);
	printf("%c ", curr->key);
	if(curr->right) inOrder(curr->right);
	if(isOperator(curr->key)) printf(") ");
}

void postOrder(struct tnode *curr){
	if(curr->left) postOrder(curr->left);
	if(curr->right) postOrder(curr->right);
	printf("%c ", curr->key);
}

int main(){
	root = newNode(postfix[i]);
	createNode(root);
	
	inOrder(root);
	puts("");
	
	preOrder(root);
	puts("");
	
	postOrder(root);
	puts("");
	
	return 0;
}
