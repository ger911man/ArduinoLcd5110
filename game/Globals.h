/*************************************************
 * Public Constants
 *************************************************/
#ifndef _GLOBALS_H
#define _GLOBALS_H

#if ARDUINO >= 100
#include "Arduino.h"
#else
#endif

// ----------------------------------------- CONSTS -----------------------------------------
#define LCD_CONTRAST 40
#define LCD_BRIGHTNESS 0            // 0 - bright, 255 - dim
#define LCD_NOKIA_WIDTH 83                // 0..83
#define LCD_NOKIA_HEIGHT 47               // 0..47
#define GAME_SPEED_DELAY 50
#define BACKGROUND_X0 0
#define BACKGROUND_Y0 0
#define BACKGROUND_X1 83
#define BACKGROUND_Y1 30

// ----------------------------------------- PINOUTS -----------------------------------------
#define PIN_LCD_BRIGHTNESS 8
#define PIN_LCD_SCLK 7
#define PIN_LCD_DIN 6
#define PIN_LCD_DC 5
#define PIN_LCD_SC 4
#define PIN_LCD_RST 3
#define PIN_SPEAKER 13
#define PIN_BUTTON_LEFT 12
#define PIN_BUTTON_RIGHT 11
#define PIN_BUTTON_UP 10
#define PIN_SPEAKER 13

// ----------------------------------------- GLOBAL VARS -----------------------------------------

#endif //_GLOBALS_H
