/*
 * Name:        Permutation
 * Author:      Moises Beato Nunez
 * Date:        02 Mar 2018
 * Description: My attempt at a permutation program. The program reads a string and prints out a permutation in the
 *              orders of n!, where n is the length of the string. This program does not account for repeated characters.
 *              After much trial and error, I could not figure this out on my own. Most of the credit goes to www.geeksforgeeks.org
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERSION 0.1

void replace(char *currentpos, char *nextpos);              //replace position values
void permuteStr(char *str, int startpos, int lastpos);      //conduct permutation via recursion

int main()
{
    char buff[10];          //holds the string input. Limited to 10 since 10! is a very large number
    int length;             //length of the string
    printf("Enter a word no longer than %d characters: ", sizeof(buff));

    fgets(buff, sizeof buff, stdin); //get input from user and the new line character
    length = strlen(buff) - 2;       //the length of the string minus the new line and NULL char
    int firstPos = 0;

    permuteStr(buff, firstPos, length);
    return 0;
}
/* replace():  swaps the value of an element in a string with another
 * arguments:  Pointers to the two positions to be swapped
 * Return:     void
 */
void replace(char *currentpos, char *nextpos){
    char newpos = *currentpos;              //replace the current position with the position next to it
    *currentpos = *nextpos;
    *nextpos = newpos;
}

/* permuteStr: Performs the permutation of a string via recursion
 * arguments:  Pointers to the string, the first index, and the last index
 * Return:     void
 */
void permuteStr(char *str, int startpos, int lastpos){

    if (startpos == lastpos) printf("%s", str);                 //print the string once the position
    else {
        for (int i = startpos; i <= lastpos; i++){
            replace((str + startpos),(str + i) );               //replace a position with the next one
            permuteStr(str, startpos+1 , lastpos);
            replace((str + startpos),(str + i) );               //restore original position
        }
    }
}
