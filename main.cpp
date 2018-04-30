#include "Code/SDK/Game/GameStartup.h"
#include "Code/logging.h"

#include <iostream>

int main() {
    GameStartup::init();
    GameStartup::start();

    return 0;
}