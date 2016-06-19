/* ==========================================================================
 NumToWords.c
 Aparna Lavanya K
 
 Program to print the Word Representation
 of a given number (0-999)
 ========================================================================== */

#include<stdio.h>

void numToWords(int);
void twoDigits(int);

char *words[] = {
	"zero", "one", "two", "three", "four", "five", "six", "seven", "eight",
	"nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
	"sixteen", "seventeen", "eighteen", "nineteen", "twenty", "thirty", "forty",
	"fifty", "sixty", "seventy", "eighty", "ninety"};

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

void twoDigits(int num) {
	if (num < 21) {
		printf("%s ", words[num]);
		return;
	}

	int tens = num / 10;
	printf("%s ", words[18 + tens]); // for numbers like 30, 40, 50,...
	if (tens != 0) {
		printf("%s ", words[num % 10]);
	}
}

void numToWords(int num) {
	int tens, hundreds;

	if (num < 100) {
		twoDigits(num);
	}

	else {
		hundreds = num / 100;
		printf("%s hundred ", words[hundreds]);
		tens = num % 100;
		if (tens != 0) {
			printf("and ");
			twoDigits(tens);
		}
	}
}
