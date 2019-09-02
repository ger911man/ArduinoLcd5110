//
// Created by dtv on 31.08.2019
//

#include "Speaker.h"

/// melodies & tempos are stored in program storage space (PROGMEM)
const uint16_t PROGMEM melodyError[8] = {
        200, 0, 200, 0, 200, 0, 100, 0
};
const uint8_t PROGMEM tempoError[8] = {
        9, 22, 9, 22, 9, 22, 9, 22
};
const uint16_t PROGMEM melodyImperialMarch[74] = {
        110, 110, 110, 87, 130, 110, 87, 130, 110, 0, 164, 164, 164, 174, 130, 103, 87, 130, 110, 0, 220, 110, 110,
        220, 207, 196, 185, 174, 185, 0, 113, 155, 146, 138, 130, 116, 130, 0, 87, 103, 87, 110, 130, 110, 130, 164,
        0, 220, 110, 110, 220, 207, 196, 185, 174, 185, 0, 113, 155, 146, 138, 130, 116, 130, 0, 87, 103, 87, 130,
        110, 87, 130, 110, 0
};
const uint8_t PROGMEM tempoImperialMarch[74] = {
        3, 3, 3, 4, 10, 3, 4, 10, 2, 3, 3, 3, 3, 4, 10, 3, 4, 10, 2, 3, 3, 5, 10, 3, 4, 9, 12, 12, 6, 4, 6, 3, 4, 9,
        12, 12, 6, 4, 6, 3, 4, 12, 3, 4, 12, 2, 3, 3, 5, 10, 3, 4, 9, 12, 12, 6, 4, 6, 3, 4, 9, 12, 12, 6, 4, 6, 3,
        4, 12, 3, 4, 12, 2, 2
};
const uint16_t PROGMEM melodyMarioTitle[78] = {
        2637, 2637, 0, 2637, 0, 2093, 2637, 0, 3136, 0, 0, 0, 1568, 0, 0, 0, 2093, 0, 0, 1568, 0, 0, 1175, 0, 0,
        1760, 0, 1976, 0, 1865, 1760, 0, 1568, 2637, 3136, 3520, 0, 2794, 3136, 0, 2637, 0, 2093, 2349, 1976, 0, 0,
        2093, 0, 0, 1568, 0, 0, 1175, 0, 0, 1760, 0, 1976, 0, 1865, 1760, 0, 1568, 2637, 3136, 3520, 0, 2794, 3136,
        0, 2637, 0, 2093, 2349, 1976, 0, 0
};
const uint8_t PROGMEM tempoMarioTitle[78] = {
        12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12, 9, 9, 9, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12, 12, 12, 12, 9, 9, 9, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12
};
const uint16_t PROGMEM melodyMarioUnderworld[56] = {
        262, 523, 220, 440, 233, 466, 0, 0, 262, 523, 220, 440, 233, 466, 0, 0, 175, 349, 147, 294, 156, 311, 0, 0,
        175, 349, 147, 294, 156, 311, 0, 0, 311, 277, 294, 277, 311, 311, 208, 196, 277, 262, 370, 349, 165, 466,
        440, 415, 311, 247, 233, 220, 208, 0, 0, 0
};
const uint8_t PROGMEM tempoMarioUnderworld[56] = {
        12, 12, 12, 12, 12, 12, 6, 3, 12, 12, 12, 12, 12, 12, 6, 3, 12, 12, 12, 12, 12, 12, 6, 3, 12, 12, 12, 12,
        12, 12, 6, 6, 18, 18, 18, 6, 6, 6, 6, 6, 6, 18, 18, 18, 18, 18, 18, 10, 10, 10, 10, 10, 10, 3, 3, 3
};
const uint16_t PROGMEM melodyPirates[66] = {
        294, 220, 262, 294, 294, 294, 330, 349, 349, 349, 392, 330, 330, 294, 262, 262, 294, 0, 220, 262, 247, 294,
        247, 330, 349, 349, 262, 262, 262, 262, 294, 262, 294, 0, 0, 220, 262, 294, 294, 294, 349, 392, 392, 392,
        440, 440, 440, 440, 392, 440, 294, 0, 294, 165, 349, 349, 392, 440, 294, 0, 294, 349, 330, 330, 349, 294
};
const uint8_t PROGMEM tempoPirates[66] = {
        8,8,8,8,4,4,8,8,4,4,8,8,4,4,8,8,8,4,8,8,8,4,4,8,8,4,4,8,8,4,4,8,4,
        4,8,8,8,8,4,4,8,8,4,4,8,8,4,4,8,8,8,4,8,8,8,4,4,4,8,4,8,8,8,4,4,8
};
const uint16_t PROGMEM melodyPotter[15] = {
        617, 824, 980, 873, 824, 1234, 1100, 925, 824, 980, 873, 777, 873, 617, 0
};
const uint8_t PROGMEM tempoPotter[15] = {
//            5, 3, 10, 5, 3, 5, 2, 2, 3, 10, 5, 3, 5, 2, 16
        6, 4, 11, 6, 4, 6, 2, 2, 4, 11, 6, 4, 6, 2, 16
};
const uint16_t* melodiesTable[6] = {
        melodyError, melodyImperialMarch, melodyMarioTitle, melodyMarioUnderworld, melodyPirates, melodyPotter
};
const uint8_t *temposTable[6] = {
        tempoError, tempoImperialMarch, tempoMarioTitle, tempoMarioUnderworld, tempoPirates, tempoPotter
};
uint64_t sizesTable[6] = {
        sizeof(tempoError), sizeof(tempoImperialMarch), sizeof(tempoMarioTitle), sizeof(tempoMarioUnderworld),
        sizeof(tempoPirates), sizeof(tempoPotter)
};


