// This Code is created on Code-Blocks IDE

#include <bits/stdc++.h>
//#include <iostream>
//#include<cstdlib>
//#include<cstdio>

using namespace std;

char sq[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int board();
int checkwin();

int main()
{
    char mark;
    int player = 1, i, choice;

    do
    {
        board(); //to show current board
        cout << "\n";

        player = player % 2 ? 1 : 2;
        printf("Player %d, Enter your move :-  ", player); //asking user to give input
        cin >> choice;                                     //getting input

        mark = (player % 2) ? 'X' : 'O';
        char ch = choice + 48;

        if (choice <= 9 && choice >= 1 && sq[choice] == ch)
            sq[choice] = mark;
        else
        {
            cout << "Invalid Move, Press any key to continue ";

            getchar(); //first will neutralize enter input
            getchar(); //second will neutralize the final key press.

            player--; //to neutralize the player++ which is gonna happen in further loop
        }

        i = checkwin(); //getting current status of game

        player++; //to change player who will move next

    } while (i == -1);

    board(); //to print final status of board

    if (i == 1)
        printf("==>\a Player %d wins!!\n", --player); //if someone win, message to let him know

    else
        printf("==> Game Draws\n"); //else game gets draws
}

/*******************************************************************
        FUNCTION TO RETURN GAME STATUS
--------------------------------------------------------------------
       1 FOR GAME IS OVER WITH RESULT
       -1 FOR GAME IS IN PROGRESS
       O GAME IS OVER AND NO RESULT
********************************************************************/
int checkwin()
{
    //checking horizontally
    for (int i = 1; i <= 9; i = i + 3)
    {
        if (sq[i] == sq[i + 1] && sq[i + 1] == sq[i + 2])
            return 1;
    }

    //checking vertically
    for (int i = 1; i <= 3; i = i + 1)
    {
        if (sq[i] == sq[i + 3] && sq[i + 3] == sq[i + 6])
            return 1;
    }

    //checking diagonally
    if (sq[1] == sq[5] && sq[5] == sq[9])
        return 1;
    if (sq[3] == sq[5] && sq[5] == sq[7])
        return 1;

    //checking if we can take further input
    for (int i = 1; i <= 9; i++)
    {
        char c = i + 48;
        if (sq[i] == c)
            return -1;
    }

    //all possible moves are out and no player is winning so the situation is of draw
    return 0;
}

/*******************************************************************
FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
********************************************************************/
int board()
{
    system("cls");

    cout << "(C) 2020 KAPIL KUNGWANI" << endl;

    printf("\n\t\t ___________________________________\n"); // border start

    cout << "\t\t|                                   |\n"; //border

    cout << "\t\t|\t   "
         << "Tic-Tac-Toe              |\n"; //printing title

    cout << "\t\t|                                   |\n"; //border

    cout << "\t\t|   Player 1 (X)  -  Player 2 (O)   |\n\t\t|                                   |\n"; //printing simple info about player

    printf("\t\t|\t _________________          |\n"); //border

    //-----------------------------------------------------------------------------------------

    cout << "\t\t|\t|     |     |     |         |\n"; //matrix start

    cout << "\t\t|\t|  " << sq[1] << "  |  " << sq[2] << "  |  " << sq[3] << "  |         |\n";

    printf("\t\t|\t|_____|_____|_____|         |\n");

    cout << "\t\t|\t|     |     |     |         |\n";

    cout << "\t\t|\t|  " << sq[4] << "  |  " << sq[5] << "  |  " << sq[6] << "  |         |\n";

    printf("\t\t|\t|_____|_____|_____|         |\n");

    cout << "\t\t|\t|     |     |     |         |\n";

    cout << "\t\t|\t|  " << sq[7] << "  |  " << sq[8] << "  |  " << sq[9] << "  |         |\n";

    printf("\t\t|\t|_____|_____|_____|         |\n"); //matrix ends

    //------------------------------------------------------------------------

    cout << "\t\t|                                   |\n"; //border

    printf("\t\t|___________________________________|\n\n"); //border ending and last output print.
}
