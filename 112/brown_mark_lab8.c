/*
 * Mark Brown
 * CSCI 112 - Lab8
 * 4/13/2016
 */

//Libraries to include
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Variable Definitions
#define MAX_STUDENTS 20
#define NAME_SIZE 40

//New struct creation called element_t
typedef struct {
    int sid;
    char last_name[NAME_SIZE];
    char first_name[NAME_SIZE];
    float *  grades;
    float  gpa;
} student_t;

//Creation of an array of element_t structs.  Size is set to MAX_ELEMENTS
//student_t students[MAX_STUDENTS];

//Function Prototypes
student_t get_info(int);
float calc_gpa(student_t, int);
void print_records(student_t *,int, int);
void free_memory(student_t *, int);
/*
 * The main function
 * Prompts usere for number of students and grades per student
 * Creates a new array of student_t objects
 * For loop gets all info for each student
 * calls print_records to print all records for each student
 * calls free memory to clear all memory
 */
int main (void){
    int num_students, grades;
    scanf("%d", &num_students);
    scanf("%d", &grades);
    printf("Number of students: %d\n", num_students);
    printf("Number of grades (each): %d\n", grades);
    
    student_t * students = (student_t *)calloc(num_students, sizeof(student_t));
    
    int i;
    for (i = 0; i < num_students; i++){
        //students[i] = get_info(grades);
        *(students + i) = get_info(grades);
    }
    print_records(students, num_students, grades);
    free_memory(students, num_students);
    return 0;
}
/*
 * Function that prompts user to insert all student info
 * Returns a student struct.
 * Takes the number of grades as an input
 */
student_t get_info(int num_grades){
    student_t student;
  /*  student_t * student;
    scanf("%d %s %s", 
        &student->sid,
        student->last_name,
       student->first_name);*/
    scanf("%d %s %s", //Gets student id, first name, last name
        &student.sid,
        student.last_name,
        student.first_name);
  
    student.grades = (float *)calloc(num_grades, sizeof(float));
    int i;
    for (i = 0; i < num_grades; i++){//For loop that gets all individual grades
        scanf("%f", &student.grades[i]);   
    }
    student.gpa = calc_gpa(student, num_grades);//calls calc_gpa to calculate the students gpa
    return  student;
}
/*
 * Function to calculate the gpa of a student based on the grades input
 * Returns the gpa stored in a float variable
 * takes a student and the number of grades as input
 */
float calc_gpa(student_t student, int grades){
    float gpa;
    int i;
    for (i = 0; i < grades; i++){
        gpa+=student.grades[i];
    }
    gpa = gpa/grades;
    
    return gpa;
}
/*
 * Function that prints out all of the student records
 * Returns nothing, takes a pointer to the beginning of the array of students
 * the total number of students and the total number of grades
 */
void print_records(student_t * students, int num_students, int grades){
    int i;
    for (i = 0; i < num_students; i++){
        printf("ID: %d, Name: %s %s, GPA: %.2f\nGrades:", students[i].sid, students[i].first_name, students[i].last_name, students[i].gpa);
        int j;
        for (j = 0; j < grades; j++){
            printf(" %.1f", students[i].grades[j]);
        }
    printf("\n");
    }
}
/*
 * Function that frees the memory allocated for the student records after the 
 * program is run
 * Returns nothing, takes a pointer to the beginning of the array of students
 * , the total number of students, and total number of grades as input
 */
void free_memory(student_t * students, int num_students){
    int i;
    for (i = 0; i < num_students; i++){
        free(students[i].grades);
        students[i].grades = NULL;
    }
    free(students);
    students = NULL;
}

