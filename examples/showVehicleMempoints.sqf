private _action = ["toggle_mem", "toggle vehicle mempoints", "", {DRAW_MEMPOINTS = !DRAW_MEMPOINTS;}, {true}] call ace_interact_menu_fnc_createAction;
[typeof player, 1, ["ACE_SelfActions"], _action] call ace_interact_menu_fnc_addActionToClass;

[] spawn {
    STOP_DRAWING = true;
    sleep 0.1;
    STOP_DRAWING = false;
    if (isNil "DRAW_MEMPOINTS") then {DRAW_MEMPOINTS = false;};
    if (isNil "CUSTOM_DRAW") then {CUSTOM_DRAW = [];};
    waitUntil { 
            {
                drawIcon3D [ 
                    "\a3\ui_f\data\IGUI\Cfg\Cursors\selected_ca.paa", 
                    [1,0,0,1], 
                    (vehicle player) modelToWorld _x, 
                    1, 
                    1, 
                    0, 
                    str _foreachIndex, 
                    2, 
                    0.03 
                ]; 
            } forEach CUSTOM_DRAW;
            if (DRAW_MEMPOINTS) then {
                {
                    drawIcon3D [ 
                        "\a3\ui_f\data\IGUI\Cfg\Cursors\selected_ca.paa", 
                        [1,1,1,1], 
                        (vehicle player) modelToWorld ((vehicle player) selectionPosition _x), 
                        1, 
                        1, 
                        0, 
                        _x, 
                        2, 
                        0.03 
                    ]; 
                } forEach (vehicle player selectionNames "memory");
        };
        STOP_DRAWING 
    };
}

/*
CUSTOM_DRAW = [

[-0.24322,0.669282,-0.925645],
[-0.24322,0.669282,-0.8885645],
[-0.24322,0.669282,-0.8555645]

]
*/