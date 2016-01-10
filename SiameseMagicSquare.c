/* ==========================================================================

 SiameseMagicSquare.c
 Aparna Lavanya K

 Program to find the n-ordered Magic Square
 Using Siamese Method

 ========================================================================== */

#include<stdio.h>
#include<stdlib.h>

void printMagicSquare(int**, int);
void siameseOddMagicSquare(int**, int);

void main() {

	int i;
	int order;
	int **matrix;

	printf("\nEnter the order of the magic square : ");
	scanf("%d", &order);

	if (order == 0) { // Corner Case : Null matix
		return;
	}

	if (order % 2 == 0) {
		// Siamese method works for only ODD ordered magic squares
		return;
	}

	// dynamically allocate matrix
	matrix = (int**)calloc(order, sizeof(int*));
	for (i = 0; i < order; i++) {
		matrix[i] = (int*)calloc(order, sizeof(int));
	}

	siameseOddMagicSquare(matrix, order);

	printf("\nThe magic square: \n");
	printMagicSquare(matrix, order);
}

void printMagicSquare(int** matrix, int order) {

	int i, j; // iteration variables

	for (i = 0; i < order; i++) {
		for (j = 0; j < order; j++) {
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}

}

void siameseOddMagicSquare(int** matrix, int order) {

	if (order == 1) { // Base case
		printf("1");
		return;
	}

	int num = order * order;
	int i, j, k;

	i = 0;
	j = order / 2;

	for (k = 1; k <= num; k++) {

		matrix[i][j] = k;

		i--;
		j++;

		if (k % order == 0) {
			i += 2;
			--j;
		}

		else {

			if (j == order) {
				j -= order;
			}

			else if (i < 0) {
				i += order;
			}

		}
	}
}
