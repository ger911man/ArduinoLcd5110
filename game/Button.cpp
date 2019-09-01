#include "Button.h"

Button::Button(uint8_t pin, Speaker *melody){
    this->pin = pin;
    this->currentState = false;
    this->prevState = false;
    this->speaker = melody;
}

boolean Button::isHit(){ // Exactly when button was hit
    boolean result = false;
    currentState = digitalRead(pin);
    if(currentState && !prevState){
        speaker->soundButtonHit();
        result = true;
    }
    prevState = currentState;
    return result;
}

boolean Button::isReleased(){ // Exactly when button was released
    boolean result = false;
    currentState = digitalRead(pin);
    if(!currentState && prevState){
        speaker->soundButtonReleased();
        result = true;
    }
    prevState = currentState;
    return result;
}

boolean Button::getState(){ // Check if button remain pressed or released
    boolean result = false;
    currentState = digitalRead(pin);
    if(currentState == prevState){
        if(currentState) result = true; else result = false;
    } else {
        if(currentState && !prevState){
            // Button hit
            speaker->soundButtonHit();
        }
        if(!currentState && prevState){
            // Button released
            speaker->soundButtonReleased();
        }
    }
    prevState = currentState;
    return result;
}