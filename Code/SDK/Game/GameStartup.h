#ifndef BRAVEHERO_GAMESTARTUP_H
#define BRAVEHERO_GAMESTARTUP_H

class GameStartup {
public:
    static void init();
    static void start();
    static void update();
    static void stop();

private:
    GameStartup() {};

    GameStartup(GameStartup const &);

    GameStartup &operator=(GameStartup const &);
};


#endif //BRAVEHERO_GAMESTARTUP_H
