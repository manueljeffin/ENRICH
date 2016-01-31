/* ==========================================================================
 BabylonianSqrt.c
 Aparna Lavanya K
 
 Program to find the Square root
 of a number by Babylon Method
 ========================================================================== */

#include<stdio.h>

float babylonianSqrt(int);

int main(){
	int num;
	float root;
	
	printf("Enter a number: ");
	scanf("%d",&num);
	
	if(num < 0){
	    return 0;
	}
	
	root = babylonianSqrt(num);
	
	printf("\nSquare Root of %d is: %f", num, root);
	
	return 0;
}
float babylonianSqrt(int num){
	
	float n = num, approx = 1;
	float diff = n - approx;
	float accuracy = 0.0001;
	
	while(diff > accuracy){
		n = (n + approx)/2;
		approx = num/n;
		diff = n - approx;
	}
	
	return n;
}



