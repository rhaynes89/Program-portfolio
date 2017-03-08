/*======================================
* Programers:Richard Haynes III, Nathan Bo, Phillip Tat
* Date: 2/12/2017
* Class: C Programming
* Exam 2: Battleship
========================================*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#define PAUSE system("pause")
#define CLS system("cls")
#define FLUSH fflush(stdin)
#define SIZE 10
#define COLS 10
#define ROWS 10
// COLS and ROWS are for the 10x10 game grid
// Although SIZE, COLS, and ROWS are all 10, we should keep them seperated anyway
#include "Phillip.h"
#include "Richard.h"
#include "Nathan.h"


main()
{
	char row;
	int column;
	char gameBoard[ROWS][COLS];
	char choice;
	int counter = 0, i, j; // i is for testing purposes
	int highscoreCounter = 0, missileCounter = 0, rowNum = 0;
	int highscore[SIZE] = { 0 };
	char shipBoard[ROWS][COLS];
	char testArray[SIZE] = "ABCDEFGHIJ"; // for testing shipBoard array
	char win, repeatFlag;
	int hitCounter[SIZE] = { 0 };
	int sunkCounter = 0;

	srand((unsigned)time(NULL));

	FILE *ptr;

	// function to read saved highscores
	// should be at or near the top of main
	// had trouble putting this in a function last time but
	// I'll experiment a little and see if I can put this in a function again
	if (ptr = fopen("highscoresTopTen.bin", "rb")) { // open highscoresTopTen.bin if it exists
		if (ptr == NULL) {
			printf("\nError! Could not open file!\n\n");
			PAUSE;
			exit(-1);
		}

		// read highscores from bin file
		fread(&highscoreCounter, sizeof(int), 1, ptr);
		fread(highscore, sizeof(int), highscoreCounter, ptr);

		fclose(ptr);
	} // end if
	
	/*
	// TEST CODE to show that the ships are properly and randomly placed
	resetBoard(shipBoard);
	randomShipBoard(shipBoard, counter);
	printf("\t\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10");
	printf("\n\t-----------------------------------------------------------------------------------\n");
	for (i = 0; i < 10; i++) {
		printf("\t%c|\t", testArray[i]);
		for (j = 0; j < 10; j++) {
			printf("%c\t", shipBoard[i][j]);
		}
		printf("\n\t |\n");
	}
	printf("\n"); PAUSE;
	// TEST CODE
	*/

	/*
	// TEST CODE
	// What do you guys think? Does this look alright?
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
	printf("Your highscore is %i missiles!\n\n", missileCounter);
	PAUSE;
	// TEST CODE
	*/
	do
	{
		choice = userChoice();

		switch (choice)
		{
		case 'A'://start game
			// This is the reset gameboard function
			// This function must come prior to the baseGameboard function
			// for it to properly output. However only for the initial call of baseGameboard();
			resetBoard(gameBoard);

			// put X's in shipBoard array
			resetBoard(shipBoard);

			// Found out through testing that we need to reset hitcounter array after every game
			resetHitCounter(hitCounter, counter);

			// This is where the random ships are placed
			randomShipBoard(shipBoard, counter);

			/*
			// TEST CODE for DEBUGGING
			printf("\t\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10");
			printf("\n\t-----------------------------------------------------------------------------------\n");
			for (i = 0; i < 10; i++) {
				printf("\t%c|\t", testArray[i]);
				for (j = 0; j < 10; j++) {
					printf("%c\t", shipBoard[i][j]);
				}
				printf("\n\t |\n");
			}
			printf("\n"); PAUSE;
			// TEST CODE for DEBUGGING
			*/

			// This loops until the user wins
			// win resets to N and sunkCounter and missileCounter resets to 0 when player starts a new game
			win = 'N'; sunkCounter = 0; missileCounter = 0;
			do {
				// nested loop activates when user enters repeat coordinates
				// sets repeatFlag to N at every new game
				repeatFlag = 'N';
				do {
					// This is the base gameboard function
					baseGameboard(gameBoard);

					// Display missile counter
					printf("\n\t\t\t\t\t\t\t\t      Missiles Fired: %i\n\n", missileCounter);
					// printf("\t\t\t\t\t\t\t\t      Sunk Counter: %i\n\n", sunkCounter); // Test code

					// This is the user choice function
					userChoiceCoordinates(&row, &column);

					// Had to decrement column to match subindex element in gameBoard array
					column--;

					// This converts char from row into int and puts it in rowNum
					rowNum = convertChar(row);

					// Check if user has already entered these coordinates
					repeatFlag = checkRepeat(gameBoard, rowNum, column);
				} while (repeatFlag != 'N'); // end do while

				// This changes X's on gameboard and displays sunk ship
				hitMissSunk(gameBoard, shipBoard, rowNum, column, hitCounter, &sunkCounter);

				// Increments missileCounter
				missileCounter++;

				// This changes win to Y when all ships are sunk and displays win messages
				win = getWinCondition(sunkCounter, missileCounter);
			} while (win != 'Y'); // end do while loop for the game

			// function to pass missileCounter value to highscore array if necessary
			highscoreCounter = missiles(highscore, highscoreCounter, missileCounter);

			// printf("%c and %i\n\n", row, column); PAUSE; // Test Code

			break;
		case 'B'://see rules
			rulesOfGame();
			PAUSE;
			break;
		case 'C'://see top 10 scores
			/*
			TEST CODE
			counter = 10;
			for (i = 0; i < counter; i++) {
				printf("Enter highscores: ");
				scanf("%i", &highscore[i]); FLUSH;
			} // end for	
			TEST CODE
			*/

			// this displays the current highscores			
			displayHighscores(highscore, highscoreCounter);
			PAUSE;
			break;
		case 'D'://Quit game

			// function to save highscores
			// should be within the "quit and save" menu option
			// may need to put bubbleSort function in front of this function if
			// the bubbleSort function inside saveHighscores doesn't work
			saveHighscores(highscore, highscoreCounter);

			CLS;
			printf("\t\t\t========================================================\n");
			printf("\t\t\t\t  You have quit playing Battleship!\n\n\t\t\t\t      Thank you come again!\n");
			printf("\t\t\t========================================================\n\n");
			PAUSE;
			break;
		default:
			printf("\nPlease pick a valid option.\n\n");
			PAUSE;
			break;
		}
	} while (choice != 'D'); // end do while
} //end main