/* ==========================================================================
 ReverseOfNumber.c
 Aparna Lavanya K

 Program to Reverse a given Number,
 Iteratively
 ========================================================================== */

#include <stdio.h>

int reverseNumber(int, int*);

void main() {
      int num, rev, digits = 0;

	     printf("Enter a number: ");
	     scanf("%d", &num);
	
	     rev = reverseNumber(num, &digits);

	     printf("\nReversed number is: %0*d\n", digits, rev);   //prints the leading zeros too
}

int reverseNumber(int num, int* digits) {
	    int rev = 0;

	    while (num > 0) {
	    
		        rev = rev*10 + num % 10;
		        num = num / 10;
		        (*digits)++;      
	}

	   return rev;
}

