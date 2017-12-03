/*
 * Mark Brown
 * CSCI 112 - Lab7
 * 4/6/2016
 */

//Libraries to include
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Variable Definitions
#define MAX_ELEMENTS 20
#define MAX_SIZE 40

//New struct creation called element_t
typedef struct {
    int atomic_number;
    char name[MAX_SIZE];
    char chemical_symbol[MAX_ELEMENTS];
    char class[MAX_SIZE];
    double atomic_weight;
    int electrons[7];
} element_t;

//Creation of an array of element_t structs.  Size is set to MAX_ELEMENTS
element_t elements[MAX_ELEMENTS];

//Function Prototypes
void scan_element(element_t *);
void print_element(element_t);

/*
 * Main Functiion
 * Takes one input from the command line
 * Calls the scan_element and print_element functions
 */
int main(int argc, char * argv[]){
    if (argc != 2){
        printf("ERROR: You must provide exactly one argument to this program.\n");

        return 0;
    } 

    int N = (int) strtol(argv[1], NULL, 10);

    if (N <= 0 || N > MAX_ELEMENTS){
        printf("ERROR: You must provide an integer greater than 0 and less than or equal to %d.\n", MAX_ELEMENTS);

        return 0;
    } 
    int num_elements;
    element_t max;// Stores the element with the highest atomic number
    element_t min;// Sotres the element with the lowest atomic number
    max.atomic_number = 0;
    min.atomic_number = 200;
    int i;
    for(i = 0; i < N; i++){//Scan in the number of elements chosen by user
        scan_element(&elements[i]);
        num_elements++;    
    }
    //Scan through struct array and find max and min atomic number
    for(i = 0; i < N; i++){
        if (elements[i].atomic_number < min.atomic_number){
            //min.atomic_number = elements[i].atomic_number; 
            min = elements[i];      
        }
        if (elements[i].atomic_number > max.atomic_number){
            //max.atomic_number = elements[i].atomic_number;
            max = elements[i];
        }
    }
    printf("%d total elements.\n", num_elements);
    printf("%s had the smallest atomic number.\n", min.name);
    printf("%s had the largest atomic number.\n", max.name);
    int j;
    for(j = 0; j < N; j++){//Print out all elements input by user
        print_element(elements[j]);
    }
    return 0;
}
/*
 * Function to scan in elements input by the user.
 * Takes an element_t pointer as an input
 */
void scan_element( element_t * element){
    scanf("%d %s %s %s %lf %d %d %d %d %d %d %d",
        &element->atomic_number,
        element->name,
        element->chemical_symbol,
        element->class,
        &element->atomic_weight,
        &element->electrons[0],
        &element->electrons[1],
        &element->electrons[2],
        &element->electrons[3],
        &element->electrons[4],
        &element->electrons[5],
        &element->electrons[6]);
}

/*
 * Function to print out all elements input by user in the given format
 * Takes an element_t struct as an input
 */
void print_element(element_t element){
    printf("---------------\n");
    printf("| %d\t%.4f\n", element.atomic_number, element.atomic_weight);
    printf("| %s\t%s\n", element.chemical_symbol, element.name);
    printf("|");
    int i;
    for (i = 0; i < 7; i++){
        if (element.electrons[i] != 0){//Only prints out number of electrons if greater than 0.
            printf(" %d", element.electrons[i]);
        }
    }
    printf("\n");       
    printf("---------------\n");
}
