.code
extern mProcs:QWORD
CloseDriver_wrapper proc
  jmp mProcs[0 * 8]
CloseDriver_wrapper endp
DefDriverProc_wrapper proc
  jmp mProcs[1 * 8]
DefDriverProc_wrapper endp
DriverCallback_wrapper proc
  jmp mProcs[2 * 8]
DriverCallback_wrapper endp
DrvGetModuleHandle_wrapper proc
  jmp mProcs[3 * 8]
DrvGetModuleHandle_wrapper endp
GetDriverModuleHandle_wrapper proc
  jmp mProcs[4 * 8]
GetDriverModuleHandle_wrapper endp
OpenDriver_wrapper proc
  jmp mProcs[5 * 8]
OpenDriver_wrapper endp
PlaySound_wrapper proc
  jmp mProcs[6 * 8]
PlaySound_wrapper endp
PlaySoundA_wrapper proc
  jmp mProcs[7 * 8]
PlaySoundA_wrapper endp
PlaySoundW_wrapper proc
  jmp mProcs[8 * 8]
PlaySoundW_wrapper endp
SendDriverMessage_wrapper proc
  jmp mProcs[9 * 8]
SendDriverMessage_wrapper endp
WOWAppExit_wrapper proc
  jmp mProcs[10 * 8]
WOWAppExit_wrapper endp
auxGetDevCapsA_wrapper proc
  jmp mProcs[11 * 8]
auxGetDevCapsA_wrapper endp
auxGetDevCapsW_wrapper proc
  jmp mProcs[12 * 8]
auxGetDevCapsW_wrapper endp
auxGetNumDevs_wrapper proc
  jmp mProcs[13 * 8]
auxGetNumDevs_wrapper endp
auxGetVolume_wrapper proc
  jmp mProcs[14 * 8]
auxGetVolume_wrapper endp
auxOutMessage_wrapper proc
  jmp mProcs[15 * 8]
auxOutMessage_wrapper endp
auxSetVolume_wrapper proc
  jmp mProcs[16 * 8]
auxSetVolume_wrapper endp
joyConfigChanged_wrapper proc
  jmp mProcs[17 * 8]
joyConfigChanged_wrapper endp
joyGetDevCapsA_wrapper proc
  jmp mProcs[18 * 8]
joyGetDevCapsA_wrapper endp
joyGetDevCapsW_wrapper proc
  jmp mProcs[19 * 8]
joyGetDevCapsW_wrapper endp
joyGetNumDevs_wrapper proc
  jmp mProcs[20 * 8]
joyGetNumDevs_wrapper endp
joyGetPos_wrapper proc
  jmp mProcs[21 * 8]
joyGetPos_wrapper endp
joyGetPosEx_wrapper proc
  jmp mProcs[22 * 8]
joyGetPosEx_wrapper endp
joyGetThreshold_wrapper proc
  jmp mProcs[23 * 8]
joyGetThreshold_wrapper endp
joyReleaseCapture_wrapper proc
  jmp mProcs[24 * 8]
joyReleaseCapture_wrapper endp
joySetCapture_wrapper proc
  jmp mProcs[25 * 8]
joySetCapture_wrapper endp
joySetThreshold_wrapper proc
  jmp mProcs[26 * 8]
joySetThreshold_wrapper endp
mciDriverNotify_wrapper proc
  jmp mProcs[27 * 8]
mciDriverNotify_wrapper endp
mciDriverYield_wrapper proc
  jmp mProcs[28 * 8]
mciDriverYield_wrapper endp
mciExecute_wrapper proc
  jmp mProcs[29 * 8]
mciExecute_wrapper endp
mciFreeCommandResource_wrapper proc
  jmp mProcs[30 * 8]
mciFreeCommandResource_wrapper endp
mciGetCreatorTask_wrapper proc
  jmp mProcs[31 * 8]
mciGetCreatorTask_wrapper endp
mciGetDeviceIDA_wrapper proc
  jmp mProcs[32 * 8]
mciGetDeviceIDA_wrapper endp
mciGetDeviceIDFromElementIDA_wrapper proc
  jmp mProcs[33 * 8]
mciGetDeviceIDFromElementIDA_wrapper endp
mciGetDeviceIDFromElementIDW_wrapper proc
  jmp mProcs[34 * 8]
mciGetDeviceIDFromElementIDW_wrapper endp
mciGetDeviceIDW_wrapper proc
  jmp mProcs[35 * 8]
