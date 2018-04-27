#include "GameObject.h"

GameObject::GameObject(float x, float y, float vx, float vy, float width, float height, const char *texture) {
    phys = new PhysObject(x, y, vx, vy, width, height);
    graph = new GraphObject(texture);
}

void GameObject::Update(float dTime = 0) {
    phys->Move(dTime);
    graph->Draw();
}