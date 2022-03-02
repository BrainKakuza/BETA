#include <iostream>
#include <cstring>

#define SIZE 5

using namespace std;

int *func(int *var)
{
    *var *= 10;
    return var;
}

void st(char *str)
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << str[i];
    }
}

int main(void)
{
    int var = 10;
    char *ch = new char[SIZE];
    
    for (int i = 0; i < SIZE; i++)
    {
        ch[i] = 'A' + i;
    }
    
    int *varPtr = &var;

    func(varPtr);
    cout << *varPtr << endl;

    st(ch);

    return 0;
}