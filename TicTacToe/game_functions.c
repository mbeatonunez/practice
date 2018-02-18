/*
 * TicTacToe Game Functions
 *  
 * Moises Beato Nunez
 * 17 Feb 2018
 */

#include "TicTacToe.h"
/*
 * CreateTable() - Generates a TicTacToe table
 * arguments: none
 * returns: -1 if the table size is outside of range.
 *           1 if all is good.
 */ 
 uint32_t CreateTable(){
    printf("\nPlease enter the size of you table (i.e \"3\" makes a 3x3 table): ");
    scanf(" %d", &table.size);
        
    if (table.size < MINSIZE || table.size > MAXSIZE) return -1; //check for table size range violations
    else {
        int pos_value = 1;                         //counts from 1 to nun*num
        for (int i = 0; i < table.size; i++){
            for(int j = 0; j < table.size; j++){
                table.blocks[i][j] = pos_value;     //enumerates each position to make it selectable
                pos_value++;
            }
        }
        return 1;
    }
} 

/*
 * DisplayTable() - Displayes the table generated
 * arguments: the size of the table
 * returns: nothing
 */
void DisplayTable(){
    for (int i = 0; i < table.size; i++){
        for(int j = 0; j < table.size; j++){
            if (table.blocks[i][j] == 'X' || table.blocks[i][j] == 'O') //check the type of data the position contains
                printf("| %c  |", table.blocks[i][j]);                  //print if it is a character
            else 
                printf("| %.2d |", table.blocks[i][j]);                 //print if it is a number
        }
        printf("\n");
    }
}

/*
 * UpdateTable - Adds the player's move to the table.
 * arguments:    The desired move, and the current player
 * returns:      1 if the move succeds
 *              -1 if the move fails 
 */
uint32_t UpdateTable(uint32_t move, uint32_t player){
    if (player == 1)             //player 1 uses the 'X' character and player 2 uses 'O'
        table.value = 'X';
    else 
        table.value = 'O';
    int pos_value = 0;            //compare the move value  with the positions value
    for (int i = 0; i < table.size; i++){
        for(int j = 0; j < table.size; j++){
            pos_value++;
            if (pos_value == move && table.blocks[i][j] == move){   //if the position is avaliable
                    table.blocks[i][j] = table.value;               //change it to the appropriate character
            } else if ((pos_value == move && table.blocks[i][j] != move) || move < 1 || move > (table.size*table.size))
                return -1;                                          //return error if the position is already taken
        }                                                           //or if the position selected is not on the table
    }
    return 1;                                                       //return if succesful
}