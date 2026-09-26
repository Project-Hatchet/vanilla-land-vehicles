#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        // Module loop lives in HCT_core, bezel buttons in HCT_interaction.
        requiredAddons[] = {"hatchet_vanilla_main", "hatchet_vanilla_waypoints", "HCT_core", "HCT_interaction"};
        author = AUTHOR;
        authors[] = {"Project Hatchet"};
        VERSION_CONFIG;
    };
};

#include "config\mfdDefines.hpp"
#include "config\cfgVehicles.hpp"
#include "CfgEventHandlers.hpp"
