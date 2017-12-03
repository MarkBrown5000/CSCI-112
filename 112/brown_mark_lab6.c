/*
 *
 *
 *
 */

//Libraries to include
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

//Function Prototypes
void get_input(char *);
void reverse(char *);

//Variable Definitions
#define SIZE 80

//Main Function
int
main(int argc, char *argv[]){
    if (argc != 2){
        printf("ERROR: Please provide an integer greater than or equal to 0\n");

        return 0;
    } 

    int N = (int) strtol(argv[1], NULL, 10);

    if (N <= 0){
        printf("ERROR: Please provide an integer greater than or equal to 0\n");

        return 0;
    } 

   // printf("N = %d\n", N);
    
    char input[SIZE];
    int i;
    for (i = 0; i < N; i++){
        get_input(input);
        reverse(input);
    }
   
    //for(i = 0; i < argc; ++i){
    //    printf("argv[%d] = %s\n", i, argv[i]);
   // }
    return 0;
}
/*
 *Gets input from the user
 *Deletes the return character from the input
 */
void get_input(char * input){
    fgets(input, SIZE, stdin);
    char * end = strchr(input, '\n');
    if (end){
        *end = '\0';
    }
}

/*
 * Function that reverses the sentencs passed in the command line
 * Takes the sentence as a String input
 * Does not return anything
 */
void reverse(char line[]){
    char temp[SIZE];
    char word[SIZE];
    memset(temp, 0, SIZE);
    int idx = strlen(line);
    int word_len = 0;
    //go through the input one letter at a time, and copy a word any time you get to a space
    for (idx = strlen(line); idx >= 0; idx--){
        memset(word, 0, SIZE);
        if (line[idx] == ' ' && word_len > 0){
            strncpy(word, line + idx + 1, word_len);
            strcat(temp, strcat(word, " "));
            word_len = 0;
        }else if (isalnum( line[idx] ) || line[idx] == '\'' ){
            word_len++;               
        }
    }
    //Copy the last word if there is one
    if (word_len > 0){
        strncpy(word, line, word_len);
        strcat(temp, word);
    }
    strcpy(line, temp);//copy temp back into word
   // printf("%s\n", word);
    printf("%s\n", line);
}
