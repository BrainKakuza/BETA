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
    cout << firstL << " " << lastL << endl;

    if (op == "+")
    {
        if(firstL == lastL){
            cout << "2";
            firstL -= 1;
            ZEROS(&firstL);
        }else{
            if(firstL > lastL){
                firstL = (firstL - lastL) - 1;
                lastL -= 1;
                cout << "1";
                ZEROS(&firstL);
                cout << "1";
                ZEROS(&lastL);
            }

        }
    }

    return 0;
}

void ZEROS(int* length){
    for (int i = 0; i < *length; i++)
    {
        cout << "0";
    }
    
}