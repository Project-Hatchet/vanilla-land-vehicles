/*
 * Draw every memory point of the vehicle you are sitting in, labelled by name.
 * Useful for positionType = "anim" interactions, where position is a selection name.
 *
 * Paste the whole file into the debug console and Local Exec once.
 * Then toggle drawing with:   DRAW_MEMPOINTS = !DRAW_MEMPOINTS;
 * And stop it for good with:  STOP_DRAWING = true;
 *
 * To check hand-picked coordinates, fill CUSTOM_DRAW with model-space points:
 *   CUSTOM_DRAW = [[-0.24,0.67,-0.92], [-0.24,0.67,-0.88]];
 *
 * For clickable button coordinates, prefer the framework tool instead:
 *   call hct_util_fnc_findModelSpaceCoordinates
 */

STOP_DRAWING = false;
if (isNil "DRAW_MEMPOINTS") then {DRAW_MEMPOINTS = true;};
if (isNil "CUSTOM_DRAW") then {CUSTOM_DRAW = [];};

if (!isNil "SHOW_MEMPOINTS_EH") then {removeMissionEventHandler ["Draw3D", SHOW_MEMPOINTS_EH];};
SHOW_MEMPOINTS_EH = addMissionEventHandler ["Draw3D", {
    if (STOP_DRAWING) exitWith {
        removeMissionEventHandler ["Draw3D", SHOW_MEMPOINTS_EH];
        SHOW_MEMPOINTS_EH = nil;
    };
    private _vehicle = vehicle player;
    if (isNull objectParent player) exitWith {};

    {
        drawIcon3D [
            "\a3\ui_f\data\IGUI\Cfg\Cursors\selected_ca.paa",
            [1,0,0,1],
            _vehicle modelToWorldVisual _x,
            1, 1, 0,
            str _forEachIndex,
            2, 0.03
        ];
    } forEach CUSTOM_DRAW;

    if (DRAW_MEMPOINTS) then {
        {
            drawIcon3D [
                "\a3\ui_f\data\IGUI\Cfg\Cursors\selected_ca.paa",
                [1,1,1,1],
                _vehicle modelToWorldVisual (_vehicle selectionPosition [_x, "Memory"]),
                1, 1, 0,
                _x,
                2, 0.03
            ];
        } forEach (_vehicle selectionNames "Memory");
    };
}];
