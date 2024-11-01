#ifndef lhelper_os_windows_h
#define lhelper_os_windows_h

#include <windows.h>

static inline char *getappfilepath() {
  WCHAR buf[32768];
  int result = GetModuleFileNameW(NULL, buf, 32768);
  if (result == 0 || result == 32768) {
    return NULL;
  }

  int len = WideCharToMultiByte(CP_UTF8, 0, buf, -1, NULL, 0, NULL, NULL);
  char *newbuf = (char *)malloc(len);
  WideCharToMultiByte(CP_UTF8, 0, buf, -1, newbuf, len, NULL, NULL);

  return newbuf;
}

static inline char *getappdirpath() { 
  char *buf = getappfilepath();
  char *lastsp = strrchr(buf, '\\');
  if (lastsp != NULL) {
    *lastsp = '\0';
  }
  return buf;
 }

#endif