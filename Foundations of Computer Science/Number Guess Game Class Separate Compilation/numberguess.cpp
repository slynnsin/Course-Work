/*************************************************************
Sarah Sindeband
Date: 12/3/21
Course:  C0P3014
//cpp file for the numberguess
*************************************************************/

#include <iostream> //standard library for i/o
#include <string> // string class
#include <ctime> //random number generator
#include "numberguess.h"
using namespace std;


//default constructor
numberGuess::numberGuess()
{
	upperValue = 0;
	//initialize all the member variables here
	small = 0;
	large = 0;
	above = 0;
	below = 0;
	numGuesses = 0;
	currentGuess = 0;
	solution = 0;
}


//explicit value constuctor
// pass the upper range and the max guesses
numberGuess::numberGuess(int upper, int max)
{
	upperValue = upper;						//15, 50, or 150
	numGuesses = max;						//4, 6, or 8
	//initialize all other the member variables here
	small = 0;
	large = 0;
	above = 0;
	below = 0;
	currentGuess = 0;
	solution = 0;
}

void numberGuess::SetUpperRange(int upper)
//mutator function
//Description:  sets the upper value of the current round
{
	//setupperValue only if function is called
	upperValue = upper;
}

void numberGuess::SetNumGuesses(int num)
//mutator function
//Description:  sets the maximum number of guesses for the current round 
{
	numGuesses = num;
}

void numberGuess::GenerateSolution()
//Description:  Describe what the function does.
{

	srand((unsigned)time(0));
	solution = 1 + rand() % upperValue;
	//cout << "\nSolution is " << solution << endl;

}

void numberGuess::GuessInput()
//Description:  Displays the range, prompts, and gets the next guess from the user
{
	if (below)
	{
		if (small < currentGuess)
		{
			small = currentGuess;
		}
	}
	else if (above)
	{
		if (large > currentGuess)
		{
			large = currentGuess;
		}
	}
	cout << "\nEnter a guess between " << small << " and " << large << " : ";
	//get the guess
	cin >> currentGuess;
}

bool numberGuess::ProcessGuess()
//Description:  Determines if the guess is right or wrong
{
	if (currentGuess > solution)
	{
		cout << "\nYour guess was too high.";
		cout << "\n-----------------------";
		above = true;
		return false;
	}
	else if (currentGuess < solution)
	{
		cout << "\nYour guess was too low.";
		cout << "\n-----------------------";
		below = true;
		return false;
	}
	else
	{
		return true;
	}

}

void numberGuess::PlayOneRound(const string& name)
//Description:  Play one round of the number guess game
{
	//initalize bool 
	above = 0;
	below = 0;

	//initialize high and low values
	small = 1;
	large = upperValue;

	cout << "\nYou will have " << numGuesses << " guess(es), Good Luck!" << endl;

	//generate the random number
	GenerateSolution();

	//loop(number of guesses)
	for (int i = 0; i < numGuesses; i++)
	{
		cout << "\n-----------------------";
		cout << "\nThis is guess number (" << i + 1 << " of " << numGuesses << ")";
		//get next guess public member function
		GuessInput();

		//reset above and below bool values to false
		below = 0;
		above = 0;

		if (ProcessGuess())
		{
			cout << "\nYou won that round, " << name << "!\n";
			//stop the lop without  break statement ???
			i = numGuesses;
		}
	}
	//print the solution
	cout << "\nSOLUTION WAS " << solution << endl;

}