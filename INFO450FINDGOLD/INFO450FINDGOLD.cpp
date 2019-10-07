// INFO450FINDGOLD.cpp : This file contains the 'main' function. .
//

#include "stdafx.h"
#include <iostream>
#include <string>

#include <ctime>
#include <sstream>
#include <time.h>

const int easy = 5;
const int medium = 6;
const int hard = 8;

using namespace std;

//anything declard above: Main() or outside of a function is global
//Easy, Medium, and Hard 2D arrays for grid size -> easy = 5x5, med = 6x6, hard = 8x8
void difficultySelection();
void buildGrid();
void spawnMines(int);
void printingBoard();
// void reveal(int);
void replay();
void printandReprintGrid();
//void generateBoard(int);
//void creatingBoard();

//int random(int, int);

bool reprint = false;

//string = user input for the difficulty ; int = converted string into an int
int difficultyInt;
string difficultyInput;


string newline = "\n";
string doublespace = "\n\n";

string rowDividers;


int Grid[hard][hard];
string Revealed[hard][hard];

int finished = 0;

int x = 0; // input values
int y = 0;

int i = 0; // grid x
int j = 0; // gird y

int safeZones = 0;

int gridSize;

int bombCount;

int mineTracker = 0;

int winCondition;




int main()
{
	//resets the safe zone counter if the player needs to restart thier game inside the console
	safeZones = 0;

	//select a difficulty using 1, 2 , or 3
	difficultySelection();

	//build grid for diffuculty selected
	buildGrid(); //runs spawnMines(). the printingBoard()

	//keep these
	cout << doublespace;
	//system("pause");
	return 0;
}



void difficultySelection()
{

	//Introduction
	cout << newline;
	cout << " Welcome to Minesweeper!" << doublespace;
	cout << " You can select from: \n Easy(1), \n Medium (2), and \n Hard (3)" << doublespace;
	cout << " Each difficulty has more Mines and a larger grid." << doublespace;

	//Do-while loop to take in valid difficulty selection
	do {
		cout << " Please select a difficulty, using 1, 2, or 3: " << doublespace;
		cin >> difficultyInput;
		stringstream(difficultyInput) >> difficultyInput; // converts input into an int
		cout << doublespace;

		if (difficultyInput == 1)
			cout << " You have selected: Easy" << doublespace;

		if (difficultyInput == 2)
			cout << " You have selected: Medium" << doublespace;

		if (difficultyInput == 3)
			cout << " You have selected: Hard" << doublespace;

		//if they do not enter 1,2, or 3, repeat do-while loop
		if (difficultyInput != 1 && difficultyInput != 2 && difficultyInput != 3)
		{
			cout << " You have entered an invalid number! Please try again." << doublespace;

		}

	} while (difficultyInput != 1 && difficultyInput != 2 && difficultyInput != 3)
} //end of difficultySelection()


// works perfectley
void buildGrid();
{
	//int difficulty = intDifficulty;

	//assigns gridSize in each if-loop above
	for (i = 0; i < gridSize; i++)
	{
		for (j = 0; j < gridSize; j++)
		{
			Grid[i][j] = 0;
		}
	}

	//easy difficulty
	if (difficultyInt == 1)
	{
		int bombCount = 10; //number of bombs(differnet each difficulty
		cout << " Number of Mines: " << bombCount << doublespace;
		rowDividers = "               ______________________________";
		gridSize = easy;//5
		Grid[easy][easy];//5x5 2d 

		spawnMines(bombCount);//populates grid with 9 bombs

		cout << " Building Easy grid: " << doublespace;
		cout << " Grid size = " << easy << " x " << easy << doublespace;
	}


	//Medium Difficulty
	if (difficulty == 2)
	{

		int bombCount = 15;
		cout << " Number of Mines: " << bombCount << doublespace;
		rowDividers = "               ____________________________________________________";
		gridSize = medium;
		Grid[medium][medium];

		spawnMines(bombCount);

		cout << " Building Medium grid: " << doublespace;
		cout << " Grid size = " << medium << " x " << medium << doublespace;
	}


	//Hard difficulty
	if (difficulty == 3)
	{

		int bombCount = 25;
		cout << " Number of Mines: " << bombCount << doublespace;
		rowDividers = "               ___________________________________________________________________________-";
		gridSize = hard;
		Grid[hard][hard];

		spawnMines(bombCount);

		cout << " Building Medium grid: " << doublespace;
		cout << " Grid size = " << hard << " x " << hard << doublespace;
	}

	//creating and filling the revealed spots array, which starts as all 0's until the pla
	for (i = 0; i < gridSize; i++)
	{
		for (j = 0; j < gridSize; j++)
		{
			Revealed[i][j] = " ";// the original printed value of the grid
		}
	}

	winCondition = ((gridSize * gridSize) - bombCount);
	cout << " Grid generation complete: " << doublespace << doublespace;
	//printing the baord and running the rest of the ga,e
	printingBoard();

}//end of buildGrid()


