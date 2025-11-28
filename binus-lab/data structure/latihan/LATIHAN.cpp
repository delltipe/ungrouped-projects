#include <stdio.h>
#include <stdlib.h>

struct tnode{
	int value;
	int height;
	struct tnode *left, *right;
}*root = NULL, *temp;

struct tnode *newNode(int value){
	struct tnode *node = (struct tnode*) malloc(sizeof(struct tnode));
	
	node->value = value;
	node->height = 1;
	node->left = node->right = NULL;
	
	return node;
}

int height(struct tnode *node){
	if(!node) return 0;
	else return node->height;
}

int max(int a, int b){
	if(a > b) return a;
	else return b;
}

struct tnode *rightRotate(struct tnode *node){
	struct tnode *temp1 = node->left;
	struct tnode *temp2 = temp1->right;
	
	temp1->right = node;
	node->left = temp2;
	
	node->height = 1 + max(height(node->left), height(node->right));
	temp1->height = 1 + max(height(temp1->left), height(temp1->right));
	
	return temp1;
}

struct tnode *leftRotate(struct tnode *node){
	struct tnode *temp1 = node->right;
	struct tnode *temp2 = temp1->left;
	
	temp1->left = node;
	node->right = temp2;
	
	node->height = 1 + max(height(node->left), height(node->right));
	temp1->height = 1 + max(height(temp1->left), height(temp1->right));
	
	return temp1;
}

int getDifference(struct tnode *node){
	if(!node) return 0;
	else return height(node->left) - height(node->right);
}

struct tnode *rebalance(struct tnode *node){
	int difference = getDifference(node);
	
	if(difference > 1 && getDifference(node->left) >= 0){
		return rightRotate(node);
	}
	else if(difference < -1 && getDifference(node->right) <= 0){
		return leftRotate(node);
	}
	else if(difference > 1 && getDifference(node->left) < 0){
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	else if(difference < -1 && getDifference(node->right) > 0){
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	
	return node;
}

struct tnode *insert(struct tnode *node, int value){
	if(!node){
		return newNode(value);
	}
	else if(value > node->value){
		node->right = insert(node->right, value);
	}
	else if(value < node->value){
		node->left = insert(node->left, value);
	}
	else{
		puts("number is already on tree!");
	}
	
	node->height = 1 + max(height(node->left), height(node->right));
	return rebalance(node);
}

struct tnode *del(struct tnode *node, int value){
	if(!node){
		puts("number not found!");
	}
	else if(value < node->value){
		node->left = del(node->left, value);
	}
	else if(value > node->value){
		node->right = del(node->right, value);
	}
	else{
		if(!node->left){
			temp = node;
			node = node->right;
			free(temp);
			return node;
		}
		else if(!node->right){
			temp = node;
			node = node->left;
			free(temp);
			return node;
		}
		else{
			temp = node->left;
			
			while(temp->right){
				temp = temp->right;
			}
			
			node->value = temp->value;
			node->left = del(node->left, temp->value);
		}
	}
	
	node->height = 1 + max(height(node->left), height(node->right));
	return rebalance(node);
}

void inorder(struct tnode *node){
	if(node){
		inorder(node->left);
		printf("%d (%d, %d) ", node->value, node->height, getDifference(node));
		inorder(node->right);
	}
}

void print(struct tnode *node){
	inorder(node);
	puts("");
}

int main(){
	root = insert(root, 19);
	print(root);
	root = insert(root, 15);
	print(root);
	root = insert(root, 6);
	print(root);
	root = insert(root, 20);
	print(root);
	root = insert(root, 23);
	print(root);
	root = insert(root, 1);
	print(root);
	root = insert(root, 18);
	print(root);
	root = insert(root, 5);
	print(root);
	
	return 0;
}