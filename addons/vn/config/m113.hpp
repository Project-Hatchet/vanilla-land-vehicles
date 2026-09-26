// S.O.G. Prairie Fire M113 family.
// Every seat's click points live inside its class interaction {}; the framework
// reads nothing else from a seat class.
class vn_armor_m113_base: APC_Tracked_01_base_F {};
class vn_armor_m113_01_base: vn_armor_m113_base {
  class hct_driver {
    class interaction {
      #ifdef POSITION
        #undef POSITION
      #endif
      #define POSITION -1.10131,1.66283,-0.621141
      #include "\z\hatchet_vanilla\addons\main\interactions\EngineOnOff.hpp"

      class Horn {
        class hornButton {
          positionType = "coordinates";
          position[] = {-0.622199,1.9071,-0.558011};
          label = "Horn";
          radius = 0.1;
          buttonDown = "[hct_vehicle, 'vn_m113_horn'] call BIS_fnc_fire;";
        };
      };

      #undef POSITION
      #define POSITION -1.1049,1.68096,-0.58947
      #include "\z\hatchet_vanilla\addons\main\interactions\LightsOnOff.hpp"

      class cargo_ramp {
        condition = "hct_vehicle animationSourcePhase 'inWater' < 0.1";
        class cargo_ramp {
          position = "cargo_ramp_lever_axis";
          positionType = "anim";
          label = "Ramp";
          animation = "cargo_ramp";
          interactionCondition = "true";
          animStates[] = {0, 1};
          animLabels[] = {"Closed", "Open"};
          animStart = "hct_vehicle animateDoor ['rampCargo', [1, 0] select ((hct_vehicle doorPhase 'rampCargo') > 0.5)];";
          animEnd = "";
          radius = 0.1;
        };
      };
    }; // interaction
  }; // hct_driver

  class hct_cargo {
    class interaction {
      class cargo_ramp {
        condition = "hct_vehicle animationSourcePhase 'inWater' < 0.1";
        class cargo_ramp {
          position = "cargo_door_handle_int_axis";
          positionType = "anim";
          label = "Ramp";
          animation = "cargo_ramp";
          animStates[] = {0, 1};
          animLabels[] = {"Closed", "Open"};
          animStart = "hct_vehicle animateDoor ['rampCargo', [1, 0] select ((hct_vehicle doorPhase 'rampCargo') > 0.5)];";
          animEnd = "";
          radius = 0.1;
        };
      };

      #undef POSITION
      #define POSITION -0.000680611,0.89321,-0.348099
      #include "\z\hatchet_vanilla\addons\main\interactions\TogglePip.hpp"
    }; // interaction
  }; // hct_cargo

  class hct_turret_0 {
    class interaction {
      class Reload {
        class ReloadButton {
          positionType = "anim";
          position = "mg1_ammobelt_shake_mov_axis";
          label = "Reload";
          radius = 0.1;
          buttonDown = "[] call hct_util_fnc_reloadTurret";
        };
      };
      class SearchLight {
        class SearchLightOnButton {
          positionType = "anim";
          position = "mg1_light_1_pos";
          label = "SearchLight";
          radius = 0.1;
          buttonDown = "hct_player action ['SearchlightOn', hct_vehicle];";
        };
      };
    }; // interaction
  }; // hct_turret_0

  class hct_turret_1 {
    class interaction {
      #undef POSITION
      #define POSITION -0.000680611,0.89321,-0.348099
      #include "\z\hatchet_vanilla\addons\main\interactions\TogglePip.hpp"
    }; // interaction
  }; // hct_turret_1

  class hct_turret_2 {
    class interaction {
      class cargo_ramp {
        condition = "!isTurnedOut hct_player && {hct_vehicle animationSourcePhase 'inWater' < 0.1}";
        class cargo_ramp {
          interactionCondition = "!isTurnedOut hct_player";
          position = "cargo_door_handle_int_axis";
          positionType = "anim";
          label = "Ramp";
          animation = "cargo_ramp";
          animStates[] = {0, 1};
          animLabels[] = {"Closed", "Open"};
          animStart = "hct_vehicle animateDoor ['rampCargo', [1, 0] select ((hct_vehicle doorPhase 'rampCargo') > 0.5)];";
          animEnd = "";
          radius = 0.1;
        };
      };

      #undef POSITION
      #define POSITION -0.000680611,0.89321,-0.348099
      #include "\z\hatchet_vanilla\addons\main\interactions\TogglePip.hpp"
    }; // interaction
  }; // hct_turret_2

  class hct_turret_3: hct_turret_2 {};
}; // vn_armor_m113_01_base

class vn_armor_m113_acav_m2_base: vn_armor_m113_01_base {
  // Re-open inherited seats explicitly so the base entries are kept and only
  // the moved controls are overridden.
  class hct_driver: hct_driver {
    class interaction: interaction {
      #undef POSITION
      #define POSITION -1.10162,1.6603,-0.670251
      #include "\z\hatchet_vanilla\addons\main\interactions\EngineOnOff.hpp"

      class Horn: Horn {
        class hornButton: hornButton {
          position[] = {-0.622505,1.90457,-0.607121};
        };
      };

      #undef POSITION
      #define POSITION -1.10521,1.67843,-0.63858
      #include "\z\hatchet_vanilla\addons\main\interactions\LightsOnOff.hpp"
    }; // interaction
  }; // hct_driver

  class hct_turret_2: hct_turret_2 {
    class interaction: interaction {
      class Reload {
        class ReloadButton {
          positionType = "anim";
          position = "mg2_belt_translate_axis";
          label = "Reload";
          radius = 0.1;
          buttonDown = "[] call hct_util_fnc_reloadTurret";
        };
      };
    }; // interaction
  }; // hct_turret_2

  class hct_turret_3: hct_turret_3 {
    class interaction: interaction {
      class Reload {
        class ReloadButton {
          positionType = "anim";
          position = "mg3_belt_translate_axis";
          label = "Reload";
          radius = 0.1;
          buttonDown = "[] call hct_util_fnc_reloadTurret";
        };
      };
    }; // interaction
  }; // hct_turret_3
}; // vn_armor_m113_acav_m2_base
