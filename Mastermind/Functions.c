#include "Functions.h"

void printPegSelectionOptions()
{
	printf("\nGuess The Peg!\n");
	printf("\n1.) Red.");
	printf("\n2.) Orange.");
	printf("\n3.) Yellow.");
	printf("\n4.) Green.");
	printf("\n5.) Blue.");
	printf("\n6.) Indigo.");
	printf("\n7.) Violet.");
} // printPegSelectionOptions()

void printMainGameMenu()
{
	printf("\n\nMain Game Menu\n");
	printf("\n1.) Start Playing Mastermind.");
	printf("\n2.) Options.");
	printf("\n3.) Exit.");
} // printGameMenu()

void printGameMenu()
{
	printf("\n\nGame Menu\n");
	printf("\n1.) Make A Guess.");
	printf("\n2.) Exit.");
} // printGameMenu()

void printOptionsMenu()
{
	printf("\n1.) Set Player Name.");
	printf("\n2.) Set Game Difficulty.");
	printf("\n3.) Set Number of Turns Allowed.");
	printf("\n4.) View The Top Scores.");
	printf("\n5.) Go Back To Main Menu.");
} // printOptionsMenu()

void printChangeGameDifMenu()
{
	printf("\n\nChoose a Game Difficuly.\n");
	printf("\nEasy = 4 Colours With No Repeats or Blanks.");
	printf("\nMedium = 4 Colours With Repeats, But No Blanks.");
	printf("\nHard = 4 Colours With Repeats And Blank Spaces As Options.");

	printf("\n\nChoose Game Difficulty.");
	printf("\n1.) Easy.");
	printf("\n2.) Medium.");
	printf("\n3.) Hard.");
} // printChangeGameDifMenu()

void printFeedbackPegs(char feedbackBoard[TURNS][GB_COLUMNS], int gameTurns)
{
	int i, j;

	printf("\nThe Feedback Board\n\n");
	// prints the game feedback board
	for (i = 0; i < gameTurns; i++) 
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

void printGameBoard(char gameBoard[TURNS][GB_COLUMNS], char feedbackBoard[TURNS][GB_COLUMNS],
	char gameSolution[], int showSolution, int gameTurns)
{
	// lots of specific spacing to get the game board
	// to print onto the screen properly
	// so it looks like an actual game board

	int i, j;
	
	printf("\n\n===========================");
	printf("\n= Game Board |  Feedback  =");
	printf("\n===========================\n");
	
	for (i = 0; i < gameTurns; i++) 
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
	if(showSolution == 1 || showSolution == 2) // if game is over
	{
		printf("========= ");
		for(i = 0; i < 4; i++)
		{
			printf("%c ", gameSolution[i]);
		}
		printf("=========");
		printf("\n===========================\n");

		if(showSolution == 1) // its won
		{
		printf("\nThe Game Has Been Won!\n");
		}
		else // its lost
		{
		printf("\nThe Game is Over!\nYou Ran Out Of Turns!\n");
		}
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

void makeGuess(char playersGuess[SINGLE_ROW], char gameDif[MAX_STRING])
{
	int guessNum = 0, menuChoice = 0;
	int numOfOptions = 7;

	// prints basic options
	printPegSelectionOptions();

	// if to decide game dif
	if (strcmp(gameDif, "Hard") == 0)
	{
		printf("\n8.) Blank Space.\n");
		numOfOptions = 8;
	}
	else
	{
		printf("\n");
		numOfOptions = 7;
	} // if else
	
	while(guessNum < 4)
	{
		// To make sure the number input is in the right range
		do
		{
			printf("\n\nEnter Option For Peg %d: ", guessNum+1);
		
			fflush(stdin); // flush buffer
			scanf_s("%d",&menuChoice);

		}while((menuChoice < 1) || (menuChoice > numOfOptions));

		guessNum++;

		switch(menuChoice)
		{
		case 1:
			printf("\nYou Guessed Peg Number %d Is Red!", guessNum);
			playersGuess[guessNum-1] = 'R'; // -1 because 0 index
			break;
		case 2:
			printf("\nYou Guessed Peg Number %d Is Orange!", guessNum);
			playersGuess[guessNum-1] = 'O'; // -1 because 0 index
			break;
		case 3:
			printf("\nYou Guessed Peg Number %d Is Yellow!", guessNum);
			playersGuess[guessNum-1] = 'Y'; // -1 because 0 index
			break;
		case 4:
			printf("\nYou Guessed Peg Number %d Is Green!", guessNum);
			playersGuess[guessNum-1] = 'G'; // -1 because 0 index
			break;
		case 5:
			printf("\nYou Guessed Peg Number %d Is Blue!", guessNum);
			playersGuess[guessNum-1] = 'B'; // -1 because 0 index
			break;
		case 6:
			printf("\nYou Guessed Peg Number %d Is Indigo!", guessNum);
			playersGuess[guessNum-1] = 'I'; // -1 because 0 index
			break;
		case 7:
			printf("\nYou Guessed Peg Number %d Is Violet!", guessNum);
			playersGuess[guessNum-1] = 'V'; // -1 because 0 index
			break;	
		case 8:
			printf("\nYou Guessed Peg Number %d Is A Blank Space!", guessNum);
			playersGuess[guessNum-1] = '.'; // -1 because 0 index
			break;
		} // switch
	} // while
} // makeGuess()

void checkPlayersGuess(char playersGuess[SINGLE_ROW], char gameSolution[SINGLE_ROW], char feedbackBoard[TURNS][GB_COLUMNS], 
	char currentGuessFeedback[SINGLE_ROW], int currentTurn, int *showSolutionPtr)
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

			if((gameSolution[i] == playersGuess[j]) && (i == j)) 
			{
				// break after peg is gotten so extra pegs aren't added
				// if a colour is guessed more then once

				// delete guess after it's give a feedback peg
				// to fix bug of giving a white peg to one
				// of the correct colours when 2 of the same 
				// colours are in the solution and correctly guessed

				playersGuess[j] = ' ';

				blackPegs++; // player gets black feedback peg
				break;
			}
			else if(gameSolution[i] == playersGuess[j] && i != j) 
			{
				// if the contents of gameSolution and playersGuess match (eg the right colour)
				// BUT the colours are in different places
				// SO: if right colour in wrong place
				
				playersGuess[j] = ' ';

				whitePegs++; // player gets white feedback peg
				break;
			} // if
		} // for
	} // for

	if(blackPegs == 4) // if all pegs are right, game is won
	{
		*showSolutionPtr = 1;
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

		*showSolutionPtr = 0;
	} // if

} // checkPlayersGuess()

