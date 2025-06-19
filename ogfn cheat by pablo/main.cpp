#include "../core/core.h"
#include "../features/esp.h"
#include "../features/aimbot.h"
#include "../features/menu.h"
#include <thread>

DWORD WINAPI MainThread(LPVOID) {
    Core::Init();
    while (!GetAsyncKeyState(VK_END)) {
        Features::ESP::TickRender();
        Features::Aimbot::TickGame();
        Features::Menu::Render();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    FreeLibraryAndExitThread(static_cast<HMODULE>(GetModuleHandle(nullptr)), 0);
}

BOOL APIENTRY DllMain(HMODULE hMod, DWORD reason, LPVOID) {
    if (reason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hMod);
        CreateThread(nullptr, 0, MainThread, hMod, 0, nullptr);
    }
    return TRUE;
}
