/*
 * hatchet_vanilla_waypoints_fnc_perSecond
 *
 * Occasional updates of waypoint data for the driver MFD.
 * Started by the framework module loop; see addons/drivermfd/config/cfgVehicles.hpp.
 *
 * params (array)[(object) vehicle]
 *
 * MFD slots written here:
 *   userText 0: time to go (h:m:s)
 *   userText 1: waypoint name
 *   userText 2: waypoint grid
 *   userText 3: waypoint index / count
 *   userValue 0: bearing to waypoint
 */

params ["_vehicle"];

private _group = group player;
private _wayPoint = [_group, currentWaypoint _group];
private _position = waypointPosition _wayPoint;
private _hasWaypoint = (waypoints _group) isNotEqualTo [] && {_position isNotEqualTo [0,0,0]};

if (customWaypointPosition isNotEqualTo []) then {
    _position = customWaypointPosition;
    _hasWaypoint = true;
    _vehicle setUserMFDText [1, "MAP MARK"];
} else {
    _vehicle setUserMFDText [1, ["NO WPT", waypointDescription _wayPoint] select _hasWaypoint];
};

if (!_hasWaypoint) exitWith {
    _vehicle setUserMFDValue [0, 0];
    _vehicle setUserMFDText [0, "--:--:--"];
    _vehicle setUserMFDText [2, ""];
    _vehicle setUserMFDText [3, "0/0"];
};

_vehicle setUserMFDValue [0, _vehicle getDir _position];

// Vanilla grid; the previous ACE MGRS helpers are gone with the ACE dependency.
_vehicle setUserMFDText [2, mapGridPosition _position];
_vehicle setUserMFDText [3, format ["%1/%2", (currentWaypoint _group) + 1, count waypoints _group]];

if (speed _vehicle > 2) then {
    private _speedMS = vectorMagnitude (velocity _vehicle);
    private _tofSecondsTotal = (_position distance _vehicle) / _speedMS;
    private _tofHours = floor (_tofSecondsTotal / 60 / 60);
    private _tofMinutes = floor (_tofSecondsTotal / 60 % 60);
    private _tofSeconds = round (_tofSecondsTotal % 60);
    _vehicle setUserMFDText [0, format ["%1:%2:%3", _tofHours, _tofMinutes, _tofSeconds]];
} else {
    _vehicle setUserMFDText [0, "--:--:--"];
};
