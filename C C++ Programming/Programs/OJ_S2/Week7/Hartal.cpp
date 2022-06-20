#include <iostream>

using namespace std;

int main()
{
    int input;
    int days, candidates;

    cin >> input;

    for (int i = 0; i < input; i++)
    {
        int hartals = 0;
        int skipDay = 6;

        cin >> days >> candidates;
        int numCandidates[candidates];

        for (int i = 0; i < candidates; i++)
        {
            cin >> numCandidates[i];
        }

        for (int i = 1; i <= days; i++)
        {
            if (i == skipDay)
            {
                skipDay += 7;
                i += 1;
            }
            else
            {
                for (int j = 0; j < candidates; j++)
                {
                    if (i % numCandidates[j] == 0)
                    {
                        hartals++;
                        break;
                    }
                }
            }
        }

        cout << hartals << endl;
    }

    return 0;
}