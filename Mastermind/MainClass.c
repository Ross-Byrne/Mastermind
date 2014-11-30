
#include "MainClass.h"

int main(void)
{
	// Variables
	char gameBoard[GB_ROWS][GB_COLUMNS]; 
	char feedbackBoard[GB_ROWS][GB_COLUMNS]; 
	char gameSolution[SINGLE_ROW]; 
	char playersGuess[SINGLE_ROW];
	char currentGuessFeedback[SINGLE_ROW];
	char possibleChoices[7] = {'R', 'O', 'Y', 'G', 'B', 'I', 'V'};

	int endGame = 0, menuChoice = 0, i, j;
	int currentTurn = 0, showSolution = 0;

	// instancating Variables
	// game board and feedback board
	for (i = 0; i < GB_ROWS; i++) 
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

		}while((menuChoice < 1) || (menuChoice > 2));

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
					showSolution = checkPlayersGuess(playersGuess, gameSolution, feedbackBoard, currentGuessFeedback, currentTurn);
					addPlayersGuessToBoard(playersGuess,gameBoard, currentTurn);
					printGameBoard(gameBoard, feedbackBoard, gameSolution, showSolution);

					// moves on to the next turn
					currentTurn++;

					if(currentTurn > 15)
					{
						
					}
					break;
				case 2: // exit
					printf("\nExiting!");
					menuChoice = 99;
					break;
				} // switch

			} // while

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

void printGameBoard(char gameBoard[GB_ROWS][GB_COLUMNS], char feedbackBoard[GB_ROWS][GB_COLUMNS],
	char gameSolution[], int showSolution)
{
	// lots of specific spacing to get the game board
	// to print onto the screen properly
	// so it looks like an actual game board

	int i, j;
	
	printf("\n===========================");
	printf("\n= Game Board |  Feedback  =");
	printf("\n===========================\n");
	
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

	printf("\n======== Solution: ========");
	printf("\n===========================\n");

	// if showSolution == 0 = false, 1 = true
	if(showSolution == 1) // if game has been won
	{
		printf("========= ");
		for(i = 0; i < 4; i++)
		{
			printf("%c ", gameSolution[i]);
		}
		printf("=========");
		printf("\n===========================\n");
	}
	else if(showSolution == 0)
	{
		printf("========= ");
		for(i = 0; i < 4; i++)
		{
			printf("? ");
		}
		printf("=========");
		printf("\n===========================\n");
	}


} // printFullGameBoard()

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

int checkPlayersGuess(char playersGuess[SINGLE_ROW], char gameSolution[SINGLE_ROW], char feedbackBoard[GB_ROWS][GB_COLUMNS], char currentGuessFeedback[SINGLE_ROW], int currentTurn)
{
	int whitePegs = 0, blackPegs = 0;
	int i, j;

	// resetting the current feedback
	// to nothing
	for(i = 0; i < 4; i++)
	{
		currentGuessFeedback[i] = '.';
	} // for

	// whitePegs = correct colour in wrong place
	// blackPegs = correct colour in right place

	// checks to see if the players guess is right or wrong
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
		{
			// if the contents of gameSolution and playersGuess match (eg the right colour)
			// AND the colours are in the same place
			// SO: if right colour is in right place.

			// break after peg is gotten so exta pegs aren't added
			// if a colour is guessed more then once
			if((gameSolution[i] == playersGuess[j]) && (i == j)) 
			{
				blackPegs++; // player gets black feedback peg
				break;
			} // if

			// if the contents of gameSolution and playersGuess match (eg the right colour)
			// BUT the colours are in different places
			// SO: if right colour in wrong place
			if(gameSolution[i] == playersGuess[j] && i != j) 
			{
				whitePegs++; // player gets white feedback peg
				break;
			} // if
		} // for
	} // for

	if(blackPegs == 4) // if all pegs are right, game is won
	{
		printf("\n\nThe Game Has Been Won!\n");
		return 1;
	} // if
	else // if there are any feedback pegs to be shown
	{
		// gets total number of pegs to output to 
		// feedback board.
		int totalPegs = 0;

		totalPegs += whitePegs + blackPegs;
		
		// outputs the white pegs first if there are any
		// decreasing the total number of feedback pegs
		// as it goes.
		// then outputs the black pegs if there are any
		while(totalPegs != 0)
		{
			if(whitePegs > 0)
			{
				for(i = 0; i < whitePegs; i++)
				{
					currentGuessFeedback[totalPegs-1] = 'W';
					totalPegs--;
				} // for
			} // if

			if(blackPegs > 0)
			{
				for(i = 0; i < blackPegs; i++)
				{
					currentGuessFeedback[totalPegs-1] = 'B';
					totalPegs--;
				} // for
			} // if

		} // while

		// shuffle feedback pegs so the player
		// cannot guess which peg right or wrong
		shuffleArray(currentGuessFeedback, 4);

		// add the current feedback pegs into 
		// the main game board

		for(i = 0; i < 4; i++)
		{
			feedbackBoard[currentTurn][i] = currentGuessFeedback[i];
		} // for

		printf("\n\nWhite Pegs: %d", whitePegs);
		printf("\nBlack Pegs: %d", blackPegs);

		return 0;
	} // if

} // checkPlayersGuess()

void addPlayersGuessToBoard(char playersGuess[SINGLE_ROW], char gameBoard[GB_ROWS][GB_COLUMNS], int currentTurn)
{
	int i;
	for(i = 0; i < 4; i++)
	{
		gameBoard[currentTurn][i] = playersGuess[i];
	} // for
} // addPlayersGuessToBoard

void shuffleArray(char array[], int arraySize)
{
	// A reworked version of the Fisher–Yates shuffle Algorithm

	int i, j;
	char temp;
	time_t t;
	
	// Intializes random number generator
	srand((unsigned)time(&t));

	// Start from the last element and swap one by one
	for (i = (arraySize-1); i > 0; i--)
    {
        // Pick a random index from 0 to i
        j = rand() % (i+1);
 
        // Swap array[i] with the element at random index
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
    } // for

} // shuffleArray()

void generateGameSolution(char gameSolution[SINGLE_ROW], char possibleChoices[7])
{
	int i;

	// shuffles the possible solutions array
	// 7 is the size of possibleChoices array
	shuffleArray(possibleChoices, 7);

	// add first 4 elements of shuffled array as 
	// the games solution
	for(i = 0; i < 4; i++)
	{
		gameSolution[i] = possibleChoices[i];
	}

} // generateGameSolution()

