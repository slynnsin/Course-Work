/*************************************************************
Sarah Sindeband
Date: 12/3/21
Course:  C0P3014
//Header file for numberguess
*************************************************************/

#ifndef NUMBERGUESS_H
#define NUMBERGUESS_H

#include<iostream>
using namespace std;

class numberGuess
{
public:
	//constructor
	numberGuess();
	//explicit value constructor for the demo game
	numberGuess(int, int);

	//the mutator functions -  used by the NON member function SetUpLevel
	void SetUpperRange(int);				//sets the upper range for the round
	void SetNumGuesses(int);				//sets the number of guesses for the round
	void PlayOneRound(const string& name);	//plays one round of the game

private:
	//three member functions are now private
	//since PlayOneRound is now member function
	void GuessInput(); //gets the next guess from the user
	bool ProcessGuess(); //determines if the guess is right or wrong
	void GenerateSolution(); //generates the solution

	int small;//lowest value for feedback
	int large;//highest value for feedback
	bool above;//current guess above the solution
	bool below;//current guess below the solution

	int upperValue;//15, 50, or 150
	int numGuesses;//4, 6, or 8
	int currentGuess;//current guess input by the user
	int solution;//pseudo random generated number
};

#endif NUMBERGUESS_H#pragma once

