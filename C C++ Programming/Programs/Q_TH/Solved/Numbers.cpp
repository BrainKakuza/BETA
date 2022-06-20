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
    int input;
    bool first = true;
    cin >> input;
    int numbers[input];

    for (int i = 0; i < input; i++)
    {
        cin >> numbers[i];
    }

    for (int i = 0; i < input; i++)
    {
        for (int j = i + 1; j < input; j++)
        {
            if (numbers[i] > numbers[j])
            {
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

    for (int i = 0; i < input; i++)
    {
        if (numbers[i] != 0)
        {
            cout << numbers[i];
            numbers[i] = -1;
            break;
        }
    }

    for (int i = 0; i < input; i++)
    {
        if(numbers[i] != -1){
            cout << numbers[i];
        }
    }
        
    return 0;
}