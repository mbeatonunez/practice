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

#define VERSION 0.2 //still working on the pvp part. 

#define MAXSIZE 9  //this is the maximun size posible for this table
#define MINSIZE 3  //minimum size requirement for a proper game

struct Table {
    uint32_t blocks[MAXSIZE][MAXSIZE];  //table blocks that hold the positions
    uint32_t size;                      //size of table
    char value;                         //holds the position value. Either 'O' of 'X'
} table;

uint32_t CreateTable();
void DisplayTable();
uint32_t UpdateTable(uint32_t move, uint32_t player);
 
 
 
 #endif