void addPlayersGuessToBoard(char playersGuess[SINGLE_ROW], char gameBoard[TURNS][GB_COLUMNS], int currentTurn)
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

void generateGameSolution(char gameSolution[SINGLE_ROW], char possibleChoices[7], char possibleHardChoices[8], 
	char gameDif[MAX_STRING])
{
	int i, j;
	time_t t;

	if(strcmp(gameDif, "Hard") == 0) // if gameDif is Hard
	{
		// Intializes random number generator
		srand((unsigned)time(&t));

		// shuffles the possible Hard solutions array
		// 8 is the size of possibleChoices array
		shuffleArray(possibleHardChoices, 8);

		// gets 4 random pegs (options can repeat)
		for(i = 0; i < 4; i++)
		{
			// Pick a random index from 0 to 7
			j = rand() % (7);

			// adds the selected random choice and adds it to solution
			gameSolution[i] = possibleHardChoices[j];
		} // for
	}
	else if(strcmp(gameDif, "Medium") == 0) // if gameDif is Medium
	{
		// Intializes random number generator
		srand((unsigned)time(&t));

		// shuffles the possible solutions array
		// 7 is the size of possibleChoices array
		shuffleArray(possibleChoices, 7);

		// gets 4 pegs from array (Options can repeat)
		for(i = 0; i < 4; i++)
		{
			// Pick a random index from 0 to 6
			j = rand() % (6);

			// adds the selected random choice and adds it to solution
			gameSolution[i] = possibleChoices[j];
		} // for 
	}
	else // if gameDif is Easy
	{
		// shuffles the possible solutions array
		// 7 is the size of possibleChoices array
		shuffleArray(possibleChoices, 7);

		// gets 4 pegs from array (Options can't repeat)
		for(i = 0; i < 4; i++)
		{
			// adds first 4 values from shuffled array
			// so values don't repeat
			gameSolution[i] = possibleChoices[i];
		}
	} // if else

} // generateGameSolution()

