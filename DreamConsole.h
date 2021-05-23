#pragma once
class DreamConsole {
public:
  DreamConsole();
  ~DreamConsole();


  bool Init();
  void ShareConsoleFile();
  void SetColor(COLORS col);
  void Write(wstring& text);
  bool IsOpen();
private:
  PROCESS_INFORMATION _pi;
  HANDLE _hPipe;
  volatile long _nLock;
  DWORD _dwConsoleProcessId;

  inline void EnterLock() {
    while(InterlockedCompareExchange(&_nLock, 1337, 0) != 0) {
      ::Sleep(0);
    }
  }

  inline void LeaveLock() {
    _nLock = 0;
  }

  inline bool WritePipe(
    /*__in      */ LPCVOID lpBuffer,
    /*__in      */ DWORD nNumberOfBytesToWrite,
    /*__out_opt */ LPDWORD lpNumberOfBytesWritten) {
    EnterLock();
    bool bRet = ::WriteFile(_hPipe, lpBuffer, nNumberOfBytesToWrite, lpNumberOfBytesWritten, nullptr);
    LeaveLock();
    return bRet;
  }
};

