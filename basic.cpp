#include <iostream>
#include <cmath>
#include <memory>

#define SUB inline auto
#define PROC int main
#define TEMPLATE template
#define VARARG class...
#define TYPENAME typename
#define USING using
#define RETURN return
#define BEGIN {
#define END }
#define IF if(
#define THEN ) {
#define ELSE } else {
#define ELIF(...) } else if(__VA_ARGS__) {
#define FI }
#define NEW STD::make_unique
#define RETURNS ->
#define OPERATOR operator
#define DECLARE extern
#define NAMESPACE namespace
#define CLASS struct
#define PUBLIC public:
#define SHARED protected:
#define PRIVATE private:
#define STD std
#define NOTHING void
#define INHERITS : public
#define REF &
#define PTR *
#define DPTR **
#define TPTR ***
#define QPTR ****
#define RVAL &&
#define DATA ;
#define LET auto
#define PASS {}
#define CONSTRUCTS :
#define TOPTR(p) p.get()

USING NAMESPACE STD;

USING INT    = int;
USING DPCHAR = char DPTR;

CLASS BaseT
BEGIN
   PUBLIC INT X;
   PUBLIC INT Y;

   BaseT (INT _X, INT _Y)
   CONSTRUCTS
      X (_X),
      Y (_Y)
   PASS
END DATA

CLASS ClassT INHERITS BaseT
BEGIN
   PUBLIC INT Z;
   PUBLIC INT W;

   ClassT (INT _X, INT _Y, INT _Z, INT _W)
   CONSTRUCTS
      BaseT (_X, _Y),
      Z (_Z),
      W (_W)
   PASS

   PUBLIC SUB Add ()
   BEGIN
      RETURN (INT (X + Y + Z + W));
   END
END DATA

DECLARE SUB OPERATOR << (ostream REF, ClassT PTR) RETURNS ostream REF;

SUB PRINT ()
BEGIN
   cout << '\n';
END

TEMPLATE<TYPENAME T, VARARG ArgsT>
SUB PRINT (T RVAL Head, ArgsT RVAL ... Tail)
BEGIN
   cout << Head;
   PRINT(Tail...);
END

PROC (INT Argc, DPCHAR Argv)
BEGIN
   LET Class = NEW <ClassT> (1, 2, 3, 4);
   PRINT(Class -> Add (), ' ', Class -> Z);
   PRINT(TOPTR(Class));
   LET Sine3 = sin (3);
   IF Sine3 < 3 THEN
      PRINT(Sine3, " < 3");
   ELSE
      PRINT(Sine3, " >= 3");
   FI
   RETURN (INT (0));
END

SUB OPERATOR << (ostream REF Out, ClassT PTR Class) RETURNS ostream REF
BEGIN
   Out << "X: " << Class -> X << '\n'
       << "Y: " << Class -> Y << '\n'
       << "Z: " << Class -> Z << '\n'
       << "W: " << Class -> W;
   RETURN (Out);
END
