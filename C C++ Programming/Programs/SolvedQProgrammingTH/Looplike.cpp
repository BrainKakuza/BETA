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
    int input , l = 10001 , max = -1 , value;
    cin >> input;
    int comments[l] = {0};

    for (int i = 0; i < input; i++)
    {
        cin >> value;
        comments[value]++;
    }

    for (int i = 1; i < l; i++)
    {
        if(max < comments[i]){
            max = comments[i];
        }
    }
    
    for (int i = 1; i < l; i++)
    {
        if(max == comments[i]){
            cout << i << ' ';
        }
    }
    


    

    return 0;
}