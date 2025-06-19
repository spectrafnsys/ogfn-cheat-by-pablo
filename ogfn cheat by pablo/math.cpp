#include "math.h"
#include <cmath>

namespace Math {

    float GetDistance2D(float x1, float y1, float x2, float y2) {
        float dx = x2 - x1;
        float dy = y2 - y1;
        return std::sqrt(dx * dx + dy * dy);
    }

    DirectX::XMFLOAT3 CalculateAimRotation(const DirectX::XMFLOAT3& source, const DirectX::XMFLOAT3& target) {
        float dx = target.x - source.x;
        float dy = target.y - source.y;
        float dz = target.z - source.z;
        float hyp = std::sqrt(dx * dx + dy * dy);

        float pitch = -atan2f(dz, hyp) * (180.0f / 3.14159265359f);
        float yaw = atan2f(dy, dx) * (180.0f / 3.14159265359f);

        return DirectX::XMFLOAT3(pitch, yaw, 0.0f);
    }

}
