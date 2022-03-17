#include <iostream>
#include <cstring>
#include <string>

using namespace std;

void Input(int input, string array[4000][4000], int &k)
{
    string name;
    int m = 0;

    for (int i = -1; i < input; i++)
    {
        string first;
        string last;
        bool space = true;
        bool notSame = true;

        if (i >= 0)
        {
            // get the input
            getline(cin, name);

            // seperate into two strings
            for (int j = 0; j < name.length(); j++)
            {
                if (name[j] == ' ')
                {
                    space = false;
                    j += 1;
                }

                if (space)
                {
                    first.push_back(name[j]);
                }
                else
                {
                    last.push_back(name[j]);
                }
            }

            // check if the first string(name) has been in the array or not
            for (int j = m; j >= 0; j--)
            {
                string check = last;
                // put the child of the offspring
                if (array[j][0] == first)
                {
                    if (last == "dominant" || last == "recessive" || last == "non-existent")
                    {
                        array[j][1] = last;
                    }
                    else
                    {
						int positon = 2;
                        while (true)
						{
							if(array[j][positon] == "")
							{
								array[j][positon] = last;
								break;
							}else
							{
								positon++;
							}
						}
                    }
                    notSame = false;
                }
            }

            if (notSame)
            {
                array[m][0] = first;

                if (last == "dominant" || last == "recessive" || last == "non-existent")
                {
                    array[m][1] = last;
                }
                else
                {
                    array[m][2] = last;
                }
                m++;
            }
        }
        else
        {
            getline(cin, name);
        }
    }

    // for adding a new member
    for (int i = 0; i < m; i++)
    {
        string back = array[i][2];
        bool newName = true;
        for (int j = 0; j < m; j++)
        {
            string compare = array[j][0];
            if (array[i][2] == array[j][0])
            {
                newName = false;
            }
        }

        if (newName)
        {
            array[m][0] = array[i][2];
            string result = array[m][0];
            m++;
        }
    }

    k = m - 1;
}

void Gene(int input, string array[4000][4000], int &k)
{
    for (int i = 0; i < k; i++)
    {
        string firstSample;
        string secondSample;
        bool swap = true;

        if (array[i][1] == "" && array[i][0] != "")
        {
            for (int j = 0; j < k; j++)
            {
                if ((array[i][0] == array[j][2]) && swap)
                {
                    firstSample = array[j][1];
                    swap = false;
                }
                else if ((array[i][0] == array[j][2]) && !swap)
                {
                    secondSample = array[j][1];
                    break;
                }
            }

            if ((firstSample == "dominant" && secondSample == "dominant") ||

                (firstSample == "dominant" && secondSample == "recessive") ||
                (firstSample == "recessive" && secondSample == "dominant"))
            {
                array[i][1] = "dominant";
            }
            else if ((firstSample == "dominant" && secondSample == "non-existent") ||
                     (firstSample == "non-existent" && secondSample == "dominant") ||

                     (firstSample == "dominant" && secondSample == "") ||
                     (firstSample == "" && secondSample == "dominant") ||

                     (firstSample == "recessive" && secondSample == "recessive"))
            {
                array[i][1] = "recessive";
            }
            else  
            {
                array[i][1] = "non-existent";
            }
        }
    }
}

void Sort(int input, string array[4000][4000], int &k)
{
    for (int i = 0; i < k; i++)
    {
        for (int j = i + 1; j < k; j++)
        {
            if (array[i][0] > array[j][0])
            {
                string name = array[i][0];
                string gene = array[i][1];
                array[i][0] = array[j][0];
                array[i][1] = array[j][1];
                array[j][0] = name;
                array[j][1] = gene;
            }
        }
    }
}

int main()
{
    int input;
    int k = 0;
    cin >> input;
    string array[4000][4000];
    
    Input(input, array, k);

    // cout << endl;

    // for (int i = 0; i < k; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         if (array[i][j] == "")
    //         {
    //             cout << "none ";
    //         }
    //         else
    //         {
    //             cout << array[i][j] << " ";
    //         }
    //     }
    //     cout << endl;
    // }

    // cout << endl;

    Gene(input, array, k);

    // for (int i = 0; i < k; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         if (array[i][j] == "")
    //         {
    //             cout << "none ";
    //         }
    //         else
    //         {
    //             cout << array[i][j] << " ";
    //         }
    //     }
    //     cout << endl;
    // }

    // cout << endl;

    Sort(input, array, k);

    //cout << endl;

    for (int i = 0; i < k; i++)
    {

        for (int j = 0; j < 2; j++)
        {
            cout << array[i][j] << " ";
        }

        
            cout << endl;
        
    }

    return 0;
}