mciGetDeviceIDW_wrapper endp
mciGetDriverData_wrapper proc
  jmp mProcs[36 * 8]
mciGetDriverData_wrapper endp
mciGetErrorStringA_wrapper proc
  jmp mProcs[37 * 8]
mciGetErrorStringA_wrapper endp
mciGetErrorStringW_wrapper proc
  jmp mProcs[38 * 8]
mciGetErrorStringW_wrapper endp
mciGetYieldProc_wrapper proc
  jmp mProcs[39 * 8]
mciGetYieldProc_wrapper endp
mciLoadCommandResource_wrapper proc
  jmp mProcs[40 * 8]
mciLoadCommandResource_wrapper endp
mciSendCommandA_wrapper proc
  jmp mProcs[41 * 8]
mciSendCommandA_wrapper endp
mciSendCommandW_wrapper proc
  jmp mProcs[42 * 8]
mciSendCommandW_wrapper endp
mciSendStringA_wrapper proc
  jmp mProcs[43 * 8]
mciSendStringA_wrapper endp
mciSendStringW_wrapper proc
  jmp mProcs[44 * 8]
mciSendStringW_wrapper endp
mciSetDriverData_wrapper proc
  jmp mProcs[45 * 8]
mciSetDriverData_wrapper endp
mciSetYieldProc_wrapper proc
  jmp mProcs[46 * 8]
mciSetYieldProc_wrapper endp
midiConnect_wrapper proc
  jmp mProcs[47 * 8]
midiConnect_wrapper endp
midiDisconnect_wrapper proc
  jmp mProcs[48 * 8]
midiDisconnect_wrapper endp
midiInAddBuffer_wrapper proc
  jmp mProcs[49 * 8]
midiInAddBuffer_wrapper endp
midiInClose_wrapper proc
  jmp mProcs[50 * 8]
midiInClose_wrapper endp
midiInGetDevCapsA_wrapper proc
  jmp mProcs[51 * 8]
midiInGetDevCapsA_wrapper endp
midiInGetDevCapsW_wrapper proc
  jmp mProcs[52 * 8]
midiInGetDevCapsW_wrapper endp
midiInGetErrorTextA_wrapper proc
  jmp mProcs[53 * 8]
midiInGetErrorTextA_wrapper endp
midiInGetErrorTextW_wrapper proc
  jmp mProcs[54 * 8]
midiInGetErrorTextW_wrapper endp
midiInGetID_wrapper proc
  jmp mProcs[55 * 8]
midiInGetID_wrapper endp
midiInGetNumDevs_wrapper proc
  jmp mProcs[56 * 8]
midiInGetNumDevs_wrapper endp
midiInMessage_wrapper proc
  jmp mProcs[57 * 8]
midiInMessage_wrapper endp
midiInOpen_wrapper proc
  jmp mProcs[58 * 8]
midiInOpen_wrapper endp
midiInPrepareHeader_wrapper proc
  jmp mProcs[59 * 8]
midiInPrepareHeader_wrapper endp
midiInReset_wrapper proc
  jmp mProcs[60 * 8]
midiInReset_wrapper endp
midiInStart_wrapper proc
  jmp mProcs[61 * 8]
midiInStart_wrapper endp
midiInStop_wrapper proc
  jmp mProcs[62 * 8]
midiInStop_wrapper endp
midiInUnprepareHeader_wrapper proc
  jmp mProcs[63 * 8]
midiInUnprepareHeader_wrapper endp
midiOutCacheDrumPatches_wrapper proc
  jmp mProcs[64 * 8]
midiOutCacheDrumPatches_wrapper endp
midiOutCachePatches_wrapper proc
  jmp mProcs[65 * 8]
midiOutCachePatches_wrapper endp
midiOutClose_wrapper proc
  jmp mProcs[66 * 8]
midiOutClose_wrapper endp
midiOutGetDevCapsA_wrapper proc
  jmp mProcs[67 * 8]
midiOutGetDevCapsA_wrapper endp
midiOutGetDevCapsW_wrapper proc
  jmp mProcs[68 * 8]
midiOutGetDevCapsW_wrapper endp
midiOutGetErrorTextA_wrapper proc
  jmp mProcs[69 * 8]
midiOutGetErrorTextA_wrapper endp
midiOutGetErrorTextW_wrapper proc
  jmp mProcs[70 * 8]
midiOutGetErrorTextW_wrapper endp
midiOutGetID_wrapper proc
  jmp mProcs[71 * 8]
