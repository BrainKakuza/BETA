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
    float result = 0;

    cin >> input;

    int numbers[input * 2];

    for (int i = 0; i < input * 2; i++)
    {
        cin >> numbers[i];
    }

    // for (int i = 0; i < input * 2; i++)
    // {
    //     cout << numbers[i] << endl;
    // }

    for (int i = 0; i < input * 2; i += 2)
    {
        if(i == (input * 2) - 2){
            result += numbers[i] * numbers[1];
            //cout << numbers[i] << " " << numbers[1] << endl;
        }else{
            result += numbers[i] * numbers[i + 3];
            //cout << numbers[i] << " " << numbers[i + 3] << endl;
        } 

        //cout << result << endl;
    }

    cout << result << endl;

    for (int i = 1; i < input * 2; i += 2)
    {
        if(i == (input * 2) - 1){
            result -= numbers[i] * numbers[0];
            //cout << numbers[i] << " " << numbers[1] << endl;
        }else{
            result -= numbers[i] * numbers[i + 1];
            //cout << numbers[i] << " " << numbers[i + 3] << endl;
        } 

        cout << result << endl;
    }

    // cout << result << endl;
    
    result = abs(result) / 2;

    cout << result << endl;

    
    



    return 0;
}