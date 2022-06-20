#include <iostream>
#include <string.h>

using namespace std;

class AllBottle
{
private:
    int startBottle;
    int maxColaOne = 0;
    int maxColaTwo = 0;

public:
    AllBottle(int start) : startBottle(start) {}

    int enjoydrinkOne()
    {
    }

    int enjoydrinkTwo()
    {
        int bottle = startBottle;
        int maxColaTwo = bottle;
        int counter = 0;

        while (1)
        {
            bottle++;
            counter++;

            if (bottle % 3 != 0)
            {
                continue;
            }

            int temp = bottle;

            while (temp % 3 != counter)
            {
                
            }
        }

        while (bottle)
        {
        }
    }
};

int main()
{
    int a;

    cin >> a;

    AllBottle bottle(a);

    return 0;
}