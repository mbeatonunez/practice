/*
 * Name:        TicTacToe
 * Author:      Moises Beato Nunez
 * Date:        21 Feb 2018
 * Description: In this program I attempt to create the TicTacToe game in C. You can create a board of any size between
 *              3x3 and 9x9. The modes include player vs player, player vs comp, and comp vs comp.
 *
 */

#include "TicTacToe.h"

int main(int argc, char **argv)
{
    uint32_t playmove;          // holds the board position selected
    uint32_t turn = 1;          // keeps track of who's turm it is. Starts with player 1
    uint32_t menu;              // holds the menu selection
    uint32_t input;             // sub-menu selection

    printf("\t* * * * * * *\n"  //here i go with the banners again
           "\t* TicTacToe *\n"
           "\t* * * * * * *\n");

    do{
        printf("\nWelcome to my attempt at TicTacToe.\n"); //menu
        printf("The game board can be as small as a %d by %d, or as large as %d by %d.\n",MINSIZE, MINSIZE, MAXSIZE, MAXSIZE);
        printf("MODES\n");
        printf("\t1) Player vs Player\n");
        printf("\t2) Player vs Computer\n");
        printf("\t3) Computer vs Computer\n");
        printf("\t4) Exit Program\n");
        printf("Select a mode: ");
        scanf("%d", &menu);

        switch (menu){
            case 1:
                /* Player Vs Player:
                 *      The user defines the board size. After the board has been generated and printer, player 1
                 *      makes a move. After each move the players alternate and a query is sent in search for a winner.
                 *      If a winner is found, the winner is displayed and the game end. If a tie is found, display a messege
                 *      then end the game.
                 */ 
                printf("\nPlease enter the size of you board: ");   //define board size
                scanf(" %u", &input);
     
                while (CreateBoard(input) == -1){                   //check for range violations, if found, display error messege
                    printf("Error: entry is outside of parameters.\nTry Again: ");
                    scanf(" %u", &input);                           //re-enter board size
                }
                while (1){                                          //continue until the game ends
                    printf("\nIt is Player %d's turn.\n", turn);
                    DisplayBoard();    //displays the board
                    printf("Make your move: ");                     //choose a position to take
                    scanf(" %d", &playmove);
                    while (UpdateBoard(playmove, turn) == -1){      //checks if position is already taken
                        printf("Error: Invalid move.\nTry again: ");
                        scanf("%d", &playmove);                     //ask for a new positions
                    }
                    if (isWin()){                                   //if a winner is declare, exit
                        DisplayBoard();
                        printf("Player %d is the winner!\n\n",turn);
                        break;
                    } else if (isTie()){                            //if a tied is reached, exit
                        DisplayBoard();
                        printf("Tie. There is no winner!\n\n");
                        break;
                    }
                    if (turn == 1){                                 //alternate between players once per move
                        turn = 2;
                    }else {
                        turn = 1;
                    }
                }
                break;
            case 2:  //working on it
                printf("\nPlease enter the size of you board: ");
                scanf(" %u", &input);
     
                while (CreateBoard(input) == -1){                   //check for range violations
                    printf("Error: entry is outside of parameters.\nTry Again: ");
                    scanf(" %u", &input);
                }
                printf("Mode under contruction. Sorry.\n");
                break;
            case 3:  //working on it
                printf("\nPlease enter the size of you board: ");
                scanf(" %u", &input);
     
                while (CreateBoard(input) == -1){                   //check for range violations
                    printf("Error: entry is outside of parameters.\nTry Again: ");
                    scanf(" %u", &input);
                }
                printf("Mode under contruction. Sorry.\n");
                break;
            case 4:                                                //break the loop and exit program
                printf("\nGood Bye.\n");
                break;
            default:                                               //check for menu selection errors
                printf("Invalid entry\n");
                break;
        }

    } while (menu != 4);

	return 0;
}

