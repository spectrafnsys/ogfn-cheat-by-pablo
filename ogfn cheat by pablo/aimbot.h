// aimbot.h
#pragma once
#include "sdk.h"
#include "offsets.h"

namespace Features {
	namespace Aimbot {

		void Tick(uintptr_t localPlayer, const FMinimalViewInfo& camInfo, int screenWidth, int screenHeight);

		extern bool bEnabled;
		extern float fFOV;
		extern float fSmooth;

	} // namespace Aimbot
} // namespace Features
