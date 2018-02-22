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
    srand(time(0));             // seed the random number generator with the current system time
    uint32_t playmove;          // holds the board position selected
    uint32_t turn;              // keeps track of who's turm it is. Starts with player 1
    uint32_t menu;              // holds the menu selection
    uint32_t input;             // holds the desired size of the board
    uint32_t comp;              // hold the computer's entry

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
                 *      If a winner or a tie is reached, the game ends and the allocated memory for the board is released.
                 */ 
                printf("\nPlease enter the size of you board: ");       //define board size
                scanf(" %u", &input);
     
                while (CreateBoard(input) == -1){                       //check for range violations, if found, display error messege
                    printf("Error: entry is outside of parameters.\nTry Again: ");
                    scanf(" %u", &input);                               //re-enter board size
                }
                turn = 1;                                               //always start with player one
                while (1){
                    printf("\nIt is Player %d's turn.\n", turn);
                    DisplayBoard();                                     //displays the board
                    printf("Make your move: ");                         //choose a position to take
                    scanf(" %d", &playmove);
                    while (UpdateBoard(playmove, turn) == -1){          //checks if position is already taken
                        printf("Error: Invalid move.\nTry again: ");
                        scanf("%d", &playmove);                         //ask for a new positions
                    }
                    if (isWin()){                                       //if a winner is declare, exit
                        DisplayBoard();
                        printf("Player %d is the winner!\n\n",turn);
                        free(board.blocks);                             //free allocated memory
                        break;
                    } else if (isTie()){                                //if a tied is reached, exit
                        DisplayBoard();
                        printf("Tie. There is no winner!\n\n");     
                        free(board.blocks);                             //free allocated memory
                        break;
                    }
                    if (turn == 1)  turn = 2;                           //alternate between players once per move
                    else turn = 1;
                }
                break;
            case 2:  
                /* Player Vs Computer: Works the same as PvP, except the computer inserts a random number from
                 * 1 to the square of the board size. If a winner or a tie is reached, the game ends and the 
                 * allocated memory for the board is released.
                 */ 
                printf("\nPlease enter the size of you board: ");
                scanf(" %u", &input);
     
                while (CreateBoard(input) == -1){                       //check for range violations
                    printf("Error: entry is outside of parameters.\nTry Again: ");
                    scanf(" %u", &input);
                }
                turn = 1;                                               //always start with player one
                while (1){
                    if (turn == 1) printf("\nIt is Player 1's turn.\n"); //display whose turn is it
                    else printf("\nIt is Computer 1's turn.\n");
                    DisplayBoard();                                     //displays the board
                    if (turn == 1){
                        printf("Make your move: ");                     //choose a position to take
                        scanf(" %d", &playmove);
                        while (UpdateBoard(playmove, turn) == -1){      //checks if position is already taken
                        printf("Error: Invalid move.\nTry again: ");
                        scanf("%d", &playmove);                         //ask for a new positions
                        }
                        
                    } else {
                        comp = rand() % (board.size * board.size);      //generate a random number between 1 and the square of the board size
                        while (UpdateBoard(comp, turn) == -1){          //enter Generated number as move
                            comp = rand() % (input * input);            //generate a new number is the previous number was already entered
                        }
                        printf("Make your Move: %d\n", comp);
                    }
                    if (isWin()){                                       //if a winner is declare, exit
                        DisplayBoard();
                        if (turn == 1) printf("Player 1 is the winner!\n\n");
                        else printf("Computer 1 is the winner!\n\n");
                        free(board.blocks);                             //free allocated memory
                        break;
                    } else if (isTie()){                                //if a tied is reached, exit
                        DisplayBoard();
                        printf("Tie. There is no winner!\n\n");
                        free(board.blocks);                             //free allocated memory
                        break;
                    }
                    if (turn == 1)  turn = 2;                            //alternate between players once per move
                    else turn = 1;
                }
                break;
            case 3: 
                /* Computer Vs Computer: Works the same as PvP, except the computers inserts random numbers from
                 * 1 to the square of the board size, and only the final result is displayed. If a winner or a tie is reached, the game ends and the 
                 * allocated memory for the board is released.
                 */
                printf("\nPlease enter the size of you board: ");
                scanf(" %u", &input);
     
                while (CreateBoard(input) == -1){                       //check for range violations
                    printf("Error: entry is outside of parameters.\nTry Again: ");
                    scanf(" %u", &input);
                }
                turn = 1;                                               //always start with player one
                printf("\nComputer 1 = X     Computer 2 = O.\n");   
                while (1){
                    DisplayBoard(); //remove after bug is fixed
                    comp = rand() % (board.size * board.size);          //generate a random number between 1 and the square of the board size
                    while (UpdateBoard(comp, turn) == -1){              //enter Generated number as move
                        comp = rand() % (input * input);                //generate a new number is the previous number was already entered
                    }
                    printf("Comp %d's move: %d\n",turn, comp); //remove after bug is fixed
                    if (isWin()){                                       //if a winner is declare, exit
                        DisplayBoard();
                        printf("Computer %d is the winner!\n\n", turn);
                        free(board.blocks);                             //free allocated memory
                        break;
                    } else if (isTie()){                                //if a tied is reached, exit
                        DisplayBoard();
                        printf("Tie. There is no winner!\n\n");
                        free(board.blocks);                             //free allocated memory
                        break;
                    }
                    if (turn == 1)  turn = 2;                            //alternate between players once per move
                    else turn = 1;
                }
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

