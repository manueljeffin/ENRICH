/* ==========================================================================
 SlidingPuzzle.c
 Aparna Lavanya K

 Program to solve the Sliding Puzzle Game
 of Generic Size with Dynamic Number Arrangements
 ========================================================================== */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int size;
int emptyRow, emptyCol;

int** initialisePuzzle(int);
void scramblePuzzle(int**);
void slide(int**, char);
int isSolved(int**);
void printPuzzle(int**);

void main() {
	int** puzzle;
	char move;

	printf("\nSLIDING PUZZLE\n\n");
	printf("\nEnter the size of the puzzle: ");
	scanf("%d", &size);

	if (size == 0 || size == 1) {
		return;
	}

	puzzle = initialisePuzzle(size);
	scramblePuzzle(puzzle);

	do {
		system("clear");
		printPuzzle(puzzle);

		printf("\nPress U ->Up, D ->Down, L ->Left, R ->Right, Q ->Quit\n");
		printf("\nEnter a move: ");
		scanf("%c", &move);
		move = toupper(move);

		slide(puzzle, move);

	}while (move != 'Q' && !isSolved(puzzle));

	system("clear");
	printPuzzle(puzzle);

	if (isSolved(puzzle)) {
		printf("\nSliding Puzzle is solved! \nCongratulations! You have won!\n");
	}
	else {
		printf("\nYou quit...");
	}
}

int** initialisePuzzle(int size) {
	int i, j;
	int** puzzle;
	int val = 1;

	// dynamic allocation
	puzzle = (int**)malloc(size*sizeof(int*));
	for (i = 0; i < size; i++) {
		puzzle[i] = (int*) malloc(size*sizeof(int));
	}

	// initialise puzzle with numbers
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			puzzle[i][j] = val++;
		}
	}
	puzzle[size - 1][size - 1] = 0;
	emptyRow = emptyCol = size - 1;

	return puzzle;
}

void scramblePuzzle(int** puzzle) {
	int i, key;
	char move[5] = {'U', 'D', 'L', 'R', 'Q'};

	srand(time(NULL));

	//dynamically rearrange the numbers on the puzzle
	while (isSolved(puzzle)) {
		for (i = 0; i < 25; i++) {
			key = rand() % 5;
			slide(puzzle, move[key]);
		}
	}
}

void printPuzzle(int** puzzle) {
	int i, j;

	printf("\n");
	for (i = 0; i < size; i++) {
		printf("------------------------------\n");
		for (j = 0; j < size; j++) {
			printf("| %d ", puzzle[i][j]);
		}
		printf("|\n");
	}
	printf("------------------------------\n");
}

void slide(int** puzzle, char move) {
	int row, col;
	char temp;

	switch (move) {   //find the position to move the empty cell into
	case 'U':
		row = emptyRow - 1;
		col = emptyCol;
		break;

	case 'D':
		row = emptyRow + 1;
		col = emptyCol;
		break;

	case 'L':
		row = emptyRow;
		col = emptyCol - 1;
		break;

	case 'R':
		row = emptyRow;
		col = emptyCol + 1;
		break;

	default:
		return;
	}

	//check if the position is valid
	if (row < 0 || row == size || col < 0 || col == size) {
		return;
	}

	// swap the empty cell with the position found
	temp = puzzle[emptyRow][emptyCol];
	puzzle[emptyRow][emptyCol] = puzzle[row][col];
	puzzle[row][col] = temp;

	//update the empty cell's location
	emptyRow = row;
	emptyCol = col;
}

int isSolved(int** puzzle) {
	int i, j;
	int flag = 1;
	int val = 1;

	puzzle[emptyRow][emptyCol] = size * size;
        
        //check if puzzle is sorted in ascending order
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (puzzle[i][j] != val++) {
				flag = 0;
				break;
			}
		}
		if (flag == 0) {
			break;
		}
	}
	
	puzzle[emptyRow][emptyCol] = 0;

	return flag;
}
