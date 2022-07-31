/************************************************************
Sarah Sindeband
Date: 11/3/21
Course:  C0P3014
Description: Interactive hangman game with words from the inputWords file.
*************************************************************/

#include <iostream> //standard library for i/o
#include <string> // always include this when you use the string class
#include <fstream> //file input/ output
#include <cstdlib> //for exit()

using namespace std;

const int numGuesses = 6;//six guesses (head, body, arm1, arm2, leg1, leg2)

/*********************************************************
//Following is the declaration of a round of the hangman game
**********************************************************/
class hangmanGame
{
public:
	string solution;							//solution word from file, all lowercase
	string userGuess;							//if the user guesses a correct letter, they can guess the word, compare to solution
	char hintWord[20] = "";						//hint word made of * same length as solution word from file, have to add null char at end
	char lettersGuessed[20] = "";				//letters guessed so far (right or wrong)
	int letterCount = 0;						//number of letters guessed so far (right or wrong), keeps track of lettersGuessed array
	int incorrectCount = 0;						//number of incorrect letters guessed so far, gets to 6, lose game
	char currentLetter = ' ';					//current letter guess
	int wordLength = 0;							//length of the solution word
	bool correctLetter = false;					//flag to set if the letter is in the word
	bool win = false;							//flag to set if all the user won that round
};


//Declaration / Prototypes

void HangmanRules(const string&);
//Description:  Provides instructions to the user on how to play the game

void SetUpOneRound(hangmanGame&, ifstream&);
//Description:  Get the word from the file and reset all member variables

void CreateHintWord(hangmanGame&);
//Description:  Creates the array of *

void PlayHangman(const string&, hangmanGame&);
//Description:  Play one round of the hangman game

void GetLetterGuess(hangmanGame&);
//Description:  Displays hint array and letters guessed, asks and gets a current letter guess from, added letter and null character to array

bool InterpretLetterGuess(hangmanGame&);
//Description:  Check if the letter guessed is in the solution and if it is, replace all * with that letter in the hintWord and return true, 
//otherwise return false

void CorrectGuess(hangmanGame&, string name);
//Description:  Checks for the final correct letter and if it is not the final correct letter,
//ask and get a word guess from the user if the user wants to guess the word 

bool GameOver(const hangmanGame&);
//Description:  This function will return true if the hintWord matches the solution, you can use ==  
//or if the userGuess matches the solution, you can use ==

void WonOrLostDisplay(const hangmanGame&, string name);
//Description:  Lets the user know if they won or lost the round

void DrawHangman(hangmanGame&);
//Description:  Draw or describe the hangman drawing


int main()
{
	//declare variables
	string name;
	string yesOrno;
	// ifstream object variable
	ifstream in;													// declaring object of type ifstream named in
	// object of type hangmanGame (name of class)					// activeGame = name of object
	hangmanGame activeGame;
	//connect to the input file 
	in.open("inputWords.txt");										// open is member function of ifstream 
	//if file did not open correctly
	if (in.fail())													// fail is member function of ifstream
	{
		cout << "Input file did not open correctly" << endl;
		exit(1);													// exit is member function of cstdlib
	}

	//ask and get the users name
	cout << "Enter your first name: ";
	cin >> name;

	// call Hangman rules function
	HangmanRules(name);

	// ask and get yes or no if the user wants to play
	cout << "Do you want to play the hangman game? (y or n): ";
	cin >> yesOrno;

	//loop to continue to play round (first or another)
	while (yesOrno == "'Y" || yesOrno == "y")
	{
		//set up the hangman round
		SetUpOneRound(activeGame, in);
		//play one round of hangman
		PlayHangman(name, activeGame);
		//again?- update
		cout << "Do you want to play another round? (y or n): ";
		cin >> yesOrno;
	}

	return  0;
}

//Function Implementations

void HangmanRules(const string& name)
//Description:  provides instructions to the user on how to play the game
{
	cout << endl << "\t\t" << name << ", WELCOME TO HANGMAN!\n\n\n";
	cout << "\tPlease read the following instructions before you play.\n\n";
	cout << "\t-You will be presented with a word to be guessed\n";
	cout << "\t-Guess letters one at a time\n";
	cout << "\t-Only lowercase letters are valid guesses, anything else will be marked as incorrect\n";
	cout << "\t-You can have up to six incorrect letter guesses\n";
	cout << "\t-You can only guess the word when you have made a correct letter guess\n";
	cout << "\t-The game will be OVER when you have guessed the word correctly\n";
	cout << "\t\tOr when you have guessed letters incorrectly SIX times.\n\n";
	cout << "\tHAVE FUN!\n\n";
}

