#pragma once
#include <DirectXMath.h>

namespace Math {
    float GetDistance2D(float x1, float y1, float x2, float y2);
    DirectX::XMFLOAT3 CalculateAimRotation(const DirectX::XMFLOAT3& source, const DirectX::XMFLOAT3& target);
}
