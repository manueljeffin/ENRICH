/* ==========================================================================
 Subsets.c
 By Aparna Lavanya K
 
 Program to print all the subsets
 of a given set of numbers
 ========================================================================== */

#include<stdio.h>
#include<stdlib.h>

void subsets(int *arr, int size);

void main() {
	
	int size, i;
	int *arr;

	printf("Enter the number of elements: ");
	scanf("%d", &size);
	
	arr = (int*) malloc(size* sizeof(int));
	
	printf("\nEnter the numbers: ");
	for (i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}
	
	printf("\nThe subsets are: \n");
	subsets(arr, size);
}

void subsets(int *arr, int size) {
	int i, j ;
	int numSubsets = 1 << size;
	
	for (i = 1; i < numSubsets; i++) {
		for (j = 0; j < size; j++) {
			if (i & (1 << j)) {
				printf("%d ", arr[j]);
			}
		}
		printf("\n");
	}

}
