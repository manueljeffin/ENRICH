/* ==========================================================================
 ReverseOfNumber.c
 Aparna Lavanya K

 Program to Reverse a given Number,
 Iteratively
 ========================================================================== */

#include <stdio.h>

int reverseNumber(int);

void main() {
	int num, rev;

	printf("Enter a number: ");
	scanf("%d", &num);

	printf("\nReversed number is: %d", reverseNumber(num));
}

int reverseNumber(int num) {
	int rev = 0;

	while (num > 0) {
		rev = num % 10;
		num = num / 10;
		printf("%d", rev);
	}

	return rev;
}
