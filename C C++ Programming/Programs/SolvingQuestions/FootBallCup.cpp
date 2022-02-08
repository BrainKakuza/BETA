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

    /*
        total  j:         a            b             c            d
        i :score
          :totalkick
          :numberkick
          :order          0            1             2            3

    */

    for (int i = 0; i < 4; i++)
    {
        cin >> teams[i];
        total[3][i] = i;
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
                    total[0][i] += 3;
                    int scoreI = scores[i][j] - scores[j][i];
                    int scoreJ = scores[j][i] - scores[i][j];
                    total[1][i] += scoreI;
                    total[1][j] += scoreJ;
                    total[2][i] += scores[i][j];
                }
                else if (scores[i][j] < scores[j][i])
                {
                    total[0][j] += 3;
                    int scoreI = scores[i][j] - scores[j][i];
                    int scoreJ = scores[j][i] - scores[i][j];
                    total[1][i] += scoreI;
                    total[1][j] += scoreJ;
                    total[2][j] += scores[j][i];
                }
                else if (scores[i][j] == scores[j][i])
                {
                    total[0][j] += 1;
                    total[0][i] += 1;
                    int scoreI = scores[i][j] - scores[j][i];
                    int scoreJ = scores[j][i] - scores[i][j];
                    total[1][i] += scoreI;
                    total[1][j] += scoreJ;
                    total[2][j] += scores[j][i];
                    total[2][i] += scores[i][j];
                }
            }
        }
    }

    cout << endl;

    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            if (total[0][i] > total[0][j])
            {
                int tempScore = total[0][i];
                int temptotal = total[1][i];
                int tempkick = total[2][i];
                int country = total[3][i];
                total[0][i] = total[0][j];
                total[1][i] = total[1][j];
                total[2][i] = total[2][j];
                total[3][i] = total[3][j];
                total[0][j] = tempScore;
                total[1][j] = temptotal;
                total[2][j] = tempkick;
                total[3][j] = country;
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            if(total[0][i] == total[0][j]){
                if(total[1][i] > total[1][j]){
                    int tempScore = total[0][i];
                    int temptotal = total[1][i];
                    int tempkick = total[2][i];
                    int country = total[3][i];
                    total[0][i] = total[0][j];
                    total[1][i] = total[1][j];
                    total[2][i] = total[2][j];
                    total[3][i] = total[3][j];
                    total[0][j] = tempScore;
                    total[1][j] = temptotal;
                    total[2][j] = tempkick;
                    total[3][j] = country;
                }else if(total[1][i] == total[1][j] && total[2][i] > total[2][j]){
                    int tempScore = total[0][i];
                    int temptotal = total[1][i];
                    int tempkick = total[2][i];
                    int country = total[3][i];
                    total[0][i] = total[0][j];
                    total[1][i] = total[1][j];
                    total[2][i] = total[2][j];
                    total[3][i] = total[3][j];
                    total[0][j] = tempScore;
                    total[1][j] = temptotal;
                    total[2][j] = tempkick;
                    total[3][j] = country;
                }
            }
        }
    }


    for (int i = 3; i >= 0; i--)
    {
        cout << teams[total[3][i]] << " " << total[0][i] << endl;
    }
    

    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cout << total[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // int tempScore = total[0][i];
    // int temptotal = total[1][i];           
    // int tempkick = total[2][i];
    // int country = total[3][i];
    // total[0][i] = total[0][j];
    // total[1][i] = total[1][j];
    // total[2][i] = total[2][j];
    // total[3][i] = total[3][j];
    // total[0][j] = tempScore;
    // total[1][j] = temptotal;
    // total[2][j] = tempkick;
    // total[3][j] = country;

    
    

    return 0;
}