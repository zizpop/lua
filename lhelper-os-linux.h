#ifndef lhelper_os_linux_h
#define lhelper_os_linux_h

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static inline char *getappfilepath() {
  return realpath("/proc/self/exe", 0);
}

static inline char *getappdirpath() {
  char *buf = getappfilepath();
  char *lastsp = strrchr(buf, '/');
  if (lastsp != NULL) {
    *lastsp = '\0';
  }
  return buf;
}

#endif