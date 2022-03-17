#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string input;

    getline(cin , input);
    int lenght = input.length();

    int longestSub = 0;

    string array[lenght][lenght];

    for (int i = 0; i <= lenght; i++)
    {
        for (int j = 1; j <= lenght - i; j++)
        {
            bool notsame = true;
            int going = 1;
            
            string subString = input.substr(i, j);

            for (int m = 0; m < subString.length(); m++)
            {
                for (int n = m - 1; n >= 0; n--)
                {
                    if(subString[m] == subString[n])
                    {
                        notsame = false;
                        going = 0;
                        break;
                    }
                }

                 if(going == 0)
                {
                    break;
                }
            }
            
            if (notsame)
            {
                array[i][j - 1] = subString;
            }else
            {
                break;
            }

        }
    }

    for (int i = 0; i < lenght; i++)
    {
        for (int j = 0; j < lenght; j++)
        {
            string temp = array[i][j];

            if(temp.length() > longestSub)
            {
                longestSub = temp.length();
            }
        }
    }

    cout << longestSub << endl;

    return 0;
}
