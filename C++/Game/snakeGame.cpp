#include <iostream>
#include <windows.h>
#include <time.h>
#include <conio.h>
using namespace std;
bool gameOver;
int score, x, y, width, height, fruitX, fruitY, tailX[100], tailY[100];
enum direction
{
    STOP,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
direction dir = STOP;
void Setup()
{
    srand(time(NULL));
    gameOver = false;
    score = 0;
    width = 40;
    height = 20;
    fruitX = rand() % width;
    fruitY = rand() % height;
label:
    if (fruitX <= 0 || fruitX >= width || fruitY <= 0 || fruitY >= height)
    {
        fruitX = rand() % width;
        fruitY = rand() % height;
        goto label;
    }
    
    x = width / 2;
    y = height / 2;
}
void Draw()
{
    for (int i = 0; i <= height; i++)
    {
        for (int j = 0; j <= width; j++)
        {
            if (i == 0 || i == height || j == 0 || j == width)
            {
                cout << "#";
            }
            else if (i == y && j == x)
            {
                cout << "O";
            }
            else if (i == fruitY && j == fruitX)
            {
                cout << "F";
            }
            else
            {
                bool print = false;
                for (int k = 0; k < score; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
    cout << "\nScore : " << (score * 10);
}
void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 'x':
            dir = STOP;
            break;
        case 'q':
            gameOver = true;
            break;
        default:
            break;
        }
    }
}
void Logic()
{
    int prevX = tailX[0], prevY = tailY[0], prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < score; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
    if (x < 0 || x > width || y < 0 || y > height)
    {
        gameOver = true;
    }
    if (fruitX == x && fruitY == y)
    {
        score += 1;
        fruitX = rand() % width;
        fruitY = rand() % height;
    label:
        if (fruitX <= 0 || fruitX >= width || fruitY <= 0 || fruitY >= height)
        {
            fruitX = rand() % width;
            fruitY = rand() % height;
            goto label;
        }
    }
}
int main()
{
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(50);
        system("cls");
    }
    cout << "\t\t\tScore = " << score * 10;
    cout << "\n\n\n\t\t\tGAME OVER";
    getchar();
    return 0;
}