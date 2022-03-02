#include <iostream>
#include <cstring>

//Add these for smartpointer
#include <memory>
#include <utility>

using namespace std;

# define ROWS 5
# define COLUMNS 5


int main(void)
{
    int **table = new int*[ROWS];
    for (int i = 0; i < ROWS; i++)
    {
        table[i] = new int[COLUMNS];
    }

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            cout << table++ << " ";
        }
        cout << endl;
    
    }


    
    return 0;
}