/* ==========================================================================
 BitManipulations.c
 Aparna Lavanya K

 Program to Generate various results
 Using Bit Manipulations
 ========================================================================== */

#include<stdio.h>

unsigned char setBit(unsigned char, unsigned char);
unsigned char unsetBit(unsigned char, unsigned char);
unsigned char toggleBit(unsigned char, unsigned char);
unsigned char toggleExceptBit(unsigned char, unsigned char);
unsigned char rightRotate(unsigned char);
unsigned char leftRotate(unsigned char);
unsigned char swapNibble(unsigned char);
void printByte(unsigned char);

int main() {

	unsigned char num, bit;
	unsigned char result;

	printf("Enter a Number");
	scanf("%hhu", &num);

	printf("\nEnter the Bit Index");
	scanf("%hhu", &bit);

	if (bit > 7) {
		return 0;
	}

	printf("\n");

	printf("\nGiven Number: ");
	printByte(num);
	printf("\t\t\t Decimal Equivalent: %d", num);

	result = setBit(num, bit);
	printf("\nBit %hhu set to 1: ", bit);
	printByte(result);
	printf(" \t\t\t Decimal Equivalent: %d", result);

	result = unsetBit(num, bit);
	printf("\nBit %hhu set to 0: ", bit);
	printByte(result);
	printf(" \t\t\t Decimal Equivalent: %d", result);

	result = toggleBit(num, bit);
	printf("\nToggling bit %hhu: ", bit);
	printByte(result);
	printf("\t\t\t Decimal Equivalent: %d", result);

	result = toggleExceptBit(num, bit);
	printf("\nToggling except bit %hhu: ", bit);
	printByte(result);
	printf("\t\t\t Decimal Equivalent: %d", result);

	result = rightRotate(num);
	printf("\nRight Rotate: ");
	printByte(result);
	printf("\t\t\t Decimal Equivalent: %d", result);

	result = leftRotate(num);
	printf("\nLeft Rotate: ");
	printByte(result);
	printf("\t\t\t Decimal Equivalent: %d", result);

	result = swapNibble(num);
	printf("\nSwap Nibble: ");
	printByte(result);
	printf("\t\t\t Decimal Equivalent: %d", result);

	return 0;

}

unsigned char setBit(unsigned char num, unsigned char bit) {

	unsigned char mask = 1 << bit;

	return (num | mask);
}

unsigned char unsetBit(unsigned char num, unsigned char bit) {

	unsigned char mask = 1 << bit;
	mask = ~mask;

	return (num & mask);
}

unsigned char toggleBit(unsigned char num, unsigned char bit) {

	unsigned char mask = 1 << bit;

	return (num ^ mask);
}

unsigned char toggleExceptBit(unsigned char num, unsigned char bit) {

	unsigned char mask = 1 << bit;

	return (~num ^ mask);
}

unsigned char rightRotate(unsigned char num) {

	unsigned result = (num >> 1) | (num << 7);

	return result;

}

unsigned char leftRotate(unsigned char num) {

	unsigned result = (num << 1) | (num >> 7);

	return result;

}

unsigned char swapNibble(unsigned char num) {

	unsigned result = (num << 4) | (num >> 4);

	return result;

}

void printByte(unsigned char num) {

	char x;
	int i;

	for (i = 7; i >= 0; i--) {

		x = (num & (1 << i)) ? '1' : '0';

		printf("%c", x);
	}
}
