#include <iostream>

using namespace std;

int main()
{
    string city[105]; // The total city in the input

    string temp; // Template for each city

    while (getline(cin, temp)) // First enter the city, num records the number of cities
    {

        // if # just finish the program
        if (temp[0] == '#')
            break;

        // Input all the city
        int num = 0;
        city[num++] = temp;
        while (getline(cin, city[num]))
        {
            if (city[num][0] == 'e')
                break;
            else
            {
                num++;
            }
        }

        if (num == 1)
            cout << num << endl; // When only one city is input just output 1
        else
        {
            // Rearrange Everything

            char sortedCity[105][6]; // To simplify string
            // Try to arrange everything in this form r o y g b
            // For example, s[i]=”r/P,o/G,y/S,g/A,b/N”, then a[i]=”PGSAN”;

            // r/P,o/G,y/S,g/A,b/N
            // r/G,o/P,y/S,g/A,b/N
            // r/P,y/S,o/G,g/N,b/A
            // r/P,o/S,y/A,g/G,b/N

            // R O Y G B

            // P G S A N
            // G P S A N
            // P G S N A
            // P S A G N

            for (int i = 0; i != num; ++i)
            {
                int j = city[i].find('r');
                sortedCity[i][0] = city[i][j + 2];

                j = city[i].find('o');
                sortedCity[i][1] = city[i][j + 2];

                j = city[i].find('y');
                sortedCity[i][2] = city[i][j + 2];

                j = city[i].find('g');
                sortedCity[i][3] = city[i][j + 2];

                j = city[i].find('b');
                sortedCity[i][4] = city[i][j + 2];
            }

            int result = 1000, candidate = 0;
            for (int i = 0; i != num; ++i)
            {

                // P G S A N
                // G P S A N
                // P G S N A
                // P S A G N

                int resultCom = 0; // how many changes need to apply
                for (int j = 0; j != num;)
                {
                    if (j == i)
                        ++j; // When j==i, no need to process
                    else
                    {
                        for (int k = 0; k != 5; ++k)
                        {
                            if (sortedCity[j][k] != sortedCity[i][k])
                                resultCom++;
                        }
                        j++;
                    }
                }

                if (result > resultCom)
                {
                    result = resultCom;
                    candidate = i;
                }
            }
            cout << candidate + 1 << endl;
        }
    }
    return 0;
}