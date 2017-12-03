/**Mark Brown
 * CSCI 112 - Lab2
 * 2/2/2016
 */
#include <stdio.h>
#include <math.h>
#include <float.h>

/* Declare the function prototypes for all functions in this file. */
double get_input();
int get_N(); 
/**
 * Main function, entry point to program.
 */
int
main(void)
{
	int N = get_N();//Use the get_N function to set a value for N.
	double lowest = DBL_MAX, highest = DBL_MIN, sum, sum_squares,range, average, std_dev, current;//Set required variable for calculations
	int i;
	for (i = 0; i < N; i++){//For loop that prompts users for values.
	 	current = get_input();
		if (current < lowest){
			lowest = current;
		}		
		if (current > highest){
			highest = current;
		}
	sum = sum + current;//Adds up all inputs
	sum_squares = sum_squares + pow(current, 2);//Adds up all inputs squared		
	}
	if (N == 0){//Sets all values in the case that N = 0.
	highest = 0;
	lowest = 0;
	average = 0;
	std_dev = 0;
	}
	else {
	average = sum/N;//Sets the average
	std_dev = sqrt((sum_squares/N) - pow(average, 2));//Sets the standard deviation
	}
	range = highest - lowest;//Sets the range
	printf("The Highest is: %.3f\n", highest);//Print statement to print out calculated values
	printf("The Lowest is: %.3f\n", lowest);
	printf("The Average is: %.3f\n", average);
	printf("The Range is: %.3f\n", range);
	printf("The Standard deviation is: %.3f\n", std_dev);
	return(0);
}

//Retrieve input from user of the program
double get_input(void)
    {
	double x;
        printf("Enter a number:  ");
	scanf("%lf", &x);

	return(x);
    }
//Prompts user for a correct value of N.
int get_N(){

	int N = -1;
	do {
	printf("Enter a value for N that is >= 0: ");
	scanf("%d", &N);
	if (N < 0){
		printf("Invalid value for N.\n");
	}
	} while (N < 0);
	return(N);
}
