#include "Dood.h"

// Sprite
const uint8_t PROGMEM spriteDood[6][32] = {
        {B00000000,B11100000,
                B00000001,B11110000,
                B00000001,B11010000,
                B00000001,B11110000,
                B00000001,B11110000,
                B00000011,B11100000,
                B00000111,B11000000,
                B00000111,B11000000,
                B00000111,B11000000,
                B00000111,B11000000,
                B00000111,B11000000,
                B00000011,B10000000,
                B00000011,B10000000,
                B00000011,B10000000,
                B00000011,B10000000,
                B00000011,B11000000
        },

        {B00000000,B11100000,
                B00000001,B11110000,
                B00000001,B11010000,
                B00000001,B11110000,
                B00000001,B11110000,
                B00000011,B11100000,
                B00000111,B11000000,
                B00001111,B11100000,
                B00011111,B11110000,
                B00011111,B10111000,
                B00001111,B11011000,
                B00000111,B11100000,
                B00001110,B11110000,
                B00001100,B01100000,
                B00011000,B11000000,
                B00011110,B11110000
        },

        {B00000000,B00111000,
                B00000000,B01111100,
                B00000000,B01111100,
                B00000000,B01110100,
                B00000000,B01111100,
                B00000001,B11111000,
                B00000011,B11100000,
                B00000111,B11101100,
                B00011111,B11111000,
                B00101111,B11100000,
                B00001111,B11000000,
                B00011111,B11100000,
                B00011100,B11000000,
                B00110001,B10000000,
                B01100000,B11000000,
                B00110000,B00000000
        },

        {B00000001,B11001100,
                B00000011,B11101100,
                B00000011,B11100110,
                B00000011,B11110110,
                B00111111,B01011110,
                B01111111,B11111110,
                B01100111,B11111100,
                B00000011,B11100000,
                B00000001,B11110000,
                B00011001,B11111100,
                B01111011,B11111110,
                B00011111,B10011100,
                B00001111,B00111000,
                B00000110,B01110000,
                B00000000,B00110000,
                B00000000,B00011000
        },

        {B11001110,B00000000,
                B11011111,B01100000,
                B10011111,B01110000,
                B11011010,B00110000,
                B11111111,B01110000,
                B01111111,B11100000,
                B00111111,B11100000,
                B00011111,B11000000,
                B00001111,B11000000,
                B00000111,B11000000,
                B00000011,B11100000,
                B00000011,B11110000,
                B00000001,B11111011,
                B00000111,B10111111,
                B00000111,B00011110,
                B00000110,B00001100
        },

        {B00000001,B11001100,
                B00000011,B11101100,
                B00000011,B11100110,
                B00000011,B11110110,
                B00111111,B01011110,
                B01111111,B11111110,
                B01110111,B11111100,
                B00111111,B11100000,
                B00011111,B11110000,
                B00001111,B11111000,
                B00000111,B11111110,
                B01111111,B10011110,
                B11111111,B00111110,
                B01111110,B01111100,
                B00110000,B00110000,
                B00000000,B00011000
        }
};

//Constructor
Dood::Dood(uint8_t x0, uint8_t y0, Adafruit_PCD8544_extended* display, Speaker* melody){
    uint8_t prevWalkSpriteChangeAtX = x0;
    coordinates0 =  Vector(x0, y0);
    coordinates1 =  Vector(x0 + DOOD_SIZE_X, y0 + DOOD_SIZE_Y);
    size = Vector(DOOD_SIZE_X, DOOD_SIZE_Y);
    displayLCD = display;
    this->melody = melody;
}

