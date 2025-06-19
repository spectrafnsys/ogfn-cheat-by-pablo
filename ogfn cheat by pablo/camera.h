#pragma once
#include <DirectXMath.h>

namespace SDK {
    struct Camera {
        DirectX::XMFLOAT3 Location;
        DirectX::XMFLOAT3 Rotation;
        float FieldOfView;
    };
}
