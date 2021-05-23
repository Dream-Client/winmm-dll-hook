#include "stdafx.h"
#include "DreamLoader.h"
#include "CommandLine.h"
#include "LicenceLoader.h"
#include "ClientDownloader.h"

bool DreamLoader::Init() {
  Console::Init();

  Console::Log(L"================================================");
  Console::Log(L"== DreamLoader v2.0.0");
  Console::Log(L"== Provided by yamiM0NSTER");
  Console::Log(L"================================================");

  if(!Utils::directoryExists(L"DreamVR")) {
    Console::R(L"Failed to find DreamVR directory, Dream Client will not be loaded.");
    Sleep(3000);
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
    return false;
  }

  if(!Utils::directoryExists(L"DreamVR\\Preferences")) {
    Console::Log(L"Failed to find DreamVR\\Preferences directory, client will not be loaded");
    Sleep(3000);
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
    return false;
  }

  if(CommandLine::_noHost) {
    Console::Log(L"No host flag active.");
  }

  bool shouldContinue = DreamUtils::LoadLocalClient();

  if(!shouldContinue)
    return false;

  GetClient();

  LoadDownloadedClient();

  return true;
}

void DreamLoader::GetClient() {
  LicenceLoader::Initialize();

  string checksum = Sha1::from_file(".\\GameAssembly.dll");
  wstringstream ss;
  ss << checksum.c_str();
  Console::A(L"GameAssembly checksum:");
  Console::A(ss.str());

  ClientDownloader::Download();

  if(ClientDownloader::_clientData == nullptr) {
    Console::Y(L"Game will start without Dream Client");
    Sleep(3000);
  }
}

void DreamLoader::LoadDownloadedClient() {
  if(ClientDownloader::_clientData == nullptr) {
    return;
  }

  wstringstream ss;
  ss << L"Client size:" << ClientDownloader::_clientSize;
  Console::A(ss.str());

  DreamUtils::DecryptClient(ClientDownloader::_clientData, ClientDownloader::_clientSize);

  HMEMORYMODULE handle = MemoryLoadLibrary(ClientDownloader::_clientData, ClientDownloader::_clientSize);
  if(handle == nullptr) {
    Console::Log(L"Downloaded client handle == NULL.");
    Console::Y(L"Game will start without Dream Client");
    Sleep(3000);
    return;
  }

  Console::Log(L"Downloaded client loaded.");
}
