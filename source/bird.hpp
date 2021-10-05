#include "global.hpp"
#include "image2.hpp"
#include "audio.hpp"

namespace bird{
    extern float birdY;
    extern float birdX;
    extern float birdSpeed;

    extern float countDown;
    extern int birdFrame;

    extern bool dead;
    extern bool outOfBounds;

    void renderBird();
    void moveBird();
    void gravityBird();
    void animateBird();
}