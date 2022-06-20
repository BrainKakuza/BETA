#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

const int SIZE = 500;

char **Screen;

int icons[50][3];
int numIcons = 0;

int nearestIcon[50];
int numNear;

void fillRegion(int x0, int y0, int x1, int y1)
{
    if (!Screen)
        return;

    static char letter = 'A';

    for (int i = x0; i <= x1; i++)
    {
        for (int j = y0; j <= y1; j++)
        {
            Screen[i][j] = letter; // Overwrite past regions and icons
        }
    }

    // Use the next letter of the alphabet
    letter = letter + 1;
}

float distance(int x0, int y0, int x1, int y1)
{
    return sqrtf(pow(x0 - x1, 2) + pow(y0 - y1, 2));
}

void findNearestIcon(int x, int y)
{
    int first = 0;

    while (first < numIcons && !icons[first][2])
    {
        first++;
    }

    float mindis = distance(x, y, icons[first][0], icons[first][1]);
    nearestIcon[0] = 1 + first;
    numNear = 1;
    float dis;

    for (int i = first + 1; i < numIcons; i++)
    {
        // Skip icons that are not visible
        if (!icons[i][2])
            continue;

        dis = distance(x, y, icons[i][0], icons[i][1]);

        if (dis < mindis)
        {
            mindis = dis;
            numNear = 1;
            nearestIcon[0] = 1 + i;
        }
        else if (dis == mindis)
        {
            nearestIcon[numNear++] = 1 + i;
        }
    }
}

int main(void)
{
    // fill in the canvas
    Screen = new char *[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        Screen[i] = new char[SIZE];
        for (int j = 0; j < SIZE; j++)
        {
            Screen[i][j] = '_';
        }
    }

    char type;
    cin >> type;

    int x1, y1, x2, y2;
    
    while (type != 'M')
    {
        cin >> x1 >> y1;

        if (type == 'R')
        {
            cin >> x2 >> y2;

            if (x1 > x2)
                swap(x1, x2);
            if (y1 > y2)
                swap(y1, y2);

            fillRegion(x1, y1, x2, y2);
        }
        else
        {
            icons[numIcons][0] = x1;
            icons[numIcons][1] = y1;
            numIcons++;
        }

        cin >> type;
    }

    // Check visibility
    for (int k = 0; k < numIcons; k++)
    {
        int x = icons[k][0];
        int y = icons[k][1];

        // The icon is visible
        icons[k][2] = Screen[x][y] == '_';

        // If the icon is visible, mark it on screen
        if (icons[k][2])
        {
            Screen[x][y] = k + 1;
            //cout << k + 1 << endl;
        }
    }

    while (type == 'M')
    {
        cin >> x1 >> y1;

        char result = Screen[x1][y1];

        // If clicked over a region
        if ('A' <= result && result <= 'Z')
        {
            cout << result << endl;

            // If clicked on icon
        }
        else if (1 <= result && result <= 50)
        {
            cout << setw(3) << result << endl;
            // Find the nearest icon(s)
        }
        else
        {
            findNearestIcon(x1, y1);
            // Print icon(s)
            for (int d = 0; d < numNear; d++)
                cout << setw(3) << nearestIcon[d];
            cout << endl;
        }

        cin >> type;
    }

    return 0;
}