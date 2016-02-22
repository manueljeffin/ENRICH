/* ==========================================================================
 AddLinkedLists.c
 Aparna Lavanya K

 Program to find the Sum of two
 numbers using Linked Lists
 ========================================================================== */

#include<stdio.h>
#include<stdlib.h>

struct node {

	int data;
	struct node *next;
};

struct node* insertNode(int, struct node *);
struct node* makeList(int);
struct node* reverseList(struct node *);
struct node* addLists(struct node *, struct node *);
void displayNum(struct node *);

int main() {

	int num1, num2;
	printf("Enter two numbers: ");
	scanf("%d %d", &num1, &num2);

	if (num1 < 0 || num2 < 0) {
		return 0;
	}

	struct node *h1 = makeList(num1);
	struct node *h2 = makeList(num2);

	struct node *h3 = addLists(h1, h2); // sum list

	printf("\nSum: ");
	displayNum(h3);

	return 0;
}

struct node* insertNode(int data, struct node *head) {

	struct node *newNode = (struct node*) malloc(sizeof(struct node));

	if (newNode != NULL) {
		newNode->data = data;
		newNode->next = head;
	}

	return newNode;
}

struct node* makeList(int num) {
	struct node *head = NULL;

	do {
		head = insertNode(num % 10, head);
		num /= 10;
	}
	while (num > 0);

	return head;
}

struct node* reverseList(struct node *head) {
	struct node *newHead = NULL;

	struct node *temp;

	while (head != NULL) {
		temp = head->next;
		head->next = newHead;
		newHead = head;
		head = temp;
	}

	return newHead;
}

struct node* addLists(struct node *h1, struct node *h2) {

	h1 = reverseList(h1);
	h2 = reverseList(h2);

	int carry = 0, sum;
	struct node *h3 = NULL; // sum list

	while (h1 != NULL && h2 != NULL) // both lists are not empty
	{
		sum = h1->data + h2->data + carry;

		if (sum > 9) {
			carry = 1;
			sum %= 10;
		}
		else {
			carry = 0;
		}

		h3 = insertNode(sum, h3);

		h1 = h1->next;
		h2 = h2->next;
	}

	while (h1 != NULL) // when h1 has more nodes than h2
	{
		sum = h1->data + carry;

		if (sum > 9) {
			carry = 1;
			sum %= 10;
		}
		else {
			carry = 0;
		}

		h3 = insertNode(sum, h3);
		h1 = h1->next;
	}

	while (h2 != NULL) // when h2 has more nodes than h1
	{
		sum = h2->data + carry;

		if (sum > 9) {
			carry = 1;
			sum %= 10;
		}
		else {
			carry = 0;
		}

		h3 = insertNode(sum, h3);
		h2 = h2->next;
	}

	if (carry) // carry generated at the end
	{
		h3 = insertNode(carry, h3);
	}

	return h3;
}

void displayNum(struct node *head) {
	while (head != NULL) {
		printf("%d", head->data);
		head = head->next;
	}
	printf("\n");
}
