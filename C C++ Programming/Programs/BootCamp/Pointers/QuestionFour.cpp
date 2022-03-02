#include <iostream>
#include <cstring>

//Add these for smartpointer
#include <memory>
#include <utility>

using namespace std;

void factorial(int * ptr , int num);

int main(void)
{
    int num;
    cin >> num;
    int * ptr = &num;

    factorial(ptr , num);

    return 0;
}

void factorial(int *ptr , int num){
    cout << *ptr << endl;
    for (int i = 1; i < num; i++)
    {
        *ptr = *ptr * i;
    }

    cout << *ptr << endl;
    
}