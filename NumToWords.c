/* ==========================================================================
 NumToWords.c
 Aparna Lavanya K

 Program to print the Word Representation
 of a given number (0-999)
 ========================================================================== */

#include<stdio.h>

void numToWords(int num);

int main() {

	int num;
	printf("Enter a number(0-999): ");
	scanf("%d", &num);

	if (num > 999) {
		return 0;
	}
	
  printf("\n");
	numToWords(num);

	return 0;
}

void numToWords(int num) {

	char *words[] = {
		"one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
		"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
		"seventeen", "eighteen", "nineteen", "twenty", "thirty", "forty",
		"fifty", "sixty", "seventy", "eighty", "ninety"};
	int tens, hundreds;

	if (num == 0) {
		printf("zero");
		return;
	}

	else if (num <= 20) {
		printf("%s ", words[num - 1]);
		return;
	}

	else if (num < 100) {
		tens = num / 10;
		printf("%s ", words[17 + tens]); // for numbers like 30, 40, 50,...
		if (tens != 0) {
			printf("%s ", words[(num % 10) - 1]);
		}
		return;
	}

	else {
		hundreds = num / 100;
		printf("%s hundred ", words[hundreds - 1]);
		tens = num % 100;
		if (tens != 0) {
			if (tens <= 20) {
				printf("and %s", words[tens - 1]);
			}
			else { // for numbers like 30, 40, 50,...
				tens = tens / 10;
				printf("and %s ", words[17 + tens]);
				if (tens != 0) {
					printf("%s ", words[(num % 10) - 1]);
				}
			}
		}
	}
	return;
}
