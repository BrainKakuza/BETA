#include <iostream>

using namespace std;

char board[2][9][9];
// board[0] == black (the main one)
// board[1] == white
int blackNum = 0;
int whiteNum = 0;

class GAME
{
public:
    void Input();
    void SpaceDetermine(int i, int j, int color);
    void SpaceDetect(int i, int j);
    void ScoreCount();
    void FinalCount();
    void printScore();
};

void GAME::Input()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[0][i][j];
            board[1][i][j] = board[0][i][j];
        }
    }
}

void GAME::SpaceDetermine(int i, int j, int color)
{
    board[color][i][j] = '1';

    if (board[color][i][j + 1] == '.' && j < 8)
    {
        SpaceDetermine(i, j + 1, color);
    }

    if (board[color][i][j - 1] == '.' && j > 0)
    {
        SpaceDetermine(i, j - 1, color);
    }

    if (board[color][i + 1][j] == '.' && i < 8)
    {
        SpaceDetermine(i + 1, j, color);
    }

    if (board[color][i - 1][j] == '.' && i > 0)
    {
        SpaceDetermine(i - 1, j, color);
    }
}

void GAME::SpaceDetect(int i, int j)
{
    if (
        ((board[0][i][j + 1] == 'X' || board[0][i][j + 1] == '1') && j < 8) ||
        ((board[0][i][j - 1] == 'X' || board[0][i][j - 1] == '1') && j > 0) ||
        ((board[0][i + 1][j] == 'X' || board[0][i + 1][j] == '1') && i < 8) ||
        ((board[0][i - 1][j] == 'X' || board[0][i - 1][j] == '1') && i > 0))
    {
        SpaceDetermine(i, j, 0);
    }

    if (
        ((board[1][i][j + 1] == 'O' || board[1][i][j + 1] == '1') && j < 8) ||
        ((board[1][i][j - 1] == 'O' || board[1][i][j - 1] == '1') && j > 0) ||
        ((board[1][i + 1][j] == 'O' || board[1][i + 1][j] == '1') && i < 8) ||
        ((board[1][i - 1][j] == 'O' || board[1][i - 1][j] == '1') && i > 0))
    {
        SpaceDetermine(i, j, 1);
    }
}

void GAME::ScoreCount()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[0][i][j] == 'X')
            {
                blackNum++;
            }
            else if (board[0][i][j] == 'O')
            {
                whiteNum++;
            }
            else if (board[0][i][j] == '.' || board[1][i][j] == '.')
            {
                SpaceDetect(i,j);
            }
        }
    }
}

void GAME::FinalCount()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[0][i][j] == '1' && board[1][i][j] == '.')
            {
                blackNum++;
            }
            else if (board[0][i][j] == '.' && board[1][i][j] == '1')
            {
                whiteNum++;
            }
            else if (board[0][i][j] == '1' && board[1][i][j] == '1')
            {
            }
            // cout << blackNum << " " << whiteNum << " " << i << " " << j << endl;
        }
    }
}

void GAME::printScore()
{
    cout << "Black " << blackNum << " "
         << "White " << whiteNum << endl;
}

int main()
{
    GAME game;
    int input;
    cin >> input;

    for (int i = 0; i < input; i++)
    {
        game.Input();
        game.ScoreCount();

        // cout << endl;

        // cout << blackNum << " " << whiteNum << endl;

        // cout << endl;

        // cout << "BLACK" << endl;
        // for (int i = 0; i < 9; i++)
        // {
        //     for (int j = 0; j < 9; j++)
        //     {
        //         cout << board[0][i][j];
        //     }
        //     cout << endl;
        // }

        // cout << endl;

        // cout << "WHITE" << endl;
        // for (int i = 0; i < 9; i++)
        // {
        //     for (int j = 0; j < 9; j++)
        //     {
        //         cout << board[1][i][j];
        //     }
        //     cout << endl;
        // }

        game.FinalCount();
        game.printScore();

        blackNum = 0;
        whiteNum = 0;
    }

    return 0;
}