// Waypoint page. userText / userValue slots are written by
// addons/waypoints/functions/fnc_perSecond.sqf and fnc_perFrame.sqf.
class nav_wp_valid {
    condition = "wpvalid";
    TEXT_MFD_USER(WP_NAME,0.17,0.2,0.7,"right",1,1);   // waypoint name
    TEXT_MFD_USER(WP_DIR,0.17,0.25,0.7,"right",1,0);   // time to go
    TEXT_MFD_USER(WP_COUNT,0.1,0.28,0.7,"right",2,3);  // index / count

    // Bearing and distance, so a map marker (shift-click) shows direction too.
    TEXT_MFD_STATIC(WP_BRG_LABEL,0.17,0.33,0.7,"right","BRG");
    TEXT_MFD_VALUE(WP_BRG,0.24,0.33,0.7,"right",0,0,3);     // userValue 0: bearing, degrees
    TEXT_MFD_STATIC(WP_DIST_LABEL,0.17,0.38,0.7,"right","DIST");
    TEXT_MFD_VALUE(WP_DIST,0.24,0.38,0.7,"right",1,0,5);    // userValue 1: distance, metres

    SIDE_POLYGON(BTN_L1,0.088,LINE1);
    SIDE_POLYGON(BTN_L2,0.088,LINE2);
    SIDE_POLYGON(BTN_L3,0.088,LINE3);
    SIDE_POLYGON(BTN_L4,0.088,LINE4);
    SIDE_POLYGON(BTN_L5,0.088,LINE5);
    SIDE_POLYGON(BTN_L6,0.088,LINE6);
    SIDE_POLYGON(BTN_L7,0.088,LINE7);

    class poly_arrow_wp_next {
        type = "polygon";
        points[] = {
            {
                {{0.12,       0.2-0.02},1},
                {{0.12-0.015, 0.2+0.02},1},
                {{0.12+0.015, 0.2+0.02},1}
            }
        };
    };
    class poly_arrow_wp_prev {
        type = "polygon";
        points[] = {
            {
                {{0.12,       0.35+0.02},1},
                {{0.12-0.015, 0.35-0.02},1},
                {{0.12+0.015, 0.35-0.02},1}
            }
        };
    };
};
