class cfgVehicles {
  class B_LSV_01_unarmed_F; // base class of the vehicle
  class B_LSV_01_unarmed_H1: B_LSV_01_unarmed_F { // change the config of the quad bike
    displayName = "Hatchet Prowler (Should Work)";
    class vxf { // framework
      class interaction { // to let the framework know these are buttons
        class EngineOn {
          condition = "isEngineOn (vehicle player)"; // here the condition is "on" because there is no ! infront of it so if the engine is on it will display this button
          class engineOffButton {
            positionType = "coordinates";
            position[] = {-0.708986,0.790938,-0.727872};
            label = "Engine off";
            radius = 0.3;
            buttonDown = "vehicle player engineOn false;";
          }; // engineOffButton^^
        };
        class EngineOff {
          condition = "!(isEngineOn (vehicle player))"; // ! = "not" so if engine is not on it will display this button
          class engineOnButton { // name class for the button
            positionType = "coordinates"; // type of position to mark location of button(can also be memory points)
            position[] = {-0.708986,0.790938,-0.727872}; // coordinates to that button location
            label = "Engine on"; // what the button will show as text when you look at it
            radius = 0.3; // how close to the button you have to look to activate it
            buttonDown = "vehicle player engineOn true;"; // if the player presses the button this is what it will do
          }; // engineOnButton^^
        };
      };
    };
  };
  class B_LSV_01_unarmed_H2: B_LSV_01_unarmed_F { // change the config of the quad bike
    displayName = "Hatchet Prowler (Works)";
    class vxf { // framework
      class interaction { // to let the framework know these are buttons
        class engineOffButton {
          condition = "isEngineOn (vehicle player)"; // here the condition is "on" because there is no ! infront of it so if the engine is on it will display this button
          positionType = "coordinates";
          position[] = {-0.708986,0.790938,-0.727872};
          label = "Engine off";
          radius = 0.3;
          buttonDown = "vehicle player engineOn false;";
        }; // engineOffButton^^
        class engineOnButton { // name class for the button
          condition = "!(isEngineOn (vehicle player))"; // ! = "not" so if engine is not on it will display this button
          positionType = "coordinates"; // type of position to mark location of button(can also be memory points)
          position[] = {-0.708986,0.790938,-0.727872}; // coordinates to that button location
          label = "Engine on"; // what the button will show as text when you look at it
          radius = 0.3; // how close to the button you have to look to activate it
          buttonDown = "vehicle player engineOn true;"; // if the player presses the button this is what it will do
        }; // engineOnButton^^
      };
    };
  };
};
