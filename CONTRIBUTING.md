# Contributing

Most of the work in this repo is authoring click-point coordinates for vehicle interiors.
This guide gets you from a clone to a merged vehicle. Read the whole thing once; it is short.

## 1. Set up
1. Install Arma 3 with CBA A3 and the Hatchet Interaction Framework subscribed on the Workshop
   (IDs are in [.hemtt/launch.toml](.hemtt/launch.toml)).
2. Install HEMTT: `winget install hemtt`.
3. Clone the repo and run `hemtt check`. It must pass before you change anything.
4. Run `hemtt launch`. Arma starts with a file-patching dev build of this mod. Spawn an Offroad
   in the editor, sit in the driver's seat, look at the dashboard, and confirm the engine and
   lights labels appear. If they do, your setup works.

## 2. Claim a vehicle
Open a [coverage issue](https://github.com/Project-Hatchet/vanilla-land-vehicles/issues/new?template=vehicle_coverage.md)
naming the family and its `*_base_F` class from the table in [README.md](README.md#coverage).
One family per issue and per pull request.

## 3. Find coordinates
The framework ships a tool for this. In the editor, sit in the seat you are authoring, open the
debug console, and run:

```sqf
call hct_util_fnc_findModelSpaceCoordinates
```

Then, for each control:
1. Move your head (free look or TrackIR), open the Esc menu, and put the mouse cursor on the control.
2. In the debug console run:
   ```sqf
   hct_helperPoints pushBack [positionCameraToWorld [0,0,0], screenToWorld getMousePosition];
   ```
3. Move your head to a clearly different angle and repeat step 2.
4. The tool intersects the two lines, draws a cross at the result, and copies the coordinates to
   your clipboard as `x,y,z`. Check the cross sits on the control, then paste into the config.

For animated controls (levers, switches, doors) you can use a selection name instead of
coordinates: set `positionType = "anim"` and `position = "selection_name"`. To see every
memory point on the vehicle with its name, paste [examples/showVehicleMempoints.sqf](examples/showVehicleMempoints.sqf)
into the debug console.

## 4. Iterate without rebuilding
Put your config in a loose `.cpp` file and load it live:

```sqf
diag_mergeConfigFile ["C:\path\to\yourVehicle.cpp"]
```

Restart the mission (Esc > Restart). Vehicles spawned after that use the merged config.
When the positions look right, move the config into the addon and run `hemtt launch` once
more to confirm it works from the real build.

## 5. Write the config
Look at [addons/a3/config/Offroad_01.hpp](addons/a3/config/Offroad_01.hpp) for a real one and
[examples/config_example_polaris.cpp](examples/config_example_polaris.cpp) for a fully commented one.
Rules:

- **One file per family** under `addons/a3/config/`, named after the base class, and included
  from [CfgVehicles.hpp](addons/a3/config/CfgVehicles.hpp). Forward-declare only the parent you inherit from.
- **Patch the `*_base_F` class**, never a faction variant, so every variant inherits it. Check at
  least one variant per faction in game; some move controls (the armed Offroad, for example).
- **Seat classes:** driver controls (engine, lights, horn, driver door) go on `hct_driver`.
  Passenger-reachable controls (doors, ramps, PiP toggle) go on `hct_cargo`. Gunner controls go on
  `hct_turret_N`. Do not use the all-seats `hct` class for controls; a passenger should not be able
  to shut off the engine.
- **Only `class interaction` is read** from a seat class (and `class modules` for scripts).
  A button placed directly under `hct_driver` is silently ignored.
- **Use the shared snippets** in [addons/main/interactions/](addons/main/interactions/) for engine,
  lights, and PiP. Set `POSITION` and include the file, as the existing configs do.
- **Radius** is screen-space, scaled by field of view. Use 0.05 to 0.1 for dashboard controls.
  Anything above 0.15 starts stealing clicks from its neighbours.
- **Labels** are short and capitalised like the existing ones: `Engine on`, `Lights off`, `Horn`.
- **Code strings:** `hct_vehicle` is the vehicle, `hct_player` is the local player. In `condition`,
  `_this` is the vehicle object. In `buttonDown` and `buttonUp`, `_this` is `[vehicle]`.
- **Vanilla commands only.** No ACE, no other mod functions. `BIS_fnc_*` is fine.
- **CDLC vehicles** go in their own addon with `skipWhenMissingDependencies = 1`, like `addons/vn`.

## 6. Open the pull request
- Branch from `main`, one family per branch.
- Attach one screenshot per seat with the labels visible on the right controls.
- Update the coverage table in README.md.
- Add yourself to AUTHORS.txt.
- CI runs `hemtt check -e --pedantic` and the two Python validators. Run them locally first:
  `python tools/sqf_validator.py` and `python tools/config_style_checker.py`.

## Reference
- Framework config schema: the [Interaction Framework README](https://github.com/Project-Hatchet/Interaction-Framework#readme).
  Where it and the framework code disagree, the code wins; `addons/interaction/functions/fnc_loadItem.sqf`
  there lists every key that is actually read.
- Model memory points and MFDs: [Arma 3 MFD config reference](https://community.bistudio.com/wiki/A3_MFD_config_reference).
