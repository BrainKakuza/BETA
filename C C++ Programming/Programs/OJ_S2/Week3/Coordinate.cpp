#include <iostream>

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
