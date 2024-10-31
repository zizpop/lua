#ifndef lhelper_archdetect_h
#define lhelper_archdetect_h

// Ref
// - LuaJIT ... src/lj_arch.h
// - QtBase ... src/corelib/global/qprocessordetection.h
// - absl   ... random/internal/platform.h
// - folly  ... Portability.h

// Ref URL
// - https://sourceforge.net/p/predef/wiki/Architectures/

#define HP_ARCH_VAL_UNKNOW 0
#define HP_ARCH_VAL_X86_32 1
#define HP_ARCH_VAL_X86_64 2
#define HP_ARCH_VAL_ARM_32 3
#define HP_ARCH_VAL_ARM_64 4
#define HP_ARCH_VAL_LOONGARCH_32 5
#define HP_ARCH_VAL_LOONGARCH_64 6

#if defined(__x86_64__)    || defined(_M_AMD64) || defined(_M_X64)
    #define HP_ARCH_VAL_TARGET HP_ARCH_VAL_X86_64
#elif defined(__i386__)    || defined(_M_IX86)
    #define HP_ARCH_VAL_TARGET HP_ARCH_VAL_X86_32
#elif defined(__aarch64__) || defined(__arm64__) || defined(_M_ARM64)
    #define HP_ARCH_VAL_TARGET HP_ARCH_VAL_ARM_64
#elif defined(__arm__)     || defined(__ARMEL__) || defined(_M_ARM)
    #define HP_ARCH_VAL_TARGET HP_ARCH_VAL_ARM_32
#elif defined(__loongarch__) && (__loongarch_grlen == 64)
    #define HP_ARCH_VAL_TARGET HP_ARCH_VAL_LOONGARCH_64
#elif defined(__loongarch__) && (__loongarch_grlen == 32)
    #define HP_ARCH_VAL_TARGET HP_ARCH_VAL_LOONGARCH_32
#else
    #define HP_ARCH_VAL_TARGET HP_ARCH_VAL_UNKNOW
    #error "Unsupport Architecture"
    // * for gcc, clang: "echo | gcc -E -dM -"
#endif

#define HP_IS_ARCH_UNKNOW       (HP_ARCH_VAL_TARGET == HP_ARCH_VAL_UNKNOW)
#define HP_IS_ARCH_X86_32       (HP_ARCH_VAL_TARGET == HP_ARCH_VAL_X86_32)
#define HP_IS_ARCH_X86_64       (HP_ARCH_VAL_TARGET == HP_ARCH_VAL_X86_64)
#define HP_IS_ARCH_ARM_32       (HP_ARCH_VAL_TARGET == HP_ARCH_VAL_ARM_32)
#define HP_IS_ARCH_ARM_64       (HP_ARCH_VAL_TARGET == HP_ARCH_VAL_ARM_64)
#define HP_IS_ARCH_LOONGARCH_32 (HP_ARCH_VAL_TARGET == HP_ARCH_VAL_LOONGARCH_32)
#define HP_IS_ARCH_LOONGARCH_64 (HP_ARCH_VAL_TARGET == HP_ARCH_VAL_LOONGARCH_64)

#if HP_IS_ARCH_UNKNOW
    #define HP_ARCH_UNKNOW
    #define HP_ARCH_FAMILY_UNKNOW
#elif HP_IS_ARCH_X86_32
    #define HP_ARCH_X86_32
    #define HP_ARCH_FAMILY_X86
#elif HP_IS_ARCH_X86_64
    #define HP_ARCH_X86_64
    #define HP_ARCH_FAMILY_X86
#elif HP_IS_ARCH_ARM_32
    #define HP_ARCH_ARM_32
    #define HP_ARCH_FAMILY_ARM
#elif HP_IS_ARCH_ARM_64
    #define HP_ARCH_ARM_64
    #define HP_ARCH_FAMILY_ARM
#elif HP_IS_ARCH_LOONGARCH_32
    #define HP_ARCH_LOONGARCH_32
    #define HP_ARCH_FAMILY_LOONGARCH
#elif HP_IS_ARCH_LOONGARCH_64
    #define HP_ARCH_LOONGARCH_64
    #define HP_ARCH_FAMILY_LOONGARCH
#else
    #warning "Unsupported Architecture"
#endif

#define HP_ARCH_NAME_UNKNOW "unknow"
#define HP_ARCH_NAME_X86_32 "x86_32"
#define HP_ARCH_NAME_X86_64 "x86_64"
#define HP_ARCH_NAME_ARM_32 "arm"
#define HP_ARCH_NAME_ARM_64 "arm64"
#define HP_ARCH_NAME_LOONGARCH_32 "loongarch32"
#define HP_ARCH_NAME_LOONGARCH_64 "loongarch64"

#if defined(HP_ARCH_UNKNOW)
    #define HP_ARCH_NAME HP_ARCH_NAME_UNKNOW
#elif defined(HP_ARCH_X86_32)
    #define HP_ARCH_NAME HP_ARCH_NAME_X86_32
#elif defined(HP_ARCH_X86_64)
    #define HP_ARCH_NAME HP_ARCH_NAME_X86_64
#elif defined(HP_ARCH_ARM_32)
    #define HP_ARCH_NAME HP_ARCH_NAME_ARM_32
#elif defined(HP_ARCH_ARM_64)
    #define HP_ARCH_NAME HP_ARCH_NAME_ARM_64
#elif defined(HP_ARCH_LOONGARCH_32)
    #define HP_ARCH_NAME HP_ARCH_NAME_LOONGARCH_32
#elif defined(HP_ARCH_LOONGARCH_64)
    #define HP_ARCH_NAME HP_ARCH_NAME_LOONGARCH_64
#else
    #warning "Unsupported Architecture"
#endif

#endif