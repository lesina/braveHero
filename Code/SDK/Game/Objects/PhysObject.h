#ifndef BRAVEHERO_PHYSOBJECT_H
#define BRAVEHERO_PHYSOBJECT_H


class PhysObject {
private:
    float x, y;
    float vx, vy;
    float width, height;
public:
    PhysObject(float, float, float, float, float, float);

    float GetX();

    float GetY();

    float GetVX();

    float GetVY();

    float GetWIDTH();

    float GetHEIGHT();

    void Move(float);
};


#endif //BRAVEHERO_PHYSOBJECT_H
