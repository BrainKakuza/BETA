#include <iostream>
using namespace std;

string toString(int n)
{
    if(n == 0)
        return "";

    if(n == 1)
        return "1";

   string res = "1";

   while (--n)
   {
       string cur = "";
       for(int i = 0; i < res.length(); i++)
       {
           int count = 1;
           while(res[i] == res[i + 1] && i < res.length())
           {
               count++;
               i++;
           }
           cur += to_string(count) + res[i];
       }
       res = cur;
   }

   return res;
   
    
}


int main()
{
   int num;

   while(cin >> num)
   {
       string output = toString(num);
       cout << output << endl;
   }
   

	return 0;
}
