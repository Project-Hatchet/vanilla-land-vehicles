#define RGBA256(R,G,B,A) {R/256,G/256,B/256,A}
#define BACKGROUND_BLUE RGBA256(0,0,0.504,0.1)
#define BORDER_BLUE RGBA256(24,243,244,1.0)


#define SIDE_BTN_SPACING 0.17
#define LINE1 (0.2+(SIDE_BTN_SPACING*0))
#define LINE2 (0.2+(SIDE_BTN_SPACING*1))
#define LINE3 (0.2+(SIDE_BTN_SPACING*2))
#define LINE4 (0.2+(SIDE_BTN_SPACING*3))
#define LINE5 (0.2+(SIDE_BTN_SPACING*4))
#define LINE6 (0.2+(SIDE_BTN_SPACING*5))
#define LINE7 (0.2+(SIDE_BTN_SPACING*6))

#define TEXT_MFD_R_SCALE(CLASS,X,Y,SIZE,ALIGN) \
    class CLASS { \
        type = "text"; \
        align = ALIGN; \
        scale = 1; \
        pos[] = {{X-0.002*SIZE, Y-0.035*SIZE}, 1}; \
        right[] = {{X + 0.06*SIZE, Y-0.035*SIZE}, 1}; \
        down[] = {{X-0.002*SIZE, Y + 0.035*SIZE}, 1};


#define SIDE_POLYGON(CLASS,X,Y) \
	class CLASS { \
		type = "polygon"; \
		points[] ={ \
			{ \
				{{X-0.006,Y-0.008},1}, \
				{{X+0.006,Y-0.008},1}, \
				{{X+0.006,Y+0.008},1}, \
				{{X-0.006,Y+0.008},1} \
			} \
		}; \
	};