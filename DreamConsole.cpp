#include "stdafx.h"
#include "DreamConsole.h"
#include "sha1.hpp"

#define DREAM_CONSOLE_PATH L".\\DreamVR\\DreamConsole.exe"

DreamConsole::DreamConsole() {
  _hPipe = INVALID_HANDLE_VALUE;
  _dwConsoleProcessId = NULL;
}

DreamConsole::~DreamConsole() {
  if(_hPipe != INVALID_HANDLE_VALUE) {
    ::DisconnectNamedPipe(_hPipe);
    ::CloseHandle(_hPipe);
    _hPipe = INVALID_HANDLE_VALUE;
  }
}

bool DreamConsole::Init() {
  // Ensure there's no pipe connected
  if(_hPipe != INVALID_HANDLE_VALUE) {
    ::DisconnectNamedPipe(_hPipe);
    ::CloseHandle(_hPipe);
    _hPipe = INVALID_HANDLE_VALUE;
  }

  wstringstream pipePath;
  pipePath << L"\\\\.\\pipe\\";

  wstringstream pipeName;

  pipeName << L"dream_console_" << (uint64_t)this << ::GetTickCount();

  pipePath << pipeName.str();

  // Create the pipe
  _hPipe = ::CreateNamedPipeW(
    pipePath.str().c_str(),		// pipe name 
    PIPE_ACCESS_OUTBOUND,	// read/write access, we're only writing...
    PIPE_TYPE_MESSAGE |     // message type pipe 
    PIPE_READMODE_BYTE |	// message-read mode 
    PIPE_WAIT,              // blocking mode 
    1,						// max. instances  
    4096,					// output buffer size 
    0,						// input buffer size (we don't read data, so 0 is fine)
    1,						// client time-out 
    NULL);                  // no security attribute 

  if(_hPipe == INVALID_HANDLE_VALUE) {
    // failure
    // "CreateNamedPipe failed"
    return false;
  }

  // Extra console : create another process , it's role is to display the pipe's output
  STARTUPINFOA si;
  ::GetStartupInfoA(&si);

  char cmdLine[MAX_PATH];

  ::sprintf(cmdLine, "%S --pipe \"%S\"", DREAM_CONSOLE_PATH, pipeName.str().c_str());

  BOOL bRet = ::CreateProcessA(NULL, cmdLine, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &_pi);
  if(!bRet) {
    ::CloseHandle(_hPipe);
    _hPipe = INVALID_HANDLE_VALUE;
    return false;
  }

  _dwConsoleProcessId = _pi.dwProcessId;

  // Connect to pipe
  BOOL bConnected = ::ConnectNamedPipe(_hPipe, NULL) ?
    TRUE : (::GetLastError() == ERROR_PIPE_CONNECTED);
  if(!bConnected) {
    // "ConnectNamedPipe failed"
    ::CloseHandle(_hPipe);
    _hPipe = INVALID_HANDLE_VALUE;
    return false;
  }

  ShareConsoleFile();

  return true;
}

void DreamConsole::ShareConsoleFile() {
  std::ofstream file(".\\DreamVR\\console");

  file << _dwConsoleProcessId << std::endl;
  file << reinterpret_cast<std::size_t>(_hPipe) << std::endl;

  file.flush();
  file.close();
}

void DreamConsole::SetColor(COLORS col) {
  DWORD cbWritten;
  BYTE command = (BYTE)COMMANDS::COLOR;
  BYTE color = (BYTE)col;

  ::WriteFile(_hPipe, &command, sizeof(BYTE), &cbWritten, NULL);
  ::WriteFile(_hPipe, &color, sizeof(BYTE), &cbWritten, NULL);
}

void DreamConsole::Write(wstring& text) {
  DWORD cbWritten;
  BYTE command = (BYTE)COMMANDS::WRITE;
  DWORD len = text.length() * sizeof(wchar_t);
  //DWORD len = ::wcslen(text.c_str()) * sizeof(wchar_t);

  ::WriteFile(_hPipe, &command, sizeof(BYTE), &cbWritten, NULL);
  ::WriteFile(_hPipe, &len, sizeof(DWORD), &cbWritten, NULL);
  ::WriteFile(_hPipe, text.c_str(), len, &cbWritten, NULL);
}

bool DreamConsole::IsOpen() {
  if(WAIT_TIMEOUT == WaitForSingleObject(_pi.hProcess, 0))
    return true;

  return false;
}

