#include "primeNumbers.h"

//checks if a given number is prime
int isPrime(int *num){
    if ( *num == 2 || *num == 3 || *num == 5 || *num == 7){
            return 1;
        } else if ((*num%2)!=0 && (*num%3)!=0 && (*num%5)!=0 && (*num%7)!=0 ){
            return 1;
        } else
            return 0;
}
// generates a list of prime number within a given range. I'm sure there is a better way to do this
// but I haven't figure it out yet.
int primeList(int *lower, int *upper){
    int primeCount = 1;                 //keeps track of how many prime numbers it finds
    printf("\nPrimes: \n");
    for (int i = *lower; i <= *upper; i++){
        if ( i == 2 || i == 3 || i == 5 || i == 7){ //account for single digit prime numbers
            printf(" %d,", i);
            primeCount++;
        } else if ((i%2)!=0 && (i%3)!=0 && (i%5)!=0 && (i%7)!=0 ){ //check if any number is divisible by the single digit primes
            printf(" %d,", i);
            if ((primeCount%10) == 0){  //print a new line every 10 numbers. Initialized to 1 because 0%10 = 0
            printf("\n");
            }
            primeCount++;
        }
    }
     printf("\nThere are %d prime numbers between %d and %d\n",primeCount-1, *lower, *upper); //primeCount -1 because it was initialized to 1
     return 1;
}