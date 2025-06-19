// esp.h
#pragma once
#include "sdk.h"
#include "offsets.h"
#include "camera.h"

namespace Features {
    namespace ESP {
        void Render(uintptr_t localPlayer, const FMinimalViewInfo& camInfo, int screenWidth, int screenHeight);
        extern bool bEnabled;
    }
}
