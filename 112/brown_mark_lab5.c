/*
 *
 *
 *
 */

#include<stdio.h>

//function prototypes
void get_input(void);
int calculate_odds(void);
int calculate_evens(void);
int total_sum(void);
int calculate_checksum(void);
void is_valid(void);

//defineds the size of the array (barcode)
#define SIZE 12

int barcode[SIZE];
//int sum_odds = 0, sum_evens = 0, total_sum = 0, check_digit = 0;

//main function
int
main() {
    get_input();
   // calculate_odds();
   // calculate_evens();
   // total_sum();
   // calculate_checksum();
    is_valid();
    return 0;
}

/*
 *Prompts user to insert a barcode, and stored that code in an array.
 */
void get_input(){
    int i = 0;
    printf("Enter a bar code to check. Separate digits with a space >\n");
    while (i < SIZE){
    scanf("%d", &barcode[i]);
    i++;
    }
    printf("\nYou entered the code:"); 
    int j;
    for (j = 0; j < SIZE; j++){
    printf(" %d", barcode[j]);
    }
}

/*
 *Calculates the sum of the odd digits multiplied by 3
 *Returns the value obtained from calculation
 */
int calculate_odds(){
    int sum_odds = 0;
    int i;
    for (i = 0; i < SIZE; i+=2){
        sum_odds += barcode[i];
        }
    sum_odds = sum_odds * 3;
    printf("\n");
    printf("STEP 1: Sum of odds times 3 is %d\n", sum_odds);
    return sum_odds;
}

/*
 *Calculates the sum of the digits in even spots of array
 *Returns the calculated value to be passed to total_sum()
 */
int calculate_evens(){
    int sum_evens = 0;
    int i;
    for (i = 1; i < SIZE - 1; i+=2){
        sum_evens += barcode[i];
    }
    printf("STEP 2: Sum of the even digits is %d\n", sum_evens);
    return sum_evens;
}

/*
 *Calculates the total sum of even and odd spots, excluding last spot of array
 *Adds values from calculate_odds() and calculate_evens().  Returns value obtained
 */
int total_sum(){
    int total_sum = calculate_odds() + calculate_evens();
    printf("STEP 3: Total sum is %d\n", total_sum);
    
    return total_sum;
}

/*
 *Calculates the check digit to be compared against the last digit of the array
 *Returns the value obtained for check_digit.
 */
int calculate_checksum(){
    int check_digit =  total_sum() % 10;  //calculated the remainder of dividing total_sum by 10.
    if (check_digit != 0){
        check_digit = 10 - check_digit;  //if remainder is not 0, it is subtracted from 10 to obtain check_digit.  Otherwise, check_digit is 0
    }
    printf("STEP 4: Calculated check digit is %d\n", check_digit);
    return check_digit;
}
/*
 *Checks to see if barcode is valid.
 *Checks value returned from calculate_checksum() against last digit in array
 */
void is_valid(){
    if (calculate_checksum() == barcode[SIZE - 1]){  //checks if check_digit equals last digit in array
        printf("STEP 5: Check digit and last digit match\nBarcode is VALID.\n");
    }else{
        printf("STEP 5: Check digit and last digit do not match\nBarcode is INVALID.\n");
    }
}
