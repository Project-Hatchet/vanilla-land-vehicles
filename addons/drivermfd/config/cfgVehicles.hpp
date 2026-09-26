// Driver MFD with a waypoint page for the NATO Panther (APC_Tracked_01).
// Untested since the framework's vxf -> hct rename; the MFD memory points
// (mfd_driver_1_*) need to be confirmed on the model before this is shipped.
class CfgVehicles {
    class APC_Tracked_01_base_F;
    class B_APC_Tracked_01_base_F: APC_Tracked_01_base_F {
        class MFD;
    };
    class B_APC_Tracked_01_rcws_F: B_APC_Tracked_01_base_F {
        class hct_driver {
            // Fallback prefix for module callbacks:
            // hatchet_vanilla_waypoints_fnc_{setup,perFrame,perSecond}
            projectPrefix = "hatchet_vanilla";
            class modules {
                class waypoints {
                    startOnEnter = 1;
                };
            };
            class interaction {
                class waypointPage {
                    condition = "true";
                    class MFD_L1 {
                        positionType = "coordinates";
                        position[] = {-0.833, 0.312142, -0.535};
                        label = "Next WP";
                        radius = 0.05;
                        buttonDown = "[_this # 0, 'cycle', 1] call hatchet_vanilla_waypoints_fnc_interaction;";
                    };
                    class MFD_L2: MFD_L1 {
                        position[] = {-0.833, 0.312142, -0.568};
                        label = "Prev WP";
                        buttonDown = "[_this # 0, 'cycle', -1] call hatchet_vanilla_waypoints_fnc_interaction;";
                    };
                };
            };
        }; // hct_driver
        class MFD: MFD {
            class MFD_DRIVER {
                bottomLeft = "mfd_driver_1_BL";
                topLeft = "mfd_driver_1_TL";
                topRight = "mfd_driver_1_TR";
                borderBottom = -8; // negative margins make the MFD larger than the mempoints it is defined between
                borderLeft = -3.5;
                borderRight = -1;
                borderTop = -8;
                alpha = 1;
                color[] = {1,1,1};
                enableParallax = 0;
                font = "RobotoCondensedLight";
                turret[] = {-1};
                class Bones {};
                class Draw {
                    class backgroundWrapper {
                        color[] = BACKGROUND_BLUE;
                        class background {
                            type = "polygon";
                            points[] = {
                                {
                                    {{0.08, 0.095},1},
                                    {{0.633, 0.097},1},
                                    {{0.633, 0.953},1},
                                    {{0.08, 0.956},1}
                                }
                            };
                        }; // background
                    }; // backgroundWrapper
                    #include "navigationDisplay.hpp"
                }; // Draw
            };
        };
    }; // B_APC_Tracked_01_rcws_F
};
