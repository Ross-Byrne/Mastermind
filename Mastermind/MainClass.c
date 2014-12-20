
#include "Functions.h"

int main(void)
{
	// Variables
	char playerName[MAX_NAME] = "Player";

	char gameBoard[TURNS][GB_COLUMNS]; 
	char feedbackBoard[TURNS][GB_COLUMNS]; 
	char gameSolution[SINGLE_ROW]; 
	char playersGuess[SINGLE_ROW];
	char currentGuessFeedback[SINGLE_ROW];
	char possibleChoices[7] = {'R', 'O', 'Y', 'G', 'B', 'I', 'V'};

	int endGame = 0, menuChoice = 0, i, j;
	int currentTurn = 0, showSolution = 0;

	int gameTurns = TURNS;

	int *gameTurnsPtr;
	int *showSolutionPtr;

	gameTurnsPtr = &gameTurns;
	showSolutionPtr = &showSolution;

	// instancating Variables
	// game board and feedback board
	for (i = 0; i < TURNS; i++) 
	{
		for (j = 0; j < GB_COLUMNS; j++) {
        gameBoard[i][j] = '.';
		feedbackBoard[i][j] = '.';
		} // for
	} // for

	// player Guess
	for(i = 0; i < 4; i++)
	{
		playersGuess[i] = '.';
	} // for

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

		}while((menuChoice < 1) || (menuChoice > 3));

		switch(menuChoice)
		{
		case 1:
			menuChoice = 0;

			generateGameSolution(gameSolution, possibleChoices);
			printGameSolution(gameSolution);

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

					// if showSolution = 1, it shows the game solution and the game is over
					checkPlayersGuess(playersGuess, gameSolution, feedbackBoard, currentGuessFeedback, currentTurn, showSolutionPtr);
					addPlayersGuessToBoard(playersGuess,gameBoard, currentTurn);

					// moves on to the next turn
					currentTurn++;

					if(currentTurn+1 > gameTurns)
					{
						showSolution = 2;
					} // if

					printGameBoard(gameBoard, feedbackBoard, gameSolution, showSolution, gameTurns);

					// shows the number of turns used out of max goes
					printf("\n%d Out Of %d Turns Used!",currentTurn, gameTurns);
					break;
				case 2: // exit
					printf("\nExiting!");
					menuChoice = 99;
					break;
				} // switch
			} // while

			break;
		case 2: // options
				options(gameTurnsPtr, playerName);

				break;
		case 3:
			printf("\nExiting!");
			endGame = 99;
			break;
		} // switch
	
	} // while

	printf("\n\n\n");
	system("pause");
} // main()