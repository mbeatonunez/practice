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
#include <stdbool.h>

#define VERSION 0.5 //still working on the pvp part.

#define MAXSIZE 9  //this is the maximun size posible for this table
#define MINSIZE 3  //minimum size requirement for a proper game

typedef struct Board {
    uint32_t size;                      //size of table
    char value;                         //holds the position value. Either 'O' of 'X'
    uint32_t **blocks;                  //table blocks that hold the positions
} BOARD;


int32_t CreateBoard(uint32_t board_size);               //creat the game board
void DisplayBoard(void);                                //displays the game board
int32_t UpdateBoard(uint32_t move, uint32_t player);    //marks the positions taken by each player
bool isWin(void);                                       //searches for a winner
bool isTie(void);                                       //checks for tie once the board is filled
#endif
