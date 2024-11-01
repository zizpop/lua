
#define loadlib_c
#define LUA_LIB

#include "lprefix.h"

#include "lhelperlib.h"
#include "stdlib.h"

#include "lua.h"

#include "lualib.h"

static int get_lua_filepath(lua_State *L) {
  char* buf = getappfilepath();
  lua_pushstring(L, buf);
  free(buf);
  return 1;
}

static int get_lua_dirpath(lua_State *L) {
  char* buf = getappdirpath();
  lua_pushstring(L, buf);
  free(buf);
  return 1;
}

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

static void set_arch_table(lua_State *L) {
  lua_newtable(L);

  lua_pushstring(L,  HP_ARCH_NAME_X86_32);
  lua_setfield(L, -2, "x86_32");

  lua_pushstring(L, HP_ARCH_NAME_X86_64);
  lua_setfield(L, -2, "x86_64");

  lua_pushstring(L, HP_ARCH_NAME_ARM_32);
  lua_setfield(L, -2, "arm");

  lua_pushstring(L, HP_ARCH_NAME_ARM_64);
  lua_setfield(L, -2, "arm64");

  lua_pushstring(L, HP_ARCH_NAME_LOONGARCH_32);
  lua_setfield(L, -2, "loongarch32");

  lua_pushstring(L, HP_ARCH_NAME_LOONGARCH_64);
  lua_setfield(L, -2, "loongarch64");

  lua_pushstring(L, HP_ARCH_NAME);
  lua_setfield(L, -2, "current");

  lua_setfield(L, -2, "arch");
}

LUAMOD_API int luaopen_helper(lua_State *L) {
  lua_newtable(L);

  set_os_table(L);
  set_arch_table(L);

  lua_pushcfunction(L, get_lua_filepath);
  lua_setfield(L, -2, "exefilepath");

  lua_pushcfunction(L, get_lua_dirpath);
  lua_setfield(L, -2, "exedirpath");

  return 1;
}
