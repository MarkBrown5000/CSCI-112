/**
 * Mark Brown
 * CSCI 112 - Lab1
 * 1/26/2016
 */
#include <stdio.h>

/* Declare the function prototypes for all functions in this file. */
int get_input(void);
void print_result(double);
double get_next(double, double);

/**
 * Main function, entry point to program.
 */
int
main(void)
{
	int x1, x2;
	double  x3, x4, x5;
	x1 = get_input();
	x2 = get_input();
	x3 = get_next(x1,x2);
	x4 = get_next(x2,x3);
	x5 = get_next(x3,x4);
	print_result(x5);

	return(0);
}

//Retrieve input from user of the program
  int  get_input(void)
    {
	int x1;
        printf("Please enter a number > ");
	scanf("%d", &x1);

	return(x1);
    }
//Get the next number in the equation
double get_next(double x1, double x2)
{
	double xn;
	xn = (x1/2) + (3 * x2);

	return(xn);
}
//print the final result of the equation
void print_result(double x)
{
	printf("The result is %.2lf\n", x);
}
