#include <iostream>
#include <sstream>

struct Class
{
   int a = 300;
};

std::ostream &operator << (std::ostream &out, Class c)
{
   out << c.a;
   return out;
}

int Print(char const *fmt)
{
   int ret = 0;

   for(auto p = fmt; *p; p++, ret++)
      std::cout.put(*p);

   std::cout.put('\n');

   return ret;
}

template<typename T, typename... Args>
int Print(char const *fmt, T &&head, Args &&...tail)
{
   int ret = 0;

   for(auto p = fmt; *p; p++, ret++)
   {
      if(p[0] == '{')
         switch(p[1])
         {
         case '}':
            if(std::ostringstream o; true)
            {
               o << head;
               std::cout << o.str();
               return (o.str().size()) + ret + Print(p + 2, tail...);
            }
         case '{': p++; break;
         }

      std::cout.put(*p);
   }

   return ret;
}

int main()
{
   Class c;
   // should output:
   // a91230b{}c{d300e{}f
   // ret = 19
   int ret = Print("a{}b{{}c{d{}e{}f", 91230, c);
   Print("ret = {}", ret);
}
