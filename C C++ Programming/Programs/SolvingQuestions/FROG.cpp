#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
    int jump, distance, times = 0, counter = 0;
    int i = 1;
    cin >> jump >> distance;
    if (jump == 0)
    {

        cout << "0" << endl;
    }
    else if (jump > distance)
    {
        cout << "1" << endl;
    }
    else
    {

        while (times < distance)
        {
            times += jump;
            counter++;
        }
        cout << counter << endl;
    }

    return 0;
}