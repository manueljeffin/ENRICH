/* ==========================================================================
 NextPrime.c
 Aparna Lavanya K
 
 Program to find the next Prime
 Number given a positive number
 ========================================================================== */

#include<stdio.h>
#include<math.h>

int nextPrime(int);

int main(){

	int num, next;
	
	printf("Enter a positive number: ");
	scanf("%d", &num);
	
	if(num < 0){    // cannot have negative numbers
		return 0;
	}
	
	next = nextPrime(num);
	
	printf("\nThe prime number next to %d is: %d", num, next);
	
	return 0;
}

int nextPrime(int num){
	
	int i,count;
	int flag = 1;
	
	if(num < 2){
		return 2;
	}
	
	while(flag){
		
	    count = 0;
	    num++;
	    
		for(i=2; i<= sqrt(num); i++){
			if(num%i == 0){
				count++;
				break; // not a prime number
			}
		}
		
		if(count == 0){  // prime number found
		    flag = 0;  
		}
		
	}
	return num;
}
