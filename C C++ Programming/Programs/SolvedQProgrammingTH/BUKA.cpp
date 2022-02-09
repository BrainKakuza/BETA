#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

void ZEROS(int* length);

int main()
{
    string first, op, last;

    cin >> first >> op >> last;

    int firstL = first.length();
    int lastL = last.length();

    if (op == "+")
    {
        if(firstL == lastL){
            cout << "2";
            firstL -= 1;
            ZEROS(&firstL);
        }else{
            if(firstL > lastL){
                int bigger = firstL - lastL - 1;
                int smaller = lastL - 1;
                cout << "1";
                ZEROS(&bigger);
                cout << "1";
                ZEROS(&smaller);
            }else{
                int bigger = lastL - firstL - 1;
                int smaller = firstL - 1;
                cout << "1";
                ZEROS(&bigger);
                cout << "1";
                ZEROS(&smaller);
            }
        }
    }else{
        int howLong = abs(firstL + lastL - 2);
        cout << "1";
        ZEROS(&howLong);
        
    }

    return 0;
}

void ZEROS(int* length){
    for (int i = 0; i < *length; i++)
    {
        cout << "0";
    }
    
}