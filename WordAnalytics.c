
/* ==========================================================================
 WordAnalytics.c
 Aparna Lavanya K

 Program to compute various Word and Letter
 Analytics from an ASCII Text File.
 ========================================================================== */

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

struct hash {
	char word[15];
	int freq;
};

void hashing(char* word, struct hash *words, int* hashCount);
int wordify(char* para, char** wordList, int* wordsCount);
int letterFrequency(char* para, int* letterFreq);
int symbolCount(char* para);
int mostCommonWord(struct hash *words, int hashCount);
int threeMostCommonWords(struct hash *words, int hashCount, int* threeWords);
int mostCommonLetter(int* letterFreq);
int threeMostCommonLetters(int* letterFreq, int* threeLetters);
void firstWordHash(char* para, struct hash *firstWords, int* firstWordsCount);
char* mostCommonFirstWord(struct hash *firstWords, int firstWordsCount);
int wordsUsedOnce(struct hash *words, int hashCount);
int lettersNotUsed(int* letterFreq, int* notUsed);

int main() {
	struct hash words[100], firstWords[10];
	char* wordList[30];
	int i, temp;
	int letterFreq[26] = {0};
	int wordsCount = 0;
	int firstWordsCount = 0;
	int symbolsCount = 0;
	int lettersCount = 0;
	int hashCount = 0;
	char text[1000];

	FILE *fp = fopen("File.txt", "r");
	// read complete file
	fscanf(fp, "%[^\r]", text);
	fclose(fp);

	const char delimiter[2] = "\n";
	char *para;

	// break into paragraphs
	para = strtok(text, delimiter);

	while (para != NULL) {
		// break para into words
		temp = wordify(para, wordList, &wordsCount);

		for (i = 0; i < temp; i++) { // hash each word
			hashing(wordList[i], words, &hashCount);
		}

		lettersCount += letterFrequency(para, letterFreq);
		symbolsCount += symbolCount(para);

		// hash first word of para
		firstWordHash(para, firstWords, &firstWordsCount);

		para = strtok(NULL, delimiter);
	}

	printf("\nTotal Number of Words: %d\n", wordsCount);

	printf("\nTotal Number of Letters: %d\n", lettersCount);

	printf("\nTotal Number of Symbols: %d\n", symbolsCount);

	printf("\nLetter Frequency: \n\n");
	for (i = 0; i < 26; i++) {
		printf("%c\t%d\n", i + 'A', letterFreq[i]);
	}

	int threeWords[3];
	int wordFlag = threeMostCommonWords(words, hashCount, threeWords);
	if (wordFlag == -1) {
		printf("\nLess Than Three Words Entered!");
	}
	else {
		printf("\nThree Most Common Words:\n\n");
		for (i = 0; i < 3; i++) {
			printf("%d. %s\n", i + 1, words[threeWords[i]].word);
		}
	}

	int threeLetters[3];
	int letterFlag = threeMostCommonLetters(letterFreq, threeLetters);
	if (letterFlag == -1) {
		printf("\nLess Than Three Letters Entered!");
	}
	else {
		printf("\nThree Most Common Letters:\n\n");
		for (i = 0; i < 3; i++) {
			printf("%d. %c\n", i + 1, threeLetters[i] + 65);
		}
	}

	printf("\nMost Common First Word of a Paragraph: %s\n",
		mostCommonFirstWord(firstWords, firstWordsCount));

	printf("\nNumber of Words Used Only Once: %d\n",
		wordsUsedOnce(words, hashCount));

	int notUsed[26] = {0};
	int notUsedCount = lettersNotUsed(letterFreq, notUsed);
	printf("\nLetters Not Used: (Total: %d)\n", notUsedCount);
	for (i = 0; i < notUsedCount; i++) {
		printf("%c\n", notUsed[i] + 65);
	}

	return 0;
}

void hashing(char* word, struct hash *words, int* hashCount) {
	int i;
	int flag = 0;

	for (i = 0; i < (*hashCount); i++) { // hash key found
		if (strcmp(word, words[i].word) == 0) {
			words[i].freq++;
			flag = 1;
			break;
		}
	}

	if (flag == 0) { // hash key does not exist

		strcpy(words[*hashCount].word, word); // so create new hash key
		words[*hashCount].freq = 1;
		(*hashCount)++; // increment count of hash words
	}
}

