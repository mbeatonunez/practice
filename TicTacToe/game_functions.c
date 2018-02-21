/*
 * TicTacToe Game Functions
 *  
 * Moises Beato Nunez
 * 21 Feb 2018
 */

#include "TicTacToe.h"

BOARD board;       //game board struct

/*
 * CreateBoard()  Generates a TicTacToe board
 * arguments:     The user defined size of the game board
 * returns:      -1 if the board size is outside of range.
 *                1 othewise
 */ 
 int32_t CreateBoard(uint32_t size){
     /*
      * The user chooses the size of the board within a pre-defined range. Memory is then allocated to build a matrix
      * of the desired size. Then the matrix is populated with postitions 1 to board_size.
      */ 
    if (size < MINSIZE || size > MAXSIZE) return -1;                //check range violations
    else {
        board.blocks = malloc(sizeof(uint32_t*) * size );           //allocate memory for array
        for (int i = 0 ; i < size; i++)
            board.blocks[i] = malloc(sizeof(uint32_t) * size);      //allocate memory for 2D array
        
        board.size = size;
        int pos_value = 1;                                          //counts from 1 to size x size
        for (int i = 0; i < board.size; i++){
            for(int j = 0; j < board.size; j++){
                board.blocks[i][j] = pos_value;                     //enumerate for selectability
                pos_value++;
            } 
        }
        return 1;
    }
} 

/*
 * DisplayBoard()   Displayes the board generated
 * arguments:       The size of the board
 * returns:         Nothing
 */
void DisplayBoard(void){
    /*
     * Cycle through the board. Positions already captured by players are maked by a X or O. 
     * If a charcter is found, display the character, othewise, display the position number.
     */ 
    for (int i = 0; i < board.size; i++){
        for(int j = 0; j < board.size; j++){
            if (board.blocks[i][j] == 'X' || board.blocks[i][j] == 'O') //search for captured positions
                 printf("| %c  |", board.blocks[i][j]);
            else printf("| %.2d |", board.blocks[i][j]);                 //otherwise, display position number
        } printf("\n");
    }
}

/*
 * UpdateBoard() Adds the player's move to the board.
 * arguments:    The board selected captured and the player who took it.
 * returns:      1 if the move succeds
 *              -1 otherwise 
 */
int32_t UpdateBoard(uint32_t move, uint32_t player){
    char value;
    if (player == 1) value = 'X';                                    //player 1 uses the 'X' character and player 2 uses 'O'
    else value = 'O';
        
    int pos_value = 0;                                               //compare the move to the position
    for (int i = 0; i < board.size; i++){
        for(int j = 0; j < board.size; j++){
            pos_value++;
            if (pos_value == move && board.blocks[i][j] == move){   //if the position is avaliable
                    board.blocks[i][j] = value;                     //change it to the appropriate character
            } else if ((pos_value == move && board.blocks[i][j] != move) || move < 1 || move > (board.size*board.size))
                return -1;                                          //return error if the position is already taken
        }                                                           //or if the position selected is out of range
    }
    return 1;                                                       //return if succesful
}

/*
 * isWin()       Check if a player has won the game.
 * arguments:    none
 * returns:      true if a winning condition has been found
 *               false otherwise
 */
