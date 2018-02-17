/*
 * Name:        TicTacToe
 * Author:      Moises Beato Nunez
 * Description: In this program I atempt to create the TicTacToe game in C. You can create a table of any size between
 *              3x3 and 9x9. The modes include player vs player, player vs comp, and comp vs comp.
 *
 */ 

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define VERSION 0.1 //still working on the pvp part. 

#define MAXSIZE 9  //this is the maximun size posible for this table
#define MINSIZE 3  //minimum size requirement for a proper game

struct Table {
    uint32_t blocks[MAXSIZE][MAXSIZE];  //table blocks that hold the positions
    uint32_t size;                      //size of table
    char value;                         //holds the position value. Either 'O' of 'X'
} table;

uint32_t CreateTable();
void DisplayTable();
uint32_t UpdateTable(uint32_t CurrentMove, uint32_t WhoPlays);


int main(int argc, char **argv)
{
    uint32_t playmove;          // holds the table position selected
    uint32_t turn = 1;          //keeps track of who's turm it is. Starts with player 1
 
    printf("\t TicTacToe Test\n\n");
    printf("Welcome to my attempt at TicTacToe.\nHere you get to choose the size of you table [%d to %d].\n", MINSIZE, MAXSIZE);
    printf("Please enter the size of you table (i.e 3 will give you a 3x3 table): ");
    scanf(" %d", &table.size);
    
    while (CreateTable() == -1){   //check to see if the table is withn the size range
        printf("Error: entry is outside of parameters.\nTry again: ");
        scanf(" %d", &table.size);
    }
    
    while (1){           //while testing, we keep this loop infinite. Haven't created a winning condition yet
        printf("\n\nIt is Player %d's turn.\n", turn);
        DisplayTable();    //displays the table
        printf("Make your move: ");
        scanf(" %d", &playmove);
        while (UpdateTable(playmove, turn) == -1){      //checks if the move was already made
            printf("Position already take.\nTry again: ");
            scanf(" %d", &playmove);
        }
        if (turn == 1){                                 //alternate between players
            turn = 2;
        }else {
            turn = 1;
        }
    }
    
	return 0;
}

/*
 * CreateTable() - Generates a TicTacToe table
 * arguments: none
 * returns: -1 if the table size is outside of range.
 *           1 if all is good.
 */ 
 uint32_t CreateTable(){
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
            if (pos_value == move && table.blocks[i][j] == move){   //if the position exist
                    table.blocks[i][j] = table.value;               //change it to the appropriate character
            } else if (pos_value == move && table.blocks[i][j] != move)
                return -1;                                          //return if the position no longer exist
        }
    }
    return 1;                                                       //return if succesful
}