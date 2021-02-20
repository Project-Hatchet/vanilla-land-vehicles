#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"hatchet_vanilla_main"};
        author = "";
        authors[] = {""};
        VERSION_CONFIG;
    };
};

#include "config\mfdDefines.hpp"
#include "config\cfgVehicles.hpp"
#include "CfgEventHandlers.hpp"
