#include "core.h"
#include "hooks.h"
#include "logger.h"

bool Core::Init() {
    logger::Init("fnv9_cheat.log");
    MH_Initialize();
    Hooks::SetupHooks();
    return true;
}
