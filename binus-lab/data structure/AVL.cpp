#include<stdio.h>
#include<stdlib.h>

struct tnode{
	char key;
	int height;
	struct tnode *left, *right;
}*root = NULL, *temp;

struct tnode *newNode(char key){
	struct tnode *node = (struct tnode*) malloc(sizeof(struct tnode));
	node->key = key;
	node->height = 1;
	node->left = node->right = NULL;
	
	return node;
}

void inorder(struct tnode *node){
	if(node){
		inorder(node->left);
		printf("%c(%d) ", node->key, node->height);
		inorder(node->right);
	}
}

void print(struct tnode *node){
	inorder(node);
	puts("");
}

int height(struct tnode *node){
	if(!node) return 0;
	else return node->height;
}

int max(int a, int b){
	if(a>b) return a;
	else return b;
}

int getBalance(struct tnode *node){
	if(!node) return 0;
	else return height(node->left) - height(node->right);
}

struct tnode *rightRotation(struct tnode *T){
	struct tnode *S = T->left;
	struct tnode *B = S->right;
	
	S->right = T;
	T->left = B;
	
	T->height = 1 + max(height(T->left), height(T->right));
	S->height = 1 + max(height(S->left), height(S->right));
	
	return S;
}

struct tnode *leftRotation(struct tnode *T){
	struct tnode *S = T->right;
	struct tnode *B = S->left;
	
	S->left = T;
	T->right = B;
	
	T->height = 1 + max(height(T->left), height(T->right));
	S->height = 1 + max(height(S->left), height(S->right));
	
	return S;
}

struct tnode *rebalance(struct tnode *node){
	int balance = getBalance(node);
	
	if(balance > 1 && getBalance(node->left) >= 0){
		//puts("LL");
		return rightRotation(node);
	}else if(balance < -1 && getBalance(node->right) <= 0){
		//puts("RR");
		return leftRotation(node);
	}else if(balance > 1 && getBalance(node->left) < 0){
		//puts("LR");
		node->left = leftRotation(node->left);
		return rightRotation(node);
	}else if(balance < -1 && getBalance(node->right) > 0){
		//puts("RL");
		node->right = rightRotation(node->right);
		return leftRotation(node);
	}
	return node;
}

struct tnode *insert(struct tnode *node, char key){
	if(!node) return newNode(key);
	else if(key < node->key) node->left = insert(node->left, key);
	else if(key > node->key) node->right = insert(node->right, key);
	else puts("Duplicate key !!!");
	
	node->height = 1 + max(height(node->left), height(node->right));
	return rebalance(node);
}

struct tnode *del(struct tnode *node, char key){
	if(!node) puts("Key not found !!!");
	else if(key < node->key) node->left = del(node->left, key);
	else if(key > node->key) node->right = del(node->right, key);
	else{
		if(!node->left){
			//puts("1");
			temp = node;
			node = node->right;
			free(temp);
			return node; 
		}else if(!node->right){
			//puts("2");
			temp = node;
			node = node->left;
			free(temp);
			return node;
		}else{
			//puts("3");
			temp = node->left;
			
			while(temp->right) temp = temp->right;
			
			node->key = temp->key;
			node->left = del(node->left, temp->key);
		}
	}
	
	node->height = 1 + max(height(node->left), height(node->right));
	return rebalance(node);
}

int main(){
	root = insert(root, 'S');
	print(root);
	root = insert(root, 'O');
	print(root);
	root = insert(root, 'F');
	print(root);
	root = insert(root, 'T');
	print(root);
	root = insert(root, 'W');
	print(root);
	root = insert(root, 'A');
	print(root);
	root = insert(root, 'R');
	print(root);
	root = insert(root, 'E');
	print(root);
	
	root = del(root, 'W');
	print(root);
	root = del(root, 'O');
	print(root);
	
	return 0;
}
