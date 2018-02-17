/*
 * Prime Numbers header
 * 
 * Moises Beato Nunez
 * 14 Feb 2018
 */

#ifndef PRIMENUMBERS_HEADER
#define PRIMENUMBERS_HEADER

#include <stdio.h>
#include <stdint.h>

#define VERSION 1.4

//minimum and maximum prime number values
#define MIN_PRIME 2
#define MAX_PRINME 1000

int isPrime(uint32_t num);                //prime number checker function
int primeList(uint32_t lower, uint32_t upper); //prime number list generator

#endif
 
