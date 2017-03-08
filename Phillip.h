// Written by: Phillip Tat
// Date written: 2/13/17
// Purpose: Exam 2: Battleship

void bubbleSort(int [], int);
char checkRepeat(char [][COLS], int, int);
int convertChar(char);
void displayHighscores(int [], int);
char getWinCondition(int, int);
int missiles(int [], int, int);
void randomShipBoard(char [][COLS], int);
void resetHitCounter(int [], int);
void saveHighscores(int [], int);
void sunkShipLetters(char [][COLS], char [][COLS], int , int , char);

// sort the arrays
void bubbleSort(int scores[], int counter) {
	int i, bottom, temp;
	char flag;

	bottom = counter - 1;

	do {
		flag = 'N';
		for (i = 0; i < bottom; i++) {
			if (scores[i] > scores[i + 1]) {
				flag = 'Y';
				temp = scores[i];
				scores[i] = scores[i + 1];
				scores[i + 1] = temp;
			} // end if
		} // end for
		bottom--;
	} while (flag == 'Y'); // end do while

	return;
} // end bubbleSort

// check if user has already entered those coordinates
char checkRepeat(char gameBoard[][COLS], int row, int column) {
	char result;

	if (gameBoard[row][column] == 'X') {
		result = 'N';
	}
	else {
		result = 'Y';
		printf("\nYou have already entered those coordinates. Please choose new coordinates!\n\n");
		PAUSE;
	}

	return result;
} // end checkRepeat

// convert row's char to an int
int convertChar(char row) {
	int result;

	switch (row) {
	case 'A':
		result = 0;
		break;
	case 'B':
		result = 1;
		break;
	case 'C':
		result = 2;
		break;
	case 'D':
		result = 3;
		break;
	case 'E':
		result = 4;
		break;
	case 'F':
		result = 5;
		break;
	case 'G':
		result = 6;
		break;
	case 'H':
		result = 7;
		break;
	case 'I':
		result = 8;
		break;
	case 'J':
		result = 9;
		break;
	} // end switch

	return result;
} // end convertChar

// display top 10 highscores
void displayHighscores(int scores[], int counter) {
	int i;

	CLS;
	printf("\t\t\t\t\t");
	for (i = 0; i < 20; i++) {
		printf("=");
	} // end for
	printf("\n\t\t\t\t\t  == HIGHSCORES ==\n\t\t\t\t\t");
	for (i = 0; i < 20; i++) {
		printf("=");
	} // end for
	printf("\n\n\n");

	bubbleSort(scores, counter);

	if (counter == 0) {
		printf("There are currently no saved highscores!\n");
	}
	else {
		for (i = 0; i < counter; i++) {
			printf("\t\t\t    Highscore #%i:\t\t%i Missiles Fired\n", i + 1, scores[i]);
		} // end for
	} // end if else
	printf("\n");

	return;
} // end of displayHighscores

// checks for win condition after every missile fired
char getWinCondition(int sunkCounter, int missiles) {
	char result = 'N';

	if (sunkCounter == 5) {
		// I wonder if this looks alright?
		printf("\n\t _\n");
		printf("\t|@|\n");
		printf("\t| |\n");
		printf("\t| |_____\n");
		printf("     __/   (0___)\n");
		printf("    |      (0___)\n");
		printf("    |      (0___)\n");
		printf("    |______(0___)\n");
		printf("\n     THUMBS UP!\n\n");

		printf("\nCongratulations! You've sunk all the ships!\n\n");
		printf("Your highscore is %i missiles!\n\n", missiles);
		result = 'Y'; PAUSE;
	}

	return result;
} // end getWinCondition

// replaces lowest score with new highscore if applicable
// then sorts scores into correct order
int missiles(int scores[], int counter, int missiles) {
	int result;
	int i;

	if (counter < 10) { // fill up highscore arrray
		scores[counter] = missiles;
		counter++; // will only count up until counter reaches 10
	}
	else {
		for (i = 0; i < counter; i++) {
			if (missiles < scores[i]) {
				// replace last highscore with new highscore
				scores[counter - 1] = missiles;
			}
		} // end for
	} // end if else
	// second bubbleSort is necessary incase new highscore is not last
	bubbleSort(scores, counter);

	result = counter;
	return result;
} // end missiles

