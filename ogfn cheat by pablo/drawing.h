#pragma once
#include <Windows.h>
#include <d3d11.h>
#include <DirectXMath.h>

namespace Drawing {
    void Initialize(ID3D11Device* device, ID3D11DeviceContext* context);
    void DrawLine(float x1, float y1, float x2, float y2, const DirectX::XMFLOAT4& color);
    void DrawCircle(float x, float y, float radius, int segments, const DirectX::XMFLOAT4& color);
    void DrawText(const char* text, float x, float y, const DirectX::XMFLOAT4& color);
}
