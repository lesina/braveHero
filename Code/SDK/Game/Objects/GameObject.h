#ifndef BRAVEHERO_GAMEOBJECT_H
#define BRAVEHERO_GAMEOBJECT_H


#include "PhysObject.h"
#include "GraphObject.h"

class GameObject {
private:
    PhysObject *phys;
    GraphObject *graph;
public:
    GameObject();
    GameObject(const char *);
    GameObject(float, float, float, float, float, float, const char *);
    void Update(float dTime);
};


#endif //BRAVEHERO_GAMEOBJECT_H
