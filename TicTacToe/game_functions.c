/*
 * TicTacToe Game Functions
 *  
 * Moises Beato Nunez
 * 17 Feb 2018
 */

#include "TicTacToe.h"

BOARD board;                        //game board struct

/*
 * CreateBoard() - Generates a TicTacToe board
 * arguments: The user defined size of the game board
 * returns: -1 if the board size is outside of range.
 *           1 if all is good.
 */ 
 int32_t CreateBoard(uint32_t board_size){
    if (board_size < MINSIZE || board_size > MAXSIZE) return -1; //check for board size range violations
    else {
        board.blocks = malloc(sizeof(uint32_t*) * board_size );  //allocate memory to the desired board size
        for (int i = 0 ; i < board_size; i++)
            board.blocks[i] = malloc(sizeof(uint32_t) * board_size);
        
        board.size = board_size;
        int pos_value = 1;                         //counts from 1 to nun*num
        for (int i = 0; i < board.size; i++){
            for(int j = 0; j < board.size; j++){
                board.blocks[i][j] = pos_value;     //enumerates each position to make it selecboard
                pos_value++;
            } 
        }
        return 1;
    }
} 

/*
 * DisplayBoard() - Displayes the board generated
 * arguments: the size of the board
 * returns: nothing
 */
void DisplayBoard(void){
    for (int i = 0; i < board.size; i++){
        for(int j = 0; j < board.size; j++){
            if (board.blocks[i][j] == 'X' || board.blocks[i][j] == 'O') //check the type of data the position contains
                printf("| %c  |", board.blocks[i][j]);                  //print if it is a character
            else 
                printf("| %.2d |", board.blocks[i][j]);                 //print if it is a number
               
        }
        printf("\n");
    }
   // printf("after loop position[0][0]: %d\n",board.blocks[0][0]);
}

/*
 * UpdateBoard - Adds the player's move to the board.
 * arguments:    The board selected captured and the player who took it.
 * returns:      1 if the move succeds
 *              -1 if the move fails 
 */
int32_t UpdateBoard(uint32_t move, uint32_t player){
    if (player == 1)             //player 1 uses the 'X' character and player 2 uses 'O'
        board.value = 'X';
    else 
        board.value = 'O';
    int pos_value = 0;            //compare the move value  with the positions value
    for (int i = 0; i < board.size; i++){
        for(int j = 0; j < board.size; j++){
            pos_value++;
            if (pos_value == move && board.blocks[i][j] == move){   //if the position is avaliable
                    board.blocks[i][j] = board.value;               //change it to the appropriate character
            } else if ((pos_value == move && board.blocks[i][j] != move) || move < 1 || move > (board.size*board.size))
                return -1;                                          //return error if the position is already taken
        }                                                           //or if the position selected is not on the board
    }
    return 1;                                                       //return if succesful
}

/*
 * isWin() - Check if a player has won the game.
 * arguments:    none
 * returns:      true if the player wins
 *               false is there is no win
 */
bool isWin(void){
    uint32_t hxcnt = 0;  //horizontal X count
    uint32_t hocnt = 0;  //horizontal O count
    uint32_t vxcnt = 0;  //vertical X count
    uint32_t vocnt = 0;  //vertical O count
    uint32_t dxcnt = 0;  //decline X count (\)
    uint32_t docnt = 0;  //delcine O count
    uint32_t ixcnt = 0;  //incline X count (/)
    uint32_t iocnt = 0;  //incline O count
    
    bool winner = false;
    
    /* win condition:
     *      The loops checks that for every positiont, if the value of the position adjesent to it
     *      match (X or O), then increment the perspective counter. Since it take [board.size] number of X's or O's
     *      to win the game (i.e. 3 X's or O's on a 3x3 size board), once the X or O count reaches [board.size], a winning 
     *      condition has been reached
     */
//    for (int i = 0; i < board.size; i++){ //horizontal winning condition
//        for (int j = 0; j < board.size; j++){
//            if ((board.blocks[i][j-1] == 'X' && board.blocks[i][j] == 'X') || (board.blocks[i][j+1] == 'X' && board.blocks[i][j] == 'X')) 
//                hxcnt++; // the two AND statemens joined by the OR make sure to account for a j+1 or J-1 positions with undefined values
//            else if ((board.blocks[i][j-1] == 'O' && board.blocks[i][j] == 'O') || (board.blocks[i][j+1] == 'O' && board.blocks[i][j] == 'O')) 
//                hocnt++;
//        }
//        if (hxcnt == board.size || hocnt == board.size){
//            winner = true;  //declare a winner
//            break;
//        }     
//
//    }
    for (int i = 0; i < board.size; i++){ //vertical winning condition
        for (int j = 0; j < board.size; j++){
            if ((board.blocks[i-1][j] == 'X' && board.blocks[i][j] == 'X') || (board.blocks[i+1][j] == 'X' && board.blocks[i][j] == 'X')) 
                vxcnt++; // the two AND statemens joined by the OR make sure to account for a i+1 or i-1 positions with undefined values
            else if ((board.blocks[i-1][j] == 'O' && board.blocks[i][j] == 'O') || (board.blocks[i+1][j] == 'O' && board.blocks[i][j] == 'O')) 
                vocnt++;
        }
        if (vxcnt == board.size || vocnt == board.size){
            winner = true;  //declare a winner
            break;
        }     
        
    }
//    for (int i = 0; i < board.size; i++){  //incline winning condition
//        for (int j = 0; j < board.size; j++){
//            if ((board.blocks[i+1][j-1] == 'X' && board.blocks[i][j] == 'X') || (board.blocks[i-1][j+1] == 'X' && board.blocks[i][j] == 'X')) 
//                ixcnt++; // the two AND statemens joined by the OR make sure to account for a j+1 or J-1 positions with undefined values
//            else if ((board.blocks[i+1][j-1] == 'O' && board.blocks[i][j] == 'O') || (board.blocks[i-1][j+1] == 'O' && board.blocks[i][j] == 'O')) 
//                iocnt++;
//        }
//        
//        if (i == (board.size - 1)){  //at the end of every loop, check for a winning condition
//            if (ixcnt == board.size || iocnt == board.size){
//                winner = true;  //declare a winner
//                break;
//            }     
//        }
//    }
//    for (int i = 0; i < board.size; i++){ //decline winning condition
//        for (int j = 0; j < board.size; j++){
//            if ((board.blocks[i-1][j-1] == 'X' && board.blocks[i][j] == 'X') || (board.blocks[i+1][j+1] == 'X' && board.blocks[i][j] == 'X')) 
//                dxcnt++; // the two AND statemens joined by the OR make sure to account for a j+1 or J-1 positions with undefined values
//            else if ((board.blocks[i-1][j-1] == 'O' && board.blocks[i][j] == 'O') || (board.blocks[i+1][j+1] == 'O' && board.blocks[i][j] == 'O')) 
//                docnt++;
//        }
//        
//        if (i == (board.size - 1)){  //at the end of every loop, check for a winning condition
//            if (dxcnt == board.size || docnt == board.size){
//                winner = true;  //declare a winner
//                break;
//            }     
//        }
//    }
    return winner; 
}
/*
 * isTie() - Check if a players reached a tied
 * arguments:    none
 * returns:      true if the tied
 *               false is there is no tie
 */
bool isTie(void){
    uint32_t tiecount = 0;
    for (int i = 0; i < board.size; i++){
        for (int j = 0; j < board.size; j++){
            if (board.blocks[i][j] == 'X' || board.blocks[i][j] == 'O')
                tiecount++;
        }
    }
    if (tiecount == (board.size * board.size))
        return true;
    else
        return false;
}