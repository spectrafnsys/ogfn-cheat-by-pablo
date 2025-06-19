#include "menu.h"
#include "aimbot.h"
#include "esp.h"
#include <imgui.h>

namespace Features {
    namespace Menu {

        bool bShowMenu = true;

        void Render() {
            if (!bShowMenu)
                return;

            ImGui::Begin("Fortnite 9.10 Cheat Menu", &bShowMenu, ImGuiWindowFlags_NoCollapse);

            if (ImGui::BeginTabBar("MainTabs")) {

                if (ImGui::BeginTabItem("Aimbot")) {
                    ImGui::Checkbox("Enable Aimbot", &Aimbot::bEnabled);
                    ImGui::SliderFloat("FOV", &Aimbot::fFOV, 1.f, 180.f);
                    ImGui::SliderFloat("Smooth", &Aimbot::fSmooth, 1.f, 20.f);
                    ImGui::EndTabItem();
                }

                if (ImGui::BeginTabItem("ESP")) {
                    ImGui::Checkbox("Enable ESP", &ESP::bEnabled);
                    // You can add more ESP options here like box color, health bar toggle, etc.
                    ImGui::EndTabItem();
                }

                if (ImGui::BeginTabItem("Settings")) {
                    // General cheat settings, keys, misc toggles, etc.
                    ImGui::Text("Fortnite 9.10 cheat by ChatGPT");
                    ImGui::Text("Press INSERT to toggle menu");
                    ImGui::EndTabItem();
                }

                ImGui::EndTabBar();
            }

            ImGui::End();
        }

    } // namespace Menu
} // namespace Features
