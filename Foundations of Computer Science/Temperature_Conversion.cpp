// Sarah Sindeband
// COP 2220
// 6/21/2021
// Description: This program converts temperature in Celsius to Fahrenheit.

// preprocessor directives
#define _CRT_SECURE_NO_WARNINGS		// suppress warnings
#include <stdio.h>					// library for printf and scanf

// function prototypes
void welcome();
double convert(double original_temp);

// main function
int main()
{
	double cent, far;		// declare variables
	welcome();			// welcome message
	printf("\nPlease enter a temperature in Centigrade: ");
	scanf("%lf", &cent);
	far = convert(cent);
	printf("\nThe temperature in Fahrenheit is: %.2f", far);
	return 0;
}

// function definitions
void welcome(void)
{
	printf("Welcome, this program converts temperature from Centigrade to Fahrenheit. "); // welcome message
}
double convert(double original_temp)  // real number
{
	double new_temp;
	new_temp = ((9 * original_temp) / 5) + 32;
	return new_temp;
}