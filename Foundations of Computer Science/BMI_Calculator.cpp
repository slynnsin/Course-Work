// Sarah Sindeband
// COP 2220
// 7.3.21
// Description: BMI Calculator

// preprocessor directives
#define _CRT_SECURE_NO_WARNINGS					// suppress warnings
#include<stdio.h>						// printf, scanf

// function prototypes
void Welcome();
double BMICalc(double weight, double height);
void Output(double bmi);

// main function
int main()
{
	//declare variables
	double weight, height, BMI;

	Welcome();						// welcome message

	// prompt and enter height and weight
	printf("\nEnter weight in pounds: ");
	scanf("%lf", &weight);
	printf("Enter height in inches: ");
	scanf("%lf", &height);

	// calculate BMI
	BMI = BMICalc(weight, height);

	// print results
	Output(BMI);

	return 0;						// Done!
}

// function definitions
void Welcome(void)
{
	printf("\nWelcome to the BMI Calculator.");
	printf("\nThis program calculates your BMI from your weight and height.\n");
}
double BMICalc(double weight, double height)
{
	double BMI;
	BMI = 703.07 * (weight / (height * height));
	return BMI;
}
void Output(double BMI)
{
	if (BMI <= 18.5)
		printf("\nYour BMI of %.2f indicates you are underweight.", BMI);
	else if (BMI <= 25)
		printf("\nYour BMI of %.2f indicates you are a normal weight.", BMI);
	else if (BMI <= 30)
		printf("\nYour BMI of %.2f indicates you are overweight.", BMI);
	else
		printf("\nYour BMI of %.2f indicates you are obese.", BMI);
	printf("\n\n");
}