/* ==========================================================================
   SelfTranspose1.c
   Aparna Lavanya K
   
   Program to find the Transpose of a Square Matrix - Inplace
 ========================================================================== */
#include<stdio.h>
#include<stdlib.h>

int** getMatrix(int, int);
void printMatrix(int**, int, int);
void selfTranspose(int**, int);

int main() {
	int order;
	int** matrix;

	printf("\nEnter the order of the square matrix: ");
	scanf("%d", &order);

	if (order == 0) { // Corner Case : Null matix
		return 0;
	}

	matrix = getMatrix(order, order);
	selfTranspose(matrix, order);
	printf("\nThe self transposed matrix: \n");
	printMatrix(matrix, order, order);

	return 0;
}

int** getMatrix(int row, int col) {

	int i, j; // iteration variables
	int** matrix;

	// dynamically allocate matrix
	matrix = (int**)malloc(row*sizeof(int *));
	for (i = 0; i < row; i++) {
		matrix[i] = (int*)malloc(col*sizeof(int));
	}

	printf("\nEnter the elements of the matrix: \n");
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}
	return matrix;
}

void printMatrix(int** matrix, int row, int col) {

	int i, j; // iteration variables
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
}

void selfTranspose(int** matrix, int order) {
	// transpose the square matrix in-place
	int i, j; // iteration variables
	int temp;
	for (i = 0; i < order - 1; i++) {
		for (j = i + 1; j < order; j++) {
			temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}
}
