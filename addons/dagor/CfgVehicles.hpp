class HATCHET(EngineOn);
class HATCHET(EngineOff);
class HATCHET(LightsOn);
class HATCHET(LightsOff);

class CfgVehicles {
  class LSV_01_unarmed_base_F; // base class of the vehicle
  class B_LSV_01_unarmed_F: LSV_01_unarmed_base_F { // change the config of the quad bike
    class hatchet { // framework
      class interaction { // to let the framework know these are buttons
        class engineOnButton: HATCHET(EngineOn) { // name class for the button
          positionType = "coordinates"; // type of position to mark location of button(can also be memory points)
          position[] = {-0.708986,0.790938,-0.727872}; // coordinates to that button location
        }; // engineOnButton^^
        class engineOffButton: HATCHET(EngineOff) {
          positionType = "coordinates";
          position[] = {-0.708986,0.790938,-0.727872};
        }; // engineOffButton^^
        class lightsOnbutton: HATCHET(LightsOn) {
          positionType = "coordinates";
          position[] = {-0.807986,0.790938,-0.727872};
        }; //lights on button ^^
        class lightsOffbutton: HATCHET(LightsOff) {
          positionType = "coordinates";
          position[] = {-0.807986,0.790938,-0.727872};
        }; // lights off button^^
      };
    };
  };
};
