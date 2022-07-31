/*************************************************************
Sarah Sindeband
Date:  10/27/21
Course:  C0P3014
Description: Number guessing game with a random number generator, static array to store game results.
*************************************************************/

#include <iostream> //standard library for i/o
#include <string> // always include for the string class
#include <ctime> //random number generator
#include <fstream>//output file
using namespace std;

const int NUM_GAMES = 40;
//maximum number of games for the array declaration

/*********************************************************
//Following is the declaration of a round of numberGuess
**********************************************************/
class numberGuess
{
public:
	int level = 0;				//game level 1,2, or 3
	int upperValue = 0;			//15, 50, or 150
	int numGuesses = 0;			//4, 6, or 8
	int currentGuess = 0;		//current guess input by the user
	int solution = 0;			//pseudo random generated number
	int small = 1;				//lowest value for feedback
	int large = 0;				//highest value for feedback
	bool above = false;			//current guess above the solution
	bool below = false;			//current guess below the solution
	string name;				//name of current player
	bool wonOrLost = 0;			//true or false for the current round of the game
};


//Declaration / Prototypes 

void SetUpperRange(numberGuess& currentGame);
//Description:  Sets the upper value and large of the current game based on the level chosen by the user

void SetNumGuesses(numberGuess& currentGame);
//Description: sets the number of guesses for the current round based on the level

void PlayOneRound(numberGuess& currentGame);
//Description: Play one round of the number guess game

void GuessInput(numberGuess& currentGame);
//Description: Displays the range, prompts, and gets the next guess from the user

bool ProcessGuess(numberGuess& currentGame);
//Description: Returns true if the guess matches the solution, or false and lets the user know if the guess
//was above or below the solution

void GenerateSolution(numberGuess& currentGame);
//Description: Generates the solution number in the correct range

void PrintGameResults(numberGuess numGameList[], int gameCount);
//Description:  Connects to an output file, prints the array results onto the screen and into the output file


int main()
{
	//declare variables and the array
	string name;
	string response;

	// declare current game
	numberGuess numGameList[NUM_GAMES];
	int gameCount = 0;
	// greet user
	cout << "Do you want to play the guessing game? (y(Y) or n(N)): ";
	cin >> response; // initialization for loop
	//while begin loop
	while (response != "N" && response != "n") // user does not want to quit, test for loop
	{	
		// get user name
		cout << "Enter your first name: ";
		//into the member variable name
		cin >> numGameList[gameCount].name;

		//Play one round of the game
		PlayOneRound(numGameList[gameCount]);

		//add one to the gamecount
		gameCount++;

		//Play again?
		cout << "\n\nDo you want to play another round? (y(Y) or n(N)): ";
		cin >> response; // update for loop
	}
	//Print the game results
	PrintGameResults(numGameList, gameCount);

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

	currentGame.large = currentGame.upperValue;
}

void SetNumGuesses(numberGuess& currentGame)
//Description:  sets the maximum number of guesses for the current round based on the level
{
	if (currentGame.level == 1) currentGame.numGuesses = 4;
	else if (currentGame.level == 2) currentGame.numGuesses = 6;
	else if (currentGame.level == 3) currentGame.numGuesses = 8;
}

void PlayOneRound(numberGuess& currentGame)
//Description:  Play one round of the number guess game
{
	currentGame.wonOrLost = 0;
	currentGame.below = 0;
	currentGame.above = 0;

	do {
		cout << "************************************************\n";
		//display and get the levels
		cout << "what level (Enter 1, 2, or 3)?\n";
		cout << "(1) Level 1 - 4 guesses, numbers 1 through 15\n";
		cout << "(2) Level 2 - 6 guesses, numbers 1 through 50\n";
		cout << "(3) Level 3 - 8 guesses, numbers 1 through 150: \n";
		cin >> currentGame.level;
		//set the upper range based on the level 
		SetUpperRange(currentGame);

		//set the max guesses based on the level 
		SetNumGuesses(currentGame);

		//generate the random number solution
		GenerateSolution(currentGame);
	} while (currentGame.level > 3 || currentGame.level < 1);

	//initalize bool and high/low values
	currentGame.above = 0;
	currentGame.below = 0;
	currentGame.small = 1;
	currentGame.large = currentGame.upperValue;
	currentGame.wonOrLost = 0;

	//loop counting loop for the number of guesses
	for (int i = 0; i < currentGame.numGuesses; i++)
	{

		//tell the user what guess number they are on
		cout << "\n-----------------------";
		cout << "\nThis is guess number (" << i + 1 << ")";
		//get the next guess
		cout << "\nEnter a guess between " << currentGame.small << " and " << currentGame.large << " : ";
		cin >> currentGame.currentGuess;
		//reset above and below bool values to false
		currentGame.below = 0;
		currentGame.above = 0;

		if (ProcessGuess(currentGame) == true)
		{
			cout << "\nYou won that round, " << currentGame.name << "!\n";
			i = currentGame.numGuesses;
			currentGame.wonOrLost = true;
		}
	}
	if (!currentGame.wonOrLost)//lost the round
	{
		cout << "\nYou did not win that round, " << currentGame.name << "!\n";
	}
	
	cout << "\nTHE SOLUTION WAS " << currentGame.solution << endl;
	cout << "--------------------------------------------------";

}

void GuessInput(numberGuess& currentGame)
//Description:  Displays the range, prompts, and gets the next guess from the user
{

	if (currentGame.below)
	{
		if (currentGame.small < currentGame.currentGuess)
		{
			currentGame.small = currentGame.currentGuess;
		}
	}
	if (currentGame.above)
		if (currentGame.large < currentGame.currentGuess)
		{
			currentGame.large = currentGame.currentGuess;
		}
		else
			cout << "\nEnter a guess between " << currentGame.small << " and " << currentGame.large << " : ";
	//get the guess
	cin >> currentGame.currentGuess;
}

bool ProcessGuess(numberGuess& currentGame)
//Description: Returns true if the guess matches the solution, or false and lets the user know if the guess
//was above or below the solution
{
	if (currentGame.currentGuess > currentGame.solution)
	{
		cout << "\nYour guess was too high.";
		cout << "\n-----------------------";
		currentGame.above = true;
		currentGame.large = currentGame.currentGuess;
		return false;
	}
	else if (currentGame.currentGuess < currentGame.solution)
	{
		cout << "\nYour guess was too low.";
		cout << "\n-----------------------";
		currentGame.below = true;
		currentGame.small = currentGame.currentGuess;
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
}

void PrintGameResults(numberGuess numGameList[], int gameCount)
// declare and connect to file inside print game results function
{
	ofstream out;
	//open the output file
	out.open("numberGuessResults.txt");

	//loop to print the array (name, level, WonOrLost) onto the screen
	cout << "\n***********************************\n";
	cout << "Name\t" << "Level\t" << "won or lost\n";
	cout << "\n***********************************";
	for (int i = 0; i < gameCount; i++)
	{
		cout << "\n" << numGameList[i].name << "\t" << numGameList[i].level << "\t" << numGameList[i].wonOrLost;
	}

	//loop to print the array (name, level, WonOrLost) into the file
	out << "\n***********************************\n";
	out << "Name\t" << "Level\t" << "won or lost";
	out << "\n***********************************";
	for (int i = 0; i < gameCount; i++)
	{
		out << "\n" << numGameList[i].name << "\t" << numGameList[i].level << "\t" << numGameList[i].wonOrLost;
	}

	//close the file
	out.close();
}