#ifndef BUTTON_H
#define BUTTON_H

#include "Globals.h"
#include "Speaker.h"

class Button {
public:
    //constructor
    Button(uint8_t pin, Speaker *melody);

    boolean isHit(); //Exactly when the button was hit

    boolean isReleased(); //Exactly when the button was released

    boolean getState(); // Check the button state, returns true if button remain pressed, false if unpressed

private:
    boolean currentState;
    boolean prevState;
    uint8_t pin;
    Speaker *speaker;


};
#endif //BUTTON_H
