#ifndef VECTOR_H
#define VECTOR_H

#if ARDUINO >= 100
#include "Arduino.h"
#else
#endif

#include "math.h"

//// Vector code example: https://www.geeksforgeeks.org/using-class-to-implement-vector-quantities-in-c/
//// Vector algebra for dummies: https://habr.com/ru/post/131931/

class Vector {
public:
    //constructors
    Vector();
    Vector(float x, float y);

    //getters
    float getX();
    float getY();

    //operators
    void operator += (Vector v);
    void operator -= (Vector v);
    void operator *= (float f);
    Vector operator * (float f);

    //setters
    void setX(float x);
    void setY(float y);
    void setXY(float x, float y);
    void invertX();
    void invertY();

    //calculate vector's length(speed)
    float getVectorLength();

    //returns this->x & this->y as string
    String asString();
private:
    float x, y;
};

#endif //VECTOR_H
