#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Robot
{
public:
    Robot()
    {
        position_x = 0;
        position_y = 0;
        direction = 'N';
    }
    void turn(string way)
    {
        char d[4] = {'N', 'E', 'S', 'W'};
        int j;
        for (j = 0; j < 4; j++)
            if (d[j] == direction)
                break;
        if (way == "RIGHT")
            direction = d[(j + 1) % 4];
        else if (way == "LEFT")
            direction = d[(j - 1 + 4) % 4];
    }
    int getPositionX()
    {
        return position_x;
    }
    int getPositionY()
    {
        return position_y;
    }
    char getDirection()
    {
        return direction;
    }
    void go()
    {
        if (direction == 'N')
            position_y++;
        else if (direction == 'E')
            position_x++;
        else if (direction == 'S')
            position_y--;
        else
            position_x--;
    }
    void display()
    {
        cout << "at(" << position_x << ", " << position_y << "), heading " << direction << endl;
    };

private:
    int position_x, position_y;
    char direction;
};

Robot robot;

// function that convert to uppercase
string stringConvert(string input)
{
    int length = input.length();
    string data;

    for (int i = 0; i < length; i++)
    {
        char upper = toupper(input[i]);
        data.push_back(upper);
    }

    return data;
}

string instructReturn(string input)
{
    string result;
    int i = 0;

    while (input[i] != '(' && i < input.length())
    {
        if (input[i] != ' ')
        {
            result.push_back(input[i]);
        }
        else
        {
            break;
        }

        i++;
    }

    return result;
}

// function that will use to get the order
string orderReturn(string input)
{
    string result;
    bool notOrder = true;
    int length = input.length();

    for (int i = 0; i < length; i++)
    {
        if (notOrder)
        {
            if (input[i] == '(' || input[i] == ' ')
            {
                notOrder = false;
            }
        }
        else
        {
            if (input[i] == ')' || input[i] == '(')
            {
                continue;
            }
            else
            {
                result.push_back(input[i]);
            }
        }
    }
    return result;
}

// function that will run until get the satisfied direction
void getDirection(char direction)
{
    while (robot.getDirection() != direction)
    {
        robot.turn("RIGHT");
    }
}

int main()
{
    string command, instruct, order;

    while (1)
    {
        getline(cin, command);

        //Get only the instruction(go , turn , turnto , etc) and order(W , E , right , left)
        instruct = instructReturn(command);
        order = orderReturn(command);

        // cout << instruct << endl;
        // cout << order << endl;

        // convert both of them to uppercase
        instruct = stringConvert(instruct);
        order = stringConvert(order);

        // cout << instruct << endl;
        // cout << order << endl;

        if (instruct == "GO")
        {
            //change order to int to use is to make to robot move
            int num = stoi(order);
            for (int i = 0; i < num; i++)
            {
                robot.go();
            }
        }
        else if (instruct == "TURN")
        {
            robot.turn(order);
        }
        else if (instruct == "TURNTO")
        {
            char m = order[0];
            getDirection(m);
        }
        else if (instruct == "GOTO")
        {
            string coorOne, coorTwo;
            int x, y;
            bool changCoor = true;

            //This loop is use to get both x and y coordinate from the input
            for (int i = 4; i < command.length();)
            {
                if (changCoor)
                {
                    if (command[i] != '(' && command[i] != ' ')
                    {
                        while (1)
                        {
                            if (command[i] == ' ' || command[i] == ')')
                            {
                                changCoor = false;
                                break;
                            }
                            else
                            {
                                coorOne.push_back(command[i]);
                            }
                            i++;
                        }
                    }
                    i++;
                }
                else
                {
                    if (command[i] != '(' && command[i] != ' ')
                    {
                        while (1)
                        {
                            if (command[i] == ' ' || i >= command.length() || command[i] == ')')
                            {
                                break;
                            }
                            else
                            {
                                coorTwo.push_back(command[i]);
                            }
                            i++;
                        }
                    }
                    i++;
                }
            }

            // cout << coorOne << endl;
            // cout << coorTwo << endl;

            x = stoi(coorOne);
            y = stoi(coorTwo);

            // Do the x direction first
            if (robot.getPositionX() != x)
            {
                if (robot.getPositionX() > x)
                {
                    getDirection('W');
                }
                else if (robot.getPositionX() < x)
                {
                    getDirection('E');
                }

                while (robot.getPositionX() != x)
                {
                    robot.go();
                }
            }

            // Then do the y direction
            if (robot.getPositionY() != y)
            {
                if (robot.getPositionY() > y)
                {
                    getDirection('S');
                }
                else if (robot.getPositionY() < y)
                {
                    getDirection('N');
                }

                while (robot.getPositionY() != y)
                {
                    robot.go();
                }
            }

            getDirection('N');
        }
        else if (instruct == "SHOWINFO")
        {
            robot.display();
        }
        else if (instruct == "STOP")
        {
            break;
        }
    }

    return 0;
}