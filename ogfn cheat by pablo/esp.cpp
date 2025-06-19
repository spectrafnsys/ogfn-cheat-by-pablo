#include "esp.h"
#include <Imgui.h>
#include <Windows.h>


namespace Features {
    namespace ESP {

        bool bEnabled = true;

        void Render(uintptr_t localPlayer, const FMinimalViewInfo& camInfo, int screenWidth, int screenHeight) {
            if (!bEnabled || !localPlayer) return;

            uintptr_t gWorld = *(uintptr_t*)Offsets::GWorld;
            if (!gWorld) return;

            uintptr_t persistentLevel = *(uintptr_t*)(gWorld + Offsets::PersistentLevel);
            if (!persistentLevel) return;

            uintptr_t actorsArray = *(uintptr_t*)(persistentLevel + Offsets::Actors);
            int actorsCount = *(int*)(actorsArray + 0x10);
            uintptr_t actorsData = *(uintptr_t*)(actorsArray + 0x18);

            int localTeam = *(int*)(*(uintptr_t*)(localPlayer + Offsets::PlayerState) + Offsets::TeamIndex);

            for (int i = 0; i < actorsCount; i++) {
                uintptr_t actor = *(uintptr_t*)(actorsData + i * sizeof(uintptr_t));
                if (!actor) continue;

                uintptr_t playerState = *(uintptr_t*)(actor + Offsets::PlayerState);
                if (!playerState) continue;

                int targetTeam = *(int*)(playerState + Offsets::TeamIndex);
                if (targetTeam == localTeam) continue;

                float health = *(float*)(playerState + Offsets::Health);
                if (health <= 0.f) continue;

                uintptr_t rootComp = *(uintptr_t*)(actor + Offsets::RootComponent);
                if (!rootComp) continue;

                FVector pos = *(FVector*)(rootComp + Offsets::RelativeLocation);

                FVector screenPos;
                if (!WorldToScreen(pos, camInfo, screenWidth, screenHeight, screenPos))
                    continue;

                // Draw simple box and health bar
                float boxWidth = 40.f;
                float boxHeight = 80.f;

                ImDrawList* drawList = ImGui::GetOverlayDrawList();
                ImVec2 topLeft(screenPos.X - boxWidth / 2.f, screenPos.Y - boxHeight);
                ImVec2 bottomRight(screenPos.X + boxWidth / 2.f, screenPos.Y);

                drawList->AddRect(topLeft, bottomRight, IM_COL32(255, 0, 0, 255));

                // Health bar on the left
                float healthPercent = health / 100.f;
                ImVec2 healthBarTop = ImVec2(topLeft.x - 6.f, topLeft.y + (boxHeight * (1.f - healthPercent)));
                ImVec2 healthBarBottom = ImVec2(topLeft.x - 2.f, bottomRight.y);
                drawList->AddRectFilled(healthBarTop, healthBarBottom, IM_COL32(0, 255, 0, 255));
            }
        }

    } // namespace ESP
} // namespace Features