void options(int *gameTurnsPtr, char playerName[MAX_STRING], char gameDif[MAX_STRING], int currentTurn)
{
	int menuChoice = 0;

	printf("\nOptions");

	while(menuChoice != 99)
	{
		printf("\n\nThe Player's Name is: %s", playerName);
		printf("\nThe Games Difficulty Level is: %s", gameDif);
		printf("\nYour current game is set to have %d turns.\n", *gameTurnsPtr);
		// To make sure the number input is in the right range
		do
		{
			printOptionsMenu();
			
			printf("\n\nEnter Option: ");
		
			fflush(stdin); // flush buffer
			scanf_s("%d",&menuChoice);

		}while((menuChoice < 1) || (menuChoice > 5));
		
		switch(menuChoice)
		{
		case 1: // set player name
			printf("\nSet The Player's Name: ");
			fflush(stdin); // flush the buffer
			gets(playerName);
			break;
		case 2: // set game difficulty

			printChangeGameDifMenu();

			do
			{
				printf("\n\nEnter Option: ");
		
				fflush(stdin); // flush buffer
				scanf_s("%d",&menuChoice);

			}while((menuChoice < 1) || (menuChoice > 3));

			if(menuChoice == 1) // easy dif
			{
				strcpy(gameDif, "Easy");
			}
			else if(menuChoice == 2) // medium dif
			{
				strcpy(gameDif, "Medium");
			}
			else // hard dif
			{
				strcpy(gameDif, "Hard");
			} // if else
			break;
		case 3: // set number of turns allowed
			// To make sure the number input is in the right range
			do
			{
				printf("\nSet The Number of Turns (up to 15 turns): ");
		
				fflush(stdin); // flush buffer
				scanf_s("%d",&menuChoice);

			}while((menuChoice < 1) || (menuChoice > 15));

			*gameTurnsPtr = menuChoice;
			break;
		case 4: // view top scores
			loadScores();
			break;
		case 5: // exit
			printf("\nExiting!");
			menuChoice = 99;
			break;
		} // switch
	} // while
} // options()

void saveScore(char playerName[MAX_STRING], char gameDif[MAX_STRING], int currentTurn, int *winsPtr, int *lossesPtr)
{
	// top score
	char name1[MAX_STRING] = "Player", difficulty1[MAX_STRING] = " - ";
	int turnsTaken1 = 15;

	// other scores
	char name2[MAX_STRING] = "Player", difficulty2[MAX_STRING] = " - ";
	int turnsTaken2 = 15;

	char name3[MAX_STRING] = "Player", difficulty3[MAX_STRING] = " - ";
	int turnsTaken3 = 15;

	char name4[MAX_STRING] = "Player", difficulty4[MAX_STRING] = " - ";
	int turnsTaken4 = 15;

	char name5[MAX_STRING] = "Player", difficulty5[MAX_STRING] = " - ";
	int turnsTaken5 = 15;

	// other score data
	int wins = 0, losses = 0; 

	FILE *fPtr;

	fPtr = fopen(FILENAME, READMODE);
	if ( fPtr == NULL)
	{
		// if file is not working
		// uses default values
	}
	else
	{
		//loads current high scores
		fscanf(fPtr, "%d %d", &wins, &losses);
		fscanf(fPtr, "%s %s %d", name1, difficulty1, &turnsTaken1);
		fscanf(fPtr, "%s %s %d", name2, difficulty2, &turnsTaken2);
		fscanf(fPtr, "%s %s %d", name3, difficulty3, &turnsTaken3);
		fscanf(fPtr, "%s %s %d", name4, difficulty4, &turnsTaken4);
		fscanf(fPtr, "%s %s %d", name5, difficulty5, &turnsTaken5);

		// closes the file
		fclose(fPtr);
	} // if

	// adds games played to the record
	wins += *winsPtr;
	losses += *lossesPtr;

	// reset game count after its been record
	*winsPtr = 0;
	*lossesPtr = 0;

	// manages the top 5 high scores
	if (currentTurn < turnsTaken1)
    {
		strcpy(name5, name4);
		strcpy(name4, name3);
		strcpy(name3, name2);
		strcpy(name2, name1);
        strcpy(name1, playerName);

		strcpy(difficulty5, difficulty4);
		strcpy(difficulty4, difficulty3);
		strcpy(difficulty3, difficulty2);
		strcpy(difficulty2, difficulty1);
        strcpy(difficulty1, gameDif);

        turnsTaken5 = turnsTaken4;
        turnsTaken4 = turnsTaken3;
        turnsTaken3 = turnsTaken2;
        turnsTaken2 = turnsTaken1;
        turnsTaken1 = currentTurn;
    }
	else
	{
		if (currentTurn < turnsTaken2)
		{
			strcpy(name5, name4);
			strcpy(name4, name3);
			strcpy(name3, name2);
			strcpy(name2, playerName);

			strcpy(difficulty5, difficulty4);
			strcpy(difficulty4, difficulty3);
			strcpy(difficulty3, difficulty2);
			strcpy(difficulty2, gameDif);

			turnsTaken5 = turnsTaken4;
			turnsTaken4 = turnsTaken3;
			turnsTaken3 = turnsTaken2;
			turnsTaken2 = currentTurn;
		}
		else 
		{
			if (currentTurn < turnsTaken3)
			{
				strcpy(name5, name4);
				strcpy(name4, name3);
				strcpy(name3, playerName);

				strcpy(difficulty5, difficulty4);
				strcpy(difficulty4, difficulty3);
				strcpy(difficulty3, gameDif);

				turnsTaken5 = turnsTaken4;
				turnsTaken4 = turnsTaken3;
				turnsTaken3 = currentTurn;
			}
			else 
			{	
				if (currentTurn < turnsTaken4)
				{
					strcpy(name5, name4);
					strcpy(name4, playerName);

					strcpy(difficulty5, difficulty4);
					strcpy(difficulty4, gameDif);

					turnsTaken5 = turnsTaken4;
					turnsTaken4 = currentTurn;
				}
				else 
				{	
					if (currentTurn < turnsTaken5)
					{
						turnsTaken5 = currentTurn;
						strcpy(difficulty5, gameDif);
						strcpy(name5, playerName);
					} // if 
				} // if
			} // if
		} // if
	} // if

	// open file
	fPtr = fopen(FILENAME, WRITEMODE);
	if ( fPtr == NULL )
	{
		printf("\n\n\tCould Not open file\n");
	}
	else
	{
		// Saves scores to file
		fprintf(fPtr, "%d %d\n", wins, losses);
		fprintf(fPtr, "%s %s %d\n", name1, difficulty1, turnsTaken1);
		fprintf(fPtr, "%s %s %d\n", name2, difficulty2, turnsTaken2);
		fprintf(fPtr, "%s %s %d\n", name3, difficulty3, turnsTaken3);
		fprintf(fPtr, "%s %s %d\n", name4, difficulty4, turnsTaken4);
		fprintf(fPtr, "%s %s %d\n", name5, difficulty5, turnsTaken5);

		// close the file
		fclose(fPtr);
	} // if

	printf("\n\nGame Score Saved!\n");
} // saveScore()

