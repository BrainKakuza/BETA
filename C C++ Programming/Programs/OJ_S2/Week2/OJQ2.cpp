#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
   char word; 
   string text , reverse;

   while (1)
   {
       cin >> word;
       if(word == '.'){
           break;
       }else{
           text.push_back(word);
       }
   }
    
   for (int i = text.length() - 1; i >= 0; i--)
   {
       reverse.push_back(text[i]);
   }

   cout << reverse;
   




    return 0;
}