Speaker::Speaker(uint8_t pinSpeaker) {
    this->pinSpeaker = pinSpeaker;
}

void Speaker::playMelody(){
    uint32_t currentTime = millis();
    if(currentTime - noteStartedAt >= noteToPlayDuration){
        noteToPlay = pgm_read_word_near(melodiesTable[melodyNumber] + noteCounter);
        noteToPlayDuration = 1600 / pgm_read_byte_near(temposTable[melodyNumber] + noteCounter);
        noteStartedAt = currentTime;
        tone(pinSpeaker, noteToPlay, noteToPlayDuration);
        noteCounter++;
        if(noteCounter >= sizesTable[melodyNumber]) noteCounter = 0;
    }
}

void Speaker::setMelodyByNumber(uint8_t melodyNumber) {
    this->melodyNumber = melodyNumber;
    melodySize = sizesTable[melodyNumber];
    noteCounter = 0;
}

void Speaker::setErrorMelody() {
    melodyNumber = 0;
    noteCounter = 0;
    melodySize = sizesTable[melodyNumber];
}

void Speaker::setImperialMarchMelody() {
    melodyNumber = 1;
    noteCounter = 0;
    melodySize = sizesTable[melodyNumber];
}

void Speaker::setMarioTitleMelody() {
    melodyNumber = 2;
    noteCounter = 0;
    melodySize = sizesTable[melodyNumber];
}

void Speaker::setMarioUnderworldMelody() {
    melodyNumber = 3;
    noteCounter = 0;
    melodySize = sizesTable[melodyNumber];
}

void Speaker::setPiratesMelody() {
    melodyNumber = 4;
    noteCounter = 0;
    melodySize = sizesTable[melodyNumber];
}

void Speaker::setPotterMelody() {
    melodyNumber = 5;
    noteCounter = 0;
    melodySize = sizesTable[melodyNumber];
}

void Speaker::replaceCurrentlyPlayingNoteWith(uint16_t note, uint16_t duration){
    // TODO: make it more smoth
    noteStartedAt = millis();
    noteToPlayDuration = duration;
    tone(pinSpeaker, note, duration);
    noteCounter++;
    if(noteCounter >= melodySize) noteCounter = 0;
}

void Speaker::soundJump(){
    replaceCurrentlyPlayingNoteWith(900, 50);
}

void Speaker::soundLand(){
    replaceCurrentlyPlayingNoteWith(100, 50);
}

void Speaker::soundCollision(){
    replaceCurrentlyPlayingNoteWith(100, 50);
}

void Speaker::soundButtonHit(){
    replaceCurrentlyPlayingNoteWith(800, 50);
}

void Speaker::soundButtonReleased(){
    replaceCurrentlyPlayingNoteWith(500, 50);
}