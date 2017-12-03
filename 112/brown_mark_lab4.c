/*
 *Mark Brown
 *CSCI 112 - Lab4
 *2/24/2016
 */

#include<stdio.h>
#include<math.h>

//Function Prototypes
int user_menu();

//Equation functions that are pass by reference
void equation1(float *);
void equation2(float *);
void equation3(float *);
void equation4(float *);

//User input functions return a value from user
float get_position_initial(void);
float get_position_final(void);
float get_velocity_initial(void);
float get_velocity_final(void);
float get_acceleration(void);
float get_time(void);

int
main(void){
    //Print welcome message
    printf("Welcome to the MOTION EQUATION CALCULATOR\n\n");

    //Variable for the user choice menu.
    int user_choice;

    do {
        user_choice = user_menu();  //print menu, validate choice is between 1 and 5

        //You will pass the address of this variable to our equation functions.
        float result;       //Variable to hold calculated result

        //Handle menu choic selected by user
        switch(user_choice){
            case 1:
                equation1(&result);  //Calculate equation 1
                     
                break;

            case 2:
                equation2(&result);  //Calculate equation 2
                break;

            case 3:
                equation3(&result);  // Calculate equation 3
                break;

            case 4:
                equation4(&result);  //Calculate equation 4
                break;

            case 5:
                //exit program
                printf("Thank you for using the MOTION EQUATION CALCULATOR. Goodbye.\n");
                return 0;
                break;   
            }
            //Print out the calculated result with 4 digits after the decimal place
            printf("Your result is %.4f.\n\n", result);
        } while (user_choice != 5);

        return 0;
}
/*
 *Obtains input from the user, and checks to make sure it is valid
 * int input stores the user input
 * returns the users input
 */
int user_menu(){
    int input;
    do{
    printf("Choose a motion equation 1-4 or choose 5 to QUIT > ");
    scanf("%d", &input);
    if (input < 1 || input > 5){
        printf("Invalid Option. Please try again.\n\n");
    }
    } while (input < 1 || input > 5);

    return input;
}

/*
 *Function that calculates equation 1 and updates result through the use of a pointer
 */
void equation1(float * finalVelocity){
    float v0 = get_velocity_initial();
    float a = get_acceleration();
    float t = get_time();
    *finalVelocity = v0 + (a * t); //Sets result equal to the equation through pointers   
}
/*
 *Function that calculates equation 2 and updates result through the use of a pointer
 */
void equation2(float * finalPosition){
    float x0 = get_position_initial();
    float v0 = get_velocity_initial();
    float t = get_time();
    float a = get_acceleration();
    *finalPosition = x0 + v0 * t + .5 * a * pow(t, 2);  //Sets result equal to the eqaution through pointers
}
/*
 *Function that calculates equation 3 and updates result through the use of a pointer
 */
void equation3(float * finalVelocity){
    float v0 = get_velocity_initial();
    float a = get_acceleration();
    float xf = get_position_final();
    float x0 = get_position_initial();
    *finalVelocity = sqrt(pow(v0, 2) + 2 * a * (xf - x0)); //Sets result equal to the equation through pointers
}
/*
 *Function that calculates equation 4 and updates result through the use of a pointer
 */
void equation4(float * finalPosition){
    float x0 = get_position_initial();
    float vf = get_velocity_final();
    float v0 = get_velocity_initial();
    float t = get_time();
    *finalPosition = x0 + .5 * (vf + v0) * t; //Sets result equal to the equation through pointer
}
/*
 *Request the initial position from the user and return it.
 */
float get_position_initial(void){
    float initial_position;
    printf("\tEnter initial position > ");
    scanf("%f", &initial_position);
    return initial_position;
}
/*
 *Request the final position from the user and return it.
 */
float get_position_final(void){
    float final_position;
    printf("\tEnter final position > ");
    scanf("%f", &final_position);
    return final_position;
}
/*
 *Request the initial velocity from the user and return it.
 */
float get_velocity_initial(void){
    float initial_velocity;
    printf("\tEnter initial velocity > ");
    scanf("%f", &initial_velocity);
    return initial_velocity;
}
/*
 *Request the final velocity from the user and return it.
 */
float get_velocity_final(void){
    float final_velocity;
    printf("\tEnter final velocity > ");
    scanf("%f", &final_velocity);
    return final_velocity;
}
/*
 *Request the acceleration from the user and return it.
 */
float get_acceleration(void){
    float acceleration;
    printf("\tEnter acceleration > ");
    scanf("%f", &acceleration);
    return acceleration;
}
/*
 *Request the time from the user and return it.
 */
float get_time(void){
    float time;
    printf("\tEnter time > ");
    scanf("%f", &time);
    return time;
}
