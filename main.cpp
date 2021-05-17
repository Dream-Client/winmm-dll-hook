#include "stdafx.h"

#include "WinmmHooker.h"
#include "CommandLine.h"

HINSTANCE mHinst = nullptr;

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
	mHinst = hinstDLL;
	if (fdwReason == DLL_PROCESS_ATTACH) {
		if (!CommandLine::Init())
			return FALSE;
		if (!WinmmHooker::Hook())
			return FALSE;
	}
	else if (fdwReason == DLL_PROCESS_DETACH) {
		WinmmHooker::Free();
	}
	return TRUE;
}

