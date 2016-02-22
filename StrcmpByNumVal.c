/* ==========================================================================
 StrcmpByNumVal.c
 Aparna Lavanya K

 Program to sort an array of Strings
 based on its Numerical Value
 ========================================================================== */

#include<stdio.h>
#include<string.h>

void swapStrings(char **, char **);
void sortByLength(char **, int);
void strcmpByNum(char **, int);

int main() {
	char *numbers[] = {"1", "3", "11", "100", "19", "2", "5"};
	int num = 7;
	int i, j;

	sortByLength(numbers, num); // sort by length first
	strcmpByNum(numbers, num); // then sort by value

	for (i = 0; i < num; i++) {
		printf("%s\n", numbers[i]);
	}

	return 0;
}

void sortByLength(char **numbers, int num) {
	int i, j;

	for (i = 0; i < num - 1; i++) {
		for (j = i + 1; j < num; j++) {
			if (strlen(numbers[i]) > strlen(numbers[j])) {
				swapStrings(&numbers[i], &numbers[j]);
			}
		}
	}
}

void swapStrings(char **str1, char **str2) {
	char *temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

void strcmpByNum(char **numbers, int num) {
	int i, j, k;

	for (i = 0; i < num - 1; i++) {
		for (j = i + 1; j < num; j++) {
			if (strlen(numbers[i]) == strlen(numbers[j])) { // compare

				k = 0;
				while (numbers[i][k] == numbers[j][k]) {
					k++;
				}

				if (numbers[i][k] > numbers[j][k]) {
					swapStrings(&numbers[i], &numbers[j]);
				}
			}
		}
	}
}
