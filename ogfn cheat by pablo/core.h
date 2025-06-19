#pragma once
#include <Windows.h>
#include "../thirdparty/minhook/MinHook.h"

namespace Core {
    inline HMODULE hModule = nullptr;

    bool Init();
}