midiOutGetID_wrapper endp
midiOutGetNumDevs_wrapper proc
  jmp mProcs[72 * 8]
midiOutGetNumDevs_wrapper endp
midiOutGetVolume_wrapper proc
  jmp mProcs[73 * 8]
midiOutGetVolume_wrapper endp
midiOutLongMsg_wrapper proc
  jmp mProcs[74 * 8]
midiOutLongMsg_wrapper endp
midiOutMessage_wrapper proc
  jmp mProcs[75 * 8]
midiOutMessage_wrapper endp
midiOutOpen_wrapper proc
  jmp mProcs[76 * 8]
midiOutOpen_wrapper endp
midiOutPrepareHeader_wrapper proc
  jmp mProcs[77 * 8]
midiOutPrepareHeader_wrapper endp
midiOutReset_wrapper proc
  jmp mProcs[78 * 8]
midiOutReset_wrapper endp
midiOutSetVolume_wrapper proc
  jmp mProcs[79 * 8]
midiOutSetVolume_wrapper endp
midiOutShortMsg_wrapper proc
  jmp mProcs[80 * 8]
midiOutShortMsg_wrapper endp
midiOutUnprepareHeader_wrapper proc
  jmp mProcs[81 * 8]
midiOutUnprepareHeader_wrapper endp
midiStreamClose_wrapper proc
  jmp mProcs[82 * 8]
midiStreamClose_wrapper endp
midiStreamOpen_wrapper proc
  jmp mProcs[83 * 8]
midiStreamOpen_wrapper endp
midiStreamOut_wrapper proc
  jmp mProcs[84 * 8]
midiStreamOut_wrapper endp
midiStreamPause_wrapper proc
  jmp mProcs[85 * 8]
midiStreamPause_wrapper endp
midiStreamPosition_wrapper proc
  jmp mProcs[86 * 8]
midiStreamPosition_wrapper endp
midiStreamProperty_wrapper proc
  jmp mProcs[87 * 8]
midiStreamProperty_wrapper endp
midiStreamRestart_wrapper proc
  jmp mProcs[88 * 8]
midiStreamRestart_wrapper endp
midiStreamStop_wrapper proc
  jmp mProcs[89 * 8]
midiStreamStop_wrapper endp
mixerClose_wrapper proc
  jmp mProcs[90 * 8]
mixerClose_wrapper endp
mixerGetControlDetailsA_wrapper proc
  jmp mProcs[91 * 8]
mixerGetControlDetailsA_wrapper endp
mixerGetControlDetailsW_wrapper proc
  jmp mProcs[92 * 8]
mixerGetControlDetailsW_wrapper endp
mixerGetDevCapsA_wrapper proc
  jmp mProcs[93 * 8]
mixerGetDevCapsA_wrapper endp
mixerGetDevCapsW_wrapper proc
  jmp mProcs[94 * 8]
mixerGetDevCapsW_wrapper endp
mixerGetID_wrapper proc
  jmp mProcs[95 * 8]
mixerGetID_wrapper endp
mixerGetLineControlsA_wrapper proc
  jmp mProcs[96 * 8]
mixerGetLineControlsA_wrapper endp
mixerGetLineControlsW_wrapper proc
  jmp mProcs[97 * 8]
mixerGetLineControlsW_wrapper endp
mixerGetLineInfoA_wrapper proc
  jmp mProcs[98 * 8]
mixerGetLineInfoA_wrapper endp
mixerGetLineInfoW_wrapper proc
  jmp mProcs[99 * 8]
mixerGetLineInfoW_wrapper endp
mixerGetNumDevs_wrapper proc
  jmp mProcs[100 * 8]
mixerGetNumDevs_wrapper endp
mixerMessage_wrapper proc
  jmp mProcs[101 * 8]
mixerMessage_wrapper endp
mixerOpen_wrapper proc
  jmp mProcs[102 * 8]
mixerOpen_wrapper endp
mixerSetControlDetails_wrapper proc
  jmp mProcs[103 * 8]
mixerSetControlDetails_wrapper endp
mmDrvInstall_wrapper proc
  jmp mProcs[104 * 8]
mmDrvInstall_wrapper endp
mmGetCurrentTask_wrapper proc
  jmp mProcs[105 * 8]
mmGetCurrentTask_wrapper endp
mmTaskBlock_wrapper proc
  jmp mProcs[106 * 8]
mmTaskBlock_wrapper endp
mmTaskCreate_wrapper proc
  jmp mProcs[107 * 8]