void loadScores()
{
	// top score
	char name1[MAX_STRING] = "Player", difficulty1[MAX_STRING] = " - ";
	int turnsTaken1 = 15;

	// other scores
	char name2[MAX_STRING] = "Player", difficulty2[MAX_STRING] = " - ";
	int turnsTaken2 = 15;

	char name3[MAX_STRING] = "Player", difficulty3[MAX_STRING] = " - ";
	int turnsTaken3 = 15;

	char name4[MAX_STRING] = "Player", difficulty4[MAX_STRING] = " - ";
	int turnsTaken4 = 15;

	char name5[MAX_STRING] = "Player", difficulty5[MAX_STRING] = " - ";
	int turnsTaken5 = 15;

	// other score data
	int gamesPlayed = 0, wins = 0, losses = 0; 
	float winsPercent = 0.00 , lossesPercent = 0.00;

	FILE *fPtr;
	int i=0;
	char strBuffer[MAX_COUNT + 1];	// +1 accounts for \0 null character

	fPtr = fopen(FILENAME, READMODE);
	if ( fPtr == NULL)
	{
		printf("\n\nCould Not open file %s. New File Created.", FILENAME);
	}
	else
	{
		// save values from text file to variables
		fscanf(fPtr, "%d %d", &wins, &losses);
		fscanf(fPtr, "%s %s %d", name1, difficulty1, &turnsTaken1);
		fscanf(fPtr, "%s %s %d", name2, difficulty2, &turnsTaken2);
		fscanf(fPtr, "%s %s %d", name3, difficulty3, &turnsTaken3);
		fscanf(fPtr, "%s %s %d", name4, difficulty4, &turnsTaken4);
		fscanf(fPtr, "%s %s %d", name5, difficulty5, &turnsTaken5);
	
		// total games played
		gamesPlayed = wins + losses;
	
		// calculates wins/losses Percentage
		winsPercent = (100 * wins / gamesPlayed);
		lossesPercent = (100 * losses / gamesPlayed);

		//then close the file
		fclose(fPtr);
	} // if

	printf("\nTotal Games Played: %d. Wins/Losses Percentage: %.0f%% / %.0f%%.\n", gamesPlayed, winsPercent, lossesPercent);
	printf("\n1: Name: %s.  Game Difficulty: %s.  Turns Taken: %d.\n", name1, difficulty1, turnsTaken1);
	printf("\n2: Name: %s.  Game Difficulty: %s.  Turns Taken: %d.\n", name2, difficulty2, turnsTaken2);
	printf("\n3: Name: %s.  Game Difficulty: %s.  Turns Taken: %d.\n", name3, difficulty3, turnsTaken3);
	printf("\n4: Name: %s.  Game Difficulty: %s.  Turns Taken: %d.\n", name4, difficulty4, turnsTaken4);
	printf("\n5: Name: %s.  Game Difficulty: %s.  Turns Taken: %d.\n", name5, difficulty5, turnsTaken5);
	
} // loadScores()