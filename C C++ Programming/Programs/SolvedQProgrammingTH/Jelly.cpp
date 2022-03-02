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
    int side[3] , counter = 0;

    cin >> side[0] >> side[1] >> side[2];

    while (side[0] != 1 || side[1] != 1 || side[2] != 1)
    {
        int max = side[0] , i = 0;

        if(max < side[1]){
            max = side[1];
            i = 1;
        }else if(max < side[2]){
            max = side[2];
            i = 2;
        }

        if(max % 2 != 0){
            max -= 1;
        }

        side[i] = max / 2;
        counter++;
    }

    cout << counter << endl;

    return 0;
}