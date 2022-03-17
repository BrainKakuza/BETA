#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

class Coordinate
{
public:
  	//Default Constructure
    Coordinate(){
        x = 0;
        y = 0;
    }

  	//Copy Constructure
    Coordinate(const Coordinate &b){
        x = b.x;
        y = b.y;
    }
  
	//Constructure that set the value
    Coordinate(int X , int Y){
        x = X;
        y = Y;
    }
  
	//Set the x value method  
    void setX(int val){
        x = val;
    }

  	//Set the y value method  
    void setY(int val){
        y = val;
    }

    //Print coordinate mehthod
  	void showCoordInfo(){
        cout << "(" << x << ", " << y << ")" << endl;
    }

  	// get x method
    int getX(){
        return x;
    }

  	// get y method
    int getY(){
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
        this -> a = _a;
        this -> b = _b;
    }

    // return the intersection with another segment if exist, return NULL when there are no intersection.
    Coordinate *getIntersection(Segment s)
    {
        Coordinate firstSEG_FirstCoor = a;
        Coordinate firstSEG_SecondCoor = b;
        Coordinate secondSEG_FirstCoor = s.getCoordinateA();
        Coordinate secondSEG_SecondCoor = s.getCoordinateB();

    
    }

    float length() // return the length of segment
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
    Coordinate m(1,2);
    Coordinate k(3,4);
    Segment a(m, k);
    a.getCoordinateA();

    

    return 0;
}