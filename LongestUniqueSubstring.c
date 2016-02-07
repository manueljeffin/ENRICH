/* ==========================================================================
 LongestUniqueSubstring.c
 Aparna Lavanya K

 Program to find the Length and Print the
 Longest Unique Substring of a given string
 ========================================================================== */

#include<stdio.h>
#include<stdlib.h>

char* longestUniqueSubstring(char str[], int *len);

int main() {
	char str[25];
	char *substr;
	int len;

	printf("Enter a string (in lowercase): ");
	scanf("%s", str);

	substr = longestUniqueSubstring(str, &len);

	printf("\nLongest Unique Substring is \"%s\" of Length %d", substr, len);

	return 0;
}

char* longestUniqueSubstring(char str[], int *len) {
	*len = 0; // length of substr

	int *flag = (int *) calloc(26, sizeof(char));
	// to keep track of characters visited
	char* substr = (char *) malloc(sizeof(str));

	int i, j, pos;
	int start = 0;

	char current;
	int length = 0; // length of str

	for (i = 0; str[i] != '\0'; i++) {
		current = str[i];
		length++;

		if (flag[current - 'a'] == 1) {  // repetition found

			if (i - start > *len) {    // update if larger string found
				*len = i - start;
				pos = start;
			}

			for (j = start; j < i; j++) {
				if (str[j] == current) {   // find positon of conflict
					start = j + 1;        // update start
					break;
				}
				flag[str[j] - 'a'] = 0;   // reset flag values
			}

		}

		else {       // no repetition so mark flag
			flag[current - 'a'] = 1;
		}

	}

	if (length - start > *len) {     // update if larger string is at end
		pos = start;
		*len = length - start;
	}

	// extract substring
	for (i = 0; i < *len; i++) {
		substr[i] = str[i + pos];
	}
	substr[*len] = '\0';

	return substr;
}
