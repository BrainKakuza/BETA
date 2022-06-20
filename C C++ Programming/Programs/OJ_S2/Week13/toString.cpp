#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Convert
{
public:
    static string toString(int n)
    {
        stringstream ss;

        ss << n;

        return ss.str();
    }
    static string toString(char c)
    {
        stringstream ss;

        ss << c;

        return ss.str();
    }
    static string toString(double d)
    {
        stringstream ss;

        ss << d;

        return ss.str();
    }
    static string toString(Point p)
    {
        stringstream ss;

        ss << "(" << p.x << ", " << p.y << ")";

        return ss.str();
    }
};
