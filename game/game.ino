#include "Adafruit_GFX.h"
#include "Adafruit_PCD8544.h"
#include "Globals.h"
#include "Speaker.h"

// ----------------------------------------- VARS -----------------------------------------
Adafruit_PCD8544 display = Adafruit_PCD8544(PIN_LCD_SCLK, PIN_LCD_DIN, PIN_LCD_DC, PIN_LCD_SC, PIN_LCD_RST);
Speaker speaker = Speaker(PIN_SPEAKER);
uint32_t frameCounter = 0;
uint32_t  currTime = 0;
uint32_t  prevTime = 0;
uint32_t  deltaTime = 0;

// ----------------------------------------- SETUP -----------------------------------------
void setup() {
    pinMode(PIN_BUTTON_LEFT, INPUT_PULLUP);
    pinMode(PIN_BUTTON_RIGHT, INPUT_PULLUP);
    pinMode(PIN_BUTTON_UP, INPUT_PULLUP);
    pinMode(PIN_SPEAKER, OUTPUT);

    analogWrite(PIN_LCD_BRIGHTNESS, LCD_BRIGHTNESS);
    display.begin();
    display.clearDisplay();
    display.setContrast(LCD_CONTRAST);
    display.setTextSize(1);
    prevTime = millis();
    Serial.begin(115200);
}

uint8_t mel = 0;

// --------------------------------------- MAIN LOOP ---------------------------------------
void loop() {
    // ----------------------------------------- PRESETS -----------------------------------------
    display.clearDisplay();
    currTime = millis();
    deltaTime = currTime - prevTime;

    // ----------------------------------------- MISIC -----------------------------------------
    speaker.playMelody();
//    speaker.soundJump();
    if(frameCounter%5000 == 0){
        speaker.replaceCurrentlyPlayingNoteWith(400,100);
        speaker.setMelodyByNumber(mel++);
        if(mel > 5) mel = 0;
    }




    // ----------------------------------------- DRAWING -----------------------------------------
    display.setCursor(60,0);
    display.println(deltaTime);

    // ----------------------------------------- FINAL -----------------------------------------
//    displayScreenFrame();
//    delay(GAME_SPEED_DELAY);
    display.display();
    frameCounter++;
    prevTime = currTime;
}