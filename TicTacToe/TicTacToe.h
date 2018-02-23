 /*
 * TicTacToe Header file
 *
 * Moises Beato Nunez
 * 22 Feb 2018
 */
 #ifndef TICTACTOE_HEADER
 #define TICTACTOE_HEADER

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define VERSION 1.0.1

#define MAXSIZE 9  //this is the maximum size possible for this table
#define MINSIZE 3  //minimum size requirement for a proper game


int32_t CreateBoard(uint32_t size);                     //create the game board
void DisplayBoard(void);                                //displays the game board
int32_t UpdateBoard(uint32_t move, uint32_t player);    //marks the positions taken by each player
bool isWin(void);                                       //searches for a winner
bool isTie(void);                                       //checks for tie once the board is filled
#endif
