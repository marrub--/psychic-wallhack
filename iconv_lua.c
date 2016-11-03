// Made by Graham Sanderson, no rights reserved.
// Link with iconv and Lua 5.1.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iconv.h>
#include <lua5.1/lua.h>
#include <lua5.1/lauxlib.h>
#include <lua5.1/lualib.h>

int main(int argc, char **argv)
{
   size_t len, srcsz, dstsz;
   char *lstr, *out, *pout;
   char const *str, *pstr;
   lua_State *lst;
   iconv_t icd;

   if(argc != 2)
   {
      printf("Invalid arguments. Usage: %s <string>\n", argv[0]);
      return 1;
   }

   len = strlen(argv[1]);
   lstr = calloc(len + 5, 1);
   memcpy(lstr, "s=\"", 3);
   memcpy(lstr + 3, argv[1], len);
   lstr[len + 3] = '"';

   lst = luaL_newstate();
   luaL_openlibs(lst);
   luaL_dostring(lst, lstr);
   lua_getglobal(lst, "s");
   str = lua_tostring(lst, 1);

   out = calloc(len * 6, 1);
   pstr = str;
   pout = out;

   srcsz = len;
   dstsz = len * 6;

   icd = iconv_open("UTF-8", "SHIFT-JIS");
   iconv(icd, &pstr, &srcsz, &pout, &dstsz);
   iconv_close(icd);

   *pout = '\0';

   puts(out);

   free(lstr);
   free(out);

   return 0;
}

// EOF