void Dood::display(){
    counterDisplayed++;

    // ----------------------------------------- PHYSICS -----------------------------------------
    speedModifier = deltaTime / 42.0; // if(deltaTime>42) deltaTime = 42;    // Game slowdown if low FPS. 24FPS: time delay between frames = 42 millis (1000/24=~42);
    if(speed.getY() !=0){             // Because you can't move in X axis while jumping
        velocity.setX(0);
    }
    speed+=velocity*speedModifier;
    if(speed.getX() > DOOD_MAX_SPEED){
        speed.setX(DOOD_MAX_SPEED);
    }
    if(speed.getX() < DOOD_MAX_SPEED * -1){
        speed.setX(-DOOD_MAX_SPEED);
    }
    coordinates0 += speed * speedModifier;
    coordinates1 += size;

    // ----------------------------------------- Manage collisions -----------------------------------------
    doodStayOnSurface();

    // ----------------------------------------- Chose the sprite to display -----------------------------------------
    if(speed.getY() == 0 ){                                 // if on surface
        if(speed.getX() == 0){                              // not moving
            spriteNumber = 0;
        } else {                                            // moving
            if(abs(prevRideSpriteChangeAtX - coordinates0.getX()) > 3){
                if(spriteNumber == 0) {
                    spriteNumber = 1;
                    prevRideSpriteChangeAtX = coordinates0.getX();
                } else {
                    spriteNumber = 0;
                    prevRideSpriteChangeAtX = coordinates0.getX();
                }
            }
        }
    } else {                                                // if jumping
        if(speed.getY() < 0){
            spriteNumber = 2;
        } else {
            spriteNumber = 4;
        }
        if(abs(speed.getY()) < 0.5){
            spriteNumber = 3;
        }
    }

    // ----------------------------------------- Display -----------------------------------------
    displayLCD->drawBitmap(coordinates0.getX(), coordinates0.getY(), spriteDood[spriteNumber], DOOD_SIZE_X, DOOD_SIZE_Y, BLACK);

//    displayLCD->drawBitmap(coordinates0.getX(), coordinates0.getY(), spriteDood[spriteNumber], DOOD_SIZE_X, DOOD_SIZE_Y, BLACK);
//    displayLCD->setCursor(60,0);
//    displayLCD->println(deltaTime);
//    displayLCD->println(coordinates0.asString());
//    displayLCD->println(speed.asString());
//    displayLCD->println(velocity.asString());
}

//    void display(uint8_t color){
//        counterDisplayed++;
//        displayLCD.drawBitmap(x0, y0, spriteDood[spriteNumber], DOOD_SIZE_X, DOOD_SIZE_Y, BLACK);
//
//    }

void Dood::doodJump(){
    if(speed.getY() == 0){
        melody->soundJump();
        speed.setY(JUMP_IMPULSE_SPEED);
        velocity.setY(GRAVITY_VELOCITY);
    }
}

void Dood::doodLongJump(){
    //make jump longer by decreasing the gravity
    if(speed.getY() != 0){
        velocity.setY(GRAVITY_VELOCITY / 3.5); //gravity/3.5 allows you to jump almost to the top of the screen
    }
}

void Dood::doodRegularJump(){
    if(speed.getY() != 0){
        velocity.setY(GRAVITY_VELOCITY);
    }
}

void Dood::moveRight(){
    velocity.setX( THROTTLE_VELOCITY);
}

void Dood::moveLeft(){
    velocity.setX(-THROTTLE_VELOCITY);
}

void Dood::brake(){
    if(speed.getX() != 0){
        if(abs(speed.getX()) <= BRAKING_VELOCITY*speedModifier){
            speed.setX(0);
            velocity.setX(0);
        } else {
            if(speed.getX() > 0){
                velocity.setX(-BRAKING_VELOCITY);
            } else {
                velocity.setX(BRAKING_VELOCITY);
            }
        }
    }
}

void Dood::setCoordinates(uint8_t x0, uint8_t y0){
    coordinates0.setXY(x0, y0);
}

void Dood::setSpeedX(float x){
    this->speed.setX(x);
}

void Dood::setSpeedY(float y){
    this->speed.setY(y);
}

void Dood::setVelocityX(float x){
    this->velocity.setX(x);
}

void Dood::setVelocityY(float y){
    this->velocity.setY(y);
}

void Dood::setSpeedVector(float x, float y){
    this->speed.setXY(x, y);
}

void Dood::setVelocityVector(float x, float y){
    this->velocity.setXY(x, y);
}

void Dood::doodStayOnSurface(){
    if(coordinates0.getX() > LCD_NOKIA_WIDTH - DOOD_SIZE_X) {
        coordinates0.setX(LCD_NOKIA_WIDTH - DOOD_SIZE_X);
        speed.setX(0);
        velocity.setX(0);
    }
    if(coordinates0.getX() < 0) {
        coordinates0.setX(0);
        speed.setX(0);
        velocity.setX(0);
    }
    if(coordinates0.getY() > LCD_NOKIA_HEIGHT - DOOD_SIZE_Y){
        coordinates0.setY(LCD_NOKIA_HEIGHT - DOOD_SIZE_Y - 1);
        speed.setY(0);
        velocity.setY(0);
        melody->soundLand();
    }
    if(coordinates0.getY() < 0){
        coordinates0.setY(0);
        speed.invertY();
        melody->soundLand();
    }
}