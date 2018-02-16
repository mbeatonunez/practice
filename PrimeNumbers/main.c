/*
 * Name:        Prime Numbers
 * Author:      Moises Beato Nunez
 * Description: The idea here is to ask a user for a range, and print all the prime numbers  
 *              within that range... Now, to figure out how. 
 */ 

#include "primeNumbers.h" 

//minimum and maximum prime number values
#define MIN_PRIME 2
#define MAX_PRINME 1000

int main(int argc, char **argv)
{   
	int upperLimit;                 //prime number range limits
    int lowerLimit; 
    int primeCheck;                 //number to be verified as a prime
    int sel = 0;                    //menu selection variable
    
    printf("\t* * * * * * * * * * * * * *\n"); //banner.... I like making them... sue me.
    printf("\t* Prime Number Calculator*\n");
    printf("\t* * * * * * * * * * * * * *\n\n");
    
    printf("Welcome to my prime number calculator. \nDont wonder why you need this.. just enjoy it!!\n"); //intro
    do {                                                            //loop until someone decides to exit
        printf("\nPlease select from the following options!\n");    //menu
        printf("\t1) Check if Prime.\n");                           //checks it a number is prime
        printf("\t2) Prime List Maker [limits: 2 - 1000].\n");      //list all prime numbers within a given range. The limist to prevent memory overflow
        printf("\t3) Quit.\n");                                     //quit the program
        printf("Selection: ");
        scanf(" %d", &sel);                  
        
        switch (sel){           //for simplicity, once an action has taken place, the program just re-starts. There is no option to remain in the selected sub-menu.
            case 1:
                printf("Enter a number greater than %d: ", (MIN_PRIME - 1));
                scanf(" %d", &primeCheck);
                while (primeCheck < MIN_PRIME ){                       //check if the entered number is greater than 1
                    printf("Invalid entry. Try again: ");
                    scanf(" %d", &primeCheck);
                } 
                if (isPrime(primeCheck)){                  // check if the number is prime
                    printf("Congrats!! %d is a prime number!\n", primeCheck);
                    break;
                } else {
                    printf("Sorry. %d is not a prime number!\n", primeCheck);
                    break;
                }
            case 2:
                printf("Enter a lower limit greater than %d: ", (MIN_PRIME - 1)); //ask for a number =< than the minimun
                scanf(" %d", &lowerLimit);
                while (lowerLimit < MIN_PRIME ){                       //check if the entered number is greater than 1
                    printf("Invalid entry. Try again: ");
                    scanf(" %d", &lowerLimit);
                } 
                printf("Enter an upper limit: ");
                scanf(" %d", &upperLimit);
                while (upperLimit < lowerLimit || upperLimit > MAX_PRINME){    //check if the entered number is greater the lower limit
                    printf("Upper limit cannot be less than Lower limit.\n");
                    printf("Try again: ");
                    scanf(" %d", &upperLimit);
                } 
                    primeList(lowerLimit, upperLimit); //print the list within the range 
                break;
            case 3:
                break;      
            default:
                printf("Invalid entry.");
                break;
        }
        
    } while (sel != 3);
    
    
	return 0;
}

