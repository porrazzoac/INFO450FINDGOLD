// INFO450FINDGOLD.cpp : This file contains the 'main' function. .
//
#include <iostream>
#include <time.h>
using namespace std;

int i, j, i2, j2;
//columns and rows of intialBoard and gameBoard
int input1;
int input2;
int totalInput = 5;
//user inputs and user input counter
const int ROW = 10;
const int COL = 10;
const int GOLD = 5;
//establishing the game board size and the total pieces of gold to be hidden


void randomBomb(char gameBoard[ROW][COL]);
void randomGold(char gameBoard[ROW][COL]);

int main()
{
	srand(time(NULL));

	char choice = ('Y' || 'y' || 'n');
	int countGold = 0;
	cout << "--- Welcome to Find the Gold ---" << endl;
	cout << "You get 5 tries to find the gold." << endl;
	cout << "You get 1 extra try for finding gold." << endl;
	cout << "Hit the bomb however, Game Over! " << endl;
	// Beginning of the Game 
	do

	{

		char initialBoard[ROW][COL] = { {'0','|','1','2','3','4','5','6','7','8'}

		, {'_','_','_','_','_','_','_','_','_','_',}, {'1','|', '?','?','?','?',

		'?', '?','?','?'}, {'2','|','?','?','?','?','?','?','?','?'}, {'3','|',

		'?', '?', '?','?','?','?','?','?'},{'4','|','?','?','?','?','?','?','?',

		'?'},{'5', '|', '?','?','?','?','?','?','?','?'}, {'6','|','?','?','?',

		'?','?','?', '?','?'}, {'7','|','?','?','?','?','?','?','?','?'}, {'8',

		'|','?','?', '?','?','?','?','?','?'} };
		//screen

		for (i = 0; i < 10; i++)

		{

			for (j = 0; j < 10; j++)

			{
				cout << initialBoard[i][j] << "  ";
			}
			cout << endl;

		}

		cout << "Follow the instructions below: " << endl;
		cout << "Only enter coordinates in the range of (1-8) " << endl;
		//Beginning of game

		char gameBoard[ROW][COL] = { {'0','|', '1', '2', '3', '4', '5', '6',

		'7', '8'}, {'_','_','_','_','_','_','_','_','_','_'},{ '1', '|',' ',

		' ',' ',' ',' ',' ',' ',' '}, { '2','|',' ',' ',' ',' ',' ',' ',' ',' '

		}, { '3','|',' ',' ',' ',' ',' ',' ',' ',' ' }, { '4', '|', ' ',' ',

		' ',' ',' ',' ',' ',' ' },{ '5','|',' ',' ',' ',' ',' ',' ',' ',' ' },{

		'6','|',' ',' ',' ',' ',' ',' ',' ',' ' },{ '7','|', ' ', ' ', ' ',' ',

		' ',' ',' ',' ' }, { '8', '|', ' ',' ',' ',' ',' ',' ',' ',' ' } };
		//hidden gameboard is initialized

		for (i = 0; i < GOLD; i++)

		{
			randomGold(gameBoard);
		}
		randomBomb(gameBoard);

		do {
			cout << "Please enter a x-coordinate: " << endl;
			cin >> input2;
			cout << "Please enter a y-coordinate: " << endl;
			cin >> input1;


			if (gameBoard[input1 + 1][input2 + 1] == 'G')
			{
				cout << "You found gold!" << endl;
				totalInput++;
				countGold++;
				cout << "There're " << totalInput << " attempts remaining " << endl;
				gameBoard[input1 + 1][input2 + 1] = 'F';
			}
			//Gold found


			else if (input1 > 8 || input1 < 1)
			{
				cout << "Sorry those coordinates are Invalid! They're not in range " << endl;
				cout << "Please try again " << endl;
			}



			else if (input2 > 8 || input2 < 1)
			{
				cout << "Sorry those coordinates are Invalid! They're not in range " << endl;
				cout << "Please try again " << endl;
			}
			//Valid coordinates in range


			else if (gameBoard[input1 + 2][input2 + 2] == 'B')
			{
				cout << "Game Over! You hit the Bomb" << endl;
				break;
			}
			//Bomb


			else if (gameBoard[input1 + 1][input2 + 1] == ' ')
			{
				totalInput--;
				gameBoard[input1 + 1][input2 + 1] = 'X';

				cout << "Sorry there was no gold at these coordinates " << endl;
				cout << "There're " << totalInput << " attempts remaining " << endl;
			}
			//Inputed coordinates


			else if ((gameBoard[input1 + 1][input2 + 1] == 'X') || (gameBoard

				[input1 + 1][input2 + 1] == 'F'))
			{
				cout << "This location was used already chosen" << endl;
				cout << "There're " << totalInput << " attempts remaining" << endl;
			}
			//Repeated coordinates entered or found already


		} while ((countGold == 5)||(totalInput != 0));
		//Checks which set of statements above the coordinates belongs to (G,F,B,X, etc) 

		cout << "The solution and your coordinates of your board: " << endl;

		for (i2 = 0; i2 < ROW; i2++)
		{
			for (j2 = 0; j2 < COL; j2++)

			{
				cout << gameBoard[i2][j2] << "  ";
			}
			cout << endl;
		}
		//soultion to the game 

		cout << "You discovered " << countGold << " total pieces of gold" << endl;

		if (countGold == 5)

			cout << "Wow You Won the Game!" << endl;
		//condition to win the game

		cout << "Would you like to play another game? y/n" << endl;
		cin >> choice;

	} while ((choice == 'Y') || (choice == 'y') && (totalInput = 5));
	system("CLS");
	return 0;
}

void randomBomb(char gameBoard[ROW][COL])
{
	int RANDROW = rand() % 8 + 1;
	int RANDCOL = rand() % 8 + 1;

	gameBoard[RANDROW + 1][RANDCOL + 1] = 'B';
}
//randomizes bomb

void randomGold(char gameBoard[ROW][COL])
{

	int RANDROW = rand() % 8 + 1;
	int RANDCOL = rand() % 8 + 1;

	gameBoard[RANDROW + 1][RANDCOL + 1] = 'G';
}
//randomizes gold


