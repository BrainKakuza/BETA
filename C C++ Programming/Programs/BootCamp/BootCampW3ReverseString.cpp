#include <iostream>
#include <string>

using namespace std;

void reverse(int length, string input);
void swap(int *fArr, int *lArr, int length);
int add(int *num);

int main()
{
    /*Reverse a word*/

    // string input;
    // getline(cin , input);
    // int length = input.length();

    // reverse(length , input);

    /*Change swap numbers in array*/
    int fArr[] = {4, 5, 7, 7, 8, 9, 0, 6};
    int lArr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int length = sizeof(fArr) / sizeof(fArr[0]);

    swap(fArr, lArr, length);

    for (auto i : fArr)
    {
        cout << i;
    }

    cout << endl;

    for (auto i : lArr)
    {
        cout << i;
    }

    /*by referenence function test*/
    // int num = 1;
    // cout
    // add(&num);

    return 0;
}

void reverse(int length, string input)
{
    string back;

    for (int i = length - 1; i >= 0; i--)
    {
        back.push_back(input[i]);
    }

    for (auto k : back)
    {
        cout << k;
    }
    cout << endl;
}

void swap(int *fArr, int *lArr, int length)
{
    for (int i = 0; i < length; i++)
    {
        fArr[i] += lArr[i];
        lArr[i] = fArr[i] - lArr[i];
        fArr[i] -= lArr[i];
    }
}
