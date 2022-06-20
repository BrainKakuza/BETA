#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int a , b;
    int squareNum = 0;

    while (1)
    {
        cin >> a >> b;

        if(a == 0 && b == 0)
        {
            break;
        }

        for (int i = a; i <= b; i++)
        {
            double square = sqrt(i);
            if(square - floor(square) == 0)
            {
                squareNum++;
            }
        }

        cout << squareNum << endl;
        
        squareNum = 0;

    }

    return 0;
}