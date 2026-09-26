#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        // CBA only. The Interaction Framework itself is CBA-only, and the
        // vehicle addons declare their own HCT_core / HCT_interaction dependency.
        requiredAddons[] = {"cba_main"};
        author = AUTHOR;
        authors[] = {"Project Hatchet"};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgModuleCategories.hpp"
