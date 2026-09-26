#include "script_component.hpp"

// Interaction configs for S.O.G. Prairie Fire (CDLC) vehicles.
// Skipped automatically when the CDLC is not loaded.
class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"hatchet_vanilla_main", "HCT_core", "HCT_interaction", "loadorder_f_vietnam"};
        skipWhenMissingDependencies = 1;
        author = AUTHOR;
        authors[] = {"Project Hatchet"};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "config\CfgVehicles.hpp"
