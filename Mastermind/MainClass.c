
#include "MainClass.h"

int main(void)
{
	// Variables
	char gameBoard[GB_ROWS][GB_COLUMNS]; 
	char feedbackBoard[GB_ROWS][GB_COLUMNS]; 
	char gameSolution[SINGLE_ROW]; 
	char playersGuess[SINGLE_ROW]; 

	int endGame = 0, menuChoice = 0, i, j;

	// instancating Variables
	// game board and feedback board
	for (i = 0; i < GB_ROWS; i++) {
			for (j = 0; j < GB_COLUMNS; j++) {
            gameBoard[i][j] = '.';
			feedbackBoard[i][j] = '.';
			} // for
		} // for

	// player Guess
	for(i = 0; i < 4; i++)
	{
		playersGuess[i] = '.';
	}

	printf("Welcome To Mastermind!\n");

	printf("\nThe aim of the game is to guess the colour and position of four pegs.");
	printf("\nThe peg colours are all the colours of the rainbow:");
	printf("\nRed, Orange, Yellow, Green, Blue, Indigo and Violet.\n");
	printf("\nThere is also 4 feedback pegs, one for each guess.");
	printf("\nA white peg indicates a correct coloured peg in the wrong place.");
	printf("\nA Black peg indicates a correct coloured peg in the right place.");
	printf("\nIf there are no feedback pegs, then there are no correct colours picked.\n");

	// Game Loop
	while(endGame != 99)
	{
		// To make sure the number input is in the right range
		do
		{
			printMainGameMenu();

			printf("\n\nEnter Option: ");
		
			fflush(stdin); // flush buffer
			scanf_s("%d",&menuChoice);

		}while((menuChoice < 1) || (menuChoice > 2));

		switch(menuChoice)
		{
		case 1:
			playGame(gameBoard, feedbackBoard, gameSolution, playersGuess);
			break;
		case 2:
			printf("\nExiting!");
			endGame = 99;
			break;
		} // switch
	
	} // while

	printf("\n\n\n");
	system("pause");
} // main()
 
void printMainGameMenu()
{
	printf("\n\nMain Game Menu\n");
	printf("\n1.) Start Playing Mastermind.");
	printf("\n2.) Exit.");
} // printGameMenu()

void printGameMenu()
{
	printf("\n\nGame Menu\n");
	printf("\n1.) Make A Guess.");
	printf("\n2.) Exit.");
} // printGameMenu()

void printFeedbackPegs(char feedbackBoard[GB_ROWS][GB_COLUMNS])
{
	int i, j;

	printf("\nThe Feedback Board\n\n");
	// prints the game feedback board
	for (i = 0; i < GB_ROWS; i++) 
	{
		for (j = 0; j < GB_COLUMNS; j++) 
		{
			printf("%c ", feedbackBoard[i][j]);
		} // for
		printf("\n");
	} // for
} // printFeedbackBoard()

void printPlayersGuess(char playersGuess[SINGLE_ROW])
{
	int i;

	printf("\nYour Guess\n\n");

	for(i = 0; i < 4; i++)
	{
		printf("%c ", playersGuess[i]);
	} // for
	printf("\n");

} // printPlayersGuess()

void printGameSolution(char gameSolution[SINGLE_ROW])
{
	int i;

	printf("\nGame Solution\n\n");

	for(i = 0; i < 4; i++)
	{
		printf("%c ", gameSolution[i]);
	} // for
	printf("\n");

} // printGameSolution()

void printGameBoard(char gameBoard[GB_ROWS][GB_COLUMNS], char feedbackBoard[GB_ROWS][GB_COLUMNS])
{
	// lots of specific spacing to get the game board
	// to print onto the screen properly
	// so it looks like an actual game board

	int i, j;
	
	printf("\n===========================");
	printf("\n= Game Board |  Feedback  =\n");
	
	for (i = 0; i < GB_ROWS; i++) 
	{
		printf("=  ");
		// game board
		for (j = 0; j < GB_COLUMNS; j++) 
		{
			printf("%c ", gameBoard[i][j]);
		} // for

		printf("  |   ");

		// feedback board
		for (j = 0; j < GB_COLUMNS; j++) 
		{
			printf("%c ", feedbackBoard[i][j]);
		} // for

		printf(" =\n");
	} // for

	printf("===========================");

} // printFullGameBoard()

void playGame(char gameBoard[GB_ROWS][GB_COLUMNS], char feedbackBoard[GB_ROWS][GB_COLUMNS], char gameSolution[SINGLE_ROW], char playersGuess[SINGLE_ROW])
{
	int menuChoice = 0;

	// testing :O (setting game solution manually)
	gameSolution[0] = 'O';
	gameSolution[1] = 'R';
	gameSolution[2] = 'V';
	gameSolution[3] = 'Y';

	printGameBoard(gameBoard, feedbackBoard);

	while(menuChoice != 99)
	{
		printGameMenu();

		// To make sure the number input is in the right range
		do
		{
			printf("\n\nEnter Option: ");
		
			fflush(stdin); // flush buffer
			scanf_s("%d",&menuChoice);

		}while((menuChoice < 1) || (menuChoice > 2));

		switch(menuChoice)
		{
		case 1: // make a guess
			makeGuess(playersGuess);
			break;
		case 2: // exit
			printf("\nExiting!");
			menuChoice = 99;
			break;
		} // switch

	} // while

} // playGame()

void makeGuess(char playersGuess[SINGLE_ROW])
{
	int guessNum = 0, menuChoice = 0;

	printf("\nGuess The Peg!\n");
	printf("\n1.) Red.");
	printf("\n2.) Orange.");
	printf("\n3.) Yellow.");
	printf("\n4.) Green.");
	printf("\n5.) Blue.");
	printf("\n6.) Indigo.");
	printf("\n7.) Violet.\n");

	while(guessNum < 4)
	{
		// To make sure the number input is in the right range
		do
		{
			printf("\n\nEnter Option: ");
		
			fflush(stdin); // flush buffer
			scanf_s("%d",&menuChoice);

		}while((menuChoice < 1) || (menuChoice > 7));

		guessNum++;

		switch(menuChoice)
		{
		case 1:
			printf("\nYou Guess Peg Number %d Is Red", guessNum);
			playersGuess[guessNum-1] = 'R'; // -1 because 0 index
			break;
		case 2:
			printf("\nYou Guess Peg Number %d Is Orange", guessNum);
			playersGuess[guessNum-1] = 'O'; // -1 because 0 index
			break;
		case 3:
			printf("\nYou Guess Peg Number %d Is Yellow", guessNum);
			playersGuess[guessNum-1] = 'Y'; // -1 because 0 index
			break;
		case 4:
			printf("\nYou Guess Peg Number %d Is Green", guessNum);
			playersGuess[guessNum-1] = 'G'; // -1 because 0 index
			break;
		case 5:
			printf("\nYou Guess Peg Number %d Is Blue", guessNum);
			playersGuess[guessNum-1] = 'B'; // -1 because 0 index
			break;
		case 6:
			printf("\nYou Guess Peg Number %d Is Indigo", guessNum);
			playersGuess[guessNum-1] = 'I'; // -1 because 0 index
			break;
		case 7:
			printf("\nYou Guess Peg Number %d Is Violet", guessNum);
			playersGuess[guessNum-1] = 'V'; // -1 because 0 index
			break;		
		} // switch
	} // while
} // makeGuess()