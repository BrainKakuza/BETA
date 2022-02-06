#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <algorithm>

using std::cout;
using std::string;
using std::endl;
using std::cin;
using std::sort;

int array[4];

int main(){

    int array[4];
    for (int i = 0; i < 4; i++)
    {
        cin >> array[i];
    }

    sort(array+4, array);

    cout << "hello" << endl;
    
    
    return 0;
}