#include "drawing.h"
#include <d3d11.h>
#include <DirectXMath.h>

namespace Drawing {

    static ID3D11Device* g_Device = nullptr;
    static ID3D11DeviceContext* g_Context = nullptr;

    void Initialize(ID3D11Device* device, ID3D11DeviceContext* context) {
        g_Device = device;
        g_Context = context;
    }

    void DrawLine(float x1, float y1, float x2, float y2, const DirectX::XMFLOAT4& color) {
        // TODO: Implement actual line drawing using your renderer or ImGui draw list
    }

    void DrawCircle(float x, float y, float radius, int segments, const DirectX::XMFLOAT4& color) {
        // TODO: Implement actual circle drawing using your renderer or ImGui draw list
    }

    void DrawText(const char* text, float x, float y, const DirectX::XMFLOAT4& color) {
        // TODO: Implement text drawing using your renderer or ImGui draw list
    }

}
