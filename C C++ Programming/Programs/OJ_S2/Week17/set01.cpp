#include <iostream>

using namespace std;

template <class T>
class Set
{
public:

    Set(): element{}
    {
        
    }

    Set(Set &copySet)
    {
        count = copySet.count;

        for(int i = 0; i < copySet.count; i++)
        {
            element[i] = copySet.element[i];
        }
    }

    int add(const int num)
    {
        bool notSame = true;

        for(int i = 0; i < count; i++)
        {
            if(element[i] == num)
            {
                notSame = false;
                break;
            }
        }

        if(notSame)
        {
            element[count++] = num;
            return 1;
        }

        return 0;
    }

    int add(const Set addedElement)
    {
        int countAdded = 0;

        for(int i = 0; i < addedElement.count; i++ )
        {
            bool notSame = true; 
            for(int j = 0; j < count + countAdded; j++)
            {
                if(addedElement.element[i] == element[j])
                {
                    notSame = false;
                    break;
                }
            }

            if(notSame)
            {
                countAdded++;
                element[count + countAdded - 1] = addedElement.element[i];
            }
        }

        count += countAdded;
        
        return countAdded;
    }

    void display()
    {
        int j;
        for (j = 0; j < count; j++)
            std::cout << element[j] << " ";
    }

private:
    T element[100];
    int count = 0;
};

int main()
{

    Set <int> a , b;
    
    cout << a.add(10) << endl;
    cout << a.add(15) << endl;
    cout << a.add(10) << endl;

    cout << b.add(20) << endl;
    cout << b.add(10) << endl;
    cout << b.add(20) << endl;

    cout << a.add(b) << endl;

    a.display();
    b.display();
}