#include "stdafx.h"
#include "Console.h"

DreamConsole* Console::_console = nullptr;

void Console::Init() {
  _console = new DreamConsole();
  _console->Init();
}

void Console::Log(wstring text) {
  _console->SetColor(COLORS::WHITE);
  _console->Write(text);
}

void Console::R(wstring text) {
  _console->SetColor(COLORS::LIGHT_RED);
  _console->Write(text);
}

void Console::G(wstring text) {
  _console->SetColor(COLORS::LIGHT_GREEN);
  _console->Write(text);
}

void Console::B(wstring text) {
  _console->SetColor(COLORS::LIGHT_BLUE);
  _console->Write(text);
}

void Console::A(wstring text) {
  _console->SetColor(COLORS::LIGHT_AQUA);
  _console->Write(text);
}

void Console::P(wstring text) {
  _console->SetColor(COLORS::LIGHT_PURPLE);
  _console->Write(text);
}

void Console::Y(wstring text) {
  _console->SetColor(COLORS::LIGHT_YELLOW);
  _console->Write(text);
}

bool Console::IsOpen() {
  return _console->IsOpen();
}
