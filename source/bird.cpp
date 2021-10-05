#include "bird.hpp"

namespace bird{
    float birdY = 120;
    float birdX = 80;
    float birdSpeed;

    float countDown = 4;
    int birdFrame = 0;

    bool dead = false;
    bool outOfBounds = false;

    void renderBird(){
        drawSpriteAlpha(0, 0, 30, 21, sprite::yellowBird[birdFrame], birdX, birdY, 0);
    }
    void moveBird(){
        if (!dead && !outOfBounds){
            birdSpeed = -2.6f;
            sfx::playFlap();
        }
    }
    void gravityBird(){
        if (!dead){
            birdY += birdSpeed;
            birdSpeed += 0.125f;
        }
    }
    void animateBird(){
        if (!dead){
            if (countDown <= 0){
                birdFrame += 1;
                countDown = 4;
            }
            else{
                countDown -= 1;
            }

            if (birdFrame > 2){
                birdFrame = 0;
            }
        }
    }
}