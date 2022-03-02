#include <iostream>
#include <cstring>

//Add these for smartpointer
#include <memory>
#include <utility>

using namespace std;

void func(int * ptr){
    cout << ptr << endl;
}

int main(void)
{
    int num;
    cin >> num;
    int *ptr = new int;
    ptr = &num;

    func(ptr);


    return 0;
}