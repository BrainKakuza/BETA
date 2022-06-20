#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

class Coordinate
{
public:
    // Default Constructure
    Coordinate()
    {
        x = 0;
        y = 0;
    }

    // Copy Constructure
    Coordinate(const Coordinate &b)
    {
        x = b.x;
        y = b.y;
    }

    // Constructure that set the value
    Coordinate(int X, int Y)
    {
        x = X;
        y = Y;
    }

    // Set the x value method
    void setX(int val)
    {
        x = val;
    }

    // Set the y value method
    void setY(int val)
    {
        y = val;
    }

    // Print coordinate mehthod
    void showCoordInfo()
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }

    // get x method
    int getX()
    {
        return x;
    }

    // get y method
    int getY()
    {
        return y;
    }

private:
    int x;
    int y;
};

/*************************************************/

class Segment // using two Coordinate to represent a segment
{
public:
    Segment(Coordinate _a, Coordinate _b)
    {
        this->a = _a;
        this->b = _b;
    }

    // return the intersection with another segment if exist, return NULL when there are no intersection.
    Coordinate *getIntersection(Segment s)
    {
        int firstCoor_X = s.getCoordinateA().getX();
        int firstCoor_Y = s.getCoordinateA().getY();
        int secondCoor_X = s.getCoordinateB().getX();
        int secondCoor_Y = s.getCoordinateB().getY();

        float slopeOne;
        float slopeTwo;
        float B1;
        float B2;

        // Find the first equation in first segment
        slopeOne = (a.getY() - b.getY()) / (a.getX() - b.getY());
        B1 = a.getY() - (slopeOne * a.getX());

        // Find the first equation in first segment
        slopeTwo = (firstCoor_Y - secondCoor_Y) / (firstCoor_X - secondCoor_X);
        B2 = firstCoor_X - (slopeTwo * firstCoor_Y);

        float X = (B2 - B1) / (slopeOne - slopeTwo);
        float Y = (slopeOne * X) + B1;

        if (
            (min(a.getX(), b.getX()) <= X && X <= max(a.getX(), b.getX())) &&
            (min(firstCoor_X, secondCoor_X) <= X && X <= max(firstCoor_X, secondCoor_X)) &&
            (min(a.getY(), b.getY()) <= X && X <= max(a.getY(), b.getY())) &&
            (min(firstCoor_Y, secondCoor_Y) <= X && X <= max(firstCoor_Y, secondCoor_Y)))
        {
            cout << X << " " << Y << endl;
            return 0;
        }
        {
            return nullptr;
        }
    }

    float length()
    {
        return sqrt(pow(a.getX() - b.getX() , 2) + pow(a.getY() - b.getY() , 2));
    }

    Coordinate getCoordinateA() { return a; }

    Coordinate getCoordinateB() { return b; }

private:
    Coordinate a, b;
};

int main()
{
    Coordinate m(1, 2);
    Coordinate k(3, 4);
    Segment a(m, k);

    Coordinate A(5, 6);
    Coordinate B(7, 8);
    Segment b(A, B);

    a.getIntersection(b);

    return 0;
}