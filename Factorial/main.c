/*
 * Name:        Factorial
 * Author:      Moises Beato Nunez
 * Description: Here the user asks for the factorial of a number, or for the factorial of a range of numbers.
 *              Each practice problem builds on the previous one, so they may look similar.
 */

#include <stdio.h>

#define VERSION 1.2

int fcalc (int num);  //calculates the factorial of a number
int trl_zero(int num);

int main(void)
{
    //hard limits of factorials
	const int MIN_FACT = 0;
    const int MAX_FACT = 15;
    int sel = 0;                    //hold the value of the menu
    int input, upper, lower;        //holds the user define limits
    int fact_val;                   //hold the factorial value


    printf("\t* * * * * * * * * * * * * *\n"); //.. I like my banners
    printf("\t*   Factorial Calculator  *\n");
    printf("\t* * * * * * * * * * * * * *\n");
    do{
        printf("\nMy factorial calculator [Limit: %d-%d]. Please select from below\n", MIN_FACT, MAX_FACT); //intro/menu
        printf("\t1) Find factorial.\n");               //calculate the factorial of a single number
        printf("\t2) Print a list of factorials.\n");   //calculate the factorial of a range of numbers
        printf("\t3) Quit.\n");                         //exit
        printf("Selection: ");
        scanf(" %d", &sel);
        switch (sel){
            case 1:   //calculate the factorial of a single number
                printf("Enter a number: ");
                scanf(" %d", &input);
                while (input < MIN_FACT || input > MAX_FACT){       //error correction
                    printf("Entry is outside of limits. Try again: ");
                    scanf(" %d", &input);
                }
                fact_val = fcalc(input);
                printf("\t%d! is %d, and has %d trailing zeroes\n", input, fact_val, trl_zero(fact_val));
                break;
            case 2: //calculate the factorial of a series of numbers
                printf("Enter a lower limit: ");
                scanf("%d", &lower);
                while (lower < MIN_FACT || lower > MAX_FACT){   //check for limit restrictions
                    printf("Entry is outside of limits. Try again: ");
                    scanf(" %d", &lower);
                }
                printf("Enter a upper limit: ");
                scanf("%d", &upper);
                while (upper < lower || upper > MAX_FACT){  //check for limit restrictions
                    printf("Entry is outside of limits. Try again: ");  //error correction
                    scanf(" %d", &lower);
                }
                for (int i = lower; i <= upper; i++){
                    fact_val = fcalc(i);
                    printf("\t%.2d! is %d [Trailing zero: %d]\n", i, fact_val, trl_zero(fact_val));
                }
                break;
            case 3:                     //exit the program
                break;
            default:
                printf("Invalid entry.\n"); //return to the top menu
                break;
        }
    }while (sel != 3);
	return 0;
}
//calculates the factorial of a number
int fcalc (int num){
    int fact = 1;
    if (num < 2){
        return 1;  //return 1 if the input number is 0 or 1
    } else {
        for (int i = 1; i <= num; i++){    //calculate the factorial
            fact *= i;
        }
        return fact;                        //return the calculated factorial
    }
}
//trailing zero calculation
int trl_zero(int num){
  int new_value = num;
  int zero_count = 0;   //for trailing zero calculation
  while((new_value % 10) == 0){
    zero_count++;
    new_value /= 10;
  }
    return zero_count;
}
