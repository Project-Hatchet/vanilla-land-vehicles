#include "script_component.hpp"

// Interaction configs for base-game (and official DLC) land vehicles.
// Config only: one file per vehicle family under config\, applied to the
// *_base_F class so every faction variant inherits it.
class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        // Module loop lives in HCT_core, click points in HCT_interaction.
        requiredAddons[] = {"hatchet_vanilla_main", "HCT_core", "HCT_interaction"};
        author = AUTHOR;
        authors[] = {"Project Hatchet"};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "config\CfgVehicles.hpp"
