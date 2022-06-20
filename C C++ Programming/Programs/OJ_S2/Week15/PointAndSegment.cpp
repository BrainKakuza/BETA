#include<iostream>
#include<math.h>

using namespace std;

class Point
{
private:
    float x;
    float y;
public:
    Point()
    {
        x = 0;
        y = 0;
    }

    Point(float a , float b): x(a) , y(b){}

    void printPoint()
    {
        cout << "\"(" << x << ", " << y << ")\"" << endl;
    }

    float getDistance(Point &point)
    {
        return sqrt(pow(x - point.getX() , 2) + pow(y - point.getY() , 2));
    }

    float setX(float val)
    {
        x = val;
        return 0;
    }

    float setY(float val)
    {
        y = val;
        return 0;
    }

    float getX()
    {
        return x;
    }

    float getY()
    {
        return y;
    }
};


class Segment
{
private: 
    Point point1;
    Point point2;
public:
    Segment()
    {
        point1.setX(0.0);
        point1.setY(0.0);
        point2.setY(0.0);
        point2.setY(0.0);
    }

    Segment(Point p1 , Point p2): point1(p1) , point2(p2){}

    float getLength()
    {
        return sqrt(pow(point1.getX() - point2.getX(),2) + pow(point1.getY() - point2.getY(),2));
    }

};

int main()
{
    Point p1(5, 10);
    Point p2(5 , 5);
    Point p3;

    p1.printPoint();
    p2.printPoint();
    p3.printPoint();

    p3.setX(5);
    p3.setY(10.11);

    p3.printPoint();

    cout << p1.getDistance(p2) << endl;
    cout << p2.getDistance(p1) << endl;

    cout << p1.getDistance(p2) << endl;

    Segment seg1;
    Segment seg2(p1 , p2);

    cout << seg1.getLength() << endl;
    cout << seg2.getLength() << endl;


    

    return 0;
}
