/*
 * TicTacToe Header file
 *
 * Moises Beato Nunez
 * 17 Feb 2018
 */
 #ifndef TICTACTOE_HEADER
 #define TICTACTOE_HEADER

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define VERSION 0.3 //still working on the pvp part.

#define MAXSIZE 9  //this is the maximun size posible for this table
#define MINSIZE 3  //minimum size requirement for a proper game

typedef struct Table {
    uint32_t size;                      //size of table
    char value;                         //holds the position value. Either 'O' of 'X'
    uint32_t blocks[0][0];              //table blocks that hold the positions
} TABLE;


int32_t CreateTable(uint32_t table_size);
void DisplayTable(void);
int32_t UpdateTable(uint32_t move, uint32_t player);



 #endif
