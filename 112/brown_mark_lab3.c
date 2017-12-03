/**
 * Mark Brown
 * CSCI 112 - Lab3
 * 2/17/2016
 */
#include<stdio.h>
#include<math.h>

#define PI 3.14159
#define LOOP_LIMIT 90

/*
 *Defines new enum menu_t
 */
typedef enum {
	Sine, Cosine, Tangent, QUIT
	} menu_t;

menu_t input;

menu_t  menu_choice;

//Defines function prototypes
void get_input(void);
void compute_sin(void);
void compute_cos(void);
void compute_tan(void);

/*
 *Main Function.  Runs a calls get_input and runs a switch statement for the 4 enums.  Runs until the user enters quit.
 */
int 
main(void){
	int done = 0;
	while (!done){
	get_input();
	switch (menu_choice) {
	case Sine:
		compute_sin();
		break;

	case Cosine:
		compute_cos();
		break;

	case Tangent:
		compute_tan();
		break;

	case QUIT:
        printf("You chose QUIT. Thank you, come again!\n");
        done = 1;
        break;
	}
	}
	
	return 0;
}

/*
 * Gets input from the user and checks to make sure that input is valid.
 */
void get_input()
{
	int flag = 0;
	do {
	printf("Please choose an option: (0) Sine (1) Cosine (2) Tangent (3) QUIT\n");
	printf("Enter your choice > ");
	scanf("%u", &menu_choice);
	if (menu_choice < Sine || menu_choice > QUIT)//If menu_choic < 0 || > 1
	{
		printf("%d is an invalid option. Please try again.\n", menu_choice);//Invalid choice.
	}else{//Valid choice.
		flag = 1;
	}
	} while (!flag);
}

/*
 *Function to compute the sin() of degrees from 0 to LOOP_LIMIT
 */
void compute_sin()
{
	double i;//i is a double so that r can be accurately computed.
	for(i = 0.0; i <= LOOP_LIMIT; i += 15.0){
		double r = (PI)*(i/180.0);//converts degrees to radians
		printf("\tsin(%d) = %.4lf\n",(int)i, sin(r));
	}
}

/*
 *Function to compute the cos() of degrees from 0 to LOOP_LIMIT
 */
void compute_cos()
{

	double i;
	for(i = 0.0; i <= LOOP_LIMIT; i += 15.0){
		double r = (PI)*(i/180.0);
		printf("\tcos(%d) = %.4lf\n",(int)i, cos(r));
	}
}

/*
 *Function to compute the tan() of degrees from 0 to LOOP_LIMIT
 */
void compute_tan()
{

	double i;
	for(i = 0.0; i <= LOOP_LIMIT; i += 15.0){
		if (i == 90.0){
			printf("\ttan(%d) is UNDEFINED\n", (int)i);
		}else {
			double r = (PI)*(i/180.0);
			printf("\ttan(%d) = %.4lf\n",(int)i, tan(r));
		}
	}
}
