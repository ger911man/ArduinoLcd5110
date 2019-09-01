//
// Created by dtv on 29.08.2019.
//

#ifndef _SPEAKER_H
#define _SPEAKER_H

#include "Arduino.h"

class Speaker{
public:
    // constructor
    Speaker(uint8_t pinSpeaker);

    // changes melody by its #
    // #0 = melodyError
    // #1 = melodyImperialMarch
    // #2 = melodyMarioTitle
    // #3 = melodyMarioUnderworld
    // #4 = melodyPirates
    // #5 = melodyPotter
    void setMelodyByNumber(uint8_t melodyNumber);

    // changes melody by its name
    void setErrorMelody();
    void setImperialMarchMelody();
    void setMarioTitleMelody();
    void setMarioUnderworldMelody();
    void setPiratesMelody();
    void setPotterMelody();

    // sounds melody notes one by one
    void playMelody();

    //change currently playing note to another (when you ned short sound effect instead melody)
    void replaceCurrentlyPlayingNoteWith(uint16_t note, uint16_t duration);

    //play jumping note
    void soundJump();

    //play landing note
    void soundLand();

    //play collision note
    void soundCollision();

    //play button hit note
    void soundButtonHit();

    //play button release note
    void soundButtonReleased();

private:
    uint8_t pinSpeaker = 0;
    uint16_t noteCounter = 0;
    uint32_t noteStartedAt = 0;
    uint16_t noteToPlay = 0;
    uint16_t noteToPlayDuration = 0;
    uint16_t melodySize = 0;
    uint16_t melodyNumber = 2; //default melody#2 (Mario)
};

#endif //_SPEAKER