void SetUpOneRound(hangmanGame& activeGame, ifstream& in)
//Description:  Get the word from the file and reset all member variables
{
	// reset all member variables in that round
	activeGame.solution = "";//clear the solution word

	//clear userGuess string
	activeGame.userGuess = "";
	activeGame.hintWord[0] = '\0'; //clear the star array by putting null char in first element of array 
	
								   //clear the lettersGuessed array
	activeGame.lettersGuessed[0] = '\0';
	activeGame.letterCount = 0; //letter count starts back at 0
	
	//reset the incorrectCount
	activeGame.incorrectCount = 0;
	activeGame.correctLetter = false; //reset correctLetter to false

	//reset win to false
	activeGame.win = false;

	//get a word form the file
	in >> activeGame.solution;

	//create the hint word
	CreateHintWord(activeGame);
}

void CreateHintWord(hangmanGame& activeGame)
//Description:  creates the array of *
{
	//get the length of the word 
	activeGame.wordLength = activeGame.solution.length();

	//use a loop to create the array of *
	int i;
	for (i = 0; i < activeGame.wordLength; i++)
	{
		activeGame.hintWord[i] = '*';
	}

	//add the null ('\0') character 
	activeGame.hintWord[activeGame.wordLength] = '\0';
}

void PlayHangman(const string& name, hangmanGame& activeGame)
//Description:  Play one round of the hangman game
{
	//let the user know how many letters are in the word
	cout << "\nWord has " << activeGame.wordLength << " letters\n";	
	//LOOP FOR THE ROUND OF THE GAME
	//the number of incorrect guesses is less than numGuesses
	//and win is false- have not won yet
	while (activeGame.incorrectCount < numGuesses && activeGame.win == false)
	{
		GetLetterGuess(activeGame);
		// update letter array - letter to the array of guessed letters
		if (InterpretLetterGuess(activeGame))
		{
			//the user guessed a correct letter
			cout << "\nThe letter was in the word!\n";

			//the user can now guess the word (if they want)
			CorrectGuess(activeGame, name);
		}
		else
		{
			//the user did not guess a correct letter
			cout << "\n" << name << ", your letter was not in the word\n";
			cout << "You have added a body part!\n";

			// add to incorrect count
			activeGame.incorrectCount++;
		}
		// Draw(tell the user how many incorrect guesses so far)
		DrawHangman(activeGame);
	}

	//WonOrLostDisplay - lets the user know if they won or lost
	WonOrLostDisplay(activeGame, name);
	cout << "\n\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << endl;

}

void GetLetterGuess(hangmanGame& activeGame)
//Description:  Displays hint array and letters guessed asks and gets a current letter guess from 
//the user and adds it to the letters guessed array
{
	//display the hint array
	cout << "\n-----------------------------------------";
	cout << "\nHere is the word so far\n" << endl;
	cout << "\t" << activeGame.hintWord << endl;
	cout << "-----------------------------------------\n";

	//display the letters that have been guessed so far
	cout << "Here are the letters guessed so far\n\n";
	cout << "\t" << activeGame.lettersGuessed << endl;

	//ask and get a letter guess from the user
	cout << "\nEnter a letter: ";
	cin >> activeGame.currentLetter;

	//Add the letter guessed to the letters array
	activeGame.lettersGuessed[activeGame.letterCount] = activeGame.currentLetter;
	
	//update the letterCount
	activeGame.letterCount++;		// to next element in the array
	
	//add the '\0' character
	activeGame.lettersGuessed[activeGame.letterCount] = '\0';
}

bool InterpretLetterGuess(hangmanGame& activeGame)
//Description:  Check if the letter guessed is in the solution and if it is, replace all * with that 
//letter in the hintWord and return true, otherwise return false
{
	bool rv = false;
	//use a loop to search the solution word
	int i;
	for (i = 0; i < activeGame.wordLength; i++)
	{
		//if the letter is found
		if (activeGame.currentLetter == activeGame.solution[i])
		{
			//replace the letters in the starword and 
			activeGame.hintWord[i] = activeGame.currentLetter;
			
			//set the rv to true
			rv = true;
		}
	}
	return rv;
}

