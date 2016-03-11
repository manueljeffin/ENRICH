/* ==========================================================================
 SumOfLeftLeaves.c
 Aparna Lavanya K
 
 Program to compute the Sum of 
 Left Leaves of a Binary Tree
 ========================================================================== */
 
#include<stdio.h>
#include<stdlib.h>

struct node* createNode(int data);
int isLeaf(struct node* root);
void sumOfLeftLeaves(struct node* root, int* sum);

struct node {
	int data;
	struct node* left;
	struct node* right;
};

/*
      10
     /  \
    9    8
        / \
       7   6
          /
        5
*/

int main() {
	int sum = 0;

	struct node *root = createNode(10);

	root->left = createNode(9);
	root->right = createNode(8);

	root->right->left = createNode(7);
	root->right->right = createNode(6);

	root->right->right->left = createNode(5);

	sumOfLeftLeaves(root, &sum);

	printf("Sum of all left leaves: %d", sum);

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

void sumOfLeftLeaves(struct node* root, int* sum) {

	if (root == NULL) {
		return;
	}

	// left child is also a leaf add to sum
	if (root->left && isLeaf(root->left)) {

		*sum += root->left->data;
	}

	sumOfLeftLeaves(root->left, sum);
	sumOfLeftLeaves(root->right, sum);
}
