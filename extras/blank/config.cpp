#include "script_component.hpp"

// Template addon. Copy to addons\<name>\, set COMPONENT in script_component.hpp,
// and add "HCT_core", "HCT_interaction" to requiredAddons if it binds vehicles
// to the Interaction Framework.
class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"hatchet_vanilla_main"};
        author = AUTHOR;
        authors[] = {"Project Hatchet"};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
