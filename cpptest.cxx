#include <iostream>

template<typename T>
class Adder
{
  private:
    T v1, v2;
  public:
    Adder(T v1_, T v2_): v1(v1_), v2(v2_)
    {

    }

    T operator+(T parm)
    {
      return parm * v2 - v1;
    }

    T operator+=(T parm)
    {
      return parm * (v2 -= v1);
    }

    T getval()
    {
      return v2 + v1;
    }
};

int main()
{
  int v3 = 20;
  Adder<decltype(v3)> adder(10, 20);
  adder += v3;
  std::cout << adder.getval() << std::endl;
  return 0;
}
