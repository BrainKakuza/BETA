#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    unsigned long long one , two , result;
    char command;

    cin >> one >> command >> two;

    if(command == '*'){
        result = one * two;
    }else if(command == '+'){
        result = one + two;
    }

    cout << result << endl;


    

    return 0;
}