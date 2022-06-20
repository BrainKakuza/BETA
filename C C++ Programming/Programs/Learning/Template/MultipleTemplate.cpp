#include<iostream>

using namespace std;

template <class T1 , class T2 , class T3>

void showStuff(T1 one , T2 two , T3 three)
{
    cout << one << " " << two << " " << three << endl;
}

int main()
{
    showStuff(2, 3.3 , 'c');
   
    return 0;
}