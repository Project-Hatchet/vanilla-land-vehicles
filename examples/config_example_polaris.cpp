// Minimal, current example: driver-seat engine and lights buttons on the Prowler.
// This is the same shape as addons/a3/config/LSV_01.hpp, written out in full
// without the shared #include snippets so every key is visible.
//
// Quick test without rebuilding the mod: save this file, then in the debug console
//   diag_mergeConfigFile ["C:\path\to\config_example_polaris.cpp"]
// and restart the mission (Esc > Restart). Vehicles spawned after that use it.
//
// Variables available inside the code strings:
//   hct_vehicle  the vehicle the framework is bound to
//   hct_player   the local player
//   _this        in condition: the vehicle object
//                in buttonDown/buttonUp: [vehicle]  (so _this # 0 is the vehicle)

class CfgVehicles {
    class Car_F;
    class LSV_01_base_F: Car_F {           // base class, so every faction variant inherits
        class hct_driver {                 // seat class: driver only
            class interaction {            // the framework reads only this (and modules)

                class EngineOn {           // a group: its condition gates everything inside
                    condition = "!isEngineOn hct_vehicle";
                    class engineOnButton {
                        positionType = "coordinates";                    // or "anim" with a selection name
                        position[] = {-0.717837, 0.870723, -0.764648};   // model space, from hct_util_fnc_findModelSpaceCoordinates
                        label = "Engine on";                             // shown when the cursor is over it
                        radius = 0.1;                                    // screen-space size, scaled by FOV; 0.05-0.1 for small controls
                        buttonDown = "hct_vehicle engineOn true;";
                    };
                };
                class EngineOff {
                    condition = "isEngineOn hct_vehicle";
                    class engineOffButton {
                        positionType = "coordinates";
                        position[] = {-0.717837, 0.870723, -0.764648};
                        label = "Engine off";
                        radius = 0.1;
                        buttonDown = "hct_vehicle engineOn false;";
                    };
                };

                class LightsOn {
                    condition = "!isLightOn hct_vehicle";
                    class lightsOnButton {
                        positionType = "coordinates";
                        position[] = {-0.828958, 0.869669, -0.765562};
                        label = "Lights on";
                        radius = 0.1;
                        buttonDown = "hct_vehicle setPilotLight true;";
                    };
                };
                class LightsOff {
                    condition = "isLightOn hct_vehicle";
                    class lightsOffButton {
                        positionType = "coordinates";
                        position[] = {-0.828958, 0.869669, -0.765562};
                        label = "Lights off";
                        radius = 0.1;
                        buttonDown = "hct_vehicle setPilotLight false;";
                    };
                };

            };
        };
    };
};
