#include <iostream>
#include <cstring>
using namespace std;
int min(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}
int main()
{
    int code[1001], guess[1001], same[10], a[10], b[10];
    int n, sn, dn, g = 1;
    while (cin >> n)
    {
        if (n == 0)
            break;
        cout << "Game " << g++ << ":" << endl;
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++)
        {
            cin >> code[i];
            a[code[i]]++;
        }

        while (1)
        {
            memset(b, 0, sizeof(b));
            memset(same, 0, sizeof(same));
            sn = 0;
            dn = 0;
            for (int i = 0; i < n; i++)
            {
                cin >> guess[i];
                b[guess[i]]++;
            }

            if (guess[0] == 0)
                break;
            for (int i = 0; i < n; i++)
            {
                if (code[i] == guess[i])
                {
                    same[code[i]]++;
                }
            }

            for (int i = 1; i < 10; i++)
            {
                sn = sn + same[i];
                dn = dn + min(a[i], b[i]) - same[i];
            }

            cout << "(" << sn << "," << dn << ")" << endl;
        }
    }
}