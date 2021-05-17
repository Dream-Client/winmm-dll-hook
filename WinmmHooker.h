#pragma once
class WinmmHooker
{
public:
	static HINSTANCE _HinstDLL;

	static bool Hook();
	static void Free();
};

