/* ==========================================================================
 BitCount.c
 Aparna Lavanya K

 Program to print the Number of Bits
 Required to Represent a given Decimal number
 ========================================================================== */

#include<stdio.h>

int bitCount(int);

int main() {
	int num, count;

	printf("Enter a number: ");
	scanf("%d", &num);

	count = bitCount(num);

	printf("Number of bits for representing %d is: %d", num, count);

	return 0;

}

int bitCount(int num) {

	if (num == 0) {
		return 1;
	}

	int count = 0;

	while (num) {
		num >>= 1;
		count++;
	}

	return count;
}
