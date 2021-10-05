#include "global.hpp"
#include "image2.hpp"

namespace menuBird{


    extern float birdY;
    extern float moveCountdown;

    extern int birdFrame;
    extern float countDown;

    extern bool movingUp;
    extern bool movingDown;

    void renderBird();
    void moveBird();
    void moveBirdUp();
    void moveBirdDown();
    void animateBird();
}

namespace menu{

    extern float cursorPos;
    extern int wichPlayButton;
    extern int wichStatsButton;
    extern int wichMusicState;

    void renderLogo();
    void renderCopyright();
    void renderButtons();
    void moveCursor();

    void renderMusicState();
}

namespace gameMenu{
    void renderTapTap();
    void renderGetReady();
    void renderGameOver();
}