mmTaskCreate_wrapper endp
mmTaskSignal_wrapper proc
  jmp mProcs[108 * 8]
mmTaskSignal_wrapper endp
mmTaskYield_wrapper proc
  jmp mProcs[109 * 8]
mmTaskYield_wrapper endp
mmioAdvance_wrapper proc
  jmp mProcs[110 * 8]
mmioAdvance_wrapper endp
mmioAscend_wrapper proc
  jmp mProcs[111 * 8]
mmioAscend_wrapper endp
mmioClose_wrapper proc
  jmp mProcs[112 * 8]
mmioClose_wrapper endp
mmioCreateChunk_wrapper proc
  jmp mProcs[113 * 8]
mmioCreateChunk_wrapper endp
mmioDescend_wrapper proc
  jmp mProcs[114 * 8]
mmioDescend_wrapper endp
mmioFlush_wrapper proc
  jmp mProcs[115 * 8]
mmioFlush_wrapper endp
mmioGetInfo_wrapper proc
  jmp mProcs[116 * 8]
mmioGetInfo_wrapper endp
mmioInstallIOProcA_wrapper proc
  jmp mProcs[117 * 8]
mmioInstallIOProcA_wrapper endp
mmioInstallIOProcW_wrapper proc
  jmp mProcs[118 * 8]
mmioInstallIOProcW_wrapper endp
mmioOpenA_wrapper proc
  jmp mProcs[119 * 8]
mmioOpenA_wrapper endp
mmioOpenW_wrapper proc
  jmp mProcs[120 * 8]
mmioOpenW_wrapper endp
mmioRead_wrapper proc
  jmp mProcs[121 * 8]
mmioRead_wrapper endp
mmioRenameA_wrapper proc
  jmp mProcs[122 * 8]
mmioRenameA_wrapper endp
mmioRenameW_wrapper proc
  jmp mProcs[123 * 8]
mmioRenameW_wrapper endp
mmioSeek_wrapper proc
  jmp mProcs[124 * 8]
mmioSeek_wrapper endp
mmioSendMessage_wrapper proc
  jmp mProcs[125 * 8]
mmioSendMessage_wrapper endp
mmioSetBuffer_wrapper proc
  jmp mProcs[126 * 8]
mmioSetBuffer_wrapper endp
mmioSetInfo_wrapper proc
  jmp mProcs[127 * 8]
mmioSetInfo_wrapper endp
mmioStringToFOURCCA_wrapper proc
  jmp mProcs[128 * 8]
mmioStringToFOURCCA_wrapper endp
mmioStringToFOURCCW_wrapper proc
  jmp mProcs[129 * 8]
mmioStringToFOURCCW_wrapper endp
mmioWrite_wrapper proc
  jmp mProcs[130 * 8]
mmioWrite_wrapper endp
mmsystemGetVersion_wrapper proc
  jmp mProcs[131 * 8]
mmsystemGetVersion_wrapper endp
sndPlaySoundA_wrapper proc
  jmp mProcs[132 * 8]
sndPlaySoundA_wrapper endp
sndPlaySoundW_wrapper proc
  jmp mProcs[133 * 8]
sndPlaySoundW_wrapper endp
timeBeginPeriod_wrapper proc
  jmp mProcs[134 * 8]
timeBeginPeriod_wrapper endp
timeEndPeriod_wrapper proc
  jmp mProcs[135 * 8]
timeEndPeriod_wrapper endp
timeGetDevCaps_wrapper proc
  jmp mProcs[136 * 8]
timeGetDevCaps_wrapper endp
timeGetSystemTime_wrapper proc
  jmp mProcs[137 * 8]
timeGetSystemTime_wrapper endp
timeGetTime_wrapper proc
  jmp mProcs[138 * 8]
timeGetTime_wrapper endp
timeKillEvent_wrapper proc
  jmp mProcs[139 * 8]
timeKillEvent_wrapper endp
timeSetEvent_wrapper proc
  jmp mProcs[140 * 8]
timeSetEvent_wrapper endp
waveInAddBuffer_wrapper proc
  jmp mProcs[141 * 8]
waveInAddBuffer_wrapper endp
waveInClose_wrapper proc
  jmp mProcs[142 * 8]
waveInClose_wrapper endp
waveInGetDevCapsA_wrapper proc
  jmp mProcs[143 * 8]
waveInGetDevCapsA_wrapper endp
waveInGetDevCapsW_wrapper proc
  jmp mProcs[144 * 8]
