#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    float var;
    float input[100];
    int counter = 0;

    while (cin >> var)
    {
        input[counter++] = var;
    }

    for (int i = 0; i < counter; i++)
    {
         cout << fixed << setprecision(3) << round(input[i] * 1000) / 1000 << endl;
    }
    
    return 0;
}