/*************************************************************
Sarah Sindeband
Date: 12/3/21
Course:  C0P3014
Description: Number guessing game with a random number generator, introduction to class member functions, private and public member variables,
mutator and accessor functions and separate compilation.
*************************************************************/

#include <iostream> //standard library for i/o
#include <string> // always include this when you use the string class
#include <ctime> //random number generator
#include "numberguess.h"//interface to the numberguess class 
using namespace std;

//function prototype
void SetUpLevel(numberGuess& currentGame);
//Description: Asks and gets the level and sets up one round of the game


int main()
{
	string name;
	string yesOrNo;

	//ask and get the users name
	cout << "Enter your first name: ";
	cin >> name;
	cout << "-----------------------------------------------------";

	//demonstration of the explict-value constructor
	numberGuess demoGame(15, 4); //explicit-value constructor
	
	//play one game at level 1
	cout << "\nHi " << name << ", here is a demonstration of the game at level 1:";
	cout << "\n-----------------------";
	demoGame.PlayOneRound(name); //play the demo game

	//calls the default constructor
	numberGuess activeGame;

	//ask the user if they want to play"
	cout << "Do you want to play a guessing game? (y(Y) or n(N)): ";
	cin >> yesOrNo; // initialization for loop

	while (yesOrNo != "n" && yesOrNo != "N")
	{
		//set up the level not a member function
		SetUpLevel(activeGame);

		//play a round
		activeGame.PlayOneRound(name);

		//another round ?
		cout << "\nDo you want to play another round? (y(Y) or n(N)): ";
		cin >> yesOrNo; // update for loop
	}
	return  0;
}

void SetUpLevel(numberGuess& currentGame)
//Description:  Asks and gets the level and sets up one round of the game
{
	int level;

	//ask and get the level
	do {
		cout << "************************************************\n";
		//display and get the levels
		cout << "what level (Enter 1, 2, or 3)?\n";
		cout << "(1) Level 1 - 4 guesses, numbers 1 through 15\n";
		cout << "(2) Level 2 - 6 guesses, numbers 1 through 50\n";
		cout << "(3) Level 3 - 8 guesses, numbers 1 through 150: \n";
		cin >> level;
	} while (level > 3 || level < 1);

	if (level == 1)
	{
		//mutator functions
		currentGame.SetNumGuesses(4);
		currentGame.SetUpperRange(15);
	}
	else if (level == 2)
	{
		//mutator functions
		currentGame.SetNumGuesses(6);
		currentGame.SetUpperRange(50);
	}
	else if (level == 3)
	{
		//mutator functions
		currentGame.SetNumGuesses(8);
		currentGame.SetUpperRange(150);
	}
	else
	{
		cout << "\nThat is not a valid level";
	}
}

