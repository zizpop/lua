
#define loadlib_c
#define LUA_LIB

#include "lprefix.h"

#include "lhelperlib.h"
#include "stdlib.h"

#include "lua.h"

#include "lualib.h"

static void set_os_table(lua_State *L) {
  lua_newtable(L);

  lua_pushstring(L, HP_OS_NAME_WINDOWS);
  lua_setfield(L, -2, "windows");

  lua_pushstring(L, HP_OS_NAME_MACOS);
  lua_setfield(L, -2, "macos");

  lua_pushstring(L, HP_OS_NAME_LINUX);
  lua_setfield(L, -2, "linux");

  lua_pushstring(L, HP_OS_NAME);
  lua_setfield(L, -2, "current");

  lua_setfield(L, -2, "os");
}

LUAMOD_API int luaopen_helper(lua_State *L) {
  lua_newtable(L);

  set_os_table(L);

  return 1;
}
