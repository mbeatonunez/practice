/*
 * TicTacToe Header file
 *
 * Moises Beato Nunez
 * 21 Feb 2018
 */
 #ifndef TICTACTOE_HEADER
 #define TICTACTOE_HEADER

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#define VERSION 0.7 //working on winning condition

#define MAXSIZE 9  //this is the maximun size posible for this table
#define MINSIZE 3  //minimum size requirement for a proper game

typedef struct Board {
    uint32_t size;                      //user defined size of the board
    uint32_t **blocks;                  //empty 2-D matrix
} BOARD;


int32_t CreateBoard(uint32_t size);               //creat the game board
void DisplayBoard(void);                                //displays the game board
int32_t UpdateBoard(uint32_t move, uint32_t player);    //marks the positions taken by each player
bool isWin(void);                                       //searches for a winner
bool isTie(void);                                       //checks for tie once the board is filled
#endif
