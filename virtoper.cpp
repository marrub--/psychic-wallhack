#include <iostream>

class A
{
public:
   virtual int operator + (int rhs) {return rhs;}
};

class B : public A
{
public:
   int operator + (int) override {return 999;}
};

void print(A &a)
{
   std::cout << a + 5 << std::endl;
}

int main()
{
   A a;
   B b;

   print(a);
   print(b);
}
