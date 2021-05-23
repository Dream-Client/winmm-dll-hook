#pragma once
class Console {
public:
  static DreamConsole* _console;

  static void Init();
  static void Log(wstring text);
  static void R(wstring text);
  static void G(wstring text);
  static void B(wstring text);
  static void A(wstring text);
  static void P(wstring text);
  static void Y(wstring text);
  static bool IsOpen();
};

