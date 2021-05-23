#include "stdafx.h"
#include "CommandLine.h"
#include <windows.h>
#include <stdio.h>
#include <shellapi.h>

bool CommandLine::_noHost = false;

bool CommandLine::Init() {
  LPWSTR *szArglist = nullptr;
  int nArgs;

  szArglist = CommandLineToArgvW(GetCommandLineW(), &nArgs);

  if(nullptr == szArglist) {
    return false;
  }

  for(int i = 0; i < nArgs; i++) {
    if(wcsstr(L"--no-mods", szArglist[i])) {
      LocalFree(szArglist);
      return false;
    }

    if(wcsstr(L"--no-host", szArglist[i])) {
      _noHost = true;
      continue;
    }
  }

  LocalFree(szArglist);

  return true;
}
