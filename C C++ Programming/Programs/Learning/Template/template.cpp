#include<iostream>

using namespace std;

template <typename T>
//Note each T variable mean each uniques variable we can't have one T as a double and char


void showStuff(int one , T two , T three)
{
    cout << one << " " << two << " " << three << endl;
}

int main()
{
    showStuff(2, 3.3 , 4.4);
   
    return 0;
}