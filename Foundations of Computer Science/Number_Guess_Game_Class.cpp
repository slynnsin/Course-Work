/*************************************************************
Sarah Sindeband
Date: 11/22/22
Course:  C0P3014
Description: Number guessing game with a random number generator, introduction to class member functions, private and public member variables,
mutator and accessor functions.
*************************************************************/

#include <iostream> //standard library for i/o
#include <string> // always include this when you use the string class
#include <ctime> //random number generator
using namespace std;

/*********************************************************
//Following is the declaration  numberGame
**********************************************************/

class numberGuess
{
public:
	//constructor automatically called when an instance numberGuess is declared
	numberGuess();
	//these functions are public so they can be accessed by non-member functions
	void SetUpperRange(int);					//sets the upper range for the round (mutator)
	int GetUpperRange()const;					//returns the value of the private member variable (accessor)
	void SetNumGuesses(int);					//sets the number of guesses for the round (mutator)
	int GetNumGuesses()const;					//returns the value of the private member variable (accessor)
	int GetSolution()const;						//returns the value of the private member variable (accessor)
	void GuessInput();							//gets the next guess from the user
	bool ProcessGuess();						//determines if the guess is right or wrong
	void GenerateSolution();					//generates the solution
	int small;									//lowest value for feedback
	int large;									//highest value for feedback
	bool above;									//current guess above the solution
	bool below;									//current guess below the solution
private:
	int upperValue;								//15, 50, or 150
	int numGuesses;								//4, 6, or 8
	int currentGuess;							//current guess input by the user
	int solution;								//pseudo random generated number
};


//numberGuess is delared
numberGuess::numberGuess()
{
	// initialize member variables
	upperValue = 0;
	small = 0;
	large = 0;
	above = 0;
	below = 0;
	upperValue = 0;
	numGuesses = 0;
	currentGuess = 0;
	solution = 0;
}

//Member function definitions

void numberGuess::SetUpperRange(int upper)
//mutator function
//Description:  sets the upper value of the current round
{
	upperValue = upper;
	large = upper;
}

int numberGuess::GetUpperRange()const
//accessor function
//Description:  returns the upper value(private member variable)
{
	return upperValue;
}

void numberGuess::SetNumGuesses(int num)
//Description:  Sets the number of guesses for the current round.
{
	//set
	numGuesses = num;
}

int numberGuess::GetNumGuesses()const
//accessor
//Description:  Returns the value of the private member variable
{
	return numGuesses;
}
int numberGuess::GetSolution()const 
//accessor
//Description:  Returns the value of the private member variable
{
	return solution;
}

void numberGuess::GuessInput() 
//Description:  Gets the next guess from the user
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
	//set currentGame.large
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

void numberGuess::GenerateSolution() //generates the solution
{
	srand((unsigned)time(0));
	solution = 1 + rand() % upperValue;
}



//Function prototypes
void PlayOneRound(const string&, numberGuess&);
//Description:  Play one round of a number guess game

void SetUpLevel(numberGuess&);
//Description:  passed current level by reference, asked the user which level, used mutator funcitons to set the number of guesses in the upper range

int main()
{
	string name;
	string yesOrNo;

	//declare an object variable of type numberGuess
	numberGuess activeGame;

	//get the name
	cout << "Enter your first name: ";
	cin >> name;

	//want to play ?
	cout << "Do you want to play a guessing game? (y(Y) or n(N)): ";
	cin >> yesOrNo; // initialization for loop

	while (yesOrNo != "n" && yesOrNo != "N")
	{
		//play a round
		PlayOneRound(name, activeGame);

		//another round ?
		cout << "\nDo you want to play another round? (y(Y) or n(N)): ";
		cin >> yesOrNo; // update for loop
	}

	return  0;
}


//Funciton definitons
void PlayOneRound(const string& name, numberGuess& currentGame)
//Description:  Play one round of the number guess game
{
	int i = 0;

	//initalize bool values (public member variables)
	currentGame.above = 0;
	currentGame.below = 0;

	//set the upper range based on the level (LevelRange function)
	SetUpLevel(currentGame);

	cout << "\nYou will have " << currentGame.GetNumGuesses() << " guess(es), Good Luck!" << endl;


	//initialize high and low values
	currentGame.small = 1;
	currentGame.large = currentGame.GetUpperRange(); //accessor function

	//generate the random number
	currentGame.GenerateSolution();

	//loop(number of guesses)
	for (int i = 0; i < currentGame.GetNumGuesses(); i++)
	{
		cout << "\n-----------------------";
		cout << "\nThis is guess number (" << i + 1 << " of " << currentGame.GetNumGuesses() << ")";
		//get next guess public member function
		currentGame.GuessInput();

		//reset above and below bool values to false
		currentGame.below = 0;
		currentGame.above = 0;

		if (currentGame.ProcessGuess())
		{
			cout << "\nYou won that round, " << name << "!\n";
			i = currentGame.GetNumGuesses();//(accessor function)
		}
	}
	//print the solution
	cout << "\nSOLUTION WAS " << currentGame.GetSolution() << endl;
}

void SetUpLevel(numberGuess& currentGame)
//Asks and gets the level and sets up one round of the game
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


