/* ==========================================================================
 BaseConvert.c
 Aparna Lavanya K

 Program to Represent a given Decimal
 number in a requested Base (2 to 36 only)
 ========================================================================== */

#include<stdio.h>

void baseConvert(int, int);

int main() {

	int num, base;

	printf("Enter a number :");
	scanf("%d", &num);

	printf("Enter a base :");
	scanf("%d", &base);

	baseConvert(num, base);

	return 0;
}

void baseConvert(int num, int base) {

	char digits[36] = {
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D',
		'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
		'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

	char result[50], temp;

	int n = num, count = 0;
	int half, i;

	if (base < 2 || base > 36) { // only bases from 2 to 36 is supported
		printf("Try Again with different base");
		return;
	}

	if (num < base) {
		printf("The number %d in base %d is: %d", num, base, num);
		return;
	}

	while (n > 0) { // convert to given base
		result[count++] = digits[n % base];
		n /= base;
	}
	result[count] = '\0';

	half = count / 2;
	// reverse the string
	for (i = 0; i < half; i++) {
		temp = result[i];
		result[i] = result[count - i - 1];
		result[count - i - 1] = temp;
	}
	printf("The number %d in base %d is: %s", num, base, result);
}
