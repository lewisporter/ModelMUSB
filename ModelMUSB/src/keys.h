#ifndef MODELM_KEYS
#define MODELM_KEYS

//Setup the pins

//Key pins
#define DUE22 IOPORT_CREATE_PIN(PIOB, 26)
#define DUE23 IOPORT_CREATE_PIN(PIOA, 14)
#define DUE24 IOPORT_CREATE_PIN(PIOA, 15)
#define DUE25 IOPORT_CREATE_PIN(PIOD, 0)
#define DUE26 IOPORT_CREATE_PIN(PIOD, 1)
#define DUE27 IOPORT_CREATE_PIN(PIOD, 2)
#define DUE28 IOPORT_CREATE_PIN(PIOD, 3)
#define DUE29 IOPORT_CREATE_PIN(PIOD, 6)
#define DUE30 IOPORT_CREATE_PIN(PIOD, 9)
#define DUE31 IOPORT_CREATE_PIN(PIOA, 7)
#define DUE32 IOPORT_CREATE_PIN(PIOD, 10)
#define DUE33 IOPORT_CREATE_PIN(PIOC, 1)
#define DUE34 IOPORT_CREATE_PIN(PIOC, 2)
#define DUE35 IOPORT_CREATE_PIN(PIOC, 3)
#define DUE36 IOPORT_CREATE_PIN(PIOC, 4)
#define DUE37 IOPORT_CREATE_PIN(PIOC, 5)
#define DUE38 IOPORT_CREATE_PIN(PIOC, 6)
#define DUE39 IOPORT_CREATE_PIN(PIOC, 7)
#define DUE40 IOPORT_CREATE_PIN(PIOC, 8)
#define DUE41 IOPORT_CREATE_PIN(PIOC, 9)
#define DUE42 IOPORT_CREATE_PIN(PIOA, 19)
#define DUE43 IOPORT_CREATE_PIN(PIOA, 20)
#define DUE44 IOPORT_CREATE_PIN(PIOC, 19)
#define DUE45 IOPORT_CREATE_PIN(PIOC, 18)

//LED Pins
#define DUE46 IOPORT_CREATE_PIN(PIOC, 17)
#define DUE47 IOPORT_CREATE_PIN(PIOC, 16)
#define DUE48 IOPORT_CREATE_PIN(PIOC, 15)

#define DEBOUNCE_DELAY 20

#define ROWPINCOUNT 16
#define COLUMNPINCOUNT 8
#define LEDPINCOUNT 3

uint32_t rowPins[] = {DUE22, DUE23, DUE24, DUE25, DUE26, DUE27, DUE28, DUE29, DUE30, DUE31, DUE32, DUE33, DUE34, DUE35, DUE36, DUE37};
uint32_t columnPins[] = {DUE38, DUE39, DUE40, DUE41, DUE42, DUE43, DUE44, DUE45};
uint32_t ledPins[] = {DUE46, DUE47, DUE48};

uint32_t numlockLed	= DUE46;
uint32_t capslockLed = DUE47;
uint32_t scrolllockLed = DUE48;

void pressKey(int pressedKey);
void releaseKey(int releasedKey);

void pressModifier(int pressModifier);
void releaseModifier(int releaseModifier);

