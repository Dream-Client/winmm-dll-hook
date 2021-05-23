#pragma once
class Utils {
public:
  static bool directoryExists(wstring path);
  static bool fileExists(wstring path);
  static void* loadFile(wstring path, size_t *pSize);
};

