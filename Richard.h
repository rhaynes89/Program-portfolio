/*======================================
* Programer:Richard Haynes III
* Date: 2/12/17
* Class: C Programming
* Battleship program
========================================*/

void displayMenu();
void hitMissSunk(char gameBoard[][COLS], char shipBoard[][COLS],
				 int i, int j, int hitCounter[], int *sunkCounter);
void rulesOfGame();
char userChoice();

/*===========================================
* Function name: displayMenu
* Date created: 2/12/2017
* Purpose: To display the menu to the user.
==============================================*/
void displayMenu()
{
	CLS;
	printf("\t\t\t\t\t====================\n\t\t\t\t\t  == BATTLESHIP ==\n\t\t\t\t\t====================\n");
	printf("\t\t\t\t\t A. Start game\n");
	printf("\t\t\t\t\t B. See rules of game.\n");
	printf("\t\t\t\t\t C. Display top ten scores\n");
	printf("\t\t\t\t\t D. Save and Quit\n\n");

	printf("\nSelect your choice: ");

} // end displayMenu

/*===========================================
* Function name: hitMissSunk
* Date created: 2/21/2017
* Purpose: This function displays the H for hit
or M for miss and tells the user which ship has been sunk.
==============================================*/
void hitMissSunk(char gameBoard[][COLS], char shipBoard[][COLS], int i, int j, int hitCounter[], int *sunkCounter)
{
	int airCraft = 5, battleShip = 4, cruiser = 2, sub = 3, destroyer = 3;
	char shipLetter = '\0';
	/*
	Ships:
	1. (C) Cruiser (2 Holes)
	2. (A) Aircraft Carrier (5 Holes)
	3. (B) Battleship (4 Holes)
	4. (S) Submarine (3 Holes)
	5. (D) Destroyer (3 Holes)
	*/


	if (shipBoard[i][j] == 'X')
	{
		gameBoard[i][j] = 'M';
		printf("\nMISS! There was no ship there!\n\n"); PAUSE;
	}
	else
	{
		gameBoard[i][j] = 'H';
		printf("\nHIT! You've hit a ship!\n\n"); PAUSE;

		switch (shipBoard[i][j])
		{
		case 'A':
			hitCounter[0]++;
			//Aircraft Carrier has been hit
			if (hitCounter[0] >= airCraft) {
				shipLetter = 'A';
				sunkShipLetters(gameBoard, shipBoard, i, j, shipLetter);
				printf("\nYou sunk the Aircraft Carrier!\n\n");
				(*sunkCounter)++; PAUSE;
			}
			break;
		case 'B':
			hitCounter[1]++;
			//battleShip has been hit
			if (hitCounter[1] >= battleShip) {
				shipLetter = 'B';
				sunkShipLetters(gameBoard, shipBoard, i, j, shipLetter);
				printf("\nYou sunk the Battleship!\n\n");
				(*sunkCounter)++; PAUSE;
			}
			break;
		case 'S':
			hitCounter[2]++;
			//submarine has been hit
			if (hitCounter[2] >= sub) {
				shipLetter = 'S';
				sunkShipLetters(gameBoard, shipBoard, i, j, shipLetter);
				printf("\nYou sunk the Submarine!\n\n");
				(*sunkCounter)++; PAUSE;
			}
			break;
		case 'D':
			hitCounter[3]++;
			//destroyer has been hit
			if (hitCounter[3] >= destroyer) {
				shipLetter = 'D';
				sunkShipLetters(gameBoard, shipBoard, i, j, shipLetter);
				printf("\nYou sunk the Destroyer!\n\n");
				(*sunkCounter)++; PAUSE;
			}
			break;
		case 'C':
			hitCounter[4]++;
			//cruiser has been hit
			if (hitCounter[4] >= cruiser) {
				shipLetter = 'C';
				sunkShipLetters(gameBoard, shipBoard, i, j, shipLetter);
				printf("\nYou sunk the the Cruiser!\n\n");
				(*sunkCounter)++; PAUSE;
			}
			break;
		}

	}

} // end hitMissSunk

/*===========================================
* Function name: ruleOfGame
* Date created: 2/14/2017
* Purpose: This function displays the
rules of the game to the user.
==============================================*/
void rulesOfGame()
{
	CLS;
	printf("\t\t\t\t============================\n\t\t\t\t == RULES OF BATTLESHIP ==\n\t\t\t\t============================\n\n");
	printf("1. This is an interactive one player game.\n");
	printf("2. You are the only player.\n");
	printf("3. Your objective is to sink the ships that the computer has placed on the\n   game board.\n");
	printf("4. There are 5 types of ships:\n");
	printf("\n\t\t*********************************************\n");
	printf("\t\t[A] Aircraft carrier - takes 5 hits.\n");
	printf("\t\t[B] Battleship - takes 4 hits.\n");
	printf("\t\t[C] Cruiser - takes 3 hits.\n");
	printf("\t\t[S] Submarine - takes 3 hits.\n");
	printf("\t\t[D] Destroyer - takes 2 hits.\n");
	printf("\t\t*********************************************\n\n");
	printf("4. The objective is to sink the ships the computer has placed.\n");
	printf("5. When you have a hit you will see a 'H' in that square and when"
		" you miss\n   you will see a 'M'.\n");
	printf("6. When a ship has been sunk, the 'H' will change to its respective"
		" letter\n   to signify that it has sunk.\n");
	printf("7. The highest score that can be achieved is 17 points.\n\n");
} // end rulesOfGame

/*===========================================
* Function name: userChoice
* Date created: 2/12/2017
* Purpose: This function gathers the choice
from the user.
==============================================*/
char userChoice()
{
	char result;
	displayMenu();
	scanf("%c", &result); FLUSH;
	return toupper(result);
} // end userChoice