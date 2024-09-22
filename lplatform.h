#ifndef lplatform_h
#define lplatform_h

#if defined(_WIN32) || defined(_WIN64)
#define LUA_PLATFORM "Windows"
#elif defined(__APPLE__)
#include <TargetConditionals.h>
#if TARGET_OS_MAC
#define LUA_PLATFORM "macOS"
#else
#define LUA_PLATFORM "Unknown"
#endif
#elif defined(__linux__)
#define LUA_PLATFORM "Linux"
#else
#define LUA_PLATFORM "Unknown"
#endif

#endif