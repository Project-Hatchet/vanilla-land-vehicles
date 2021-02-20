class nav_wp_valid {
    condition = "wpvalid";
    TEXT_MFD_R_SCALE(WP_NAME,0.17,0.2,0.7,"right")
        source="userText";
        sourceScale=1;
        sourceIndex=1;
    }; // WP_NAME

    TEXT_MFD_R_SCALE(WP_DIR,0.17,0.25,0.7,"right")
        source="userText";
        sourceScale=1;
        sourceIndex=0;
    }; // WP_DIR

    TEXT_MFD_R_SCALE(WP_COUNT,0.1,0.28,0.7,"right")
        source="userText";
        sourceScale=2;
        sourceIndex=3;
    }; // WP_COUNT
	
    TEXT_MFD_R_SCALE(WP_IMPORT,0.1,LINE3,0.7,"right")
        source="static";
        sourceScale=2;
        sourceIndex=3;
		text="MICRO-DAGR IMPORT"
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
				{{0.12,       0.2-0.02},1},
				{{0.12-0.015, 0.2+0.02},1},
				{{0.12+0.015, 0.2+0.02},1}
			}
		};
	}; // poly_arrow_wp_next
	class poly_arrow_wp_prev {
		type = "polygon";
		points[] ={
			{
				{{0.12,       0.35+0.02},1},
				{{0.12-0.015, 0.35-0.02},1},
				{{0.12+0.015, 0.35-0.02},1}
			}
		};
	}; // poly_arrow_wp_prev
};