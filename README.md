# Hatchet Vanilla Vehicles

Clickable interiors for base-game Arma 3 land vehicles, built on the
[Hatchet Interaction Framework](https://github.com/Project-Hatchet/Interaction-Framework).
Sit in the driver's seat, look at the dashboard, and press the interaction key on the
engine switch, the lights, the horn, or the door handle.

## Requirements
- Arma 3 2.18 or newer
- [CBA A3](https://steamcommunity.com/sharedfiles/filedetails/?id=450814997)
- [Hatchet Interaction Framework](https://steamcommunity.com/sharedfiles/filedetails/?id=2941986336) (stable)

No ACE dependency. Vehicles from a DLC only appear if you own that DLC.

## Scope
- `addons/a3`: base game and official Bohemia DLC land vehicles. One file per vehicle family.
- `addons/vn`: S.O.G. Prairie Fire vehicles. Loads only when the CDLC is present.
- `addons/drivermfd` and `addons/waypoints`: an experimental driver MFD with a waypoint page for the Panther. Untested since the framework's 2025 rename; kept for reference.

Other CDLCs are welcome as their own gated addon, following the `vn` pattern.
Third-party mod vehicles are out of scope here; they belong in their own compatibility mod.

## Coverage
Claim a family with a [coverage issue](https://github.com/Project-Hatchet/vanilla-land-vehicles/issues/new?template=vehicle_coverage.md) before you start, so two people do not author the same dashboard.

| Family | Base class | DLC | Status |
|---|---|---|---|
| Prowler | `LSV_01_base_F` | Apex | Done: engine, lights, horn |
| Offroad | `Offroad_01_base_F` | | Done: engine, lights, horn |
| Van | `Van_02_base_F` | Contact | Done: engine, lights, horn, driver door, PiP |
| Quadbike | `Quadbike_01_base_F` | | Open |
| Kart | `Kart_01_Base_F` | Karts | Open |
| Qilin | `LSV_02_base_F` | Apex | Open |
| Offroad (SUV) | `Offroad_02_base_F` | Contact | Open |
| Van (transport) | `Van_01_base_F` | Laws of War | Open |
| Tractor | `Tractor_01_base_F` | Contact | Open |
| Hunter | `MRAP_01_base_F` | | Open |
| Ifrit | `MRAP_02_base_F` | | Open |
| Strider | `MRAP_03_base_F` | | Open |
| HEMTT | `Truck_01_base_F` | | Open |
| Zamak | `Truck_02_base_F` | | Open |
| Tempest | `Truck_03_base_F` | | Open |
| Marshall | `APC_Wheeled_01_base_F` | | Open |
| Gorgon | `APC_Wheeled_02_base_F` | | Open |
| Panther | `APC_Tracked_01_base_F` | | Open (experimental driver MFD only) |
| Kamysh | `APC_Tracked_02_base_F` | | Open |
| Mora | `APC_Tracked_03_base_F` | | Open |
| Slammer | `MBT_01_base_F` | | Open |
| Varsuk | `MBT_02_base_F` | | Open |
| Kuma | `MBT_03_base_F` | | Open |
| Angara | `MBT_04_base_F` | Tanks | Open |
| Rhino | `AFV_Wheeled_01_base_F` | Tanks | Open |
| Nyx | `LT_01_base_F` | Tanks | Open |
| M113 (Prairie Fire) | `vn_armor_m113_01_base` | CDLC | Done: engine, lights, horn, ramp, reload, searchlight, PiP |
| UH-1 (Prairie Fire) | `vn_air_uh1_01_base` | CDLC | Placeholder: cabin doors only, cockpit coordinates not authored |

Artillery, anti-air, and CRV variants inherit from the families above and get their driver
controls for free once the base class is done.

## Building and testing
Install [HEMTT](https://github.com/BrettMayson/HEMTT) (`winget install hemtt`), then from the repo root:

```
hemtt check          # lint and rapify, same as CI
hemtt launch         # dev build with file patching, starts Arma with CBA and the framework
hemtt launch vn      # same, plus S.O.G. Prairie Fire
hemtt launch dev     # against the framework's unlisted development branch
hemtt build          # test build to .hemttout/build
```

See [CONTRIBUTING.md](CONTRIBUTING.md) for how to find coordinates and add a vehicle.

## License
[MIT](LICENSE). Contributors are listed in [AUTHORS.txt](AUTHORS.txt).
