#include <Windows.h>
#include <thread>
#include <atomic>
#include <imgui.h>

namespace Features {
    namespace Menu {
        void Render();
        inline bool bShowMenu = true;
    }
    namespace ESP {
        void Render(uintptr_t localPlayer, int screenWidth, int screenHeight);
        inline bool bEnabled = true;
    }
    namespace Aimbot {
        void Tick(uintptr_t localPlayer, int screenWidth, int screenHeight);
        inline bool bEnabled = true;
    }
}

std::atomic<bool> g_Running = true;
uintptr_t g_LocalPlayer = 0;
int g_ScreenWidth = 1920;
int g_ScreenHeight = 1080;

uintptr_t GetLocalPlayer() {
    return g_LocalPlayer;
}

void CheatLoop() {
    while (g_Running.load()) {
        if (GetAsyncKeyState(VK_INSERT) & 1)
            Features::Menu::bShowMenu = !Features::Menu::bShowMenu;

        if (GetAsyncKeyState(VK_END) & 1)
            g_Running = false;

        if (!g_LocalPlayer)
            g_LocalPlayer = GetLocalPlayer();

        if (g_LocalPlayer) {
            Features::Menu::Render();
            Features::ESP::Render(g_LocalPlayer, g_ScreenWidth, g_ScreenHeight);
            Features::Aimbot::Tick(g_LocalPlayer, g_ScreenWidth, g_ScreenHeight);
        }

        Sleep(10);
    }

    FreeLibraryAndExitThread(GetModuleHandle(nullptr), 0);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hModule);
        std::thread(CheatLoop).detach();
    }
    return TRUE;
}
