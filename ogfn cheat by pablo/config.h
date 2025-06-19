#pragma once

namespace Config {
    struct {
        bool bEnableAimbot = true;
        float fAimbotFOV = 30.0f;
        float fSmooth = 6.0f;
        int iAimbotKey = VK_RBUTTON;
        bool bSilentAim = false;
        bool bBulletTP = false;
    } Aimbot;

    struct {
        bool bShowESP = true;
        bool bBoxes = true;
        bool bNames = true;
        bool bHealth = true;
        float fMaxDistance = 250.0f;
    } Esp;
}