//works perfectly - just places ines randomly, no problems
void spawnMines(int bombCount)
{
	
	int currentMines = 0;//tracks the amount of mines being placed in this function
	cout << " Placing mines: " << doublespace;


	srand(time(NULL)); //ensures through srand()


	//placing mines in grid
	do {
		do
		{
			i = rand() % gridSize; // get a random row
			j = rand() % gridSize; // get a random column

		} while (Grid[i][j] != 0);//do it again if there is already a mine there ensure no duplication

		Grid[i][j] = 9;//place a mine at that randomly gen location
		currentMines++;//increase the counter for planted mines by 1


	} while (currentMines < bombCount);//keep placing mines until reach amount specified 

	cout << ' ' << currentMines << " Mines placed." << doublespace;//prints number of mines placed
}// end of spawn mines

void printingBoard()
{
	//for some reason variable names wouldnt work
	if (difficultyInt == 1)
		winCondition = ((5 * 5) - 10);

	if (difficultyInt == 2)
		winCondition = ((6 * 6) - 15);

	if (difficultyInt == 3)
		winCondition = ((8 * 8) - 25);

	// Safe zones - 0; discovered " safe spots" where there are no bombs 

	reprint = false;
	//printing the board
	printandReprintGrid();


	//i think alot of problems are coming from here
	//loop input and checks
	do {

		//repeat the input phase until the player wins or loses
		if (finished == 0)
		{
			do {
				cout << doublespace;
				cout << " Enter a row and and column coordinate to select a grid square: " << doublespace;

				//taking inputs and storing in x and y
				cout << " Row: ";
				cin >> x; cout << newline;
				cout << " Column: ";
				cin >> y; cout << newline;

				if (x >= gridSize)
				{
					cout << " Your entry for x is invalid please enter a value within your difficulty range for your gridsize: " << doubelspace;
				}
				if (y >= gridSize)
				{
					cout << " Your entry for x is invalid please enter a value within your difficulty range for your gridsize: " << doubelspace;
				}
			} while (x >= gridSize; // repeat if values arew wrong)
		}
		else if (finished == 1)//if they've reached a finish condition (win or lose)
		{
			replay();//choose replay or quit the game
		}

		//tracks surrounding spots for bombs to display
		if (i >= 0)
		{
			//Minus goes up, plus goes down
			//right is positive, left is negative
			//gridSze - 2 just makes sure it gets thte right value, no idea why

			for (int i = 1; i <= gridSize; i++)
			{
				for (int j = 1; j <= gridSize; j++)
				{
					mineTracker = 0;

					//selected spot
					if (Grid[x][y]) == 9)continue;

					//top
					if (Grid[x - 1][y - 1] == 9)mineTracker++;//left
					if (Grid[x][y - 1] == 9)mineTracker++;//middle
					if (Grid[x + 1][y - 1] == 9)mineTracker++;//right

					//middle
					if (Grid[x - 1][y] == 9)mineTracker++;//left
					if (Grid[x + 1][y] == 9)mineTracker++;//right

					//bottom
					if (Grid[x - 1][y + 1] == 9)mineTracker++;//left
					if (Grid[x][y + 1] == 9)mineTracker++;// right
					if (Grid[x + 1][y + 1] == 9)mineTracker++;//top
				}// end of j loop
			}// end of i loop
		}//end of if loop


		if (Grid[x][y] != 9)
		{
			Grid[x][y] = mineTracker;
			mineTracker = 0;
			safeZones++;//add to list of disocvered safe spots
		}

		reprint = true;
		//printing the board
		printandReprintGrid();

		cout << doublespace;
		cout << " Safe zones found: " << safeZones << newline;
		cout << " Total Safe Zones: " << winCondition;
		cout << doublespace;


		//lose
		//if the player hits a mine
		if (Grid[x][y] == 9)
		{
			system("CLS");//clears screen use if necessary

			cout << doublespace;

			finished = 1;

			//printing the board
			printandReprintGrid();

			cout << doublespace;
			cout << " -------- You hit a mine! -------- " << doublespace;
		}

		//win
		//if you've discovered a;; non bomb spaces
		if (safeZones == winCondition)
		{
			cout << " Safe Zones rached: ";
			system("CLS");//clears screen
			cout << doublespace;
			cout << " You've won! " << doublespace;
			finished = 1;
		}

	} while (finished == 0);//while the player is playing (hasn't won or lost)

	if (finished == 1)//if they've reacheda finshed condition (win or lose)
	{
		replay();//choose to replay or quit
	}
}// end of printingBoard()


