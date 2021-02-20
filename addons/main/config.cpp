#include "script_component.hpp"

class CfgPatches {
  class ADDON {
    name = COMPONENT_NAME;
    units[] = {};
    weapons[] = {};
    requiredVersion = REQUIRED_VERSION;
    requiredAddons[] = {"cba_common", "hatchet_main"};
    author = "Project Hatchet";
    VERSION_CONFIG;
  };
};

#include "CfgEventHandlers.hpp"
#include "CfgModuleCategories.hpp"
