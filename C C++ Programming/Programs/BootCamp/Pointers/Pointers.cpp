/*
    Pointers
    - A pointer is just a variable that point the location(memeory address in CPU) of the variables
    - It's not a variable , it doesn't hold data

    Ex:
    //when we do this it is a null pointer
    void* ptr = 0;
    ptr = nullptr;
    ptr = NULL;
    when we return these data it will return 0

    Ex:
    int var = 10;
    int* ptr;
    ptr = &var;
    //ptr is now holding the address of var

    Why they imp
        - Enable use to allocare memory dynamically this means we can change the size of memory allocated to us during our program
        - It gives us the benefit of passing/call by reference via functions , you change the data the function and the data it is the same
        as we get the data after the function(It is called by reference)
        - Store a data by reference our pointer
        - We can use it like an array

    To store a data
    int *var = new int;
    int *var = 10;

    Allocate a block of memory
    int * ptr = new int[8];
    //It is going to point at the first block
    | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
      ^
      |


      delete (ptr); //delete the entire block
*/

#include <iostream>
#include <cstring>

#define SIZE 5;
using namespace std;


int main()
{

    /*
    int var = 20;
    int * ptr = &var; //Make it store a address of the variable
    int * temp = ptr;
    //If we do the down below is pointer point to an integer
    //int * temp = * ptr;

    //Get the address
    cout << ptr << endl;
    //Get the number
    cout << *ptr << endl;
    //Get the address
    cout << temp << endl;
    //Get the number
    cout << *temp << endl;
    */


    
    //for more pointers content
    
    int num = 10;
    int * ptr = new int;
    int * temp;
    ptr = &num;

    //Make temp point to the samw point as ptr point
    
    temp = ptr;

    cout << *ptr << endl;
    cout << *temp << endl;

    //create a new ptr that point to a new memory and it will not connect to the previous pointing
    ptr = new int;
    //Declare new ptr equals 50
    *ptr = 50;

    cout << *ptr << endl;

    //PTR should now equal to null
    delete ptr;

    cout << *ptr << endl;
    cout << *temp << endl;
    

    //Array like pointer
    /*
    int * ptr = new int[8];

    for(int i = 0; i < 8; i++){
        ptr[i] = i + 1;
    }

    for (int i = 0; i < 8; i++)
    {
        cout << ptr[i] << " ";
    }
    */


    

    return 0;
}