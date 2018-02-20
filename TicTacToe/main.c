/*
 * Name:        TicTacToe
 * Author:      Moises Beato Nunez
 * Description: In this program I atempt to create the TicTacToe game in C. You can create a board of any size between
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
        printf("MODES\n");
        printf("\t1) Player vs Player\n");
        printf("\t2) Player vs Computer\n");
        printf("\t3) Computer vs Computer\n");
        printf("\t4) Exit Program\n");
        printf("Select a mode: ");
        scanf("%d", &menu);

        switch (menu){
            case 1:
                printf("\nPlease enter the size of you board (i.e \"3\" makes a 3x3 board): ");
                scanf(" %u", &input);
     
                while (CreateBoard(input) == -1){   //check to see if the board is withn the size range
                    printf("Error: entry is outside of parameters.\nTry Again: ");
                    scanf(" %u", &input);
                }
                while (1){           //while testing, we keep this loop infinite. Haven't created a winning condition yet
                    printf("\nIt is Player %d's turn.\n", turn);
                    DisplayBoard();    //displays the board
                    printf("Make your move: ");
                    scanf(" %d", &playmove);
                    while (UpdateBoard(playmove, turn) == -1){      //checks if the move was already made
                        printf("Error: Invalid move.\nTry again: ");
                        scanf("%d", &playmove);
                    }
                    if (isWin()){  //if a winner is declare, exit loop.
                        DisplayBoard();
                        printf("Player %d is the winner!\n\n",turn);
                        break;
                    } else if (isTie()){ //if a tied is reached, exit
                        DisplayBoard();
                        printf("Tie. There is no winner!\n\n");
                        break;
                    }
                    if (turn == 1){                                 //alternate between players
                        turn = 2;
                    }else {
                        turn = 1;
                    }
                }
                break;
            case 2:  //working on it
                printf("\nPlease enter the size of you board (i.e \"3\" makes a 3x3 board): ");
                scanf(" %u", &input);
     
                while (CreateBoard(input) == -1){   //check to see if the board is withn the size range
                    printf("Error: entry is outside of parameters.\nTry Again: ");
                    scanf(" %u", &input);
                }
                printf("Mode under contruction. Sorry.\n");
                break;
            case 3:  //working on it
                printf("\nPlease enter the size of you board (i.e \"3\" makes a 3x3 board): ");
                scanf(" %u", &input);
     
                while (CreateBoard(input) == -1){   //check to see if the board is withn the size range
                    printf("Error: entry is outside of parameters.\nTry Again: ");
                    scanf(" %u", &input);
                }
                printf("Mode under contruction. Sorry.\n");
                break;
            case 4:
                printf("\nGood Bye.\n");
                break;
            default:
                printf("Invalid entry\n");
                break;
        }

    } while (menu != 4);

	return 0;
}

