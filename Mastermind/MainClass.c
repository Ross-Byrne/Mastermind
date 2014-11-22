
#include "MainClass.h"

int main(void)
{
	
	char gameBoard[GBROWS][GBCOLUMNS]; 
	char feedbackBoard[16][5]; 
	char gameSolution[5]; 
	char playersGuess[5]; 

	int endGame = 0, menuChoice = 0;

	printf("Welcome To Mastermind.");

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
			printf("Play Game!");
			playGame(gameBoard);
			break;
		case 2:
			printf("Exiting");
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

void playGame(char gameBoard[GBROWS][GBCOLUMNS])
{
	int menuChoice = 0;

	printf("\nThe aim of the game is to guess the colour and position of four pins.");
	printf("\nThe pin colours are all the colours of the rainbow:");
	printf("\nRed, Orange, Yellow, Green, Blue, Indigo and Violet.\n");

	while(menuChoice != 99)
	{

		// To make sure the number input is in the right range
		do
		{
			printGameMenu();

			printf("\n\nEnter Option: ");
		
			fflush(stdin); // flush buffer
			scanf_s("%d",&menuChoice);

		}while((menuChoice < 1) || (menuChoice > 2));

		switch(menuChoice)
		{
		case 1:
			printf("\nMake A Guess\n");


			//endGame = 0;
			break;
		case 2:
			printf("Exiting");
			menuChoice = 99;
			break;
		} // switch



	
	} // while

} // playGame()