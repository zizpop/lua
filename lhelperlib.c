
#define loadlib_c
#define LUA_LIB

#include "lprefix.h"

#include "lhelperlib.h"
#include "stdlib.h"

#include "lua.h"

#include "lualib.h"

LUAMOD_API int luaopen_helper(lua_State *L) {
  lua_newtable(L);

  return 1;
}
