#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// num of rows and columns on the game board
#define TURNS 15
#define GB_COLUMNS 4
#define MAX_STRING 20

// num of places in a row
#define SINGLE_ROW 4

// Fuctions
void printPegSelectionOptions();
void printMainGameMenu();
void printGameMenu();
void printOptionsMenu();
void printChangeGameDifMenu();

void printGameBoard(char gameBoard[TURNS][GB_COLUMNS], char feedbackBoard[TURNS][GB_COLUMNS],
	char gameSolution[], int showSolution, int gameTurns);
void printFeedbackPegs(char feedbackBoard[TURNS][GB_COLUMNS], int gameTurns);
void printPlayersGuess(char playersGuess[SINGLE_ROW]);
void printGameSolution(char gameSolution[SINGLE_ROW]);

void makeGuess(char playersGuess[SINGLE_ROW], char gameDif[MAX_STRING]);

void checkPlayersGuess(char playersGuess[SINGLE_ROW], char gameSolution[SINGLE_ROW], 
	char feedbackBoard[TURNS][GB_COLUMNS], char currentGuessFeedback[SINGLE_ROW], int currentTurn, int *showSolution);

void addPlayersGuessToBoard(char playersGuess[SINGLE_ROW], char gameBoard[TURNS][GB_COLUMNS], int currentTurn);

void shuffleArray(char array[], int arraySize);
void generateGameSolution(char gameSolution[SINGLE_ROW], char possibleChoices[7], char possibleHardChoices[8], 
	char gameDif[MAX_STRING]);

void options(int *gameTurnsPtr, char playerName[MAX_STRING], char gameDif[MAX_STRING]);
