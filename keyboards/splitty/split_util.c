#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/power.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/eeprom.h>
#include "split_util.h"
#include "matrix.h"
#include "keyboard.h"
#include "config.h"
#include "timer.h"


volatile bool isLeftHand = true;
volatile bool contacted_by_master = false;

static void setup_handedness(void) {
  #ifdef EE_HANDS
    isLeftHand = eeprom_read_byte(EECONFIG_HANDEDNESS);
  #else
    #error "Only EE_HANDS supported"
  #endif
}

void split_keyboard_setup(void) {
    timer_init();
    setup_handedness();
}

// this code runs before the usb and keyboard is initialized
void matrix_setup(void) {
    split_keyboard_setup();
}
