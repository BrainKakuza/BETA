#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>

using namespace std;

class F
{
private:
    double a, r;

public:
    F(double _a, double _r) : a(_a), r(_r) {}

    double at(int x)
    {
        return a * pow(r, x);
    }

    double * S()
    {
        if (r > -1 && r < 1)
        {
            double * answer = new double;
            double result = a / (1 - r);
            *answer = result;
            return answer;
        }
        else
        {
            return nullptr;
        }
    }
};

int main()
{
    int j, k;
    double a, r;
    cin >> a >> r;
    F f(a, r);
    for (k = 0; k < 3; k++)
        printf("%.2lf\n", f.at(k));
    double *s = f.S();
    if (s == NULL)
        printf("NULL\n");
    else
        printf("%.2lf\n", *s);
}
