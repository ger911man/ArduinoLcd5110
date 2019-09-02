#ifndef DOOD_H
#define DOOD_H

#include "Globals.h"
#include "Vector.h"
#include "Speaker.h"
#include "Adafruit_GFX_extended.h"
#include "Adafruit_PCD8544_extended.h"

#define GRAVITY_VELOCITY 0.2
#define BRAKING_VELOCITY 0.05
#define THROTTLE_VELOCITY 0.3
#define JUMP_IMPULSE_SPEED -1.75
#define DOOD_MAX_SPEED 1
#define DOOD_SIZE_X 16
#define DOOD_SIZE_Y 16

class Dood {
public:
    //constructor
    Dood(uint8_t x0, uint8_t y0, Adafruit_PCD8544_extended* display, Speaker* melody);

    //calculate coordinates of dood according to it's speeds & velocities, put it's sprite to the screen buffer
    void display();

    //dood jumps
    void doodJump(); //jump start speed on button hit
    void doodLongJump(); //long jump if button remain pressed
    void doodRegularJump(); //jump will not so high and long if button released

    //dood moves
    void moveRight();
    void moveLeft();
    void brake(); //Dood slowdown/stop if buttons are not pressed

    //teleports dood to
    void setCoordinates(uint8_t x0, uint8_t y0);

    //pushes dood in any direction
    void setSpeedX(float x);  //for kickback etc...
    void setSpeedY(float y);  //for jumping or falling
    void setSpeedVector(float x, float y);

    //gaging || loosing speed in any direction
    void setVelocityX(float x);
    void setVelocityY(float y);
    void setVelocityVector(float x, float y);

private:
    Vector speed = Vector(0, 0);
    Vector velocity = Vector(0, GRAVITY_VELOCITY);
    Vector coordinates0;
    Vector coordinates1;
    Vector size;
    uint8_t prevRideSpriteChangeAtX = 0;
    uint8_t spriteNumber = 0;
    uint32_t counterDisplayed = 0;
    float speedModifier = 1;
//    boolean isAlive = true;
//    boolean isRiding = false; //isMooving
//    boolean isJumping = false;
    Adafruit_PCD8544_extended* displayLCD;
    Speaker* melody;

    void doodStayOnSurface();
};
#endif //DOOD_H