/* ==========================================================================

 DelayedPrinting.c
 Aparna Lavanya K

 Program to print "HAPPY PONGAL"
 With time delay between each character

 ========================================================================== */
 
 
#include<stdio.h>
#include<unistd.h>

int main() {

	char msg[] = "HAPPY PONGAL";
	int i;

	for (i = 0; msg[i] != '\0'; i++) {
		printf("%c", msg[i]);
		sleep(3);
	}

	return 0;
}
