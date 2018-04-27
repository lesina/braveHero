#include "PhysObject.h"

PhysObject::PhysObject(float x, float y, float vx, float vy, float width, float height) {
    this->x = x;
    this->y = y;
    this->vx = vx;
    this->vy = vy;
    this->width = width;
    this->height = height;
}

float PhysObject::GetX() {
    return x;
}

float PhysObject::GetY() {
    return y;
}

float PhysObject::GetVX() {
    return vx;
}

float PhysObject::GetVY() {
    return vy;
}

float PhysObject::GetWIDTH() {
    return width;
}

float PhysObject::GetHEIGHT() {
    return height;
}

void PhysObject::Move(float dTime) {
    x = x + vx * dTime;
}