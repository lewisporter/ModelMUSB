/**
 *
 * Model M USB Controller
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
#include <asf.h>
#include <keys.h>

void pressKey(int pressedKey);
void releaseKey(int releasedKey);


bool keyboardEnableCallback(void)
{
	keyboardEnabledFlag = true;
	return true;
}

void keyboardDisableCallback(void)
{
	keyboardEnabledFlag = false;
}

void pressKey(int pressedKey)
{
	if (!keyboardEnabledFlag) {
		return;
	}
	udi_hid_kbd_down(pressedKey);
}

void releaseKey(int releasedKey)
{
	if ((!keyboardEnabledFlag)) {
		return;
	}
	udi_hid_kbd_up(releasedKey);
}

int main (void)
{
	/* Initialise the board */
	sysclk_init();
	irq_initialize_vectors();
	cpu_irq_enable();
	board_init();
	sleepmgr_init();
	board_init();
	ioport_init();

	/* Main application code */
	

	//Start the USB HID service
	udc_start();
	bool scanValue;
	while (1) 
	{
		/* This code updates the stateMap array */
		for (int rowPinOutput = 0; rowPinOutput <= ROWPINCOUNT; rowPinOutput++) 
		{
			for (int rowPin = 0; rowPin <= ROWPINCOUNT; rowPin++) 
			{
				ioport_set_pin_dir(rowPins[rowPin], IOPORT_DIR_INPUT);
			}

			ioport_set_pin_dir(rowPins[rowPinOutput], IOPORT_DIR_OUTPUT);
			ioport_set_pin_level(rowPins[rowPinOutput], IOPORT_PIN_LEVEL_LOW);

			for (int columnReadPin = 0; columnReadPin <= COLUMNPINCOUNT; columnReadPin++)
			{
				for (int columnPin = 0; columnPin <= COLUMNPINCOUNT; columnPin++)
				{
					ioport_set_pin_dir(columnPins[columnPin], IOPORT_DIR_INPUT);
				}
				scanValue = ioport_get_pin_level(columnPins[columnReadPin]);
				if (!scanValue) {
					stateMap[rowPinOutput][columnReadPin] = true;
				} else {
					stateMap[rowPinOutput][columnReadPin] = false;
				}
			}
		}
		
		for (int stateRow = 0; stateRow <= ROWPINCOUNT; stateRow++) {
			for (int stateColumn = 0; stateColumn <= COLUMNPINCOUNT; stateColumn++) {
				if (stateMap[stateRow][stateColumn]) {
					pressKey(keyMap[stateRow][stateColumn]);
				} else {
					releaseKey(keyMap[stateRow][stateColumn]);
				}
			}
		}	
	}
}