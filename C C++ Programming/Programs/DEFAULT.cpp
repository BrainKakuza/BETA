#include <iostream>

using namespace std;

class M
{
public:
    virtual int remove() = 0;
};

int main()
{
    M * m = new M();

    cout << *m.remove() << endl;
    return 0;
}