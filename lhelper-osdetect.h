#ifndef lhelper_osdetect_h
#define lhelper_osdetect_h

// Ref
// - LuaJIT ... src/lj_arch.h
// - QtBase ... src/corelib/global/qsystemdetect.h

#define HP_OS_VAL_UNKNOW  0
#define HP_OS_VAL_WINDOWS 1
#define HP_OS_VAL_MACOS   2
#define HP_OS_VAL_LINUX   3

#if defined(_WIN32) || defined(_WIN64)
    #define HP_OS_VAL_TARGET HP_OS_VAL_WINDOWS
#elif defined(__APPLE__)
    #define HP_OS_VAL_TARGET HP_OS_VAL_MACOS
#elif defined(__linux__)
    #define HP_OS_VAL_TARGET HP_OS_VAL_LINUX
#else
    #define HP_OS_VAL_TARGET HP_OS_VAL_UNKNOW
    #error "Unsupported System"
#endif

#define HP_IS_OS_UNKNOW  (HP_OS_VAL_TARGET == HP_OS_VAL_UNKNOW)
#define HP_IS_OS_WINDOWS (HP_OS_VAL_TARGET == HP_OS_VAL_WINDOWS)
#define HP_IS_OS_MACOS   (HP_OS_VAL_TARGET == HP_OS_VAL_MACOS)
#define HP_IS_OS_LINUX   (HP_OS_VAL_TARGET == HP_OS_VAL_LINUX)

#if HP_IS_OS_UNKNOW
    #define HP_OS_UNKNOW
#elif HP_IS_OS_WINDOWS
    #define HP_OS_WINDOWS
#elif HP_IS_OS_MACOS
    #define HP_OS_MACOS
#elif HP_IS_OS_LINUX
    #define HP_OS_LINUX
#else
    #warning "Unsupported System"
#endif

#define HP_OS_NAME_UNKNOW  "Unknow"
#define HP_OS_NAME_WINDOWS "Windows"
#define HP_OS_NAME_MACOS   "macOS"
#define HP_OS_NAME_LINUX   "Linux"

#if defined(HP_OS_UNKNOW)
    #define HP_OS_NAME     HP_OS_NAME_UNKNOW
#elif defined(HP_OS_WINDOWS)
    #define HP_OS_NAME     HP_OS_NAME_WINDOWS
#elif defined(HP_OS_MACOS)
    #define HP_OS_NAME     HP_OS_NAME_MACOS
#elif defined(HP_OS_LINUX)
    #define HP_OS_NAME     HP_OS_NAME_LINUX
#else
    #warning "Unsupported System"
#endif

#endif