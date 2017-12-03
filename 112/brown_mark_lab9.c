/*
 * Mark Brown
 * CSCI 112 - Lab9
 * 4/18/2016
 */

//Libraries to include
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Variable Definitions
#define MAX_ELEMENTS 20
#define MAX_SIZE 40
#define ELEMENT_FILENAME "element_dv.csv"

//New struct creation called element_t
typedef struct {
    int atomic_number;
    char chemical_symbol[MAX_ELEMENTS];
    char name[MAX_SIZE];
    float atomic_weight;
    char rt_state[MAX_SIZE];
    char bonding_type[MAX_SIZE];
    char discovered[MAX_SIZE];
} element_t;

//Creation of an array of element_t structs.  Size is set to MAX_ELEMENTS
element_t elements[MAX_ELEMENTS];

//Function Prototypes
void scan_element(element_t *);
void print_element(element_t);
element_t * find_element(element_t * list, char * symbol);

/*
 * Main Function
 * Returns an int and takes in command line arguments in the form of chemical symbol
 * Reads from a text file.  Makes calls to find element and print_element
 */
int main(int argc, char * argv[]){
    if (argc < 2){//Check to verify that there is at least 1 command line argument input by the user
        printf("ERROR: Please provide at least one program argument.\n");
    
        return 0;
    } 

    int N = (int) strtol(argv[1], NULL, 10);
    element_t * elements = (element_t *)calloc( 118, sizeof(element_t) );

    FILE * element_file = fopen(ELEMENT_FILENAME, "r");
    if (element_file != NULL){
        char line[100];
        while(fgets(line, 100, element_file) != NULL){
            //printf("line = %s\n", line);
            char * nl = strchr(line, '\n');
            if (nl){
                *nl = '\0';
            }
            element_t e;
            char * str = strtok( line, "," );
            int col = 0;
            while ( str != NULL){
                switch( col ){//Switch statement to transfer info from text file to structure
                    case 0:
                        e.atomic_number = atoi( str );
                        break;
                    case 1:
                        strcpy( e.chemical_symbol, str );           
                        break;
                    case 2:
                        strcpy( e.name, str );
                        break;
                    case 3:
                        e.atomic_weight = atof( str );
                        break;
                    case 4:
                        strcpy( e.rt_state, str);
                        break;
                    case 5:
                        strcpy( e.bonding_type, str);
                        break;
                    case 6:
                        strcpy( e.discovered, str);       
                        break;
                }
                //printf ("word = %s", str);
                //printf("\n");
                str = strtok( NULL, "," );
                col++;
            }
            //printf("e.atomic_number = %d\n", e.atomic_number);
            elements[e.atomic_number - 1] = e;
        }    
        fclose(element_file);
    }
    //process program arguments
    FILE * output_f = NULL;
    int i;
    for(i = 1; i < argc; i++){
        if(i == 1){// check for filename
            char * dot = strchr( argv[i], '.');
            if(dot){
                output_f = fopen(argv[i], "w");
                continue;   
            }
        }    
        // Look up this element
        element_t * ele = find_element( elements, argv[i]);
    }
    int j;
    for(j = 0; j < N; j++){
        print_element(elements[j]);
    }
    return 0;
}
/*
 * Function to look up an element in the table
 * Returns a pointer to a structure
 *  takes in a pointer to a structure, and the chemeical symbol to look up
 */
element_t * find_element( element_t * list, char * symbol){
    int i;
    for(i = 0; i < 118; i++){
        if(strcmp( list[i].chemical_symbol, symbol) == 0){
            element_t * result = &list[i];
            return result;
        }
    }
    return NULL;
}
/*
 * Function to print out all elements input by user in the given format
 * Takes an element_t struct as an input
 */
void print_element(element_t element){
    printf("---------------\n");
    printf("| %d\t%.4f\n", element.atomic_number, element.atomic_weight);
    printf("| %s\t%s\n", element.chemical_symbol, element.name);
    printf("| %s\n", element.rt_state);
    printf("| %s\n", element.bonding_type);
    printf("| Found: %s\n", element.discovered);       
    printf("---------------\n");
}
