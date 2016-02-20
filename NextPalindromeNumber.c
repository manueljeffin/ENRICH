/* ==========================================================================
 NextPalindromeNumber.c
 Aparna Lavanya K

 Program to generate the next immediate
 palindrome number given a positive number
 ========================================================================== */

#include<stdio.h>

int nextPalindrome(int);
int extractDigits(int, int[]);

int main() {

	int num;
	printf("Enter a number: ");
	scanf("%d", &num);

	if (num < 0) {
		return 0;
	}

	printf("\nThe next immediate palindrome: %d", nextPalindrome(num));

	return 0;
}

int extractDigits(int num, int digits[]) {
	int digitCount = 0;
	while (num > 0) {
		digits[digitCount++] = num % 10;
		num = num / 10;
	}
	return digitCount;
}

int nextPalindrome(int num) {
	if (num <= 8) {
		return num + 1;
	}

	int digits[10] = {0};
	int digitCount = extractDigits(num + 1, digits);
	int i = 0, j = digitCount - 1;
	int palindrome = 0;
	int flag = 1; // to indicate if number was decreased

	while (i <= j) {
		if (digits[i] > digits[j]) {
			digits[i] = digits[j];
			flag = 0; // number was decreased
		}
		else if (digits[i] < digits[j]) {
			digits[i] = digits[j];
			flag = 1;
		}
		i++;
		j--;
	}
	i--;

	// i now points to the middle element
	if (flag == 0) {
		// since number was decreased increment digit in mean position
		if (digits[i] != 9) {
			digits[i]++;
			digits[digitCount - 1 - i] = digits[i];
		}
		else { // for numbers like 191, 1991,...
			while (digits[i] == 9) {
				digits[i] = 0;
				digits[digitCount - 1 - i] = digits[i];
				i--;
			}
			digits[i]++;
			digits[digitCount - 1 - i] = digits[i];
		}
	}

	// form number
	palindrome = digits[0];
	for (i = 1; i < digitCount; i++) {
		palindrome = palindrome * 10 + digits[i];
	}
	return palindrome;
}
