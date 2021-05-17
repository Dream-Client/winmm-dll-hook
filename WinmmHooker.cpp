#include "stdafx.h"
#include "WinmmHooker.h"


extern "C" UINT_PTR mProcs[181] = { 0 };

LPCSTR mImportNames[] = {
  "CloseDriver",
  "DefDriverProc",
  "DriverCallback",
  "DrvGetModuleHandle",
  "GetDriverModuleHandle",
  "OpenDriver",
  "PlaySound",
  "PlaySoundA",
  "PlaySoundW",
  "SendDriverMessage",
  "WOWAppExit",
  "auxGetDevCapsA",
  "auxGetDevCapsW",
  "auxGetNumDevs",
  "auxGetVolume",
  "auxOutMessage",
  "auxSetVolume",
  "joyConfigChanged",
  "joyGetDevCapsA",
  "joyGetDevCapsW",
  "joyGetNumDevs",
  "joyGetPos",
  "joyGetPosEx",
  "joyGetThreshold",
  "joyReleaseCapture",
  "joySetCapture",
  "joySetThreshold",
  "mciDriverNotify",
  "mciDriverYield",
  "mciExecute",
  "mciFreeCommandResource",
  "mciGetCreatorTask",
  "mciGetDeviceIDA",
  "mciGetDeviceIDFromElementIDA",
  "mciGetDeviceIDFromElementIDW",
  "mciGetDeviceIDW",
  "mciGetDriverData",
  "mciGetErrorStringA",
  "mciGetErrorStringW",
  "mciGetYieldProc",
  "mciLoadCommandResource",
  "mciSendCommandA",
  "mciSendCommandW",
  "mciSendStringA",
  "mciSendStringW",
  "mciSetDriverData",
  "mciSetYieldProc",
  "midiConnect",
  "midiDisconnect",
  "midiInAddBuffer",
  "midiInClose",
  "midiInGetDevCapsA",
  "midiInGetDevCapsW",
  "midiInGetErrorTextA",
  "midiInGetErrorTextW",
  "midiInGetID",
  "midiInGetNumDevs",
  "midiInMessage",
  "midiInOpen",
  "midiInPrepareHeader",
  "midiInReset",
  "midiInStart",
  "midiInStop",
  "midiInUnprepareHeader",
  "midiOutCacheDrumPatches",
  "midiOutCachePatches",
  "midiOutClose",
  "midiOutGetDevCapsA",
  "midiOutGetDevCapsW",
  "midiOutGetErrorTextA",
  "midiOutGetErrorTextW",
  "midiOutGetID",
  "midiOutGetNumDevs",
  "midiOutGetVolume",
  "midiOutLongMsg",
  "midiOutMessage",
  "midiOutOpen",
  "midiOutPrepareHeader",
  "midiOutReset",
  "midiOutSetVolume",
  "midiOutShortMsg",
  "midiOutUnprepareHeader",
  "midiStreamClose",
  "midiStreamOpen",
  "midiStreamOut",
  "midiStreamPause",
  "midiStreamPosition",
  "midiStreamProperty",
  "midiStreamRestart",
  "midiStreamStop",
  "mixerClose",
  "mixerGetControlDetailsA",
  "mixerGetControlDetailsW",
  "mixerGetDevCapsA",
  "mixerGetDevCapsW",
  "mixerGetID",
  "mixerGetLineControlsA",
  "mixerGetLineControlsW",
  "mixerGetLineInfoA",
  "mixerGetLineInfoW",
  "mixerGetNumDevs",
  "mixerMessage",
  "mixerOpen",
  "mixerSetControlDetails",
  "mmDrvInstall",
  "mmGetCurrentTask",
  "mmTaskBlock",
  "mmTaskCreate",
  "mmTaskSignal",
  "mmTaskYield",
  "mmioAdvance",
  "mmioAscend",
  "mmioClose",
  "mmioCreateChunk",
  "mmioDescend",
  "mmioFlush",
  "mmioGetInfo",
  "mmioInstallIOProcA",
  "mmioInstallIOProcW",
  "mmioOpenA",
  "mmioOpenW",
  "mmioRead",
  "mmioRenameA",
  "mmioRenameW",
  "mmioSeek",
  "mmioSendMessage",
  "mmioSetBuffer",
  "mmioSetInfo",
  "mmioStringToFOURCCA",
  "mmioStringToFOURCCW",
  "mmioWrite",
  "mmsystemGetVersion",
  "sndPlaySoundA",
  "sndPlaySoundW",
  "timeBeginPeriod",
  "timeEndPeriod",
  "timeGetDevCaps",
  "timeGetSystemTime",
  "timeGetTime",
  "timeKillEvent",
  "timeSetEvent",
  "waveInAddBuffer",
  "waveInClose",
  "waveInGetDevCapsA",
  "waveInGetDevCapsW",
  "waveInGetErrorTextA",
  "waveInGetErrorTextW",
  "waveInGetID",
  "waveInGetNumDevs",
  "waveInGetPosition",
  "waveInMessage",
  "waveInOpen",
  "waveInPrepareHeader",
  "waveInReset",
  "waveInStart",
  "waveInStop",
  "waveInUnprepareHeader",
  "waveOutBreakLoop",
  "waveOutClose",
  "waveOutGetDevCapsA",
  "waveOutGetDevCapsW",
  "waveOutGetErrorTextA",
  "waveOutGetErrorTextW",
  "waveOutGetID",
  "waveOutGetNumDevs",
  "waveOutGetPitch",
  "waveOutGetPlaybackRate",
  "waveOutGetPosition",
  "waveOutGetVolume",
  "waveOutMessage",
  "waveOutOpen",
  "waveOutPause",
  "waveOutPrepareHeader",
  "waveOutReset",
  "waveOutRestart",
  "waveOutSetPitch",
  "waveOutSetPlaybackRate",
  "waveOutSetVolume",
  "waveOutUnprepareHeader",
  "waveOutWrite",
  (LPCSTR)2,
};

HINSTANCE WinmmHooker::_HinstDLL = nullptr;

bool WinmmHooker::Hook()
{
	wchar_t* swPath = new wchar_t[MAX_PATH];

	if (GetWindowsDirectoryW(swPath, MAX_PATH) == 0) {
		return false;
	}

	wstring winmmPath = wstring(swPath);
	winmmPath.append(L"\\System32\\winmm.dll");

	_HinstDLL = LoadLibraryW(winmmPath.c_str());

	if (!_HinstDLL) {
		return false;
	}

	for (int i = 0; i < 181; ++i) {
		mProcs[i] = (UINT_PTR)GetProcAddress(_HinstDLL, mImportNames[i]);
	}
}

void WinmmHooker::Free()
{
	FreeLibrary(_HinstDLL);
}
