#pragma once

//.#include "targetver.h"
#include <SDKDDKVer.h>

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <iostream>
#include <queue>
#include <intrin.h>
#include <stdio.h>
#include <tchar.h>
#include <string>
#include <vector>

#include <windows.h>
#include "exports.h"
#include "enums.h"

using namespace std;

#include "DreamConsole.h"
#include "Console.h"
#include "Libs\httplib.h"



#include "sha1.hpp"
#include "Libs\json.hpp"

#include "MemoryModule.h"
#include "Utils.h"
#include "DreamUtils.h"

#include "DreamLoader.h"