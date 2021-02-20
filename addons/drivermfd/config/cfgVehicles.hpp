class cfgVehicles {
	class APC_Tracked_01_base_F;
	class B_APC_Tracked_01_base_F: APC_Tracked_01_base_F {
		class MFD;
	};
	class B_APC_Tracked_01_rcws_F: B_APC_Tracked_01_base_F {
		class vxf {
			projectPrefix = "hatchet_vanilla";
			class modules {
				class waypoints {
					startOnEnter = 1;
				};
			};
			class interaction {
				crossHair = 1;
				class engineOnCondition {
					condition = "true";
					class MFD_L1 {
						positionType = "coordinates";
						position[] = {-0.833,0.312142,-0.535};
						label = "Next WP";
						radius = 0.05;
						buttonDown = "[_this # 0, ""cycle"", 1] call hatchet_vanilla_waypoints_fnc_interaction;";
					};
					class MFD_L2: MFD_L1 {
						position[] = {-0.833,0.312142,-0.568};
						label = "Prev WP";
						buttonDown = "[_this # 0, ""cycle"", 1] call hatchet_vanilla_waypoints_fnc_interaction;";
					};
					class MFD_L3: MFD_L1 {
						position[] = {-0.833,0.312142,-0.603};
						label = "Import waypoints";
						buttonDown = "[_this # 0, ""import""] call hatchet_vanilla_waypoints_fnc_interaction;";
					};
				};
			};
		}; // vxf
		class MFD: MFD {
			class MFD_DRIVER {
                bottomLeft = "mfd_driver_1_BL";
                topLeft = "mfd_driver_1_TL";
                topRight = "mfd_driver_1_TR";
                borderBottom = -8; // here I use a negative margin to make the MFD bigger than the mempoints it's defined between
                borderLeft = -3.5;
                borderRight = -1;
                borderTop = -8;
				alpha = 1; // opacity
                color[] = {1,1,1}; // default colour for MFD elements
                enableParallax = 0; // this means whether the MFD moves based on your head position, so this is used in a HUD
                font = "RobotoCondensedLight";
                turret[] = {-1}; // if you use any weapon related information in the MFD, it will use this turret's weapons
                class Bones {}; // here we can define bones, this is used for moving elements, like a waypoint overlay
                class Draw { // here we can draw elements
					class backgroundWrapper {
						color[] = BACKGROUND_BLUE;
						class background { // I'm drawing a background polygon here that just covers the whole MFD in a white square
							type = "polygon";
							points[] ={
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
	}; // B_APC_Tracked_01_base_F
};