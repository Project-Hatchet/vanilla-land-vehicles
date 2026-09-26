// CBA macro layer. This mod has no ACE dependency; do not include ACE headers here.
#include "\x\cba\addons\main\script_macros_common.hpp"
#include "\x\cba\addons\xeh\script_xeh.hpp"

// CBA's default PREP looks for fnc_*.sqf in the component root. Our functions
// live in functions\ (ACE layout), so point PREP there. Same override as H-1.
#undef PREP
#ifdef DISABLE_COMPILE_CACHE
    #define PREP(fncName) FUNC(fncName) = compile preprocessFileLineNumbers QPATHTOF(functions\DOUBLES(fnc,fncName).sqf)
#else
    #define PREP(fncName) [QPATHTOF(functions\DOUBLES(fnc,fncName).sqf), QFUNC(fncName)] call CBA_fnc_compileFunction
#endif
