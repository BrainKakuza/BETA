#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

int main()
{

    int day, month, totalDay = 0, i = 4;

    string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    cin >> day >> month;

    for (int j = 1; j < month; j++)
    {
        if(j <= 7){
            if (j % 2 == 0 && j != 2)
            {
                totalDay += 30;
            }
            else if (j % 2 != 0 || j == 8)
            {
                totalDay += 31;
            }
            else 
            {
            totalDay += 28;
            }
        }else if(j >= 8){
            if (j % 2 == 0 && j != 2)
            {
                totalDay += 31;
            }
            else if (j % 2 != 0 || j == 8)
            {
                totalDay += 30;
            }
        }
        
    }

    totalDay = totalDay % 7;

    while (totalDay >  0)
    {
        i++;
        if (i == 7)
        {
            i = 0;
        }
        totalDay--;
    }

    while (day > 1)
    {
        i++;
        if (i == 7)
        {
            i = 0;
        }
        day--;
    }

    cout << days[i] << endl;

    return 0;
}