#ifndef lhelper_os_macos_h
#define lhelper_os_macos_h

#include <mach-o/dyld.h>
#include <stdlib.h>
#include <string.h>

static inline char *getappfilepath() {
  uint32_t bufsize = 1024;
  char *buf = NULL;

  buf = (char *)malloc(bufsize * sizeof(char));
  if (_NSGetExecutablePath(buf, &bufsize) == 0) {
    return buf;
  }
  free(buf);

  buf = (char *)malloc(bufsize * sizeof(char));
  if (_NSGetExecutablePath(buf, &bufsize) == 0) {
    return buf;
  }
  free(buf);

  return NULL;
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