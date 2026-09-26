/*
 * hatchet_vanilla_waypoints_fnc_interaction
 *
 * Handle interaction with the waypoint page. Called from MFD bezel buttons.
 *
 * params (array)[(object) vehicle, (string) action, (misc) value]
 *   action "cycle": value is the step to move the current waypoint by (+1 / -1)
 */

params ["_vehicle", "_action", ["_value", 0]];

switch (_action) do {
    case "cycle": {
        private _group = group player;
        private _count = count waypoints _group;
        if (_count == 0) exitWith {};
        private _index = ((currentWaypoint _group) + _value) max 0 min (_count - 1);
        _group setCurrentWaypoint [_group, _index];
    };
};

[_vehicle] call hatchet_vanilla_waypoints_fnc_perSecond;
