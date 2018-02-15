/*
 * Name:        Fibonacci Series
 * Author:      Moises Beato Nunez
 * Description: Here I try to figure out how to print the fibonacci series. Like the other programs, the user can define
 *              the lenght of the series. 
 *
 */ 

#include <stdio.h>

#define VERSION 1.0

int printFibo(int *lenght);

int main(int argc, char **argv)
{
	
    const int UpperLimit = 40; //limit of the number of items printed
    const int LowerLimit = 0;
    int menu; // menu selection
    int input; //user input
    
    
    printf("\t* * * * * * * * * * * * * *\n"); //...I know... another banner...
    printf("\t*    Fibonacci Series     *\n");
    printf("\t* * * * * * * * * * * * * *\n");
    do{
        printf("\nWelcome to the Fibonacci Series printer [LIMIT: %d to %d].\n", LowerLimit, UpperLimit);
        printf("Please select from the menu below.\n");
        printf("\t1) Print The Fibonacci Series.\n");   //print the series to a given length
        printf("\t2) I don't need this. Quit\n");       //exits the program
        printf("Selection: ");
        scanf(" %d", &menu);                            //user input
        switch(menu){
            case 1:
                printf("Please enter the lenght of the series: ");
                scanf(" %d", &input);
                while (input < LowerLimit || input > UpperLimit){     //check for limit errors
                    printf("Entry is outside of limit bounderies. Try again: ");
                    scanf(" %d", &input);
                }
                if (!printFibo(&input)){                    //checks to see if the function cashed.
                    printf("An error has occured!.\n");
                    break;
                }
                break;
            case 2:                                         //exit program
                break;
            default:
                printf("Invalid entry.\n");                   //go back to main menu
                break;
        }
    
    }while (menu != 2);
	return 0;
}

//print the fibonacci series for a given length
int printFibo(int *length){
    int fibo1 = 0; //holds the previous value of the series
    int fibo2 = 1; //holds the next value on the series
    int count = 0; //hold the count of the numbers printes
    printf("Series:\n"); 
    while (count < *length){ 
        printf("%d ", fibo1);
        fibo1 = fibo1 + fibo2;
        count++;
        if (count < *length ){ // this section accounts for odd lengths 
            printf("%d ", fibo2);
            fibo2 = fibo2 + fibo1;
            count++;
        }        
        if (count%10 == 0) //limit items per line to 10
            printf("\n");
    }
    return 1;
}