/* ==========================================================================
 StudentResults.c
 Aparna Lavanya K

 Program to Rank Students
 Based on their Results
 ========================================================================== */

#include<stdio.h>

struct student {
	char name[25];
	int rollNo;
	int marks[5];
};

struct result {
	struct student stud;
	int passFlag;
	int total;
	float aggregate;
	int rank;
};

void findTotalAggreg(struct result *ptr, int numStud);
int computeRank(struct result *ptr, int numStud);
void swap(struct result *x, struct result *y);

int main() {

	int numStud = 15;
	int i, j, passCount;
	struct result res[numStud];
	char heading[7][25];

	FILE *fp;
	fp = fopen("marks.csv", "r");

	if (fp == NULL) {
		printf("File not found!");
		return 0;
	}

	// read file and store data
	for (i = 0; i < 7; i++) {
		fscanf(fp, "%[^,\n],", heading[i]);

	}

	for (i = 0; i < numStud; i++) {

		fscanf(fp, "%d,%[^,],%d,%d,%d,%d,%d", &res[i].stud.rollNo,
			res[i].stud.name, &res[i].stud.marks[0], &res[i].stud.marks[1],
			&res[i].stud.marks[2], &res[i].stud.marks[3],
			&res[i].stud.marks[4]);

	}

	fclose(fp);

	// calculating results
	findTotalAggreg(res, numStud);
	passCount = computeRank(res, numStud);

	// writing results into file
	fp = fopen("rank.csv", "w");

	fprintf(fp,
		"Rank,RollNo,Name,Aggregate,Total,Maths,Physics,Chemistry,Language1,Language2\n");

	for (i = 0; i < passCount; i++) {
		fprintf(fp, "%d,%d,%s,%f,%d,%d,%d,%d,%d,%d\n", res[i].rank,
			res[i].stud.rollNo, res[i].stud.name, res[i].aggregate,
			res[i].total, res[i].stud.marks[0], res[i].stud.marks[1],
			res[i].stud.marks[2], res[i].stud.marks[3], res[i].stud.marks[4]);
	}

	return 0;
}

void findTotalAggreg(struct result *ptr, int numStud) {
	int i, j;

	// check for pass percentage
	for (i = 0; i < numStud; i++) {
		ptr[i].passFlag = 1;
		for (j = 0; j < 5; j++) {
			if (ptr[i].stud.marks[j] < 70) {
				ptr[i].passFlag = -1; // fail
				break;
			}
		}
	}

	// compute total and aggregate
	for (i = 0; i < numStud; i++) {
		ptr[i].total = 0;

		// total calculation
		for (j = 0; j < 5; j++) {
			ptr[i].total += ptr[i].stud.marks[j];
		}

		// aggregate calculation
		ptr[i].aggregate =
			((ptr[i].stud.marks[0] / 2) +
			((ptr[i].stud.marks[1] + ptr[i].stud.marks[2]) / 4));
	}
}

void swap(struct result *x, struct result *y) {
	struct result temp = *x;
	*x = *y;
	*y = temp;
}

int computeRank(struct result *ptr, int numStud) {
	int i, j;

	// sort students
	for (i = 0; i < numStud - 1; i++) {
		for (j = i + 1; j < numStud; j++) {
			if (ptr[i].aggregate < ptr[j].aggregate) {
				swap(&ptr[i], &ptr[j]);
			}
			else if (ptr[i].aggregate == ptr[j].aggregate && ptr[i].total <
				ptr[j].total) {
				swap(&ptr[i], &ptr[j]);
			}
			else if (ptr[i].total == ptr[j].total && ptr[i].stud.marks[3] <
				ptr[j].stud.marks[3]) {
				swap(&ptr[i], &ptr[j]);
			}
			else if (ptr[i].stud.marks[3] == ptr[j].stud.marks[3] && ptr[i]
				.stud.marks[4] < ptr[j].stud.marks[4]) {
				swap(&ptr[i], &ptr[j]);
			}
		}
	}

	// assign ranks
	i = 0;
	while (ptr[i].passFlag != -1 && i < numStud) {
		ptr[i].rank = ++i;
	}

	return i; // number of passed students
}
