#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string teams[4];
    int scores[4][4];
    int total[4][4] = {0};

    for (int i = 0; i < 4; i++)
    {
        cin >> teams[i];
        total[i][3] = i;
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> scores[i][j];
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            if (i != j)
            {
                if (scores[i][j] > scores[j][i])
                {
                    // totalscore
                    total[i][0] += 3;
                    // kickIn getkicked team I
                    total[i][1] += scores[i][j];
                    total[i][2] += scores[j][i];
                    // kickIn getKicked tema J
                    total[j][1] += scores[j][i];
                    total[j][2] += scores[i][j];
                }
                else if (scores[i][j] < scores[j][i])
                {
                    // totalscore
                    total[j][0] += 3;
                    // kickIn getkicked team I
                    total[i][1] += scores[i][j];
                    total[i][2] += scores[j][i];
                    // kickIn getKicked team J
                    total[j][1] += scores[j][i];
                    total[j][2] += scores[i][j];
                }
                else if (scores[i][j] == scores[j][i])
                {
                    // totalscore
                    total[i][0] += 1;
                    total[j][0] += 1;
                    // kickIn getkicked team I
                    total[i][1] += scores[i][j];
                    total[i][2] += scores[j][i];
                    // kickIn getKicked team J
                    total[j][1] += scores[j][i];
                    total[j][2] += scores[i][j];
                }
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            if (total[i][0] > total[j][0])
            {
                int tempScore = total[i][0];
                int temptotal = total[i][1];
                int tempkick = total[i][2];
                int country = total[i][3];
                total[i][0] = total[j][0];
                total[i][1] = total[j][1];
                total[i][2] = total[j][2];
                total[i][3] = total[j][3];
                total[j][0] = tempScore;
                total[j][1] = temptotal;
                total[j][2] = tempkick;
                total[j][3] = country;
            }
            else if (total[i][0] == total[j][0])
            {
                int scoreI = total[i][1] - total[i][2];
                int scoreJ = total[j][1] - total[j][2];

                if (scoreI > scoreJ)
                {
                    int tempScore = total[i][0];
                    int temptotal = total[i][1];
                    int tempkick = total[i][2];
                    int country = total[i][3];
                    total[i][0] = total[j][0];
                    total[i][1] = total[j][1];
                    total[i][2] = total[j][2];
                    total[i][3] = total[j][3];
                    total[j][0] = tempScore;
                    total[j][1] = temptotal;
                    total[j][2] = tempkick;
                    total[j][3] = country;
                }
                else if (scoreI == scoreJ)
                {
                    if (total[i][1] > total[j][1])
                    {
                        int tempScore = total[i][0];
                        int temptotal = total[i][1];
                        int tempkick = total[i][2];
                        int country = total[i][3];
                        total[i][0] = total[j][0];
                        total[i][1] = total[j][1];
                        total[i][2] = total[j][2];
                        total[i][3] = total[j][3];
                        total[j][0] = tempScore;
                        total[j][1] = temptotal;
                        total[j][2] = tempkick;
                        total[j][3] = country;
                    }
                }
            }
        }
    }

    for (int i = 3; i >= 0; i--)
    {
        cout << teams[total[i][3]] << " " << total[i][0] << endl;
    }

    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cout << total[i][j] << " ";
    //     }
    //     cout << endl;
    // }

   

    return 0;
}