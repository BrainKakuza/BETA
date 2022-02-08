#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void)
{
    /*
        The hill question
    */
    int input, maxHeigth, i = -1, counter = 0, max = 0;

    cin >> input;

    if (input % 2 == 0)
    {
        while (counter != input)
        {
            if (counter < (input / 2))
            {
                i++;
            }
            else if (counter > (input / 2))
            {
                i--;
            }

            cout << i << endl;

            if (i > max)
            {
                max = i;
            }
            counter++;
        }
    }
    else if (input % 2 != 0)
    {
        while (counter != input)
        {
            if (counter < (input / 2) + 1)
            {
                i++;
            }
            else if (counter > (input / 2) + 1)
            {
                i--;
            }else{
                i--;
            }

            cout << i << endl;

            if (i > max)
            {
                max = i;
            }
            counter++;
        }
    }

    cout << "Output: " << max << endl;

    return 0;
}