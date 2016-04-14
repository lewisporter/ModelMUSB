#ifndef MODELM_KEYS
#define MODELM_KEYS

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

const int ROWPINCOUNT = 15;
const int COLUMNPINCOUNT = 8;

uint32_t rowPins[] = {DUE22, DUE23, DUE24, DUE25, DUE26, DUE27, DUE28, DUE29, DUE30, DUE31, DUE32, DUE33, DUE34, DUE35, DUE36, DUE37};

uint32_t columnPins[] = {DUE38, DUE39, DUE40, DUE41, DUE42, DUE43, DUE44, DUE45};

const unsigned int keyMap[15][8] = {
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{HID_ESCAPE, HID_TAB,       0,      HID_1, HID_Q, HID_A, HID_Z, 0},
{0,          HID_CAPS_LOCK, HID_F1, HID_2, HID_W, HID_S, HID_X, 0},
{HID_F4,     HID_F3,        HID_F2, HID_3, HID_E, HID_D, HID_C, 0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0}
};

bool stateMap[15][8] = {
	{false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false}
};

bool keyboardEnabledFlag = true;
#endif