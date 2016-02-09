/* ==========================================================================
 CSVFileParsing.c
 Aparna Lavanya K

 Program to parse the data in a CSV and Calculate the
 Average marks and Top Scorers in each subject
 ========================================================================== */

#include<stdio.h>
#include<stdlib.h>

struct student {
	char name[25];
	int serialNo;
	int marks[5];
}*stud;

void averageMarks(struct student *stud, int noStud, float avg[]);
void highestScore(struct student *stud, int noStud, char *high[]);

int main() {

	char heading[7][25];
	int noStud = 0, i, j;
	char ch;

	FILE *fp;
	fp = fopen("Student.csv", "r");

	if (fp == NULL) {
		printf("File not found!");
		return 0;
	}

	// get number of students
	do {
		ch = fgetc(fp);
		if (ch == '\n') {
			noStud++;
		}
	}
	while (ch != EOF);

	// dynamically allocate memory
	stud = (struct student*) malloc((noStud)*sizeof(struct student));

	rewind(fp);

	// read file and store data
	for (i = 0; i < 6; i++) {
		fscanf(fp, "%[^,],", heading[i]);

	}
	fscanf(fp, "%[^\n]", heading[i]);

	for (i = 0; i < noStud; i++) {

		fscanf(fp, "%d,%[^,],%d,%d,%d,%d,%d", &stud[i].serialNo, stud[i].name,
			&stud[i].marks[0], &stud[i].marks[1], &stud[i].marks[2],
			&stud[i].marks[3], &stud[i].marks[4]);

	}

	float avg[5] = {0};
	char *high[5];

	averageMarks(stud, noStud, avg);
	highestScore(stud, noStud, high);

	printf("\nAVERAGE MARKS :\n\n");

	for (i = 0; i < 5; i++) {
		printf("In %s : %f\n", heading[i + 2], avg[i]);
	}

	printf("\nTOP SCORERS :\n\n");

	for (i = 0; i < 5; i++) {
		printf("In %s : %s\n", heading[i + 2], high[i]);
	}

	return 0;
}

void averageMarks(struct student *stud, int noStud, float avg[]) {
	int i, j;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < noStud; j++) {
			avg[i] += stud[j].marks[i];
		}
	}
	for (i = 0; i < 5; i++) {
		avg[i] /= noStud;
	}
}

void highestScore(struct student *stud, int noStud, char *high[]) {
	int i, j;
	int max[5] = {0};
	for (i = 0; i < 5; i++) {
		for (j = 0; j < noStud; j++) {
			if (stud[j].marks[i] > max[i]) {
				max[i] = stud[j].marks[i];
				high[i] = stud[j].name;
			}
		}
	}
}
