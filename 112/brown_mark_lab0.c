/*
 * Mark Brown
 * Lab 0, CSCI 112
 * 1/20/2016
 */
 #include <stdio.h>

 int
 main(void)
 {
    /* declare required variables */
    double celsius = 0, fahrenheit = 0;

    /* get the temperature in Celsius */
    printf("Enter a temperature in degrees Celsius: ");
    scanf("%lf", &celsius);

    /* convert to Fahrenheit */
    fahrenheit = (9.0/5.0) * celsius + 32.0;


    /* print out the temp in Fahrenheit */
    printf("That is %.2f Fahrenheit \n", fahrenheit);

    /* get the temperature in Fahrenheit */
    printf("Enter a temperature in degrees Fahrenheit: ");
    scanf("%lf", &fahrenheit);

    /* convert to celsius */
    celsius = (fahrenheit - 32) * (5.0/9.0);


    /* print out the temp in Celsius */
    printf("That is %.2f Celsius \n", celsius);

    /* exit with no errors */
    return(0);
 }
