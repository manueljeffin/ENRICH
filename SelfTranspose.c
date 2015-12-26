#include<stdio.h>
#include<stdlib.h>

int** getSquareMatrix(int);
void printSquareMatrix(int**, int);
void selfTranspose(int**, int);

int main() {
	int order;
	int** matrix;

	printf("\nEnter the order of the square matrix: ");
	scanf("%d", &order);

	if (order == 0) { // Corner Case : Null matix
		return 0;
	}

	matrix = getSquareMatrix(order);
	selfTranspose(matrix, order);
	printf("\nThe self transposed matrix: \n");
	printSquareMatrix(matrix, order);

	return 0;
}

int** getSquareMatrix(int order) {

	int i, j; // iteration variables
	int** matrix;

	// dynamically allocate matrix
	matrix = (int**)malloc(order*sizeof(int *));
	for (i = 0; i < order; i++) {
		matrix[i] = (int*)malloc(order*sizeof(int));
	}

	printf("\nEnter the elements of the matrix: \n");
	for (i = 0; i < order; i++) {
		for (j = 0; j < order; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}
	return matrix;
}

void printSquareMatrix(int** matrix, int order) {

	int i, j; // iteration variables
	for (i = 0; i < order; i++) {
		for (j = 0; j < order; j++) {
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
