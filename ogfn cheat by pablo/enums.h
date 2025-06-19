#pragma once

namespace SDK {
    enum class ETeam : int {
        Unknown = -1,
        Team1 = 0,
        Team2 = 1,
        // Add more teams if needed
    };

    enum class EWeaponType : int {
        None = 0,
        AssaultRifle,
        Sniper,
        Shotgun,
        // etc
    };
}
