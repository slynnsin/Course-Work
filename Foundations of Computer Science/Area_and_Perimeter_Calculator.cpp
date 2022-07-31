
/***********************************************************
Sarah Sindeband
Date: 9/29/21
Course:  C0P3014
Description: This program will calculate the area and perimeter of a triangle or rectangle based on user input
*************************************************************/
#include <iostream> //standard library for i/o
#include <string> // always use this for the string class
#include <cmath> //for sqrt

using namespace std;

//function prototypes
void MenuChoices(string& choice);
// precondition: string variable was declared before the function was called
// postcondition: menu choice was entered by user
// description: gets menu choice by reference from user 
void ProcessChoice(string& choice, double& area, double& perimeter, double& side1, double& side2, double& side3, double& S_p);
// precondition: all variables were delcared before the funciton was called
// postcondition: if the information was valid, the information gets passed by reference to the calculation funciton
// description: gets shape dimension information from the user for the calculation
void TriangleCalculator(double& area, double& perimeter, double& side1, double& side2, double& side3, double& S_p);
// precondition: variables are passed by reference if the dimensions are valid for the calculations
// postcondition: the varaibles are assigned values based on the equations
// description: calculates the area and perimeter based on the dimensions that were passed by reference to the function
void RectangleCalculator(double& area, double& perimeter, double& side1, double& side2);
// precondition: variables are passed by reference for the calculation
// postcondition: variables are assigned values based on the equations
// description: calculates the area and perimeter based on the diensions that were passed by reference to the function


//the driver to test funcitons

int main()
{
	//declare variables
	string choice;
	double area = 0, perimeter = 0, side1, side2, side3;
	double S_p = 0.0;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(3); //display the area to 3 decimal places

	// greet user
	cout << "\nWelcome to the area and perimeter calculator";

	do
	{
		// menu
		MenuChoices(choice);
		if (choice == "Q" || choice == "q")	// input tp quit program
		{
			cout << "\nGoodbye, Have a great day!\n";
			return 0;
		}
		else if (choice == "T" || choice == "t" || choice == "R" || choice == "r")
		{
			//process selection
			ProcessChoice(choice, area, perimeter, side1, side2, side3, S_p);
		}
		else // invalid input
		{
			cout << "\nThat input is not recognized";
			area = 0.000;
			perimeter = 0.000;
		}
		cout.precision(3); //display the area and perimeter to 3 decimal places
		cout << "\n\nThe area is " << area;
		cout << "\n\nThe perimeter is " << perimeter << endl;
	} while (choice != "Q" && choice != "q");	// endloop
	return 0;
}


//function definitions
void MenuChoices(string& choice)
// description: gets menu choice by reference from user
{
	cout << "\n----------------------------------------------\n\n";
	cout << "Please enter a T, R, or Q. \n\n";
	cout << "To calculate: \n";
	cout << "The area and perimeter of a triangle, enter T\n";
	cout << "The area and perimeter of a rectangle, enter R\n";
	cout << "----------------------------------------------\n";
	cout << "Enter Q to quit: ";
	cin >> choice;
}
void ProcessChoice(string& choice, double& area, double& perimeter, double& side1, double& side2, double& side3, double& S_p)
// description: gets shape dimension information from for the calculation
{
	if ((choice == "T") || (choice == "t"))
	{
		cout << "\n*********************************************";
		cout << "\nEnter the length of side one: ";
		cin >> side1;
		cout << "Enter the length of side two: ";
		cin >> side2;
		cout << "Enter the length of side three: ";
		cin >> side3;
		if ((side1 + side2 > side3) && (side2 + side3 > side1) && (side1 + side3 > side2))
		{
			cout << "------------------------------------";
			cout << "\nSide A\t\tSide B\t\tSide C\n";
			cout.precision(1);
			cout << side1 << "\t\t" << side2 << "\t\t" << side3;
			TriangleCalculator(area, perimeter, side1, side2, side3, S_p);
		}
		else
		{
			cout << "\nNot a valid triangle";
			perimeter = 0.000;
			area = 0.00;
		}
	}
	else if ((choice == "R") || (choice == "r"))
	{
		cout << "\n*********************************************";
		cout << "\nEnter the length of side one: ";
		cin >> side1;
		cout << "\nEnter the length of side two: ";
		cin >> side2;
		cout << "------------------------------------";
		cout << "\nSide X\t\tSide Y\n";
		cout.precision(1);
		cout << side1 << "\t\t" << side2;
		RectangleCalculator(area, perimeter, side1, side2);
	}
}
void TriangleCalculator(double& area, double& perimeter, double& side1, double& side2, double& side3, double& S_p)
// description: calculates the area and perimeter based on the diensions that were passed by reference to the function
{
	if ((side1 + side2 > side3) && (side2 + side3 > side1) && (side1 + side3 > side2))
	{
		//calculate perimeter and area
		perimeter = (side1 + side2 + side3);
		S_p = (perimeter / 2);
		area = sqrt((S_p) * (S_p - side1) * (S_p - side2) * (S_p - side3));
	}
	else
	{
		cout << "\n\n";
		perimeter = 0.000;
		area = 0.00;
	}
}
void RectangleCalculator(double& area, double& perimeter, double& side1, double& side2)
// description: calculates the area and perimeter based on the diensions that were passed by reference to the function
{
	perimeter = (2 * side1) + (2 * side2);
	area = side1 * side2;
}