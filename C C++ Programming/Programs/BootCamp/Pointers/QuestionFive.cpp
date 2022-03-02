#include <iostream>
#include <cstring>

//Add these for smartpointer
#include <memory>
#include <utility>

using namespace std;

int main(void)
{
    string number;
    cin >> number;
    char * reverse = new char[number.length()];
    int j = 0;

    for (int i = number.length() - 1; i >= 0; i--)
    {
        reverse[j] = number[i];
        j++; 
    }

    for (int i = 0; i <= number.length(); i++)
    {
        cout << reverse[i]; 
    }
    


    return 0;
}

