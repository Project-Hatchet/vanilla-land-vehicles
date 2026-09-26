/*
 * hatchet_vanilla_waypoints_fnc_perFrame
 *
 * Per-frame update of waypoint distance for the driver MFD.
 *
 * params (array)[(object) vehicle, (SCALAR) frameTime]
 *
 * MFD slots written here:
 *   userValue 1: distance to waypoint (m)
 */

params ["_vehicle", "_frameTime"];

private _position = if (customWaypointPosition isNotEqualTo []) then {
    customWaypointPosition
} else {
    waypointPosition [group player, currentWaypoint group player]
};

_vehicle setUserMFDValue [1, _vehicle distance2D _position];
