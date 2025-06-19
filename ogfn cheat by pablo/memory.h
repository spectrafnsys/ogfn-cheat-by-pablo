#pragma once

template<typename T>
T ReadPointer(uintptr_t base, std::vector<uintptr_t> offsets) {
    uintptr_t addr = base;
    for (size_t i = 0; i < offsets.size(); i++) {
        addr = *(uintptr_t*)(addr + offsets[i]);
        if (addr == 0) return T{};
    }
    return *(T*)addr;
}
