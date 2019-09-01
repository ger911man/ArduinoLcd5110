#include "Vector.h"

Vector::Vector(){
}

Vector::Vector(float x, float y)
{
    this->x = x;
    this->y = y;
}

float Vector:: getX(){
    return x;
}

float Vector::getY(){
    return y;
}

void Vector::operator+=(Vector v){
    x += v.x;
    y += v.y;
}

void Vector::operator-=(Vector v){
    x -= v.x;
    y -= v.y;
}

void Vector::operator*=(float f){
    x *= f;
    y *= f;
}

Vector Vector::operator*(float f){
    return Vector(x * f, y * f);
}

void Vector::setX(float x){
    this->x = x;
}

void Vector::setY(float y){
    this->y = y;
}

void Vector::setXY(float x, float y){
    this->x = x;
    this->y = y;
}

void Vector::invertX(){
    x = x*-1;
}

void Vector::invertY(){
    y = y*-1;
}

float Vector::getVectorLength(){
    return sqrt(x*x+y*y);
}

String Vector::asString(){
    return String(String(x,2)+":"+String(y,2));
}

