#include <iostream>

using namespace std;

template <class T>
class Pair
{
public:
    Pair();
    Pair(T firstValue, T secondValue);
    void setFirst(T newValue);
    void setSecond(T newValue);
    T getFirst( ) const;
    T getSecond( ) const;
private:
    T first;
    T second;
};

template <class T>
Pair<T>::Pair()
{
    first = 0;
    second = 0;
}

template <class T>
Pair<T>::Pair(T firstValue, T secondValue)
{
    first = firstValue;
    second = secondValue;
}

template <class T>
void Pair<T>::setFirst(T newValue)
{
    first = newValue;
}

template <class T>
void Pair<T>::setSecond(T newValue)
{
    second = newValue;
}

template <class T>
T Pair<T>::getFirst() const
{
    return first;
}

template <class T>
T Pair<T>::getSecond() const
{
    return second;
}

template <class T>
T addUp(const Pair<T> thePair)
{
    T result = thePair.getFirst() + thePair.getSecond();
    return result;
}

int main()
{
    int sum;
    Pair<int> p(1, 2);
    cout << "First is " << p.getFirst() << endl;
    cout << "Second is " << p.getSecond() << endl;
    cout << "The sum is " << addUp(p) << endl;

    cout << endl;

    p.setFirst(3);
    p.setSecond(10);

    cout << "First changed to " << p.getFirst() << endl;
    cout << "Second changed to " << p.getSecond() << endl;
    cout << "Now the sum is " << addUp(p) << endl;

    return 0;
}