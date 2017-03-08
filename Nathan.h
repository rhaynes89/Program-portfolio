//Written by: Nathan Bo
//Date:
//Purpose:

void baseGameboard(char gameboard[ROWS][COLS]);
void resetBoard(char gameboard[ROWS][COLS]);
void userChoiceCoordinates(char *row, int *column);

void baseGameboard(char gameboard[ROWS][COLS]) {
	CLS;
	int i, j;

	printf("\t\t\t\t\t====================\n\t\t\t\t\t  == BATTLESHIP ==\n\t\t\t\t\t====================\n");
	printf("\n\t\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\t\n");
	for (i = 0; i < ROWS; i++){
		printf("\t  --------------------------------------------------------------------------------\n");
		if (i == 0)
			printf("\tA|");
		else if (i == 1)
			printf("\tB|");
		else if (i == 2)
			printf("\tC|");
		else if (i == 3)
			printf("\tD|");
		else if (i == 4)
			printf("\tE|");
		else if (i == 5)
			printf("\tF|");
		else if (i == 6)
			printf("\tG|");
		else if (i == 7)
			printf("\tH|");
		else if (i == 8)
			printf("\tI|");
		else if (i == 9)
			printf("\tJ|");
		for (j = 0; j < COLS; j++){
			printf("\t%c", gameboard[i][j]);
		}
		printf("\n");
	}
} // end baseGameboard

void resetBoard(char gameboard[ROWS][COLS]){//IMPORTANT: Call this function at the start of every new game to reset the gameboard
	int i, j;

	for (i = 0; i < ROWS; i++){
		for (j = 0; j < COLS; j++){
			gameboard[i][j] = 'X';
		}
	}
} // end resetBoard

void userChoiceCoordinates(char *row, int *column){
	do { // loop until valid variable
		printf("\nChoose your row(A-J): ");
		scanf("%c", row); FLUSH;
		*row = toupper(*row);
		if ( (*row) < 'A' || (*row) > 'J') { // the paranthesis help with order of operations
			printf("\nThat is not a valid coordinate. Please re-enter!\n");
		}
	} while ( (*row) < 'A' || (*row) > 'J'); // end do while

	do { // loop until validi variable
		printf("\nChoose your column(1-10): ");
		scanf("%i", column); FLUSH;
		if ( (*column) < 1 || (*column) > 10) { // the paranthesis help with order of operations
			printf("\nThat is not a valid coordinate. Please re-enter!\n");
		}
	} while ( (*column) < 1 || (*column) > 10); // end do while	
} // end userChoiceCoordinates