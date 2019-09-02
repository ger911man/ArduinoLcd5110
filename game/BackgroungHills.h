#ifndef BACKGROUNGHILLS_H
#define BACKGROUNGHILLS_H

#include "Globals.h"
#include "Adafruit_GFX.h"
#include "Adafruit_PCD8544.h"

class BackgroungHills {

private:
    uint8_t x0;
    uint8_t y0;
    uint8_t x1;
    uint8_t y1;
    Adafruit_PCD8544* displayBG;
    uint8_t *horizonArray;
    uint8_t horizonArraySize;
    boolean isUphill = true;
    uint8_t nextMountainTop = 3;
    uint8_t mountainMaxHeight;
    uint8_t mountainMinHeight;

public:

    void displayMountains()
    {
        for(int i = 0; i < this->horizonArraySize; i++){
            if (this->horizonArray[i]%2 == 0){
                //Magic formula to draw a mountain: line [ix0,iy0,ix1+n*2,iy1+n] + ...
                //tang = 2/1 = 2.0
                uint8_t ix1 = this->x0 + i + (this->y1 - this->horizonArray[i]) / 2;
                //Draw mountains only inside the frame (Right side, even)
                if(ix1 <= this->x1){
                    this->displayBG->drawLine(this->x0 + i, this->horizonArray[i], ix1, this->y1, BLACK);
                } else {
                    this->displayBG->drawLine(this->x0 + i, this->horizonArray[i], this->x1,  this->y1 - (ix1 - this->x1)*2, BLACK);
                }
                //Draw mountains only inside the frame (Left side, even)
                if(i == 0){
                    for(int iy0 = this->horizonArray[i] + 6; iy0 < this->y1; iy0 += 6){
                        uint8_t  ix1 = this->x0 + (this->y1 - iy0) / 2;
                        this->displayBG->drawLine(this->x0, iy0, ix1, this->y1, BLACK);
                    }
                }
            } else {
                this->displayBG->drawPixel(this->x0 + i,this->horizonArray[i], BLACK);
                //Draw mountains only inside the frame (Left side, odd)
                if(i == 0){
                    for(int iy0 = this->horizonArray[i] + 3; iy0 < this->y1; iy0 += 6){
                        uint8_t  ix1 = this->x0 + (this->y1 - iy0) / 2;
                        this->displayBG->drawLine(this->x0, iy0, ix1, this->y1, BLACK);
                    }
                }
            }
        }
    }

    void setFrame(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1)
    {
        uint8_t dy = this->y1 - y1;
        int dx = (x1 - x0) - (this->x1 - this->x0);
        this->x0 = x0;
        this->y0 = y0;
        this->x1 = x1;
        this->y1 = y1;
        this->horizonArraySize = x1 - x0 + 1;
        this->mountainMaxHeight = (this->y1 - this->y0);
        this->mountainMinHeight = (this->y1 - this->y0)*0.25;
        for(int i = 0; i <= this->horizonArraySize; i++){
            this->horizonArray[i] = (this->horizonArray[i] - dy);
        }
        if(dx > 0){
            for(int j = 0; j <= dx; j++){
                this->horizonArray[0] = this->y1;
                for(int i = this->horizonArraySize; i > 0; i--) {
                    this->horizonArray[i] = this->horizonArray[i-1];
                }
            }
        }
    }

    void displayMountainsShiftedBy(uint8_t n){
        for(int j = 1; j <= n; j++ ){
            //The last pixel of the horizon array never displayed, it's used to create the landscape...
            for(int i = 0; i < this->horizonArraySize; i++){
                this->horizonArray[i] = this->horizonArray[i + 1];
            }

            //Check if the last pixel of the horizon is on bottom. If so: create the uphill.
            if(this->horizonArray[this->horizonArraySize] >= this->y1){
                this->isUphill = true;
                this->nextMountainTop = this->y1 - random(this->mountainMinHeight, this->mountainMaxHeight);
            }

            //Check if the last pixel of the horizon is on top of the mountain. If so: downhill.
            if(this->horizonArray[this->horizonArraySize] <= this->nextMountainTop){
                this->isUphill = false;
            }

            //Move the last pixel up/down(decr/incr) according to the "isUphill" var
            if(this->isUphill){
                this->horizonArray[this->horizonArraySize] -= 1;
            } else {
                this->horizonArray[this->horizonArraySize] += 1;
            }
        }
        displayMountains();
    }

    void displayBackgroundFrame(){
        // TODO: for developing purposes, to see where exactly the frame is located
        this->displayBG->drawFastHLine(this->x0, this->y0, this->x1 - this->x0, 1);
        this->displayBG->drawFastHLine(this->x0, this->y1, this->x1 - this->x0, 1);
        this->displayBG->drawFastVLine(this->x0, this->y0, this->y1 - this->y0, 1);
        this->displayBG->drawFastVLine(this->x1, this->y0, this->y1 - this->y0, 1);
    }

    BackgroungHills(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, Adafruit_PCD8544* displayBG){
        this->x0 = x0;
        this->y0 = y0;
        this->x1 = x1;
        this->y1 = y1;
//            this->horizonArraySize = x1 - x0 + 1;
        this->horizonArraySize = x1 - x0 + 1;
        this->horizonArray = new uint8_t[this->horizonArraySize];
        this->displayBG = displayBG;
        this->mountainMaxHeight = (this->y1 - this->y0);
        this->mountainMinHeight = (this->y1 - this->y0)*0.25;
        for(int i = 0; i <= this->horizonArraySize; i++){
            this->horizonArray[i] = this->y1;
        }
        displayMountainsShiftedBy(this->x1 - this->x0);
    }
};


#endif //KITCHEN_LIGHTS_BACKGROUNGHILLS_H