#include "Adafruit_GFX.h"
#include "Adafruit_PCD8544.h"
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

#define SCREEN_WIDTH 83     // 0..83
#define SCREEN_HEIGHT 47    // 0..47


void setup() {
    analogWrite(11, 0);     // 0 - bright, 255 - dimm
    display.begin();
    display.setContrast(45);
    display.clearDisplay();
    display.setTextSize(1);
}

int x = 7;
int y = 17;
int dx = 1;
int dy = 1;
int brightness = 0;
int db = 1;


void loop() {

    display.drawPixel(x, y, 1);
    x = x + dx;
    y = y + dy;
    if( x <= 0 || x >= SCREEN_WIDTH){
        dx = dx*-1;
        display.setCursor(0, 0);
        display.println(brightness);
        display.display();
        display.clearDisplay();
        delay(200);
    }
    if( y <= 0 || y >= SCREEN_HEIGHT){
        dy = dy*-1;
        display.setCursor(0, 0);
        display.println(brightness);
        display.display();
        display.clearDisplay();
        delay(200);
    }

    brightness += db;
    analogWrite(11, brightness);

    display.setCursor(0, 0);
    display.println(brightness);
    display.display();
    display.clearDisplay();
    delay(100);

    if( brightness <= 0 || brightness >= 255){
        db = db*-1;
    }
}

