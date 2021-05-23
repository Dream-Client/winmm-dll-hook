#include "stdafx.h"

#include "WinmmHooker.h"
#include "CommandLine.h"
#include "DreamLoader.h"

HINSTANCE mHinst = nullptr;

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
  mHinst = hinstDLL;
  if(fdwReason == DLL_PROCESS_ATTACH) {
    if(!CommandLine::Init()) {
      return TRUE;
    }

    if(!WinmmHooker::Hook()) {
      return FALSE;
    }

    if(!DreamLoader::Init()) {
      return TRUE;
    }

    //exit(0);
  } else if(fdwReason == DLL_PROCESS_DETACH) {
    WinmmHooker::Free();
  }
  return TRUE;
}

