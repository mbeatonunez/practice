#include "primeNumbers.h"

/* isPrime() – checks if given number is prime
 * arguments: an unsigned integer
 * returns: 1 if prime, 0 if composite
 */
int isPrime(uint32_t num){
    if (num < MIN_PRIME) return -1;
    else {
        int check = 0;     //keeps track of the number of remainders
        int max_factor = num/2; //optimized the number of prime checks
        for (int i = 2; i < max_factor; i++)
              if(!(num % i)) check++; //checks if a number is divisable by any before it

        if(check == 0) return 1;          //if a number is only divisable by two numbers, then it is a prime
        else return 0;                    //if divisable by more than 2, then it is not prime.
      }
}

/* primeList() – prints a defined range of prime numbers
 * arguments:  unsigned integers
 * returns: prints the prime numbers sequentially 
 */
int primeList(uint32_t lower, uint32_t upper){
    if (lower < MIN_PRIME || upper > MAX_PRINME){
        return -1;
    } else {
        int primeCount = 1;                 //keeps track of how many prime numbers it finds
        printf("\nPrimes: \n");
        for (int i = lower; i <= upper; i++){
            if (isPrime(i)){             //check if the number is prime
                printf(" %d", i);
                if (!(primeCount % 10)){  //print a new line every 10 numbers. 
                    printf("\n");
                }
                primeCount++;           // add +1 to the count of prime numbers
            }
        }       //primeCount - 1 since it is initialized to 1.
        printf("\nThere are %d prime numbers between %d and %d\n",(primeCount - 1), lower, upper); 
        return 1;
    }
}