#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

//#define size 5

int main(void)
{
    // Another way to write a for loop that will print all the data in the array
    //  int names[] = { 1,
    //                    2,
    //                    3,
    //                    4,
    //                    5 };

    // int idxCounter = 0;

    // for (auto i : names)
    // {
    //     cout << idxCounter++ <<". \t" << i << endl;
    //}

    // Example of array

    // string names[] = {"Mark" , "Harry" , "Maria" , "Carmen" , "Freddy"};
    // int index, counter = 0;
    // cout << "Index\tNames\n" << endl;
    // for (auto i : names)
    // {
    //     cout << counter++ << ". \t" << i << endl;
    // }
    // cout << "To Access an element please enter the indes: ";
    // cin >> index;
    // cout << endl << endl << "You just accessed " << names[index] << endl;

    // Example 2 in the question *Input for array*

    // int space , counter;

    // cin >> space;
    // int numbers[space];

    // for(int i = 0 ; i < space; i++){
    //     cin >> numbers[i];
    // }

    // counter = 0;

    // for(auto i: numbers){
    //     cout << "Index No."<< counter++ << " \t" << i << endl;
    // }

    // char array and string experiment
    // string name;
    // int change = 0 , j = 0, k = 0;
    // getline(cin , name);

    // char firstName[100];
    // char lastName[100];

    // for (int i = 0; i < name.length(); i++)
    // {
    //     if(name[i] != ' ' && change == 0){
    //         firstName[j] = name[i];
    //         j++;
    //     }else if(name[i] == ' '){
    //         change = 1;
    //     }else if(name[i] != ' ' && change == 1){
    //         lastName[k] = name[i];
    //         k++;
    //     }
    // }

    // cout << "First Name: " << firstName << endl;
    // cout << "Last Name: " << lastName << endl;

    // Find the largest number in array

    // int numbers[100], temp, i = 0, max = 0 , counter = 0;

    // while (cin >> temp && temp != EOF)
    // {
    //     numbers[i] = temp;
    //     i++;
    //     counter++;
    // }

    // cout << counter << endl;

    // for (int j = 0; j < counter; j++)
    // {
    //     if (max < numbers[j])
    //     {
    //         max = numbers[j];
    //     }
    // }

    //Capitalize the first word of the letter
    string word;
    bool first = true;
    cin >> word;
    char characters[word.length()];
    int j = 0;

    for (int i = 0; i < word.length(); i++)
    {
        if(first){
            if((int)word[i] <= 97 && (int)word[i] <= 122){
                word[i] -= 32;
                characters[j++] = word[i];
            }else{
                characters[j++] = word[i];
            }
            first = false;
        }
        characters[j++] = word[i];
    }

    characters[j] = '\0';

    cout << characters << endl;


    // char a = 'a';
    // char z = 'z';
    // char A = 'A';
    // char Z = 'Z';
    // char b = 'b';
    
    // cout << int(a) << " " << int(b) << " " << int(z) << endl;
    // cout << int(A) << " " << int(Z) << endl;

    

    



    return 0;
}