#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void)
{
    /*
        The Elephant Question
    */

   int stepCounter = 0 , input;

   cin >> input;

   while (input != 0)
   {
       if(input - 5 >= 0){
           input -= 5;
           stepCounter++;
       }else if(input - 4 >= 0){
           input -= 4;
           stepCounter++;
       }else if(input - 3 >= 0){
           input -= 3;
           stepCounter++;
       }else if(input - 2 >= 0){
           input -= 2;
           stepCounter++;
       }else if(input - 1 >= 0){
           input -= 1;
           stepCounter++;
       }

       cout << input << endl;
   }

   cout << stepCounter << endl;
   
    

    return 0;
}