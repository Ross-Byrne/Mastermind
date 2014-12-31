
#include "Functions.h"

int main(void)
{
	// Variables
	char gameDif[MAX_STRING] = "Easy";
	char playerName[MAX_STRING] = "Player";

	char gameBoard[TURNS][GB_COLUMNS]; 
	char feedbackBoard[TURNS][GB_COLUMNS]; 
	char gameSolution[SINGLE_ROW]; 
	char playersGuess[SINGLE_ROW];
	char currentGuessFeedback[SINGLE_ROW];
	char possibleChoices[7] = {'R', 'O', 'Y', 'G', 'B', 'I', 'V'};
	char possibleHardChoices[8] = {'R', 'O', 'Y', 'G', 'B', 'I', 'V', '.'};

	int endGame = 0, menuChoice = 0, i, j;
	int currentTurn = 0, showSolution = 0;
	int wins = 0, losses = 0;

	int gameTurns = TURNS;

	// pointers
	int *gameTurnsPtr;
	int *showSolutionPtr;
	int *winsPtr;
	int *lossesPtr;

	// pointing pointers
	gameTurnsPtr = &gameTurns;
	showSolutionPtr = &showSolution;
	winsPtr = &wins;
	lossesPtr = &losses;

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

	printf("\nFor a greater gameplay experience, make the window fullscreen!\n");

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
		case 1: // play the game
			menuChoice = 0;
			currentTurn = 0;

			// clears game board and feedback board
			for (i = 0; i < TURNS; i++) 
			{
				for (j = 0; j < GB_COLUMNS; j++) {
				gameBoard[i][j] = '.';
				feedbackBoard[i][j] = '.';
				} // for
			} // for

			generateGameSolution(gameSolution, possibleChoices, possibleHardChoices, gameDif);

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
					makeGuess(playersGuess, gameDif);

					addPlayersGuessToBoard(playersGuess,gameBoard, currentTurn);
					// if showSolution = 1, it shows the game solution and the game is over
					checkPlayersGuess(playersGuess, gameSolution, feedbackBoard, currentGuessFeedback, currentTurn, showSolutionPtr);
					
					// moves on to the next turn
					currentTurn++;

					if(currentTurn+1 > gameTurns && showSolution != 1)
					{
						// if last turn was used and guess wasn't right
						showSolution = 2;
					} // if

					// prints the game board
					printGameBoard(gameBoard, feedbackBoard, gameSolution, showSolution, gameTurns);

					// shows the number of turns used out of max goes
					printf("\n%d Out Of %d Turns Used!",currentTurn, gameTurns);

					// if the game is over because it was won or lost
					if(showSolution == 1 || showSolution == 2)
					{
						if(showSolution == 1) // if won
						{
							++*winsPtr;
						}
						else // if lost
						{
							++*lossesPtr;
						} // if

						saveScore(playerName, gameDif, currentTurn, winsPtr, lossesPtr);

						// exits back to the main menu
						menuChoice = 99;
					} // if
					break;
				case 2: // exit
					printf("\n\nAre You Sure You Want To Exit?");
					printf("\nAll Progress Will Be Lost!\n");
					printf("\nExit Current Game?\n");
					printf("\n1.) Yes.");
					printf("\n2.) No.");

					// To make sure the number input is in the right range
					do
					{
						printf("\n\nEnter Option: ");
		
						fflush(stdin); // flush buffer
						scanf_s("%d",&menuChoice);

					}while((menuChoice < 1) || (menuChoice > 2));

					if(menuChoice == 1)
					{
						printf("\nExiting!");
						menuChoice = 99;
					}
					else
					{
						printf("\nGoing Back To Game!.");
					}
					break;
				} // switch
			} // while
			break;
		case 2: // options
				options(gameTurnsPtr, playerName, gameDif, currentTurn);
				break;
		case 3: // exit
			printf("\nExiting!");
			endGame = 99;
			break;
		} // switch
	} // while

	printf("\n\n\n");
	system("pause");
} // main()