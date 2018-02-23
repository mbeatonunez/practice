/*
 * TicTacToe Game Functions
 *
 * Moises Beato Nunez
 * 22 Feb 2018
 */

#include "TicTacToe.h"
struct Board {
    uint32_t size;                      //user defined size of the board
    uint32_t **blocks;                  //empty 2-D matrix
} board;

/*
 * CreateBoard()  Generates a TicTacToe board
 * arguments:     The user defined size of the game board
 * returns:      -1 if the board size is outside of range.
 *                1 otherwise
 */
 int32_t CreateBoard(uint32_t size){
     /*
      * The user chooses the size of the board within a pre-defined range. Memory is then allocated to build a matrix
      * of the desired size. Then the matrix is populated with positions 1 to board_size.
      */
    if (size < MINSIZE || size > MAXSIZE) return -1;                //check range violations
    else {
        board.blocks = malloc(sizeof(**board.blocks) * size );     //allocate memory for array
        for (uint32_t i = 0 ; i < size; i++)
            board.blocks[i] = malloc(sizeof(**board.blocks) * size ); //allocate  memory for 2D array


        board.size = size;
        uint32_t pos_value = 1;                                     //counts from 1 to size x size
        for (uint32_t i = 0; i < board.size; i++){
            for(uint32_t j = 0; j < board.size; j++){
                board.blocks[i][j] = pos_value;                     //enumerate for selectivity
                pos_value++;
            }
        }
        return 1;
    }
}

/*
 * DisplayBoard()   Displays the board generated
 * arguments:       The size of the board
 * returns:         Nothing
 */
void DisplayBoard(void){
    /*
     * Cycle through the board. Positions already captured by players are marked by a X or O.
     * If a character is found, display the character, otherwise, display the position number.
     */
    printf("\n");
    for (uint32_t i = 0; i < board.size; i++){
        for(uint32_t j = 0; j < board.size; j++){
            if (board.blocks[i][j] == 'X' || board.blocks[i][j] == 'O') //search for captured positions
                 printf("| %c  |", board.blocks[i][j]);
            else printf("| %.2d |", board.blocks[i][j]);                 //otherwise, display position number
        } printf("\n");
    }
}

/*
 * UpdateBoard() Adds the player's move to the board.
 * arguments:    The board selected captured and the player who took it.
 * returns:      1 if the move success
 *              -1 otherwise
 */
int32_t UpdateBoard(uint32_t move, uint32_t player){
    char value;
    if (player == 1) value = 'X';                                    //player 1 uses the 'X' character and player 2 uses 'O'
    else value = 'O';

    uint32_t pos_value = 0;                                          //compare the move to the position
    for (uint32_t i = 0; i < board.size; i++){
        for(uint32_t j = 0; j < board.size; j++){
            pos_value++;
            if (pos_value == move && board.blocks[i][j] == move){   //if the position is available
                    board.blocks[i][j] = value;                     //change it to the appropriate character
            } else if ((pos_value == move && board.blocks[i][j] != move) || move < 1 || move > (board.size*board.size))
                return -1;                                          //return error if the position is already taken
        }                                                           //or if the position selected is out of range
    }
    return 1;                                                       //return if successful
}

/*
 * isWin()       Check if a player has won the game.
 * arguments:    none
 * returns:      true if a winning condition has been found
 *               false otherwise
 */
bool isWin(void){
    bool winner = false;
    uint32_t xcount;        //holds the amount of X's and O's found
    uint32_t ocount;
    uint32_t k;             //incline counter

    /* win condition:
     *      The loops checks that, for every position, if the value of the position adjacent to it
     *      is a match (X or O), then increment the respective counter. Since the number of X's or O's
     *      needs to match the number of rows to win the game, once the counter reaches [board.size], a winning
     *      condition has been reached.
     */
    xcount = ocount = 0;                                //initialize the count to zero
   //Horizontal winning condition
   for (uint32_t i = 0; i < board.size; i++){
        for (uint32_t j = 0; j < board.size; j++){
             if (board.blocks[i][j] == 'X') xcount++;   //add 1 for every X in the row
             if (board.blocks[i][j] == 'O') ocount++;   //add 1 for every X in the row
        }
     if (xcount == board.size || ocount == board.size) winner = true;
     else xcount = ocount = 0;                          //if the row is not a winner, reset count
    }
    //Vertical winning condition
    for (uint32_t i = 0; i < board.size; i++){
        for (uint32_t j = 0; j < board.size; j++){
             if (board.blocks[j][i] == 'X') xcount++;   //add 1 for every X in the column
             if (board.blocks[j][i] == 'O') ocount++;   //add 1 for every X in the column
        }
     if (xcount == board.size || ocount == board.size) winner = true;
     else xcount = ocount = 0;                          //if the column is not a winner, reset count
    }
    //incline (/) winning condition
    k = 0;      //incline counter
    for (uint32_t i = board.size; i > 0; i--){ //If there is an X or O adjacent to the selected position, increment the count by 1
        if (board.blocks[i-1][k] == 'X') xcount++;
        if (board.blocks[i-1][k] == 'O') ocount++;
        k++;
    }
    if (xcount == board.size || ocount == board.size) winner = true;
    else xcount = ocount = 0;
    //decline winning condition (\)
    for (uint32_t i = 0; i < board.size; i++){ //If there is an X or O adjacent to the selected position, increment the count by 1
        if (board.blocks[i][i] == 'X') xcount++;
        if (board.blocks[i][i] == 'O') ocount++;
    }
    if (xcount == board.size || ocount == board.size) winner = true;
    if (winner == true){
        DisplayBoard();       //display the final table
        free(board.blocks);   //free memory when game ends
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
     * The max number of possible moves is board.size*board.size (i.e. a 3x3 board as 9 possible moves).
     * The function count the number of X's and O's found. If that count = the max number of moves
     * then a tie has been reached
     */
    uint32_t tiecount = 0;                           //count the number of taken positions
    uint32_t maxmoves = board.size * board.size;     //calculate the maximum number of possible moves
    for (uint32_t i = 0; i < board.size; i++){
        for (uint32_t j = 0; j < board.size; j++){       //search for taken position, if found, increment the counter
            if (board.blocks[i][j] == 'X' || board.blocks[i][j] == 'O') tiecount++;
        }
    }
    if (tiecount == maxmoves){
        DisplayBoard();         //display the final table
        free(board.blocks);     //free memory when game ends
        return true;            //return true if a tie has been reached
    }
    else return false;
}

