#ifndef lhelper_h
#define lhelper_h

#define LUA_LIB

#include "lprefix.h"

#include "lhelperlib.h"
#include <stdio.h>

#include "lua.h"

#include "lualib.h"

static inline void helper_set_path(lua_State *L) {
  lua_getglobal(L, "package"); // 获取 package 表
  lua_getfield(L, -1, "path"); // 获取 package.path 字段

  const char *old_path = NULL;

  // 确保 package.path 是字符串
  if (l_likely(lua_isstring(L, -1))) {
    old_path = lua_tostring(L, -1); // 获取当前 path 字符串
    lua_pop(L, 1);                  // 弹出原来的 package.path
  } else {
    lua_pop(L, 1); // 清理栈
    return;
  }

  const char *suffix = "/../share/?.lua";
  char *appdirpath = getappdirpath();

  int new_path_len = strlen(old_path) + strlen(appdirpath) + strlen(suffix) + 2;
  char *new_path = (char *)malloc(new_path_len);
  snprintf(new_path, new_path_len, "%s;%s%s", old_path, appdirpath, suffix);

  lua_pushstring(L, new_path); // 压入新的 path
  lua_setfield(L, -2, "path"); // 设置 package.path

  free(appdirpath);
  free(new_path);
  lua_pop(L, 1); // 弹出 package 表
  return;
}

#endif