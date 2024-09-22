
#define loadlib_c
#define LUA_LIB

#include "lprefix.h"

#include "lplatform.h"

#include "lua.h"

#include "lualib.h"

LUAMOD_API int luaopen_platform(lua_State *L) {
  lua_newtable(L);

  lua_pushstring(L, LUA_PLATFORM); // 根据平台设置 os 的值
  lua_setfield(L, -2, "os");

  return 1;
}
