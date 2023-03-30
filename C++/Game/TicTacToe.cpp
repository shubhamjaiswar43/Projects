#include <iostream>
#include <vector>
#include <map>
using namespace std;
/*
 0 | 1 | 2
-----------
 3 | 4 | 5
-----------
 6 | 7 | 8
win: 012,345,678,036,147,258,048,246
*/
void playingBoard(vector<char> v)
{
    cout << " " << v[0] << " |";
    cout << " " << v[1] << " |";
    cout << " " << v[2];
    cout << endl
         << "-----------" << endl;
    cout << " " << v[3] << " |";
    cout << " " << v[4] << " |";
    cout << " " << v[5];
    cout << endl
         << "-----------" << endl;
    cout << " " << v[6] << " |";
    cout << " " << v[7] << " |";
    cout << " " << v[8];
    cout << endl;
}
int chkwin(vector<char> v)
{
    int win[8][3] = {0, 1, 2,
                     3, 4, 5,
                     6, 7, 8,
                     0, 3, 6,
                     1, 4, 7,
                     2, 5, 8,
                     0, 4, 8,
                     2, 4, 6};
    for (int i = 0; i < 8; i++)
    {
        if (v[(win[i][0])] == v[(win[i][1])] && v[(win[i][1])] == v[(win[i][2])])
        {
            if (v[(win[i][0])] == 'O')
            {
                return 1;
            }
            else if (v[(win[i][0])] == 'X')
            {
                return 2;
            }
        }
    }
    return 0;
}
int main()
{
    vector<char> game;
    map<int, int> mapp;
    map<int, int>::iterator iter;
    for (int i = 0; i < 9; i++)
    {
        game.push_back(i + 49);
    }
    playingBoard(game);
    int turn;
    for (int i = 0; i < 9; i++)
    {
        if (i % 2 == 0)
        {
        player1turn:
            cout << "Player 1 turn's : ";
            cin >> turn;
            if (turn > 9 || turn <= 0)
            {
                cout << "Invalid Entry...." << endl
                     << "Try Again..." << endl;
                goto player1turn;
            }
            iter = mapp.find(turn);
            if (iter == mapp.end())
            {
                mapp[turn] = turn;
            }
            else
            {
                cout << "The Entered placed is already taken...." << endl
                     << "Try Again..." << endl;
                goto player1turn;
            }

            game[turn - 1] = 'O';
        }
        else
        {
        player2turn:
            cout << "Player 2 turn's : ";
            cin >> turn;
            if (turn > 9 || turn <= 0)
            {
                cout << "Invalid Entry...." << endl
                     << "Try Again..." << endl;
                goto player2turn;
            }
            iter = mapp.find(turn);
            if (iter == mapp.end())
            {
                mapp[turn] = turn;
            }
            else
            {
                cout << "The Entered placed is already taken...." << endl
                     << "Try Again..." << endl;
                goto player2turn;
            }

            game[turn - 1] = 'X';
        }
        playingBoard(game);
        if (chkwin(game) == 1)
        {
            cout << "******Player1 win the Game******" << endl;
            cout << "GAME OVER";
            return 0;
        }

        else if (chkwin(game) == 2)
        {
            cout << "******Player2 win the Game******" << endl;
            cout << "GAME OVER";
            return 0;
        }
    }

    cout << "No One Win's" << endl
         << "GAME OVER" << endl;
    return 0;
}