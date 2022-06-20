#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
const int inf = 0xfffffff;
typedef long long ll;
using namespace std;

const int S = 15;
char a[S][S][S], b[S][S][S];
int N, x, y, z;

void chag(int i, int j, int k, int l)
{
    if (j == 0)
    {
        x = i;
        y = k;
        z = l;
    }
    if (j == 1)
    {
        x = i;
        y = l;
        z = N - 1 - k;
    }
    if (j == 2)
    {
        x = i;
        y = N - 1 - k;
        z = N - 1 - l;
    }
    if (j == 3)
    {
        x = i;
        y = N - 1 - l;
        z = k;
    }
    if (j == 4)
    {
        x = l;
        y = k;
        z = N - 1 - i;
    }
    if (j == 5)
    {
        x = N - 1 - l;
        y = k;
        z = i;
    }
}
void init()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
                a[i][j][k] = '#';
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            for (int k = 0; k < N; k++)
            {
                scanf("%c", &b[i][j][k]);
                if (b[i][j][k] == '.')
                {
                    for (int l = 0; l < N; l++)
                    {
                        chag(i, j, k, l);
                        a[x][y][z] = '.';
                    }
                }
            }
            getchar();
        }
    }
}

void solve()
{
    while (1)
    {
        int test = true;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                for (int k = 0; k < N; k++)
                {
                    if (b[i][j][k] != '.')
                    {
                        for (int l = 0; l < N; l++)
                        {
                            chag(i, j, k, l);
                            if (a[x][y][z] == '.')
                                continue;
                            if (a[x][y][z] == '#')
                                a[x][y][z] = b[i][j][k];
                            if (a[x][y][z] == b[i][j][k])
                                break;
                            a[x][y][z] = '.';
                            test = false;
                        }
                    }
                }
            }
        }
        if (test)
            break;
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if (a[i][j][k] != '.')
                    ans++;
            }
        }
    }
    printf("Maximum weight: %d gram(s)\n", ans);
}

int main()
{
    // freopen("in", "r", stdin);
    while (~scanf("%d%*c", &N))
    {
        if (N == 0)
            break;
        init();
        solve();
    }
    return 0;
}