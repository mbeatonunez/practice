#include "primeNumbers.h"

/* isPrime() – checks if given number is prime
 * arguments: an unsigned integer
 * returns: 1 if prime, 0 if composite
 */
int isPrime(unsigned int num){
    int check = 0;     //keeps track of the number of remainders 
    for (int i = 1; i <= num; i++){
          if((num % i) == 0 ){  //checks if a number is divisable by any before it
            check++;
          }
       }
       if(check == 2)           //if a number is only divisable by two numbers, then it is a prime
          return 1;
       else                     //if divisable by more than 2, then it is not prime.
           return 0;
}

/* primeList() – prints a defined range of prime numbers
 * arguments:  unsigned integers
 * returns: prints the prime numbers sequentially 
 */
void primeList(unsigned int lower, unsigned int upper){
    int primeCount = 0;                 //keeps track of how many prime numbers it finds
    printf("\nPrimes: ");
    for (int i = lower; i <= upper; i++){
        if (isPrime(i)){             //check if the number is prime
            printf(" %d", i);
            if ((primeCount % 10) == 0){  //print a new line every 10 numbers. 
                printf("\n");
            }
            primeCount++;           // add +1 to the count of prime numbers
        }
    }
    printf("\nThere are %d prime numbers between %d and %d\n",primeCount, lower, upper); 
}