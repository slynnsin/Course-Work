/*************************************************************
Sarah Sindeband
Date: 10/13/21
Course:  C0P3014
Description:  This program will interact with the user in a number guessing game with three levels

*************************************************************/
#include <iostream> //standard library for i/o
#include <string> // string class
#include <ctime> //random number generator
using namespace std;

/*********************************************************
//Following is the declaration of numberGuess
**********************************************************/
class numberGuess
{
public:					// making the class public
	int level = 0;//game level 1,2, or 3
	int upperValue = 0;//15, 50, or 150
	int numGuesses = 0;//4, 6, or 8
	int currentGuess = 0; //current guess input by the user
	int solution = 0; //pseudo random generated number
	int small = 0;//lowest value for feedback
	int large = 0;//highest value for feedback
	bool above = false;//current guess above the solution
	bool below = false;//current guess below the solution
};


//Declaration / Prototypes for functions

void SetUpperRange(numberGuess& currentGame);
//Description:  Sets the upper value and large of the current game based on the level chosen by the user

void SetNumGuesses(numberGuess& currentGame);
//Description: Sets the maximum number of guesses for the current round based on the level

void PlayOneRound(const string& name, numberGuess& currentGame);
//Description: Play one round of the number guess game

void GuessInput(numberGuess& currentGame);
//Description: Displays the range, prompts, and gets the next guess from the user

bool ProcessGuess(numberGuess& currentGame);
//Description: Returns true if the guess matches the solution, or false and lets the user know if the guess
//was above or below the solution

void GenerateSolution(numberGuess& currentGame);
//Description: Generates the solution number in the correct range

//main function
int main()
{
	//declare variables
	string name;
	string response;

	//declare current game
	numberGuess currentGame;

	// get user name
	cout << "Enter your first name: ";
	cin >> name;
	cout << "Hi " << name << ", do you want to play a guessing game? (y(Y) or n(N)): ";
	cin >> response; //initialization for loop

	//while begin loop (use while not do while)
	while (response != "N" && response != "n") // user does not want to quit, test for loop
	{
		//play one round
		PlayOneRound(name, currentGame);
		//again?
		cout << "\n\nDo you want to play another round? (y(Y) or n(N)): ";
		cin >> response; //update for loop
	}

	return  0;
}

//Function Implementations
void SetUpperRange(numberGuess& currentGame)
//Description:  sets the upper value of the current game based on the level
{
	if (currentGame.level == 1) currentGame.upperValue = 15;

	else if (currentGame.level == 2) currentGame.upperValue = 50;

	else if (currentGame.level == 3) currentGame.upperValue = 150;

	else cout << "That is not a valid level. \n";

	//set the large value so that it is displayed for the first guess
	currentGame.large = currentGame.upperValue;
}

void SetNumGuesses(numberGuess& currentGame)
//Description:  Sets the maximum number of guesses for the current round based on the level
{
	if (currentGame.level == 1) currentGame.numGuesses = 4;
	else if (currentGame.level == 2) currentGame.numGuesses = 6;
	else if (currentGame.level == 3) currentGame.numGuesses = 8;
}

void PlayOneRound(const string& name, numberGuess& currentGame)
//Description:  Play one round of the number guess game
{
	do {
		cout << "\n************************************************\n";
		//display and get the levels
		cout << "what level (Enter 1, 2, or 3)?\n";
		cout << "(1) Level 1 - 4 guesses, numbers 1 through 15\n";
		cout << "(2) Level 2 - 6 guesses, numbers 1 through 50\n";
		cout << "(3) Level 3 - 8 guesses, numbers 1 through 150: ";
		cin >> currentGame.level;

		//set the upper range based on the level 
		SetUpperRange(currentGame);

		//set the max guesses based on the level 
		SetNumGuesses(currentGame);

		//generate the random number solution
		GenerateSolution(currentGame);

	} while (currentGame.level > 3 || currentGame.level < 1);


	//initalize bool and high/low values
	for (int i = 0; i < currentGame.numGuesses; i++)
	{
		//tell the user what guess number they are on
		//get the next guess
		GuessInput(currentGame);
		// reset above and below to 0
		//reset above and below bool values to false
		currentGame.below = 0;
		currentGame.above = 0;

		//loop header, counting loop for the number of guesses
		if (ProcessGuess(currentGame) == true)
		{
			cout << "\nYou won that round, " << name << "!\n";
			//stop the loop, do not use a break statement to stop the loop
			i = currentGame.numGuesses;
		}
	}//tell the user the solution after the round of the game is done
	//display the solution when they win or lose
	cout << "\nTHE SOLUTION WAS " << currentGame.solution;
}

void GuessInput(numberGuess& currentGame)
//Description:  Displays the range, prompts, and gets the next guess from the user
{
	//set the small and large variables
	if (currentGame.below)
	{
		if (currentGame.small < currentGame.currentGuess)
		{
			currentGame.small = currentGame.currentGuess;
		}
	}
	else if (currentGame.above)
	{
		if (currentGame.large < currentGame.currentGuess)
		{
			currentGame.large = currentGame.currentGuess;
		}
	}
	//set currentGame.large
	else cout << "\nEnter a guess between " << currentGame.small << " and " << currentGame.large << " : ";
	//get the guess
	cin >> currentGame.currentGuess;
}

bool ProcessGuess(numberGuess& currentGame)
//Description:  Returns true if the guess matches the solution, or false and lets the user know if the guess
// was above or below the solution
{
	currentGame.above = 0;
	currentGame.below = 0;
	currentGame.small = 1;
	//cout << "PLAY small: " << currentGame.small << endl;
	//cout << "PLAY large: " << currentGame.large << endl;

	if (currentGame.currentGuess > currentGame.solution)
	{
		cout << "\nYour guess was too high, try again.";
		cout << "\n-----------------------\n";
		currentGame.above = true;
		return false;
	}
	//add the other conditions
	else if (currentGame.currentGuess < currentGame.solution)
	{
		cout << "\nYour guess was too low, try again.";
		cout << "\n-----------------------\n";
		currentGame.below = true;
		return false;
	}
	else
	{
		return true;
	}
}

void GenerateSolution(numberGuess& currentGame)
//Description:  Generates the solution number in the correct range
{

	srand((unsigned)time(0));
	currentGame.solution = 1 + rand() % currentGame.upperValue;
	//cout << "\nSolution is " << currentGame.solution << endl;
}