waveInGetDevCapsW_wrapper endp
waveInGetErrorTextA_wrapper proc
  jmp mProcs[145 * 8]
waveInGetErrorTextA_wrapper endp
waveInGetErrorTextW_wrapper proc
  jmp mProcs[146 * 8]
waveInGetErrorTextW_wrapper endp
waveInGetID_wrapper proc
  jmp mProcs[147 * 8]
waveInGetID_wrapper endp
waveInGetNumDevs_wrapper proc
  jmp mProcs[148 * 8]
waveInGetNumDevs_wrapper endp
waveInGetPosition_wrapper proc
  jmp mProcs[149 * 8]
waveInGetPosition_wrapper endp
waveInMessage_wrapper proc
  jmp mProcs[150 * 8]
waveInMessage_wrapper endp
waveInOpen_wrapper proc
  jmp mProcs[151 * 8]
waveInOpen_wrapper endp
waveInPrepareHeader_wrapper proc
  jmp mProcs[152 * 8]
waveInPrepareHeader_wrapper endp
waveInReset_wrapper proc
  jmp mProcs[153 * 8]
waveInReset_wrapper endp
waveInStart_wrapper proc
  jmp mProcs[154 * 8]
waveInStart_wrapper endp
waveInStop_wrapper proc
  jmp mProcs[155 * 8]
waveInStop_wrapper endp
waveInUnprepareHeader_wrapper proc
  jmp mProcs[156 * 8]
waveInUnprepareHeader_wrapper endp
waveOutBreakLoop_wrapper proc
  jmp mProcs[157 * 8]
waveOutBreakLoop_wrapper endp
waveOutClose_wrapper proc
  jmp mProcs[158 * 8]
waveOutClose_wrapper endp
waveOutGetDevCapsA_wrapper proc
  jmp mProcs[159 * 8]
waveOutGetDevCapsA_wrapper endp
waveOutGetDevCapsW_wrapper proc
  jmp mProcs[160 * 8]
waveOutGetDevCapsW_wrapper endp
waveOutGetErrorTextA_wrapper proc
  jmp mProcs[161 * 8]
waveOutGetErrorTextA_wrapper endp
waveOutGetErrorTextW_wrapper proc
  jmp mProcs[162 * 8]
waveOutGetErrorTextW_wrapper endp
waveOutGetID_wrapper proc
  jmp mProcs[163 * 8]
waveOutGetID_wrapper endp
waveOutGetNumDevs_wrapper proc
  jmp mProcs[164 * 8]
waveOutGetNumDevs_wrapper endp
waveOutGetPitch_wrapper proc
  jmp mProcs[165 * 8]
waveOutGetPitch_wrapper endp
waveOutGetPlaybackRate_wrapper proc
  jmp mProcs[166 * 8]
waveOutGetPlaybackRate_wrapper endp
waveOutGetPosition_wrapper proc
  jmp mProcs[167 * 8]
waveOutGetPosition_wrapper endp
waveOutGetVolume_wrapper proc
  jmp mProcs[168 * 8]
waveOutGetVolume_wrapper endp
waveOutMessage_wrapper proc
  jmp mProcs[169 * 8]
waveOutMessage_wrapper endp
waveOutOpen_wrapper proc
  jmp mProcs[170 * 8]
waveOutOpen_wrapper endp
waveOutPause_wrapper proc
  jmp mProcs[171 * 8]
waveOutPause_wrapper endp
waveOutPrepareHeader_wrapper proc
  jmp mProcs[172 * 8]
waveOutPrepareHeader_wrapper endp
waveOutReset_wrapper proc
  jmp mProcs[173 * 8]
waveOutReset_wrapper endp
waveOutRestart_wrapper proc
  jmp mProcs[174 * 8]
waveOutRestart_wrapper endp
waveOutSetPitch_wrapper proc
  jmp mProcs[175 * 8]
waveOutSetPitch_wrapper endp
waveOutSetPlaybackRate_wrapper proc
  jmp mProcs[176 * 8]
waveOutSetPlaybackRate_wrapper endp
waveOutSetVolume_wrapper proc
  jmp mProcs[177 * 8]
waveOutSetVolume_wrapper endp
waveOutUnprepareHeader_wrapper proc
  jmp mProcs[178 * 8]
waveOutUnprepareHeader_wrapper endp
waveOutWrite_wrapper proc
  jmp mProcs[179 * 8]
waveOutWrite_wrapper endp
ExportByOrdinal2 proc
  jmp mProcs[180 * 8]
ExportByOrdinal2 endp
end