void CorrectGuess(hangmanGame& activeGame, string name)
//Description:  checks for the final correct letter and if it is not the final correct letter
//ask and get a word guess from the user if the user wants to guess the word 
{
	char guess;

	//display the starword
	cout << "\n-----------------------------------------\n";
	cout << activeGame.hintWord << endl;
	if (GameOver(activeGame) == true) //the correct letter completed the hintword
	{
		activeGame.win = true;//they won the round by entering all the letters- they don't need to guess work because they replaced all the stars correctly
	}
	else //the user entered a correct letter but it was not the final correct letter
	{
		//ask and get a response (y or n) if they want to guess the word
		cout << "\nIT WILL NOT COUNT AGAINST YOU IF YOU DO NOT GET THE CORRECT WORD!\n\n";
		cout << name << ", would you like to guess the FULL word (y or n)? ";
		cin >> guess;
		if (guess == 'y')
		{
			//prompt for the word 
			cout << "\nWhat is the word: ";

			//get the word from the user
			cin >> activeGame.userGuess;

			//see if the game is over 
			if (GameOver(activeGame) == true) //the user word matches the solution
			{
				activeGame.win = true;//they won the round by entering all the letters- they don't need to guess work because they replaced all the stars correctly
			}
			else
				cout << "\nTHAT WAS NOT THE CORRECT WORD!\n";
		}
	}

}

bool GameOver(const hangmanGame& activeGame)
//Description:  This function will return true if the hintWord matches the solution, you can use ==  
//or if the userGuess matches the solution, you can use ==
{
	return activeGame.solution == activeGame.hintWord || activeGame.userGuess == activeGame.solution;
	//return false;
}

void WonOrLostDisplay(const hangmanGame& activeGame, string name)
//Description: Lets the user know if they won or lost the round
{
	cout << "\n-----------------------------------------";
	cout << "\n-----------------------------------------";
	if (activeGame.win)
	{
		//tell the user they won that round
		cout << endl << name << ", you have solved the word without being hung!\nYOU WIN!\n";
	}
	else
	{
		//tell the user they did not win that round
		cout << "GAME OVER\n";

		//display the solution word
		cout << "The word was " << activeGame.solution << endl << endl;
	}

}

void DrawHangman(hangmanGame& activeGame)
//Description:  Draw or describe the hangman drawing
{
	cout << "\n------------------------------------------------------";
	cout << "\nO-|--<  O-|--<  O-|--<  O-|--<  O-|--<  O-|--<  O-|--<";
	cout << "\n------------------------------------------------------";
	if (activeGame.incorrectCount == 0)
	{

		cout << "\nYou have no incorrect guesses yet! O-|--<";
	}
	else if (activeGame.incorrectCount == 1)
	{

		cout << "\nHEAD\t\tO\n - 1 of 6 incorrect guesses!\n";
	}
	else if (activeGame.incorrectCount == 2)
	{

		cout << "\nHEAD\t\tO\nBODY\t\t|\n - 2 of 6 incorrect guesses!\n";
	}
	else if (activeGame.incorrectCount == 3)
	{

		cout << "\nHEAD\t\tO\nBODY\t       /|\nARM 1\n - 3 of 6 incorrect guesses!\n";
	}
	else if (activeGame.incorrectCount == 4)
	{

		cout << "\nHEAD\t\tO\nBODY\t       /|\\\nARM 1\nARM 2\n - 4 of 6 incorrect guesses!\n";
	}
	else if (activeGame.incorrectCount == 5)
	{

		cout << "\nHEAD\t\tO\nBODY\t       /|\\\nARM 1\t       /\nARM 2\nLEG 1\n - 5 of 6 incorrect guesses!\n";
	}
	else if (activeGame.incorrectCount == 6)
	{

		cout << "\nHEAD\t\tO\nBODY\t       /|\\\nARM 1\t       / \\\nARM 2\nLEG 1\nLEG 2\n - 6 of 6 incorrect guesses!\n";
	}
	cout << "\n------------------------------------------------------";
	cout << "\nO-|--<  O-|--<  O-|--<  O-|--<  O-|--<  O-|--<  O-|--<";
	cout << "\n------------------------------------------------------";
}