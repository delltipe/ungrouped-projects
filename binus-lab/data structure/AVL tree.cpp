#include<stdio.h>
#include<stdlib.h>

struct Node{
	int value;
	Node *left, *right;
	int height;
} *root, *temp;

int getHeight(Node *node){
	if(node == NULL) return 0;
	return node->height;
}

int max(int a, int b){
	return a > b ? a : b;
}

int calcBalance(Node *node){
	return getHeight(node->right) - getHeight(node->left);
}

Node *leftRotate(Node *n){
	Node *t = n->right;
	Node *t2 = t->left;
	
	t->left = n;
	n->right = t2;
	
	n->height = 1 + max(getHeight(n->left), getHeight(n->right));
	t->height = 1 + max(getHeight(t->left), getHeight(t->right));
	
	return t;
}

Node *rightRotate(Node *n){
	Node *t = n->left;
	Node *t2 = t->right;
	
	t->right = n;
	n->left = t2;
	
	n->height = 1 + max(getHeight(n->left), getHeight(n->right));
	t->height = 1 + max(getHeight(t->left), getHeight(t->right));
	
	return t;
}

Node *insertNode(Node* node, int value){
	// buat node baru
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->value = value;
	newNode->left = newNode->right = NULL;
	newNode->height = 1;
	
	//untuk handle recursive
	if(node == NULL){ // insert node di tempat kosong
		return newNode;	
	}
	else if(value > node->value){ // ke kanan
		node->right = insertNode(node->right, value);
	}
	else if(value < node->value){ // ke kiri 
		node->left = insertNode(node->left, value);
	}
	else
		return node;
	
	node->height = 1 + max(getHeight(node->left), getHeight(node->right));
		
	int balance = calcBalance(node);
	
/*
	Kondisi rotate (insert)
	
	balance > 1
	LR: newValue > n->right->value;
	
	balance < -1
	RR: newValue < n->left->value;
	
	balance < -1
	LRR: newValue > n->left->value;
	
	balance > 1
	RLR: newValue < n->right->value;
*/
	
	if(balance > 1 && value > node->right->value){
		return leftRotate(node);
	}
	else if(balance < -1 && value < node->left->value){
		return rightRotate(node);
	}
	//left right rotate
	else if(balance < -1 && value > node->left->value){
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	//right left rotate
	else if(balance > 1 && value < node->right->value){
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	
	return node;
}

void inOrder(Node* node){
	if(node != NULL){
		inOrder(node->left);
		printf(" %d ", node->value);
		inOrder(node->right);
	}
}

void postOrder(Node* node){
	if(node != NULL){
		postOrder(node->left);
		postOrder(node->right);
		printf(" %d ", node->value);
		
	}
}

void preOrder(Node* node){
	if(node != NULL){
		printf(" %d ", node->value);
		preOrder(node->left);
		preOrder(node->right);
	}
}

Node* goToMin(Node* node){ // masukkin anak kanan
	if(node == NULL){
		return NULL;
	}
	// berjalan terus ke kiri
	else if(node->left != NULL){
		return goToMin(node->left);
	}
	return node; 
}

Node* searchNode(Node* node, int searchValue){
	if(node == NULL || searchValue == node->value){
		return node;
	}
	else if(searchValue > node->value){ //ke kanan
		return searchNode(node->right, searchValue);
	}
	else if(searchValue < node->value) { //ke kiri
		return searchNode(node->left, searchValue);
	}
}

Node* deleteNode(Node* node, int searchValue){
	if(node == NULL){ // gak ketemu
		return NULL;
	}
	else if(searchValue > node->value){ // ke kanan
		node->right = deleteNode(node->right, searchValue);
	}
	else if(searchValue < node->value){ // ke kiri
		node->left = deleteNode(node->left, searchValue);
	}
	else{ // ketemu
		// kalau ketemu cek lagi:
		// gak punya anak
		if(node->left == NULL && node->right == NULL){ 
			free(node);
			return NULL;
		}
		// punya 1 anak di kiri atau di kanan
		else if(node->left == NULL || node->right == NULL){
			//kalau punya nya anak kanan
			if(node->left == NULL){
				temp = node->right;
			}
			else{
				temp = node->left;
			}
			free(node);
			return temp;
		}
		// punya 2 anak
		else{
			// butuh successor
			temp = goToMin(node->right);
			//copy value dari successor
			node->value = temp->value;
			//delete si successor dari tempat asalnya
			node->right = deleteNode(node->right, temp->value);
		}
	}
	
	node->height = 1 + max(getHeight(node->left), getHeight(node->right));
	
	int balance = calcBalance(node);
	
/*
	Kondisi rotate (delete)
	
	balance(n) > 1 && balance(n->right) >= 0
	LR: newValue > n->right->value;
	
	balance(n) < -1 && balance(n->left) <= 0
	RR: newValue < n->left->value;
	
	balance(n) < -1 && balance(n->left) > 0
	LRR: newValue > n->left->value;
	
	balance(n) > 1 && balance(n->right) < 0
	RLR: newValue < n->right->value;
*/
	
	if(balance > 1 && calcBalance(node->right) >= 0){
		return leftRotate(node);
	}
	else if(balance < -1 && calcBalance(node->left) <= 0){
		return rightRotate(node);
	}
	else if(balance < -1 && calcBalance(node->left) > 0){
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	else if(balance > 1 && calcBalance(node->right) < 0){
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	
	return node;
}

int main(){
	root = insertNode(root, 100);
	root = insertNode(root, 50);
	root = insertNode(root, 200);
	root = insertNode(root, 150);
	root = insertNode(root, 250);
	root = deleteNode(root, 250);
	root = deleteNode(root, 50);
	
	inOrder(root); printf("\n");
	postOrder(root); printf("\n");
	preOrder(root); printf("\n");
	
	printf("root: %d", root->value);
	
	
	
	
	return 0;
}
