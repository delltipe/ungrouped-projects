#include<stdio.h>
#include<stdlib.h>

struct tnode{
	int key;
	struct tnode *left, *right;
}*root = NULL;

struct tnode *newNode(int key){
	struct tnode *node = (struct tnode*) malloc (sizeof(struct tnode));
	node->key = key;
	node->left = node->right = NULL;
	
	return node;
}

void inOrder(struct tnode *curr){
	if(curr->left) inOrder(curr->left);
	printf("%d ", curr->key);
	if(curr->right) inOrder(curr->right);
}

void insert(struct tnode *curr, int key){
	if(!root) root = newNode(key);
	else{
		if(key == curr->key) printf("Duplicate value while inserting %d\n", key);
		else if(key < curr->key){
			if(!curr->left) curr->left = newNode(key);
			else insert(curr->left, key);
		}else{
			if(!curr->right) curr->right = newNode(key);
			else insert(curr->right, key);
		}
	}
}

void find(struct tnode *curr, int key){
	if(curr){
		if(key == curr->key) printf("| Key %d found\n", key);
		else if(key < curr->key){
			printf("left ");
			find(curr->left, key);
		}else{
			printf("right ");
			find(curr->right, key);
		}
	}else printf("| Key %d not found\n", key);
}

void del(struct tnode *curr, struct tnode *parent){
	if(!curr->left && !curr->right){
		if(!parent) root = NULL;
		else{
			if(curr == parent->left) parent->left = NULL;
			else if (curr == parent->right) parent->right = NULL;
		}
		free(curr);
	}else if(curr->left && !curr->right){
		if(curr == parent->left) parent->left = curr->left;
		else if(curr == parent->right) parent->right = curr->left;
		
		free(curr);
	}else if(!curr->left && curr->right){
		if(curr == parent->left) parent->left = curr->right;
		else if(curr == parent->right) parent->right = curr->right;
		
		free(curr);
	}else{
		struct tnode *maxNode = curr->left, *maxParent = curr;
		
		while(maxNode->right){
			maxParent = maxNode;
			maxNode = maxNode->right;
		}
		
		int maxKey = maxNode->key;
		del(maxNode, maxParent);
		curr->key = maxKey;
	}
	inOrder(root);
	puts("");
}

void findDel(int key){
	struct tnode *parent = NULL, *curr;
	
	curr = root;
	while(curr){
		if(key == curr->key) break;
		else{
			parent = curr;
			curr = key < curr->key ? curr->left : curr->right;
		}
	}
	
	if(curr) del(curr, parent);
	else printf("Key %d not found\n", key);
}

int main(){
	insert(root, 98);
	insert(root, 2);
	insert(root, 48);
	insert(root, 12);
	insert(root, 56);
	insert(root, 32);
	insert(root, 4);
	insert(root, 67);
	insert(root, 23);
	insert(root, 87);
	insert(root, 23);
	insert(root, 55);
	insert(root, 46);
	insert(root, 21);
	insert(root, 39);
	insert(root, 45);
	insert(root, 54);
	insert(root, 63);
	
	/*
	find(root, 100);
	find(root, 55);
	find(root, 98);
	*/
	inOrder(root);
	puts("");
	
	findDel(23);
	findDel(56);
	findDel(2);
	findDel(45);
	
	return 0;
}
