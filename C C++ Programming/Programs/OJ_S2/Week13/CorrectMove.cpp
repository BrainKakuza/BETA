#include <iostream>

using namespace std;

/*
numberAvailable
- 0 (free)
- 1 (king)
- 2(queen)
- 3(king path)
- 4(queen path)
- 5(interfere path)
- 6 (new queen spot)
- 7 (new queen path)
*/

int numberSpot[8][8];
int numberAvailable[8][8];

class board
{
public:
};

int main()
{
    int king, queen, newQueen, spotI, spotJ, spotKI, spotKJ;

    while (cin >> king >> queen >> newQueen)
    {
        int num = 0;
        
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                numberSpot[i][j] = num;
                numberAvailable[i][j] = 0;
                num++;
            }
        }

        if (king == queen)
        {
            cout << "Illegal state" << endl;
        }
        else
        {
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (numberSpot[i][j] == king)
                    {
                        spotKI = i;
                        spotKJ = j;

                        numberAvailable[i][j] = 1;

                        if (numberAvailable[i][j - 1] == 0 && j - 1 >= 0)
                        {
                            numberAvailable[i][j - 1] = 3;
                        }

                        if (numberAvailable[i][j + 1] == 0 && j + 1 < 8)
                        {
                            numberAvailable[i][j + 1] = 3;
                        }

                        if (numberAvailable[i + 1][j] == 0 && i + 1 < 8)
                        {
                            numberAvailable[i + 1][j] = 3;
                        }

                        if (numberAvailable[i - 1][j] == 0 && i - 1 >= 0)
                        {
                            numberAvailable[i - 1][j] = 3;
                        }
                    }
                }
            }

            // for (int i = 0; i < 8; i++)
            // {
            //     for (int j = 0; j < 8; j++)
            //     {
            //         cout << numberAvailable[i][j] << " ";
            //     }
            //     cout << endl;
            // }

            // cout << endl;

            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (numberSpot[i][j] == queen)
                    {
                        numberAvailable[i][j] = 2;

                        for (int k = j + 1; k < 8; k++)
                        {
                            if (numberAvailable[i][k] == 1)
                            {
                                break;
                            }
                            else if (numberAvailable[i][k] == 3)
                            {
                                numberAvailable[i][k] = 5;
                            }
                            else
                            {
                                numberAvailable[i][k] = 4;
                            }
                        }

                        for (int k = j - 1; k >= 0; k--)
                        {
                            if (numberAvailable[i][k] == 1)
                            {
                                break;
                            }
                            else if (numberAvailable[i][k] == 3)
                            {
                                numberAvailable[i][k] = 5;
                            }
                            else
                            {
                                numberAvailable[i][k] = 4;
                            }
                        }

                        for (int k = i + 1; k < 8; k++)
                        {
                            if (numberAvailable[k][j] == 1)
                            {
                                break;
                            }
                            else if (numberAvailable[k][j] == 3)
                            {
                                numberAvailable[k][j] = 5;
                            }
                            else
                            {
                                numberAvailable[k][j] = 4;
                            }
                        }

                        for (int k = i - 1; k >= 0; k--)
                        {
                            if (numberAvailable[k][j] == 1)
                            {
                                break;
                            }
                            else if (numberAvailable[k][j] == 3)
                            {
                                numberAvailable[k][j] = 5;
                            }
                            else
                            {
                                numberAvailable[k][j] = 4;
                            }
                        }
                    }
                }
            }

            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (numberSpot[i][j] == newQueen)
                    {
                        spotI = i;
                        spotJ = j;
                    }
                }
            }

            // for (int i = 0; i < 8; i++)
            // {
            //     for (int j = 0; j < 8; j++)
            //     {
            //         cout << numberAvailable[i][j] << " ";
            //     }
            //     cout << endl;
            // }

            // cout << endl;

            if (numberAvailable[spotI][spotJ] == 0 || numberAvailable[spotI][spotJ] == 1 || numberAvailable[spotI][spotJ] == 2 || numberAvailable[spotI][spotJ] == 3)
            {
                cout << "Illegal move" << endl;
            }
            else if (numberAvailable[spotI][spotJ] == 5)
            {
                cout << "Move not allowed" << endl;
            }
            else if (numberAvailable[spotI][spotJ] == 4)
            {
                numberAvailable[spotI][spotJ] = 6;

                for (int k = spotJ + 1; k < 8; k++)
                {
                    if (numberAvailable[spotI][k] == 1)
                    {
                        break;
                    }
                    else
                    {
                        numberAvailable[spotI][k] = 7;
                    }
                }

                for (int k = spotJ - 1; k >= 0; k--)
                {
                    if (numberAvailable[spotI][k] == 1)
                    {
                        break;
                    }
                    else
                    {
                        numberAvailable[spotI][k] = 7;
                    }
                }

                for (int k = spotI + 1; k < 8; k++)
                {
                    if (numberAvailable[k][spotJ] == 1)
                    {
                        break;
                    }
                    else
                    {
                        numberAvailable[k][spotJ] = 7;
                    }
                }

                for (int k = spotI - 1; k >= 0; k--)
                {
                    if (numberAvailable[k][spotJ] == 1)
                    {
                        break;
                    }
                    else
                    {
                        numberAvailable[k][spotJ] = 7;
                    }
                }

                // for (int i = 0; i < 8; i++)
                // {
                //     for (int j = 0; j < 8; j++)
                //     {
                //         cout << numberAvailable[i][j] << " ";
                //     }
                //     cout << endl;
                // }

                // cout << endl;

                if (
                    (numberAvailable[spotKI][spotKJ + 1] == 3 && spotKJ + 1 < 8) ||
                    (numberAvailable[spotKI][spotKJ - 1] == 3 && spotKJ - 1 >= 0) ||
                    (numberAvailable[spotKI + 1][spotKJ] == 3 && spotKI + 1 < 8) ||
                    (numberAvailable[spotKI - 1][spotKJ] == 3 && spotKI - 1 >= 0))
                {
                    cout << "Continue" << endl;
                }
                else
                {
                    cout << "Stop" << endl;
                }
            }
        }
    }

    return 0;
}