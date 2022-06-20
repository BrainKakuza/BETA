#include<iostream>

using namespace std;

class Convert: public string
{
    Convert()
    {
        this->clear();
    }

    Convert(string str)
    {
        this->append(str);
        this->clear();
    }

    int toInt()
    {
        int num = 0 , s = 1 , i = 0;

        if((*this)[0] == '-')
        {
            s = -1;
            i = 1;
        }

        for(; i < length(); i++)
        {
            num = num * 10 + ((*this)[i] - '0');
        }

        num *= s;

        return num;
    }

    double toDouble()
    {
        double num;
        int s = 1 , i = 0 , base = 1;
        bool change = false;

        if((*this) == '-')
        {
            s = -1;
            i = 1;
        }

        for(; i < length(); i++)
        {
            if((*this)[i] == '.')
            {
                change = true;
                continue;
            }

            num = num * 10 + ((*this)[i] - '0');

            if(change)
            {
                base *= 10;
            }
        }

        num *= s;
        num = num / base;

        return num;
    }
};
