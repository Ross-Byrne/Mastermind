/* MainClass.h for MinClass.c */

#include <stdio.h>
#include <stdlib.h>

// num of rows and columns on the game board
#define GB_ROWS 15
#define GB_COLUMNS 4

// num of places in a row
#define SINGLE_ROW 4

// Fuctions
void printMainGameMenu();
void printGameMenu();

void printGameBoard(char gameBoard[GB_ROWS][GB_COLUMNS], char feedbackBoard[GB_ROWS][GB_COLUMNS],
	char gameSolution[SINGLE_ROW], int gameWon);
void printFeedbackPegs(char feedbackBoard[GB_ROWS][GB_COLUMNS]);
void printPlayersGuess(char playersGuess[SINGLE_ROW]);
void printGameSolution(char gameSolution[SINGLE_ROW]);

void playGame(char gameBoard[GB_ROWS][GB_COLUMNS], char feedbackBoard[GB_ROWS][GB_COLUMNS], 
	char gameSolution[SINGLE_ROW], char playersGuess[SINGLE_ROW], int currentTurn, int gameWon);

void makeGuess(char playersGuess[SINGLE_ROW]);

void checkPlayersGuess(char playersGuess[SINGLE_ROW], char gameSolution[SINGLE_ROW], 
	char feedbackBoard[GB_ROWS][GB_COLUMNS], int currentTurn, int gameWon);

void addPlayersGuessToBoard(char playersGuess[SINGLE_ROW], char gameBoard[GB_ROWS][GB_COLUMNS], int currentTurn);
