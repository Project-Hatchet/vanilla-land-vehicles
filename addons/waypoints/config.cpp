#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        // Pure functions; the framework calls them by name from the drivermfd
        // module config, so no framework load-order dependency is needed here.
        requiredAddons[] = {"hatchet_vanilla_main"};
        author = AUTHOR;
        authors[] = {"Project Hatchet"};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
