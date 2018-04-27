#ifndef BRAVEHERO_GRAPHOBJECT_H
#define BRAVEHERO_GRAPHOBJECT_H

#include <iostream>
#include <cstring>

class GraphObject {
private:
    std::string texture;
public:
    void Draw();
    GraphObject(const char*);
};


#endif //BRAVEHERO_GRAPHOBJECT_H