bool isWin(void){
    bool winner = false;            
    uint32_t xcount[] = {0,0,0,0}; //holds the amount of X's and O's found
    uint32_t ocount[] = {0,0,0,0}; 

    /* win condition:
     *      The loops checks that, for every position, if the value of the position adjacent to it
     *      is a match (X or O), then increment the respective counter. Since the number of X's or O's
     *      needs to match the number of rows to win the game, once the counter reaches [board.size], a winning 
     *      condition has been reached. 
     */
    for (int i = 0; i < board.size; i++){ 
        for (int j = 0; j < board.size; j++){   //If there is an X or O adjacent to the selected position, increment the count by 1
            //Horizontal condition
            if ((board.blocks[i][j-1] == 'X' && board.blocks[i][j] == 'X') || (board.blocks[i][j+1] == 'X' && board.blocks[i][j] == 'X'))      xcount[0]++;
            else if ((board.blocks[i][j-1] == 'O' && board.blocks[i][j] == 'O') || (board.blocks[i][j+1] == 'O' && board.blocks[i][j] == 'O')) ocount[0]++;
            //Vertical condition
            else if (i == 0 && board.blocks[i][j] == 'X' && board.blocks[i+1][j] == 'X')                       xcount[1]++; //check the first position
            else if (i == (board.size -1) && board.blocks[i][j] == 'X' && board.blocks[i-1][j] == 'X')         xcount[1]++; //check the last postition
            else if (i != (board.size -1) && board.blocks[i][j] == 'X' && board.blocks[i+1][j] == 'X')         xcount[1]++; //check every position in between
            else if (i == 0 && board.blocks[i][j] == 'O' && board.blocks[i+1][j] == 'O')                       ocount[1]++; 
            else if (i == (board.size -1) && board.blocks[i][j] == 'O' && board.blocks[i-1][j] == 'O')         ocount[1]++;          
            else if (i != (board.size -1) && board.blocks[i][j] == 'O' && board.blocks[i+1][j] == 'O')         ocount[1]++;
            //Decline condition (\)
//            else if (i == 0 && board.blocks[i][j] == 'X' && board.blocks[i+1][j+1] == 'X')                                          xcount[2]++; //check the first position
//            else if (i == (board.size -1) && j == (board.size -1) && board.blocks[i][j] == 'X' && board.blocks[i-1][j-1] == 'X')    xcount[2]++; //check the last postition
//            else if (j != (board.size -1) && i != 0 && board.blocks[i][j] == 'X' && board.blocks[i+1][j+1] == 'X')                  xcount[2]++; //check every position in between
//            else if (i == 0 && board.blocks[i][j] == 'O' && board.blocks[i+1][j+1] == 'O')                                          ocount[2]++; 
//            else if (i == (board.size -1) && j == (board.size -1) && board.blocks[i][j] == 'O' && board.blocks[i-1][j-1] == 'O')    ocount[2]++; 
//            else if (j != (board.size -1) && i != 0 && board.blocks[i][j] == 'O' && board.blocks[i+1][j+1] == 'O')                  ocount[2]++; 
            //Incline condition (/)
            else if (i == 0 && j == (board.size -1) && board.blocks[i][j] == 'X')                                     xcount[3]++; //check the first position
            else if (i == (board.size -1) && j == 0 && board.blocks[i][j] == 'X' && board.blocks[i-1][j+1] == 'X')    xcount[3]++; //check the last postition
            else if (j != 0 && i != (board.size -1) && board.blocks[i][j] == 'X' && board.blocks[i+1][j-1] == 'X')    xcount[3]++; //check every position in between
            else if (i == 0 && j == (board.size -1) && board.blocks[i][j] == 'O')                                     ocount[3]++; 
            else if (i == (board.size -1) && j == 0 && board.blocks[i][j] == 'O' && board.blocks[i-1][j+1] == 'O')    ocount[3]++; 
            else if (j != 0 && i != (board.size -1) && board.blocks[i][j] == 'O' && board.blocks[i+1][j-1] == 'O')    ocount[3]++; 
        }
    } 
    for (int i = 0; i <= board.size; i++){// if the count of adjacent potiions matches the lengt of a row, declare a winner
        if (xcount[i] == board.size || ocount[i] == board.size) winner = true;
    }
    return winner; 
}

/*
 * isTie()       Check if a players reached a tied
 * arguments:    none
 * returns:      true if the tied
 *               false otherwise
 */
bool isTie(void){
    /*
     * The max number of posible moves is board.size*board.size (i.e. a 3x3 board as 9 posible moves).
     * The function count the number of X's and O's found. If that count = the max number of moves
     * then a tie has been reached
     */ 
    uint32_t tiecount = 0;                           //count the number of taken positions
    uint32_t maxmoves = board.size * board.size;     //calculate the maximun number of posible moves
    for (int i = 0; i < board.size; i++){
        for (int j = 0; j < board.size; j++){       //search for taken postision, if found, increment the counter
            if (board.blocks[i][j] == 'X' || board.blocks[i][j] == 'O') tiecount++;
        }
    }
    if (tiecount == maxmoves) return true;         //return true if a tie has been reached
    else return false;
}