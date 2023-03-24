#include <stdio.h>
#include <string.h>
char board[10] = "123456789"; // board
int turn = 0;                 // 0 for player 1(X) and 1 for player 2(O);
int choice;                   // for position of X/O;
int arrC[9], n = 0;           // To Store Choice of the player and to check that it is not repeated;
int win = 0;
int op = 0;
void Board()
{
    printf("\n");
    for (int i = 0; i < 9; i += 3)
    {
        printf("%c | %c | %c\n", board[i], board[i + 1], board[i + 2]);
        if (i != 6)
            printf("----------\n");
    }
}
int chkPresent()
{
    for (int i = 0; i < n; i++)
    {
        if (arrC[i] == choice)
            return 1;
    }
    return 0;
}
void write()
{
    arrC[n] = choice;
    n++;
    if (turn)
        board[choice - 1] = 'X';

    else
        board[choice - 1] = 'O';
}
int cmp3Char(char x, char y, char z)
{
    if (x == y && y == z)
        return 1;
    return 0;
}
int chkWin()
{
    int winChoice[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6},
    };
    for (int i = 0; i < 8; i++)
    {
        if (cmp3Char(board[winChoice[i][0]], board[winChoice[i][1]], board[winChoice[i][2]]))
        {
            if (board[winChoice[i][0]] == 'X')
                return 1;
            else
                return 2;
        }
    }
    return 0;
}
int main()
{
Start:
    Board();
    for (int i = 0; i < 9; i++)
    {
    Choice:
        if (!turn)
        {
            printf("\nPlayer 1's Turn's : ");
            scanf("%d", &choice);
            turn = !turn;
        }
        else
        {

            printf("\nPlayer 2's Turn's : ");
            scanf("%d", &choice);
            turn = !turn;
        }
        if (choice > 9)
        {
            printf("Invalid Choice!!!\nTry Again...\n");
            turn = !turn;
            goto Choice;
        }
        if (chkPresent())
        {
            printf("It is already choiced....\nChoose Other Place....\n");
            turn = !turn;
            goto Choice;
        }
        write();
        Board();
        win = chkWin();
        if (win == 1)
        {
            printf("\n******** Player 1 Wins ***********\n");
            break;
        }
        if (win == 2)
        {
            printf("\n******** Player 2 Wins ***********\n");
            break;
        }
    }
    if (!win)
    {
        printf("\n************ Match Draw ********\n");
    }
    printf("\n\nEnter 1 for Replay and 0 for exit : ");
    scanf("%d", &op);
    if (op == 1)
        goto Start;
    return 0;
}