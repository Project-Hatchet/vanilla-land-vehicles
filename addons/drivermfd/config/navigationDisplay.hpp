class nav_wp_valid {
    condition = "wpvalid";
    TEXT_MFD_R_SCALE(WP_NAME,0.15,0.3,0.7,"right")
        source="userText";
        sourceScale=1;
        sourceIndex=1;
    }; // WP_NAME

    TEXT_MFD_R_SCALE(WP_DIR,0.15,0.3+(0.05),0.7,"right")
        source="userText";
        sourceScale=1;
        sourceIndex=0;
    }; // ETA

    TEXT_MFD_R_SCALE(WP_COUNT,0.1,LINE2+(SIDE_BTN_SPACING*0.5),0.7,"right")
        source="userText";
        sourceScale=2;
        sourceIndex=3;
    }; // WP_COUNT
	class WPCaret
	{
		type="line";
		width=4;
		points[]=
		{
			{"WP_DIR_BONE",1,"WP_DIR_LIMITS",1,{-0.010, 0.015},1},
			{"WP_DIR_BONE",1,"WP_DIR_LIMITS",1,{ 0.000, 0.000},1},
			{"WP_DIR_BONE",1,"WP_DIR_LIMITS",1,{ 0.010, 0.015},1}
		};					
	};
};

class dismountsPresent {
	condition = "user5";
	class red {
		color[] = {1,0,0,1};
		class background {
			type = "polygon";
			points[] ={
				{
					{{0.3, LINE3},1},
					{{0.4, LINE3},1},
					{{0.5, LINE3+0.05},1},
					{{0.2, LINE3+0.05},1}
				}
			};
		}; // background
		class background2 {
			type = "polygon";
			points[] ={
				{
					{{0.2, LINE3+0.05},1},
					{{0.5, LINE3+0.05},1},
					{{0.5, LINE3+0.10},1},
					{{0.2, LINE3+0.10},1}
				}
			};
		}; // background2
	};
	class white {
		color[] = {1,1,1,1};
		TEXT_MFD_R_SCALE(DISMOUNTS,0.34,LINE3+0.06,1,"center")
			source="static";
			sourceScale=2;
			sourceIndex=3;
			text="DISMOUNTS";
		}; // WP_COUNT
	};
};

TEXT_MFD_R_SCALE(WP_IMPORT_1,0.1,LINE4-0.025,0.7,"right")
	source="static";
	sourceScale=2;
	sourceIndex=3;
	text="MICRO-DAGR";
}; // WP_COUNT
TEXT_MFD_R_SCALE(WP_IMPORT_2,0.1,LINE4+0.025,0.7,"right")
	source="static";
	sourceScale=2;
	sourceIndex=3;
	text="IMPORT";
}; // WP_COUNT

SIDE_POLYGON(BTN_L1,0.088,0.2+(SIDE_BTN_SPACING*0))
SIDE_POLYGON(BTN_L2,0.088,0.2+(SIDE_BTN_SPACING*1))
SIDE_POLYGON(BTN_L3,0.088,0.2+(SIDE_BTN_SPACING*2))
SIDE_POLYGON(BTN_L4,0.088,0.2+(SIDE_BTN_SPACING*3))
SIDE_POLYGON(BTN_L5,0.088,0.2+(SIDE_BTN_SPACING*4))
SIDE_POLYGON(BTN_L6,0.088,0.2+(SIDE_BTN_SPACING*5))
SIDE_POLYGON(BTN_L7,0.088,0.2+(SIDE_BTN_SPACING*6))
class poly_arrow_wp_next {
	type = "polygon";
	points[] ={
		{
			{{0.12,       LINE2-0.02},1},
			{{0.12-0.015, LINE2+0.02},1},
			{{0.12+0.015, LINE2+0.02},1}
		}
	};
}; // poly_arrow_wp_next
class poly_arrow_wp_prev {
	type = "polygon";
	points[] ={
		{
			{{0.12,       LINE3+0.02},1},
			{{0.12-0.015, LINE3-0.02},1},
			{{0.12+0.015, LINE3-0.02},1}
		}
	};
}; // poly_arrow_wp_prev
class poly_arrow_forward {
	type = "polygon";
	points[] ={
		{
			{{0.35,             0.18-(0.02*0.5)},1},
			{{0.35-(0.015*0.5), 0.18+(0.02*0.5)},1},
			{{0.35+(0.015*0.5), 0.18+(0.02*0.5)},1}
		}
	};
}; // poly_arrow_forward
class HeadingScale
{
	type = "scale";
	NeverEatSeaWeed = 1;
	horizontal = 1;
	source = "heading";
	sourceScale = 1;
	width = 1;
	top = 0.1;
	center = 0.35;
	bottom = 0.6;
	lineXleft = 0.105+0.05;
	lineYright = 0.115+0.05;
	lineXleftMajor = 0.095+0.05;
	lineYrightMajor = 0.115+0.05;
	majorLineEach = 5;
	numberEach = 5;
	step = "18 / 9";
	stepSize = "(0.70 - 0.3) / 15";
	align = "center";
	scale = 1;
	pos[] = {0.096, 0.0546+0.05};
	right[] = {0.143, 0.0546+0.05};
	down[] = {0.096, 0.093+0.05};
};
class vehicleIcon {
	type = "polygon";
	texture = "\a3\armor_f_beta\APC_Tracked_01\Data\UI\map_APC_Tracked_01_ca.paa";
	points[] ={
		{
			{{0.23+0.00, 0.25+0.00},1},
			{{0.23+0.25, 0.25+0.00},1},
			{{0.23+0.25, 0.25+0.30},1},
			{{0.23+0.00, 0.25+0.30},1}
		}
	};
}; // vehicleIcon