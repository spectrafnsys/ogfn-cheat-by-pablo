#pragma once

namespace Offsets {
    constexpr uintptr_t GWorld = 0x91E3B40;          
    constexpr uintptr_t PersistentLevel = 0x30;
    constexpr uintptr_t Actors = 0x98;

    constexpr uintptr_t PlayerController = 0x30;     
    constexpr uintptr_t LocalPlayers = 0x38;          
    constexpr uintptr_t GameInstance = 0x1A0;         
    constexpr uintptr_t LocalPlayerArray = 0x38;

    constexpr uintptr_t PlayerCameraManager = 0x2B8; 
    constexpr uintptr_t CameraCache = 0x370;          
    constexpr uintptr_t CameraCachePOV_Location = 0x10; 
    constexpr uintptr_t CameraCachePOV_Rotation = 0x20; 
    constexpr uintptr_t CameraCachePOV_FOV = 0x2C;   

    constexpr uintptr_t RootComponent = 0x130;
    constexpr uintptr_t RelativeLocation = 0x11C;

    constexpr uintptr_t PlayerState = 0x2A8;
    constexpr uintptr_t TeamIndex = 0xED0;
    constexpr uintptr_t Health = 0xED8;
    constexpr uintptr_t Shield = 0xEDC;

    constexpr uintptr_t ControlRotation = 0x30C;     
}
