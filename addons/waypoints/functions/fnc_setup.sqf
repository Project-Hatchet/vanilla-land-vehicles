/*
 * hatchet_vanilla_waypoints_fnc_setup
 *
 * Initial setup of the waypoint module. Must return true or the framework
 * will not start the perFrame / perSecond loops for this module.
 *
 * params (array)[(object) vehicle]
 */

params ["_vehicle"];

_vehicle setUserMFDValue [0, 0];
_vehicle setUserMFDValue [1, 0];
_vehicle setUserMFDText [0, "--:--:--"];
_vehicle setUserMFDText [1, "NO WPT"];
_vehicle setUserMFDText [2, ""];
_vehicle setUserMFDText [3, "0/0"];

true
