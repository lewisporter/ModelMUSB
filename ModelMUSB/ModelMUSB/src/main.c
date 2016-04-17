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

void pressModifier(int pressedModifier) {
	if (!keyboardEnabledFlag) {
		return;
	}
	udi_hid_kbd_modifier_down(pressedModifier);
}

void releaseModifier(int releaseModifier)
{
	if ((!keyboardEnabledFlag)) {
		return;
	}
	udi_hid_kbd_modifier_up(releaseModifier);
}

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
	
	//Set the column pins as inputs
	for (int columnPin = 0; columnPin < COLUMNPINCOUNT; columnPin++) {
		ioport_set_pin_dir(columnPins[columnPin], IOPORT_DIR_INPUT);
	}

	// Start the USB HID service
	udc_start();
	bool scanValue;
	while (1) 
	{
		// Cycle through the row pins, designating one as output
		for (int rowPinOutput = 0; rowPinOutput < ROWPINCOUNT; rowPinOutput++) 
		{
			// Set all of the row pins as inputs
			for (int rowPin = 0; rowPin < ROWPINCOUNT; rowPin++) 
			{
				ioport_set_pin_dir(rowPins[rowPin], IOPORT_DIR_INPUT);
			}

			//Set the designated pin as low outputs
			ioport_set_pin_dir(rowPins[rowPinOutput], IOPORT_DIR_OUTPUT);
			ioport_set_pin_level(rowPins[rowPinOutput], IOPORT_PIN_LEVEL_LOW);

			// Cycle through column pins
			for (int columnReadPin = 0; columnReadPin < COLUMNPINCOUNT; columnReadPin++) {
				
				// Get the value of the column pin
				scanValue = !ioport_get_pin_level(columnPins[columnReadPin]);

				// If the saved state differs from the recorded state
				if (stateMap[rowPinOutput][columnReadPin] != scanValue) {
					
					// Update the state
					stateMap[rowPinOutput][columnReadPin] = scanValue;

					if (stateMap[rowPinOutput][columnReadPin]) {
						if (modifierMap[rowPinOutput][columnReadPin] == 0) {
							pressKey(keyMap[rowPinOutput][columnReadPin]);
						} else {
							pressModifier(keyMap[rowPinOutput][columnReadPin]);
						}
					} else {
						if (modifierMap[rowPinOutput][columnReadPin] == 0) {
							releaseKey(keyMap[rowPinOutput][columnReadPin]);
						} else {
							releaseModifier(keyMap[rowPinOutput][columnReadPin]);
						}
					}
				}
			}
		}	
	}
}