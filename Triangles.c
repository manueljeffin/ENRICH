/* ==========================================================================

 Triangles.c
 By Aparna Lavanya K

 Program to print the Floyd's Triangle,
 Pascal's Triangle and Odd-Even Triangle

 ========================================================================== */

#include<stdio.h>

void floydsTriangle(int num);
void pascalsTriangle(int num);
void swap(int* a, int* b);
void oddEvenTriangle(int num);

int main() {
	int num;

	printf("Enter the number of lines for the triangle : ");
	scanf("%d", &num);

	printf("\nFloyd's Triangle : \n");
	floydsTriangle(num);

	printf("\nPascals's Triangle : \n");
	pascalsTriangle(num);

	printf("\nOdd-Even Triangle : \n");
	oddEvenTriangle(num);

	return 0;
}

void floydsTriangle(int num) {

	int i, j;
	int value = 1;

	for (i = 1; i <= num; i++) {
		for (j = 1; j <= i; j++) {
			printf("%d ", value++);
		}
		printf("\n");
	}
}

void pascalsTriangle(int num) {
	int c, i, j;

	for (i = 1; i <= num; i++) {
		c = 1;
		for (j = 0; j <= i; j++) {
			printf("%d ", c);
			c = c * (i - j) / (j + 1);
		}
		printf("\n");
	}
}

void swap(int* x, int* y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void oddEvenTriangle(int num) {
	int value = 1;
	int buffer = 2;
	int i, j;

	for (i = 1; i <= num; i++) {
		for (j = 1; j <= i; j++) {
			printf("%d ", value);
			value += 2;
		}
		swap(&value, &buffer);
		printf("\n");
	}
}