// randomly place ships into shipboard array without overlapping
void randomShipBoard(char ship[][COLS], int counter) {
	char flag = 'N'; // flag to make sure ship is placed
	char full = 'N'; // flag to make sure there isn't another ship in that position
	int LB, UB;
	int randomRows = 0, randomCols = 0, position = 0, temp = 0;
	// found that I needed temp to fix a bug I had

	// I know this is a mess but this was the only way I could think of doing this
	do { // loop until AIRCRAFT CARRIER is placed
		// get random coordinates
		flag = 'N'; counter = 0;
		LB = 0, UB = 9;
		randomRows = LB + rand() % (UB - LB + 1);
		randomCols = LB + rand() % (UB - LB + 1);
		// get random decision for horizontal(1) or vertical(2) positioning
		LB = 1, UB = 2;
		position = LB + rand() % (UB - LB + 1);

		if (position == 1) {
			counter = randomCols + 4;
			// check to see if coordinates are too near the boundary
			if (counter < 10) {
				for (randomCols; randomCols <= counter; randomCols++) {
					// place ship letters in array
					ship[randomRows][randomCols] = 'A';
				} // end for
				flag = 'Y';
			}
		}
		else {
			counter = randomRows + 4;
			if (counter < 10) {
				for (randomRows; randomRows <= counter; randomRows++) {
					ship[randomRows][randomCols] = 'A';
				} // end for
				flag = 'Y';
			}
		}
	} while (flag != 'Y'); // end do while

	do { // loop until BATTLESHIP is placed
		// get random coordinates
		flag = 'N'; full = 'N'; counter = 0;
		LB = 0, UB = 9;
		randomRows = LB + rand() % (UB - LB + 1);
		randomCols = LB + rand() % (UB - LB + 1);
		// get random decision for horizontal(1) or vertical(2) positioning
		LB = 1, UB = 2;
		position = LB + rand() % (UB - LB + 1);

		if (position == 1) {
			temp = randomCols;
			counter = randomCols + 3;
			// check to see if there is another ship there
			for (randomCols = temp; randomCols <= counter; randomCols++) {
				if (ship[randomRows][randomCols] != 'X') {
					full = 'Y';
				}
			} // end for
			if (counter < 10 && full == 'N') {
				for (randomCols = temp; randomCols <= counter; randomCols++) {
					ship[randomRows][randomCols] = 'B';
				} // end for
				flag = 'Y';
			}
		}
		else {
			temp = randomRows;
			counter = randomRows + 3;
			for (randomRows = temp; randomRows <= counter; randomRows++) {
				if (ship[randomRows][randomCols] != 'X') {
					full = 'Y';
				}
			} // end for
			if (counter < 10 && full == 'N') {
				for (randomRows = temp; randomRows <= counter; randomRows++) {
					ship[randomRows][randomCols] = 'B';
				} // end for
				flag = 'Y';
			}
		}
	} while (flag != 'Y'); // end do while

	do { // loop until SUBMARINE is placed
		// get random coordinates
		flag = 'N'; full = 'N'; counter = 0;
		LB = 0, UB = 9;
		randomRows = LB + rand() % (UB - LB + 1);
		randomCols = LB + rand() % (UB - LB + 1);
		// get random decision for horizontal(1) or vertical(2) positioning
		LB = 1, UB = 2;
		position = LB + rand() % (UB - LB + 1);

		if (position == 1) {
			temp = randomCols;
			counter = randomCols + 2;
			// check to see if there is another ship there
			for (randomCols = temp; randomCols <= counter; randomCols++) {
				if (ship[randomRows][randomCols] != 'X') {
					full = 'Y';
				}
			} // end for
			if (counter < 10 && full == 'N') {
				for (randomCols = temp; randomCols <= counter; randomCols++) {
					ship[randomRows][randomCols] = 'S';
				} // end for
				flag = 'Y';
			}
		}
		else {
			temp = randomRows;
			counter = randomRows + 2;
			for (randomRows = temp; randomRows <= counter; randomRows++) {
				if (ship[randomRows][randomCols] != 'X') {
					full = 'Y';
				}
			} // end for
			if (counter < 10 && full == 'N') {
				for (randomRows = temp; randomRows <= counter; randomRows++) {
					ship[randomRows][randomCols] = 'S';
				} // end for
				flag = 'Y';
			}
		}
	} while (flag != 'Y'); // end do while

	do { // loop until DESTROYER is placed
		// get random coordinates
		flag = 'N'; full = 'N'; counter = 0;
		LB = 0, UB = 9;
		randomRows = LB + rand() % (UB - LB + 1);
		randomCols = LB + rand() % (UB - LB + 1);
		// get random decision for horizontal(1) or vertical(2) positioning
		LB = 1, UB = 2;
		position = LB + rand() % (UB - LB + 1);

		if (position == 1) {
			temp = randomCols;
			counter = randomCols + 2;
			// check to see if there is another ship there
			for (randomCols = temp; randomCols <= counter; randomCols++) {
				if (ship[randomRows][randomCols] != 'X') {
					full = 'Y';
				}
			} // end for
			if (counter < 10 && full == 'N') {
				for (randomCols = temp; randomCols <= counter; randomCols++) {
					ship[randomRows][randomCols] = 'D';
				} // end for
				flag = 'Y';
			}
		}
		else {
			temp = randomRows;
			counter = randomRows + 2;
			for (randomRows = temp; randomRows <= counter; randomRows++) {
				if (ship[randomRows][randomCols] != 'X') {
					full = 'Y';
				}
			} // end for
			if (counter < 10 && full == 'N') {
				for (randomRows = temp; randomRows <= counter; randomRows++) {
					ship[randomRows][randomCols] = 'D';
				} // end for
				flag = 'Y';
			}
		}
	} while (flag != 'Y'); // end do while

	do { // loop until CRUISER is placed
		// get random coordinates
		flag = 'N'; full = 'N'; counter = 0;
		LB = 0, UB = 9;
		randomRows = LB + rand() % (UB - LB + 1);
		randomCols = LB + rand() % (UB - LB + 1);
		// get random decision for horizontal(1) or vertical(2) positioning
		LB = 1, UB = 2;
		position = LB + rand() % (UB - LB + 1);

		if (position == 1) {
			temp = randomCols;
			counter = randomCols + 1;
			// check to see if there is another ship there
			for (randomCols = temp; randomCols <= counter; randomCols++) {
				if (ship[randomRows][randomCols] != 'X') {
					full = 'Y';
				}
			} // end for
			if (counter < 10 && full == 'N') {
				for (randomCols = temp; randomCols <= counter; randomCols++) {
					ship[randomRows][randomCols] = 'C';
				} // end for
				flag = 'Y';
			}
		}
		else {
			temp = randomRows;
			counter = randomRows + 1;
			for (randomRows = temp; randomRows <= counter; randomRows++) {
				if (ship[randomRows][randomCols] != 'X') {
					full = 'Y';
				}
			} // end for
			if (counter < 10 && full == 'N') {
				for (randomRows = temp; randomRows <= counter; randomRows++) {
					ship[randomRows][randomCols] = 'C';
				} // end for
				flag = 'Y';
			}
		}
	} while (flag != 'Y'); // end do while

	/*
	Ships:
	1. (C) Cruiser (2 Holes)
	2. (A) Aircraft Carrier (5 Holes)
	3. (B) Battleship (4 Holes)
	4. (S) Submarine (3 Holes)
	5. (D) Destroyer (3 Holes)
	*/

	return;
} // end randomShipBoard

// reset hitcounter array
void resetHitCounter(int hitCounter[], int i) {

	for (i = 0; i < SIZE; i++) {
		hitCounter[i] = 0;
	} // end for

	return;
} // end resetHitCounter

// save highscores into bin file
void saveHighscores(int scores[], int counter) {
	FILE *ptr;

	ptr = fopen("highscoresTopTen.bin", "wb"); // create highscoresTopTen.bin file
	if (ptr == NULL) {
		printf("\nError! Could not open file!\n\n");
		PAUSE;
		exit(-1);
	}

	// sort the highscores array before saving
	bubbleSort(scores, counter);
	// save highscores into the bin file
	fwrite(&counter, sizeof(int), 1, ptr);
	fwrite(scores, sizeof(int), counter, ptr);

	fclose(ptr);

	return;
} // end saveHighscores

// changes H's to ship's letter when a ship is sunk
void sunkShipLetters(char gameBoard[][COLS], char shipBoard[][COLS], int i, int j, char letter) {

	// loop through the entire ship board
	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLS; j++) { // replace game board letter with ship letter
			if (shipBoard[i][j] == letter) {
				gameBoard[i][j] = letter;
			}
		} // end inner for
	} // end outer for

	return;
} // end sunkShipLetters