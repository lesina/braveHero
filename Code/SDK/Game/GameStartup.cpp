#include "GameStartup.h"
#include "../../logging.h"
#include "GraphicStartup.h"

void GameStartup::init() {
    braveLog::braveLogAlways("%s: Init game", __PRETTY_FUNCTION__);
    GraphicStartup::init();
}

void GameStartup::start() {
    braveLog::braveLogAlways("%s: Start game", __PRETTY_FUNCTION__);
    while (GraphicStartup::WindowShouldNotClose()) {
        update();
    }

    stop();
}

void GameStartup::update() {
    GraphicStartup::update();
}

void GameStartup::stop() {
    braveLog::braveLogAlways("%s: Stop game", __PRETTY_FUNCTION__);
    GraphicStartup::stop();
}