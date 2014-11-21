
#include "MainClass.h"

int main(void)
{
	char gameBoard[16][5]; // game board is 15 rows of 4 pegs
	char feedbackBoard[16][5]; // board for feedback pins, while or black
	int endGame = 0, menuChoice = 0;

	printf("Welcome To Mastermind.");

	// Game Loop
	while(endGame != 99)
	{
		// To make sure the number input is in the right range
		// and that it is actually an int
		do
		{
			printGameMenu();

			printf("\n\nEnter Option: ");
		
			fflush(stdin); // flush buffer
			scanf("%d",&menuChoice);

		}while((menuChoice < 1) || (menuChoice > 2));

		switch(menuChoice)
		{
		case 1:
			printf("Play Game!");
			//endGame = 0;
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
 
void printGameMenu()
{
	// prints game menu
	printf("\n\n\Game Menu\n");
	printf("\n1.) Start Playing Mastermind.");
	printf("\n2.) Exit.");
} // printGameMenu()