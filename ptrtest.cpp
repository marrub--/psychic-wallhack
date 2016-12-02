#include <memory>
#include <iostream>

#define GenPrint(name) \
    name() {std::cout <<     #name "()\n";} \
   ~name() {std::cout << "~" #name "()\n";}

class Base                  {public: GenPrint(Base)};
class A                     {public: GenPrint(A) std::shared_ptr<Base> base;};
class Derived : public Base {public: GenPrint(Derived)};

int main() {A a; a.base.reset(new Derived());}

