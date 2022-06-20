#include <iostream>

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

void getDirection(char direction)
{
    while (robot.getDirection() != direction)
    {
        robot.turn("LEFT");
    }
}

int main()
{
    int x, y, go;
    char direction;
    string way, instruction;

    while (1)
    {
        cin >> instruction;

        if (instruction == "GO")
        {
            cin >> go;

            while (go--)
            {
                robot.go();
            }
        }
        else if (instruction == "TURN")
        {
            cin >> way;

            robot.turn(way);
        }
        else if (instruction == "TURNTO")
        {
            cin >> direction;

            getDirection(direction);
        }
        else if (instruction == "GOTO")
        {
            cin >> x;

            if (robot.getPositionX() > x)
            {
                getDirection('W');

                while (robot.getPositionX() != x)
                {
                    robot.go();
                }
            }
            else if (robot.getPositionX() < x)
            {
                getDirection('E');

                while (robot.getPositionX() != x)
                {
                    robot.go();
                }
            }

            cin >> y;

            if (robot.getPositionY() > y)
            {
                getDirection('S');

                while (robot.getPositionY() != y)
                {
                    robot.go();
                }
            }
            else if (robot.getPositionY() < y)
            {
                getDirection('N');

                while (robot.getPositionY() != y)
                {
                    robot.go();
                }
            }

            getDirection('N');
        }else if(instruction == "SHOWINFO")
        {
            robot.display();
        }else if(instruction == "STOP")
        {
            break;
        }
    }

    return 0;
}