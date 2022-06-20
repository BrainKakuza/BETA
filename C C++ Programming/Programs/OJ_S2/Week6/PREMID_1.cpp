#include <iostream>
class F
{
private:
  int a, b;

public:
  F(int numOne, int numTwo) : a(numOne), b(numTwo) {}

  int S(int x)
  {
    int result = 0;
    for (int i = 0; i <= x; i++)
    {
      result += (a * i) + b;
    }

    return result;
  }

  int G(int x, int y)
  {
    int result = 0;
    for (int i = x; i <= y; i++)
    {
      result += (a * i) + b;
    }

    return result;
  }
};
int main()
{
  int a, b, j;

  std::cin >> a >> b;
  F f(a, b);

  for (j = 0; j < 10; j++)
  {
    int x, y;
    std::cin >> x >> y;
    std::cout << f.S(x) << std::endl;
    std::cout << f.G(x, y) << std::endl;
  }
  return 0;
}
