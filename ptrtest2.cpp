#include <memory>
#include <iostream>

#define GenPrint(name) \
            name() {std::cout <<     #name "()\n";} \
   virtual ~name() {std::cout << "~" #name "()\n";}

class Base                  {public: GenPrint(Base)};
class A                     {public: GenPrint(A) std::unique_ptr<Base> base;};
class Derived : public Base {public: GenPrint(Derived)};

int main() {A a; a.base.reset(new Derived());}

