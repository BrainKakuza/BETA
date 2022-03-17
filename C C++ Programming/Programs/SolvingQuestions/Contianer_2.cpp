#include <iostream>
#include <string.h>

class container
{
private:
  int *box;
  int len;
  int index;
  const static int count = 0;

  bool reallocated(int size)
  {
      
  }
public:
  container(void): box(NULL), len(0), index(-1) {}

  container(int len)
  {
    box = new int[len]; 
  }

  int getLen();
  int getIndex();

  ~container(){}

};



int main()
{
    
    
    return 0;
}