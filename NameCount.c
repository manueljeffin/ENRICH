/* ==========================================================================
 NameCount.c
 Aparna Lavanya K

 Program to display the
 Student name details
 ========================================================================== */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student {
	int id;
	char name[30];
	char firstName[10];
};

struct hash {
	char firstName[10];
	int count;
	int ids[10];//stores the varios indexes for a same name
}*h;

void findFirstNames(struct student*, int);
int hashing(struct student*, int);
int findKey(char*, int);

int main() {
	int numStud;
	int i, j;
	printf("Enter the number of students: ");
	scanf("%d", &numStud);
	
	if(numStud<1){
	  return 0;
	}

	struct student *s = (struct student*)malloc(numStud*sizeof(struct student));

	printf("\nEnter the Students: \n");
	for (i = 0; i < numStud; i++) {
		scanf("%d %[^\n]", &s[i].id, s[i].name);
	}

	findFirstNames(s, numStud);        // extract first name

	int keysCount = hashing(s, numStud);       // count of hashkeys

	for (i = 0; i < keysCount; i++) {
		printf("%s, %d, [%d", h[i].firstName, h[i].count, h[i].ids[0]);
		for (j = 1; j < h[i].count; j++) {
			printf(",%d", h[i].ids[j]);
		}
		printf("]\n");
	}

	return 0;
}

void findFirstNames(struct student *s, int numStud) { //we will have only first names in firstName[]
	int i, j, k;

	for (i = 0; i < numStud; i++) {
		k = 0;
		for (j = 0; j < strlen(s[i].name); j++) {

			if (s[i].name[j] == '.') {
				k = 0;
				continue;
			}
			else if (s[i].name[j] == ' ') {
				break;
			}
			else {
				s[i].firstName[k++] = s[i].name[j];
			}

		}
		s[i].firstName[k] = '\0';

	}
}

int findKey(char* name, int keysCount) {
	int i;
	
	for (i = 0; i < keysCount; i++) {
		if (strcmp(h[i].firstName, name) == 0) {
			return i;   //key is found, so return its index
		}
	}
	return -1;
}

int hashing(struct student *s, int numStud) {//brilliant way of hashing
	int i;
	h = (struct hash*)malloc(numStud*sizeof(struct hash));
	int keysCount = 0;
	int index;
	for (i = 0; i < numStud; i++) {
		index = findKey(s[i].firstName, keysCount);
		
		if (index != -1) {  //find index of key
			h[index].ids[h[index].count] = s[i].id;
			h[index].count++;
		}
		
		else {    //make new entry
			strcpy(h[keysCount].firstName, s[i].firstName);
			h[keysCount].count = 0;
			h[keysCount].ids[h[keysCount].count] = s[i].id;
			h[keysCount].count++;
			keysCount++;
		}
	}
	return keysCount;
}
