#include <stdio.h>
#include <stdlib.h>

char square[10] = {
    '0',
    '1', '2', '3',
    '4', '5', '6',
    '7', '8', '9'};

int choice, player;

int checkForWin();
void displayBoard();
void markBoard(char mark);
void showMenu();
void resetBoard();

void showMenu()
{
    system("cls||clear");
    printf("\n");
    printf("\t======================================\n");
    printf("\t|        TIC  TAC  TOE  GAME         |\n");
    printf("\t======================================\n");
    printf("\t|                                    |\n");
    printf("\t|     [1]  Start New Game            |\n");
    printf("\t|     [2]  How to Play               |\n");
    printf("\t|     [3]  Exit                      |\n");
    printf("\t|                                    |\n");
    printf("\t======================================\n");
    printf("\n\t  Enter your choice: ");
}

void resetBoard()
{
    for (int i = 1; i <= 9; i++)
        square[i] = '0' + i;
}

int main(int argc, char const *argv[])
{
    int menuChoice;

    while (1)
    {
        showMenu();
        scanf("%d", &menuChoice);

        if (menuChoice == 1)
        {
            // start a new round
            int gameStatus;
            char mark;
            resetBoard();
            player = 1;

            do
            {
                displayBoard();

                // odd player value = P1's turn, even = P2's turn
                player = (player % 2) ? 1 : 2;

                printf("\n\t  [ PLAYER %d ] Enter a number [1-9]: ", player);
                scanf("%d", &choice);

                mark = (player == 1) ? 'X' : 'O';
                markBoard(mark);

                gameStatus = checkForWin();
                player++;

            } while (gameStatus == -1);

            displayBoard();

            if (gameStatus == 1)
            {
                printf("\n\t  ==============================\n");
                printf("\t    PLAYER %d WINS! Well played!\n", --player);
                printf("\t  ==============================\n\n");
            }
            else
            {
                printf("\n\t  ==============================\n");
                printf("\t     GAME DRAW! Nobody wins.\n");
                printf("\t  ==============================\n\n");
            }

            printf("\t  Press Enter to return to menu...");
            getchar();
            getchar();
        }
        else if (menuChoice == 2)
        {
            // just print the rules, no game state involved
            system("cls||clear");
            printf("\n");
            printf("\t======================================\n");
            printf("\t|          HOW TO PLAY               |\n");
            printf("\t======================================\n");
            printf("\t|                                    |\n");
            printf("\t|  1. Two players take turns.        |\n");
            printf("\t|     Player 1 is  X                 |\n");
            printf("\t|     Player 2 is  O                 |\n");
            printf("\t|  3. Pick a number (1-9) to         |\n");
            printf("\t|     place your mark on the board.  |\n");
            printf("\t|  4. First to get 3 in a row        |\n");
            printf("\t|     (horizontal, vertical, or      |\n");
            printf("\t|      diagonal) wins!               |\n");
            printf("\t|  5. If all spots filled and no     |\n");
            printf("\t|     winner, it's a draw.           |\n");
            printf("\t|                                    |\n");
            printf("\t======================================\n\n");
            printf("\t  Press Enter to go back...");
            getchar();
            getchar();
        }
        else if (menuChoice == 3)
        {
            // break out of the main loop, program ends after this
            system("cls||clear");
            printf("\n\t  Thanks for playing! Goodbye.\n\n");
            break;
        }
        else
        {
            printf("\n\t  Invalid choice! Try again.\n");
            getchar();
            getchar();
        }
    }

    return 0;
}

// 1 = someone won, 0 = draw, -1 = game still in progress
int checkForWin()
{
    int returnValue;

    // rows
    if (square[1] == square[2] && square[2] == square[3])
        returnValue = 1;
    else if (square[4] == square[5] && square[5] == square[6])
        returnValue = 1;
    else if (square[7] == square[8] && square[8] == square[9])
        returnValue = 1;

    // columns
    else if (square[1] == square[4] && square[4] == square[7])
        returnValue = 1;
    else if (square[2] == square[5] && square[5] == square[8])
        returnValue = 1;
    else if (square[3] == square[6] && square[6] == square[9])
        returnValue = 1;

    // diagonals
    else if (square[1] == square[5] && square[5] == square[9])
        returnValue = 1;
    else if (square[3] == square[5] && square[5] == square[7])
        returnValue = 1;

    // no win found and every cell has been overwritten -> draw
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' &&
             square[7] != '7' && square[8] != '8' && square[9] != '9')
        returnValue = 0;
    else
        returnValue = -1;

    return returnValue;
}

void displayBoard()
{
    system("cls||clear");
    printf("\n");
    printf("\t======================================\n");
    printf("\t|        TIC  TAC  TOE  GAME         |\n");
    printf("\t======================================\n");
    printf("\t|   PLAYER-1 [X]   PLAYER-2 [O]     |\n");
    printf("\t======================================\n\n");

    printf("\t\t     |     |     \n");
    printf("\t\t  %c  |  %c  |  %c  \n", square[1], square[2], square[3]);
    printf("\t\t_____|_____|_____\n");
    printf("\t\t     |     |     \n");
    printf("\t\t  %c  |  %c  |  %c  \n", square[4], square[5], square[6]);
    printf("\t\t_____|_____|_____\n");
    printf("\t\t     |     |     \n");
    printf("\t\t  %c  |  %c  |  %c  \n", square[7], square[8], square[9]);
    printf("\t\t     |     |     \n");
}

void markBoard(char mark)
{
    if (choice == 1 && square[1] == '1')
        square[1] = mark;
    else if (choice == 2 && square[2] == '2')
        square[2] = mark;
    else if (choice == 3 && square[3] == '3')
        square[3] = mark;
    else if (choice == 4 && square[4] == '4')
        square[4] = mark;
    else if (choice == 5 && square[5] == '5')
        square[5] = mark;
    else if (choice == 6 && square[6] == '6')
        square[6] = mark;
    else if (choice == 7 && square[7] == '7')
        square[7] = mark;
    else if (choice == 8 && square[8] == '8')
        square[8] = mark;
    else if (choice == 9 && square[9] == '9')
        square[9] = mark;
    else
    {
        printf("\n\t  Invalid input! Spot taken or out of range.\n");
        printf("\t  Press Enter to try again...");
        getchar();
        getchar();
        // main() always does player++ after this call, so undo it here
        // to make the same player try again instead of skipping their turn
        player--;
    }
}
