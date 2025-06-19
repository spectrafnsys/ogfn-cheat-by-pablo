struct FVector {
    float X, Y, Z;
    FVector operator-(const FVector& other) const { return { X - other.X, Y - other.Y, Z - other.Z }; }
    float Length() const { return sqrtf(X * X + Y * Y + Z * Z); }
};

struct FRotator {
    float Pitch, Yaw, Roll;
    void Normalize() {
        while (Yaw > 180.f) Yaw -= 360.f;
        while (Yaw < -180.f) Yaw += 360.f;
        if (Pitch > 89.f) Pitch = 89.f;
        if (Pitch < -89.f) Pitch = -89.f;
        Roll = 0.f;
    }
};
