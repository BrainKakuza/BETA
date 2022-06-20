#include <iostream>

using namespace std;


class Player
{
public:
  
  	//Defalut constructure
    Player() {}

  	//Constructure with some manipulation
    Player(int num, string name)
    {
        if (num > 5 || num < 0)
        {
            cerr << "out of range\n";
        }

        if (name.length() >= 20)
        {
            cerr << "your name is illegal\n";
        }
        else if (name.length() < 20)
        {
            for (int i = 0; i < name.length() - 1; i++)
            {
                if ((name[i] >= 97 && name[i] <= 122) || (name[i] >= 65 && name[i] <= 90))
                {
                }
                else
                {
                    cerr << "your name is illegal\n";
                    break;
                }
            }
        }
    }

    int getPlayerNum()
    {
        return number;
    }

    string getPlayerName()
    {
        return Name;
    }

    bool setPlayerNum(int n)
    {
        if (n < 5 && n > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool setPlayerName(string n)
    {
        bool valid = true;

        if (n.length() >= 20)
        {
            valid = false;
        }
        else if (n.length() < 20)
        {
            for (int i = 0; i < n.length() - 1; i++)
            {
                if ((n[i] >= 97 && n[i] <= 122) || (n[i] >= 65 && n[i] <= 90))
                {
                }
                else
                {
                    valid = false;
                    break;
                }
            }
        }

        if(valid){
            return true;
        }else{
            return false;
        }
    }

private:
    int number;
    string Name;
};