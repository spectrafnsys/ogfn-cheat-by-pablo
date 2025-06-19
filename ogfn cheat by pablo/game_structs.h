#pragma once
#include <cstdint>
#include <DirectXMath.h>

namespace SDK {

    struct FVector {
        float X, Y, Z;
    };

    struct FRotator {
        float Pitch, Yaw, Roll;
    };

    struct FTransform {
        FRotator Rotation;
        FVector Translation;
        FVector Scale3D;
    };

    struct AActor {
        uintptr_t VTable;
        FVector Location;
        FRotator Rotation;
    };

    struct AFortPawn : AActor {
        int TeamIndex;
        bool IsDead;
        bool IsDBNO;
        // Add more player related variables as needed
    };

} // namespace SDK
