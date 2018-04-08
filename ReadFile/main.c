/*
 * Name:        ReadFile
 * Author:      Moises Beato Nunez
 * Description: This program read a file, then prints out the last 10 lines of it.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEST "[insert complete path]\\Test.txt"  
#define NewLine '\n'

int main(int argc, char **argv)
{
    FILE *test;                                 
    char *a, *pos = NULL;               
	long size;                             
    int nl_cnt = 0;                       //number of lines counted
    int target = 10;                      //number of lines to be printed
    
    test = fopen(TEST, "rb");             //open the test file                      

    if (test == NULL)                     //error checking                   
    {
        printf("Error.\n");
        //exit(1);
    }
    /* copy the file data into a string   */
    fseek(test , 0 , SEEK_END);                   //set cursor to end of file
    size = ftell(test);                           //get the size of the file  
    rewind(test);
    a = (char*)malloc(size);
    fread(a,sizeof(char),size,test);              //copy file into string

    pos = strrchr(a, NewLine);                      //find the last new line char in the string
    if (pos == NULL) {                              //error checking
        fprintf(stderr,"File does not contain a \\n character\n");
        exit(1);
    }
     
    while (nl_cnt < target){                    
        while ((a < pos) && (*pos != NewLine))      //go backwards one charcter at a time
            pos--;
        if (*pos == NewLine) {                      //if you find a new line char
            pos--;
            nl_cnt++;                               //increment the new line counter
        } else
            break;                                  //if the file has less than 10 lines, leave
    }
     if (a < pos)                                   //move forward twice to compensate for the double decrement    
         pos += 2;

    printf("%s \n", pos);                           //print the lines.
    
    
    fclose(test);
    unlink("Test.txt");
	return 0;
}
