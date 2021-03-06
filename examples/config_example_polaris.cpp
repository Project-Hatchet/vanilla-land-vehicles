class cfgVehicles {
    class LSV_01_unarmed_base_F; // base class of the vehicle
    class B_LSV_01_unarmed_F: LSV_01_unarmed_base_F { // change the config of the quad bike
        class vxf { // framework
           class interaction { // to let the framework know these are buttons
                class engineOnButton { // name class for the button
                    condition = "!(isEngineOn (vehicle player))" // ! = "not" so if engine is not on it will display this button
                    positionType = "coordinates"; // type of position to mark location of button(can also be memory points)
                    position[] = {-0.708986,0.790938,-0.727872}; // coordinates to that button location
                    label = "Engine on"; // what the button will show as text when you look at it
                    radius = 0.3; // how close to the button you have to look to activate it
                    buttonDown = "vehicle player engineOn true;"; // if the player presses the button this is what it will do
                }; // engineOnButton^^
                class engineOffButton {
                    condition = "isEngineOn (vehicle player)"; // here the condition is "on" because there is no ! infront of it so if the engine is on it will display this button
                    positionType = "coordinates";
                    position[] = {-0.708986,0.790938,-0.727872};
                    label = "Engine off";
                    radius = 0.3;
                    buttonDown = "vehicle player engineOn false;";
                }; // engineOffButton^^
                class lightsOnbutton {
                    condition = "!(isLighton(vehicle player))";
                    positionType = "coordinates";
                    position[] = {-0.807986,0.790938,-0.727872};
                    label = "Lights on";
                    radius = 0.3;
                    buttonDown = "vehicle player setpilotLight true;";
                }; //lights on button ^^ 
                 class lightsOffbutton {
                    condition = "isLightOn (vehicle player)";
                    positionType = "coordinates";
                    position[] = {-0.807986,0.790938,-0.727872};
                    label = "Lights off";
                    radius = 0.3;
                    buttonDown = "vehicle player setpilotLight false;";
                }; // lights off button^^
            };
        };
    };
};

// diag_mergeConfigFile ["c:\path\to\file"] exectute this in your arma 3 debug console then press "local exec" make sure to press "restart" after or the effects wont take place
// script above adds 2 basic buttons to the polaris

// to find all of the script information visit these links
// https://github.com/Project-Hatchet/hatchet-framework/wiki/MFD-Editing-notes This link will show you how to use the framework and how to find memory points
// https://community.bistudio.com/wiki/A3_MFD_config_reference This link is used for making MFD displays
// https://community.bistudio.com/wiki/Category:Arma_3:_Scripting_Commands This link will show you all of the config stuff you can use if its not on this list it wont work