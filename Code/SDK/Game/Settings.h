#ifndef BRAVEHERO_SETTINGS_H
#define BRAVEHERO_SETTINGS_H

#include <zconf.h>

class Settings {
public:
    static Settings &Instance() {
        static Settings braveSettings;
        return braveSettings;
    }

    static uint GetScrWidth();

    static uint GetScrHeight();

    static uint GetGLVersion();

    static bool GetFullscreen();

private:
    static uint SCR_WIDTH;
    static uint SCR_HEIGHT;
    static uint VERSION_GL;
    static bool FULLSCREEN;

    Settings() {}

    Settings(Settings const &);

    Settings &operator=(Settings const &);
};


#endif //BRAVEHERO_SETTINGS_H
