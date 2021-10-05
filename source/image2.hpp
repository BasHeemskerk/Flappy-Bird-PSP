#include "global.hpp"

namespace image{
    extern Image *backgrounds[2];
    extern Image *ground;

    void loadBackground();
    void unloadBackground();

    void loadGround();
    void unloadGround();
}

namespace sprite{
    extern Image *logo;
    extern Image *copyright;

    extern Image *playButton[2];
    extern Image *statsButton[2];
    extern Image *pauseButton;

    extern Image *yellowBird[3];
    extern Image *redBird[3];
    extern Image *blueBird[3];

    extern Image *medals[4];
    extern Image *medalContainer;

    extern Image *tapTap;

    extern Image *bottomPipe;
    extern Image *topPipe;

    extern Image *getReady;
    extern Image *gameOver;

    extern Image *musicState[2];

    void loadLogo();
    void unloadLogo();

    void loadCopyright();
    void unloadCopyright();

    void loadBird();
    void unloadBird();

    void loadMedals();
    void unloadMedals();

    void loadMedalContainer();
    void unloadMedalContainer();

    void loadTapTap();
    void unloadTapTap();

    void loadPipe();
    void unloadPipe();

    void loadMainButtons();
    void unloadMainButtons();

    void loadPauseButton();
    void unloadPauseButton();

    void loadGetReady();
    void unloadGetReady();

    void loadGameOver();
    void unloadGameOver();

    void loadMusicState();
    void unloadMusicState();
}

namespace number{
    extern Image *numbersSmall[10];
    extern Image *numbersBig[10];

    void loadNumbers();
    void unloadNumbers();
}