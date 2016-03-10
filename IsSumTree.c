/* ==========================================================================
 IsSumTree.c
 Aparna Lavanya K
 
 Program to check if a 
 Binary tree is Sum tree
 ========================================================================== */
 
#include<stdio.h>
#include<stdlib.h>

struct node* createNode(int data);
int isLeaf(struct node* root);
int isSumTree(struct node* root);

struct node {
	int data;
	struct node* left;
	struct node* right;
};

/*
	
	26 
      /    \ 
    10      3 
   /   \     \ 
  4    6      3
  
*/

int main() {

	struct node *root = createNode(26);                             
	root->left = createNode(10);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(6);
	root->right->right = createNode(3);

	if (isSumTree(root) == -1) {
		printf("NO! It is not a Sum Tree ");
	}

	else {
		printf("YES! It is a Sum Tree ");
	}

	return 0;
}

struct node* createNode(int data) {

	struct node* newNode = (struct node*)malloc(sizeof(struct node));

	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
};

int isLeaf(struct node* root) {
	return (root->left == NULL && root->right == NULL);
}

int isSumTree(struct node* root) {

	if (root == NULL) { // empty tree is sum tree
		return 0;
	}

	if (isLeaf(root)) { // leaf nodes are sum trees
		return root->data;
	}

	int rootSum = isSumTree(root->left) + isSumTree(root->right);

	if (root->data == rootSum) { // root data matches sum of children
		return (root->data + rootSum);
	}

	else { // root data & sum mismatch
		return -1;
	}
}
