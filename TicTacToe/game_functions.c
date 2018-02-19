/*
 * TicTacToe Game Functions
 *  
 * Moises Beato Nunez
 * 17 Feb 2018
 */

#include "TicTacToe.h"

TABLE *tableptr;                        //pointer to the table struct

/*
 * CreateTable() - Generates a TicTacToe table
 * arguments: none
 * returns: -1 if the table size is outside of range.
 *           1 if all is good.
 */ 
 int32_t CreateTable(uint32_t table_size){
    if (table_size < MINSIZE || table_size > MAXSIZE) return -1; //check for table size range violations
    else {
        tableptr = malloc(sizeof(TABLE) + (table_size * table_size));  //allocate memory to the desired table size  
        tableptr->size = table_size;
        int pos_value = 1;                         //counts from 1 to nun*num
        for (int i = 0; i < tableptr->size; i++){
            for(int j = 0; j < tableptr->size; j++){
                tableptr->blocks[i][j] = pos_value;     //enumerates each position to make it selectable
                pos_value++;
                printf("position[%d][%d]: %d\n",i,j,tableptr->blocks[i][j]);  //test
            } 
        }
        printf("after loop position[0][0]: %d\n",tableptr->blocks[0][0]);  //test
        return 1;
    }
} 

/*
 * DisplayTable() - Displayes the table generated
 * arguments: the size of the table
 * returns: nothing
 */
void DisplayTable(void){
    for (int i = 0; i < tableptr->size; i++){
        for(int j = 0; j < tableptr->size; j++){
            if (tableptr->blocks[i][j] == 'X' || tableptr->blocks[i][j] == 'O') //check the type of data the position contains
                printf("| %c  |", tableptr->blocks[i][j]);                  //print if it is a character
            else 
                printf("| %.2d |", tableptr->blocks[i][j]);                 //print if it is a number
               
        }
        printf("\n");
    }
   // printf("after loop position[0][0]: %d\n",tableptr->blocks[0][0]);
}

/*
 * UpdateTable - Adds the player's move to the table.
 * arguments:    The desired move, and the current player
 * returns:      1 if the move succeds
 *              -1 if the move fails 
 */
int32_t UpdateTable(uint32_t move, uint32_t player){
    if (player == 1)             //player 1 uses the 'X' character and player 2 uses 'O'
        tableptr->value = 'X';
    else 
        tableptr->value = 'O';
    int pos_value = 0;            //compare the move value  with the positions value
    for (int i = 0; i < tableptr->size; i++){
        for(int j = 0; j < tableptr->size; j++){
            pos_value++;
            if (pos_value == move && tableptr->blocks[i][j] == move){   //if the position is avaliable
                    tableptr->blocks[i][j] = tableptr->value;               //change it to the appropriate character
            } else if ((pos_value == move && tableptr->blocks[i][j] != move) || move < 1 || move > (tableptr->size*tableptr->size))
                return -1;                                          //return error if the position is already taken
        }                                                           //or if the position selected is not on the table
    }
    return 1;                                                       //return if succesful
}