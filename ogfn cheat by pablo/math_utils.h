// math_utils.h
#pragma once
#include "sdk.h"
#include <Windows.h>

// Simple WorldToScreen with camera info and screen size
bool WorldToScreen(const FVector& worldLocation, const FMinimalViewInfo& camInfo, int screenWidth, int screenHeight, FVector& outScreen) {
    FVector camForward;
    camForward.X = cosf(camInfo.Rotation.Pitch * (3.1415926535f / 180.f)) * cosf(camInfo.Rotation.Yaw * (3.1415926535f / 180.f));
    camForward.Y = cosf(camInfo.Rotation.Pitch * (3.1415926535f / 180.f)) * sinf(camInfo.Rotation.Yaw * (3.1415926535f / 180.f));
    camForward.Z = sinf(camInfo.Rotation.Pitch * (3.1415926535f / 180.f));

    FVector vDelta = worldLocation - camInfo.Location;
    float dot = vDelta.X * camForward.X + vDelta.Y * camForward.Y + vDelta.Z * camForward.Z;

    if (dot < 1.f)
        return false;

    float fov = camInfo.FOV;
    float screenCenterX = screenWidth / 2.f;
    float screenCenterY = screenHeight / 2.f;

    float angleYaw = atan2f(vDelta.Y, vDelta.X) - camInfo.Rotation.Yaw * (3.1415926535f / 180.f);
    float anglePitch = atanf(vDelta.Z / sqrtf(vDelta.X * vDelta.X + vDelta.Y * vDelta.Y)) - camInfo.Rotation.Pitch * (3.1415926535f / 180.f);

    outScreen.X = screenCenterX + (angleYaw * (screenCenterX / (fov * 0.5f * (3.1415926535f / 180.f))));
    outScreen.Y = screenCenterY - (anglePitch * (screenCenterX / (fov * 0.5f * (3.1415926535f / 180.f))));

    return (outScreen.X >= 0 && outScreen.X <= screenWidth && outScreen.Y >= 0 && outScreen.Y <= screenHeight);
}
