#include<stdio.h>
#include<stdlib.h>

struct Node{
	int value;
	Node *left, *right;
} *root, *temp;

Node *insertNode(Node* node, int value){
	// buat node baru
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->value = value;
	newNode->left = newNode->right = NULL;
	
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
	
	return node;
}

int main(){
	root = insertNode(root, 10);
	root = insertNode(root, 20);
	root = insertNode(root, 30);
	root = insertNode(root, 40);
	root = insertNode(root, 25);
	root = deleteNode(root, 20);
	
	inOrder(root); printf("\n");
	postOrder(root); printf("\n");
	preOrder(root); printf("\n");
	
	printf("root: %d", root->value);
	
	
	
	
	return 0;
}
