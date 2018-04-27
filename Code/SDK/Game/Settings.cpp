#include "Settings.h"

uint Settings::GetScrWidth() {
    return Settings::SCR_WIDTH;
}

uint Settings::GetScrHeight() {
    return Settings::SCR_HEIGHT;
}

uint Settings::GetGLVersion() {
    return Settings::VERSION_GL;
}

bool Settings::GetFullscreen() {
    return Settings::FULLSCREEN;
}

uint Settings::SCR_WIDTH = 800;
uint Settings::SCR_HEIGHT = 600;
uint Settings::VERSION_GL = 3;
bool Settings::FULLSCREEN = false;