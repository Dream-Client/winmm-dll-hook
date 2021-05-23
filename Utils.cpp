#include "stdafx.h"
#include "Utils.h"

bool Utils::directoryExists(wstring path) {

  DWORD fileAttributes = GetFileAttributesW(path.c_str());

  if(fileAttributes == INVALID_FILE_ATTRIBUTES) {
    return false;
  }

  if(fileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
    return true;
  }

  return false;
}

bool Utils::fileExists(wstring path) {
  DWORD fileAttributes = GetFileAttributesW(path.c_str());

  if(fileAttributes == INVALID_FILE_ATTRIBUTES) {
    return false;
  }

  if(fileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
    return false;
  }

  return true;
}

void* Utils::loadFile(wstring path, size_t * pSize) {
  size_t read;
  void* result;
  FILE* fp;
  errno_t err;

  err = _wfopen_s(&fp, path.c_str(), _T("rb"));
  if(err) {
    Console::Log(L"Can't open DLL file == NULL");
    return nullptr;
  }
  //if(fp == NULL) {
  //  Console::Log(L"Can't open DLL file == NULL");
  //  return NULL;
  //}
  fseek(fp, 0, SEEK_END);
  *pSize = static_cast<size_t>(ftell(fp));
  if(*pSize == 0) {
    fclose(fp);
    return nullptr;
  }

  result = (unsigned char *)malloc(*pSize);
  if(result == nullptr) {
    return nullptr;
  }

  fseek(fp, 0, SEEK_SET);
  read = fread(result, 1, *pSize, fp);
  fclose(fp);
  if(read != *pSize) {
    free(result);
    return nullptr;
  }

  return result;
}

