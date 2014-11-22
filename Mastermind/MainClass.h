/* MainClass.h for MinClass.c */

#include <stdio.h>
#include <stdlib.h>

#define GB_ROWS 15
#define GB_COLUMNS 4

#define FB_ROWS 15
#define FB_COLUMNS 4

// Fuctions
void printMainGameMenu();
void printGameMenu();

void printGameBoard(char gameBoard[GB_ROWS][GB_COLUMNS]);

void playGame(char gameBoard[GB_ROWS][GB_COLUMNS]);
