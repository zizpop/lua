#ifndef lhelperlib_h
#define lhelperlib_h

#include "lhelper-osdetect.h"
#include "lhelper-archdetect.h"

#if defined (HP_OS_WINDOWS)
  #include "lhelper-os-windows.h"
#elif defined(HP_OS_MACOS)
  #include "lhelper-os-macos.h"
#elif defined(HP_OS_LINUX)
  #include "lhelper-os-linux.h"
#endif

#endif