#include <iostream>
#include <cstring>

//Add these for smartpointer
#include <memory>
#include <utility>

using namespace std;

int main(void)
{
    int *numbers = new int[5];
    int min = 10000, max = 0;

    for (int i = 0; i < 5; i++)
    {
        int temp;
        cin >> temp;
        numbers[i] = temp;
    }

    for (int i = 0; i < 5; i++)
    {
        if(numbers[i] > max){
            max = numbers[i];
        }

        if(numbers[i] < min){
            min = numbers[i];
        }
        
    }
    
    cout << "Max " << max << endl;
    cout << "Min " << min << endl; 

    
    

    
    return 0;
}