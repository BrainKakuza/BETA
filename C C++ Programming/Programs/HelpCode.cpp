#include <iostream>
#include <string.h>
#include <cstring>
#include <string>
using namespace std;

bool uniqueCharacters(string str)
{
    for (int i = 0; i < str.length() - 1; i++)
    {
        for (int j = i + 1; j < str.length(); j++)
        {
            if (str[i] == str[j])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    string a, temp;
    getline(cin, a);
    int i, k, l, j;
    int col, high;
    string arr[a.size()][a.size()] = {};

    for (i = 0; i < a.size(); i++)
    {
        col = 0;
        for (k = i; k < a.size(); k++)
        {
            temp.clear();
            for (l = col; l < a.size(); l++)
            {
                temp = temp + a[l];
            }

            if (uniqueCharacters(temp) == 1)
            {
                arr[i][col] = temp;
            }

            col++;
        }
    }

    int q = a.size();
    int adjustQ = a.size();
    for (int i = 0; i < q; i++)
    {
        for (int j = 0; j < adjustQ; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
        adjustQ--;
    }

    high = 0;

    for (i = 0; i < a.size(); i++)
    {
        for (j = 0; j < a.size(); j++)
        {
            if ((arr[i][j].size()) >= high)
            {
                high = arr[i][j].size();
            }
        }
    }

    cout << high;
}