#include "global.hpp"

namespace music{

    extern OSL_SOUND* music;

    void loadMusic();
    void playMusic();
    void stopMusic();
    void unloadMusic();
}

namespace sfx{
    extern OSL_SOUND* flap;
    extern OSL_SOUND* hit;
    extern OSL_SOUND* die;
    extern OSL_SOUND* pass;
    extern OSL_SOUND* woosh;

    void loadSfx();
    void playFlap();
    void playHit();
    void playDie();
    void playPass();
    void playWoosh();
    void unloadSfx();
}