const unsigned int keyMap[ROWPINCOUNT][COLUMNPINCOUNT] = {
	/*0*/         /*1*/              /*2*/           /*3*/            /*4*/            /*5*/             /*6*/								/*7*/
	/*0*/	{0,			   0,				 0,				 0,			       0,			    0,                0,                                  0},
	/*1*/	{0,			   0,	  			 0,				 0,				   0,			    0,                0,                                  0},
	/*2*/	{HID_ESCAPE,   HID_TAB,           HID_TILDE,      HID_1,           HID_Q,           HID_A,            HID_Z,                              0},
	/*3*/	{0,            HID_CAPS_LOCK,     HID_F1,         HID_2,           HID_W,           HID_S,            HID_X,                              0},
	/*4*/   {HID_F4,       HID_F3,            HID_F2,	      HID_3,           HID_E,           HID_D,            HID_C,                              0},
	/*5*/	{HID_G,        HID_T,             HID_5,	      HID_4,           HID_R,           HID_F,            HID_V,                          HID_B},
	/*6*/	{HID_F5,       HID_BACKSPACE,     HID_F9,		  HID_F10,         0,               0,                HID_ENTER,               HID_SPACEBAR},
	/*7*/	{HID_H,        HID_Y,             HID_6,          HID_7,           HID_U,           HID_J,            HID_M,                          HID_N},
	/*8*/	{HID_F6,       HID_CLOSE_BRACKET, HID_PLUS,       HID_8,           HID_I,           HID_K,            HID_COMMA,                          0},
	/*9*/	{0,            HID_F7,            HID_F8,         HID_9,           HID_O,           HID_L,            HID_DOT,                            0},
	/*10*/	{HID_QUOTE,    HID_OPEN_BRACKET,  HID_UNDERSCORE, HID_0,           HID_P,           HID_COLON,        HID_BACKSLASH,              HID_SLASH},
	/*11*/	{0,            HID_KEYPAD_4,	  HID_DELETE,     HID_F11,         0,               HID_KEYPAD_1,     HID_KEYPAD_NUM_LOCK,         HID_DOWN},
	/*12*/	{HID_KEYPAD_0, HID_KEYPAD_5,      HID_INSERT,     HID_F12,         HID_KEYPAD_8,    HID_KEYPAD_2,	  HID_KEYPAD_DIVIDE,          HID_RIGHT},
	/*13*/	{0,            HID_KEYPAD_6,      HID_PAGEUP,     HID_PAGEDOWN,    HID_KEYPAD_9,    HID_KEYPAD_3,     HID_KEYPAD_MULTIPLY, HID_KEYPAD_MINUS},
	/*14*/	{HID_UP,       0,                 HID_HOME,       HID_END,         0,               HID_KEYPAD_ENTER, HID_PAUSE,                   HID_LEFT},
	/*15*/	{0,            0,                 0,              HID_PRINTSCREEN, HID_SCROLL_LOCK, 0,                0,                                  0}
};


const unsigned int modifierMap[ROWPINCOUNT][COLUMNPINCOUNT] = {
	/*0*/                  /*1*/                    /*2*/                   /*3  4  5  6*/                                          /*7*/
	/*0*/	{0,                     0,                       HID_MODIFIER_LEFT_CTRL, 0, 0, 0, HID_MODIFIER_RIGHT_CTRL,                       0},
	/*1*/	{0,                     HID_MODIFIER_LEFT_SHIFT, 0,                      0, 0, 0, HID_MODIFIER_RIGHT_SHIFT,                      0},
	/*2*/	{0,                     0,                       0,                      0, 0, 0, 0,                                             0},
	/*3*/	{0,                     0,                       0,                      0, 0, 0, 0,                                             0},
	/*4*/	{0,                     0,                       0,                      0, 0, 0, 0,                                             0},
	/*5*/	{0,                     0,                       0,                      0, 0, 0, 0,                                             0},
	/*6*/	{0,                     0,                       0,                      0, 0, 0, 0,                                             0},
	/*7*/	{0,                     0,                       0,                      0, 0, 0, 0,                                             0},
	/*8*/	{0,                     0,                       0,                      0, 0, 0, 0,                                             0},
	/*9*/	{0,                     0,                       0,                      0, 0, 0, 0,                                             0},
	/*10*/	{0,                     0,                       0,                      0, 0, 0, 0,                                             0},
	/*11*/	{0,                     0,                       0,                      0, 0, 0, 0,                                             0},
	/*12*/	{0,                     0,                       0,                      0, 0, 0, 0,                                             0},
	/*13*/	{0,                     0,                       0,                      0, 0, 0, 0,                                             0},
	/*14*/	{0,                     0,                       0,                      0, 0, 0, 0,                                             0},
	/*15*/	{HID_MODIFIER_LEFT_ALT, 0,                       0,                      0, 0, 0, 0,                        HID_MODIFIER_RIGHT_ALT}
};


bool keyboardEnabledFlag = true;
bool scanValue;
#endif