int wordify(char* para, char** wordList, int* wordsCount) {
	int i = 0, j = 0;
	int count = 0;
	char word[15];

	while (para[i] != '\0') {
		if (isalpha(para[i])) {
			// extract word
			word[j++] = tolower(para[i++]);
		}

		else {
			if (j > 0) {
				word[j] = '\0';
				wordList[*wordsCount] = (char*)malloc((strlen(word) + 1)*sizeof(char));
				// update word to list
				strcpy(wordList[*wordsCount], word);
				(*wordsCount)++;
				count++;
			}
			i++;
			j = 0;
		}
	}
	return count;
}

int letterFrequency(char* para, int* letterFreq) {
	int i = 0;
	int letterCount = 0; // total number of letters

	while (para[i] != '\0') {
		if (isalpha(para[i])) {
			letterFreq[tolower(para[i]) - 'a']++;
			letterCount++;
		}
		i++;
	}

	return letterCount;
}

int symbolCount(char* para) {
	int i = 0;
	int count = 0;

	while (para[i] != '\0') {
		if (!isalnum(para[i])) {
			count++;
		}
		i++;
	}

	return count;
}

int mostCommonWord(struct hash *words, int hashCount) {
	int i;
	int max = -1;
	int wordPos = 0;

	for (i = 0; i < hashCount; i++) {
		if (max < words[i].freq) {
			max = words[i].freq;
			wordPos = i;
		}
	}

	return wordPos;
}

int threeMostCommonWords(struct hash *words, int hashCount, int* threeWords) {
	int i;

	if (hashCount < 3) {
		return -1;
	}

	for (i = 0; i < 3; i++) {
		threeWords[i] = mostCommonWord(words, hashCount);
		words[threeWords[i]].freq *= -1; // mark the visited maximum
	}

	for (i = 0; i < 3; i++) {
		words[threeWords[i]].freq *= -1; // revert to old values
	}

	return 1;
}

int mostCommonLetter(int* letterFreq) {
	int i, max = -1;
	int letterPos = 0;

	for (i = 0; i < 26; i++) {
		if (max < letterFreq[i]) {
			max = letterFreq[i];
			letterPos = i;
		}
	}

	return letterPos;
}

int threeMostCommonLetters(int* letterFreq, int* threeLetters) {
	int i;

	for (i = 0; i < 3; i++) {
		threeLetters[i] = mostCommonLetter(letterFreq);

		if (letterFreq[threeLetters[i]] == 0) {
			return -1; // less than three letters entered
		}

		letterFreq[threeLetters[i]] *= -1; // mark the visited maximum
	}

	for (i = 0; i < 3; i++) {
		letterFreq[threeLetters[i]] *= -1; // revert to old values
	}

	return 1;
}

void firstWordHash(char* para, struct hash *firstWords, int* firstWordsCount) {
	char firstWord[15];
	int i = 0, j = 0;
	int flag = 0;

	while (isalpha(para[i])) {
		// extract first word
		firstWord[j++] = tolower(para[i++]);
	}
	firstWord[j] = '\0';

	for (i = 0; i < (*firstWordsCount); i++) { // hash key found
		if (strcmp(firstWord, firstWords[i].word) == 0) {
			firstWords[i].freq++;
			flag = 1;
			break;
		}
	}

	if (flag == 0) { // hash key does not exist
		strcpy(firstWords[*firstWordsCount].word, firstWord);
		// so create new hash key
		firstWords[*firstWordsCount].freq = 1;
		(*firstWordsCount)++;

	}
}

char* mostCommonFirstWord(struct hash *firstWords, int firstWordsCount) {
	int i;
	int max = 0;
	char* mostCommon;

	for (i = 0; i < firstWordsCount; i++) {
		if (max < firstWords[i].freq) {
			max = firstWords[i].freq;
			mostCommon = firstWords[i].word;
		}
	}

	return mostCommon;
}

int wordsUsedOnce(struct hash *words, int hashCount) {
	int i;
	int usedOnceCount = 0;

	for (i = 0; i < hashCount; i++) {
		if (words[i].freq == 1) {
			usedOnceCount++;
		}
	}

	return usedOnceCount;
}

int lettersNotUsed(int* letterFreq, int* notUsed) {
	int i;
	int j = 0;

	for (i = 0; i < 26; i++) {
		if (letterFreq[i] == 0) {
			notUsed[j++] = i;
		}
	}

	return j;
}
