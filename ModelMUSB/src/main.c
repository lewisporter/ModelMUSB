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
#include "keys.h"

void pressModifier(int pressedModifier) {
    if (!keyboardEnabledFlag) {
        return;
    }
    udi_hid_kbd_modifier_down(pressedModifier);
}


void releaseModifier(int releasedModifier) {
    if (!keyboardEnabledFlag) {
        return;
    }
    udi_hid_kbd_modifier_up(releasedModifier);
}

void pressKey(int pressedKey) {
    if (!keyboardEnabledFlag) {
        return;
    }
    udi_hid_kbd_down(pressedKey);
}

void releaseKey(int releasedKey) {
    if (!keyboardEnabledFlag) {
        return;
    }
    udi_hid_kbd_up(releasedKey);
}

bool keyboardEnableCallback(void) {
	keyboardEnabledFlag = true;
	return true;
}

void keyboardDisableCallback(void) {
	keyboardEnabledFlag = false;
}

void ledCallback(uint8_t value) {
	ioport_set_pin_level(numlockLed, !(value & HID_LED_NUM_LOCK));
	ioport_set_pin_level(capslockLed, !(value & HID_LED_CAPS_LOCK));
	ioport_set_pin_level(scrolllockLed, !(value & HID_LED_SCROLL_LOCK));
}

int main(void) {
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
	
	//Set LED pins as outputs
	for (int ledPin = 0; ledPin < LEDPINCOUNT; ledPin++) {
		ioport_set_pin_dir(ledPins[ledPin], IOPORT_DIR_OUTPUT);
	}

    // Start the USB HID service
    udc_start();

    while (1) {
        // Cycle through the row pins, designating one as output
        for (int rowPinOutput = 0; rowPinOutput < ROWPINCOUNT; rowPinOutput++) {
            // Set all of the row pins as inputs
            for (int rowPin = 0; rowPin < ROWPINCOUNT; rowPin++) {
                ioport_set_pin_dir(rowPins[rowPin], IOPORT_DIR_INPUT);
            }

            //Set the designated pin as low outputs
            ioport_set_pin_dir(rowPins[rowPinOutput], IOPORT_DIR_OUTPUT);
            ioport_set_pin_level(rowPins[rowPinOutput], IOPORT_PIN_LEVEL_LOW);

            // Cycle through column pins
            for (int columnReadPin = 0; columnReadPin < COLUMNPINCOUNT; columnReadPin++) {

                // Get the value of the column pin
                scanValue = (int) !ioport_get_pin_level(columnPins[columnReadPin]);

                // If the saved state differs from the recorded state
                if (stateMap[rowPinOutput][columnReadPin] != scanValue) {
					delay_ms(DEBOUNCE_DELAY);
						
                    // Update the state
                    stateMap[rowPinOutput][columnReadPin] = scanValue;
                    if (stateMap[rowPinOutput][columnReadPin]) {
                        if (modifierMap[rowPinOutput][columnReadPin] == 0) {
							pressKey(keyMap[rowPinOutput][columnReadPin]);
                        } else {
                            pressModifier(modifierMap[rowPinOutput][columnReadPin]);
                        }
                    } else {
                        if (modifierMap[rowPinOutput][columnReadPin] == 0) {
                            releaseKey(keyMap[rowPinOutput][columnReadPin]);
                        } else {
                            releaseModifier(modifierMap[rowPinOutput][columnReadPin]);
                        }
                    }
                }
            }
        }
    }
}