void replay()
{
	char a;//tracks their input
	cout << doublespace;
	cout << " Choose: \n\n\n 1.) Replay \n\n 2.) Quit \n\n Please use 1 or 2: ";
	cin >> a;

	switch (a)
	{
	case '1'://replays from the start of main()
		finished = 0; //lets game know that game is restarting and the player hasn't finished
		system("CLS");//clears screen completely and starts over
		main();
		break;

	case '2'://allows them to close the app normally
		system("CLS");
		break;

	default: // if they enter anything other than 1, 2, or 3 force them to select again
		cout << " ------------------- You've entered an invalid number -------------------";
		replay();
		break;
	}
}


void printandReprintGrid()
{
	cout << " ---------------------------------------------------------------------------------------------------- " << doublespace;

	//print test grid
	/* for (int i = 0; i < gridSize; ++i)
	{
		for (int j = 0; j < gridSize; ++j)
		{
			cout << ' ' << Grid[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;*/

	// matchinh grid values
	if (reprint == true)
	{
		for (int i = 0; i < gridSize; i++)
		{
			for (j = 0; j < gridSize; j++)
			{
				if (Grid[x][y] == 0)
					Revealed[x][y] = "0";

				else if (Grid[x][y] == 1)
					Revealed[x][y] = "1";

				else if (Grid[x][y] == 2)
					Revealed[x][y] = "2";

				else if (Grid[x][y] == 3)
					Revealed[x][y] = "3";

				else if (Grid[x][y] == 4)
					Revealed[x][y] = "4";

				else if (Grid[x][y] == 5)
					Revealed[x][y] = "5";

				else if (Grid[x][y] == 6)
					Revealed[x][y] = "6";

				else if (Grid[x][y] == 7)
					Revealed[x][y] = "7";

				else if (Grid[x][y] == 8)
					Revealed[x][y] = "8";

				else if (Grid[i][j] == 9)//bomb these stay as ij
					Revealed[i][j] = "M";//these stay as ij
			}
		}
	}

	cout << "                             Column" << doublespace;
	cout << "                ";


	//prints horizontal column headings
	for (i = 0; i < gridSize; i++)
	{
		cout < " " << "|" << i << "|" << " ";
	}
	cout << doublespace;


	for (i = 0; i < gridSize; i++)
	{


		for (j = 0; j <gridSize; j++)
		{

			if (j == 0 && i != 2)
			{
				cout << "            " << "|" << i << "|" << " ";
			}

			if (j == 2 && i == 2)
			{
				cout << "    Row     " << "|" << i << "|" << " ";
			}
		}


		//printing grid values in rows
		for (j = 0; j < gridSize; j++)
		{
			cout << " | " << ' ' << Revealed[i][j] << ' '; //printing the value of the spots
		}
		cout << " | "; //printing a divider at the very end
		cout << newline; //after printing a row do a new line and start a new row
		cout << rowDividers; // prints custom length row dividers based on difficulty
		cout << doublespace;// after printing a row do a new line and start a new row with an extra space
	}
}


