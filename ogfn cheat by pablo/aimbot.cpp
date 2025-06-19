// aimbot.cpp
#include "aimbot.h"
#include <cmath>

namespace Features {
    namespace Aimbot {

        bool bEnabled = true;
        float fFOV = 30.f;
        float fSmooth = 5.f;

        static float CalcFOV(const FRotator& viewRotation, const FVector& targetPos, const FVector& camLoc) {
            FVector delta = targetPos - camLoc;
            float distXY = sqrtf(delta.X * delta.X + delta.Y * delta.Y);
            float pitch = -atan2f(delta.Z, distXY) * (180.f / 3.1415926535f);
            float yaw = atan2f(delta.Y, delta.X) * (180.f / 3.1415926535f);

            float pitchDiff = pitch - viewRotation.Pitch;
            float yawDiff = yaw - viewRotation.Yaw;

            while (yawDiff > 180.f) yawDiff -= 360.f;
            while (yawDiff < -180.f) yawDiff += 360.f;

            return sqrtf(pitchDiff * pitchDiff + yawDiff * yawDiff);
        }

        static FRotator SmoothAim(const FRotator& current, const FRotator& target, float smooth) {
            FRotator delta{ target.Pitch - current.Pitch, target.Yaw - current.Yaw, 0.f };
            while (delta.Yaw > 180.f) delta.Yaw -= 360.f;
            while (delta.Yaw < -180.f) delta.Yaw += 360.f;

            FRotator smoothed{
                current.Pitch + delta.Pitch / smooth,
                current.Yaw + delta.Yaw / smooth,
                0.f
            };
            smoothed.Normalize();
            return smoothed;
        }

        void Tick(uintptr_t localPlayer, const FMinimalViewInfo& camInfo, int screenWidth, int screenHeight) {
            if (!bEnabled || !localPlayer) return;

            uintptr_t playerController = *(uintptr_t*)(localPlayer + Offsets::PlayerController);
            if (!playerController) return;

            FRotator controlRotation = *(FRotator*)(playerController + Offsets::ControlRotation);

            uintptr_t gWorld = *(uintptr_t*)Offsets::GWorld;
            if (!gWorld) return;

            uintptr_t persistentLevel = *(uintptr_t*)(gWorld + Offsets::PersistentLevel);
            if (!persistentLevel) return;

            uintptr_t actorsArray = *(uintptr_t*)(persistentLevel + Offsets::Actors);
            int actorsCount = *(int*)(actorsArray + 0x10);
            uintptr_t actorsData = *(uintptr_t*)(actorsArray + 0x18);

            float bestFOV = fFOV;
            FVector bestTargetPos{};
            uintptr_t bestTargetActor = 0;

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

                FVector targetPos = *(FVector*)(rootComp + Offsets::RelativeLocation);

                float fovToTarget = CalcFOV(controlRotation, targetPos, camInfo.Location);

                if (fovToTarget < bestFOV) {
                    bestFOV = fovToTarget;
                    bestTargetPos = targetPos;
                    bestTargetActor = actor;
                }
            }

            if (bestTargetActor != 0) {
                // Calculate new rotation to target
                FVector delta = bestTargetPos - camInfo.Location;
                float distXY = sqrtf(delta.X * delta.X + delta.Y * delta.Y);
                float pitch = -atan2f(delta.Z, distXY) * (180.f / 3.1415926535f);
                float yaw = atan2f(delta.Y, delta.X) * (180.f / 3.1415926535f);

                FRotator targetRot{ pitch, yaw, 0.f };
                FRotator newRot = SmoothAim(controlRotation, targetRot, fSmooth);

                // Write control rotation back (replace with your memory writing method)
                *(FRotator*)(playerController + Offsets::ControlRotation) = newRot;
            }
        }

    } // namespace Aimbot
} // namespace Features
