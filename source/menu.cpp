#include "menu.hpp"

namespace menuBird{

    int wichBird = 0;
    float birdY = 136;
    float moveCountdown = 15;

    int birdFrame = 0;
    float countDown = 5;

    bool movingUp = true;
    bool movingDown = false;
    

    void renderBird(){
        drawSpriteAlpha(0, 0, 30, 21, sprite::yellowBird[birdFrame], 220, birdY, 0);
    }
    void moveBird(){
        if (moveCountdown <= 0){
            if (movingDown){
                movingUp = true;
                movingDown = false;
            }
            else if (movingUp){
                movingDown = true;
                movingUp = false;
            }

            moveCountdown = 15;
        }
        else{
            moveCountdown -= 1;
        }

        if (movingUp){
            moveBirdDown();
        }
        else if (movingDown){
            moveBirdUp();
        }
    }
    void moveBirdUp(){
        birdY -= 1;
    }
    void moveBirdDown(){
        birdY += 1;
    }
    void animateBird(){
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

namespace menu{

    float cursorPos = 0;
    int wichPlayButton = 1;
    int wichStatsButton = 0;
    int wichMusicState = 0;

    void renderLogo(){
        drawSpriteAlpha(0, 0, 230, 109, sprite::logo, 120, 10, 0);
    }

    void renderCopyright(){
        drawSpriteAlpha(0, 0, 150, 57, sprite::copyright, 0, 0, 0);
    }

    void renderButtons(){
        drawSpriteAlpha(0, 0, 100, 56, sprite::playButton[wichPlayButton], 105, 200, 0);
        drawSpriteAlpha(0, 0, 100, 56, sprite::statsButton[wichStatsButton], 265, 200, 0);
    }

    void moveCursor(){
        if (cursorPos == 0){
            wichPlayButton = 1;
            wichStatsButton = 0;
        }
        else if (cursorPos == 1){
            wichPlayButton = 0;
            wichStatsButton = 1;
        }

        if (cursorPos <= 0){
            cursorPos = 0;
        }
        if (cursorPos >= 1){
            cursorPos = 1;
        }
    }

    void renderMusicState(){
        drawSpriteAlpha(0, 0, 135, 45, sprite::musicState[wichMusicState], 345, 0, 0);
    }
}

namespace gameMenu{
    void renderTapTap(){
        drawSpriteAlpha(0, 0, 97, 83, sprite::tapTap, 180, 80, 0);
    }

    void renderGetReady(){
        drawSpriteAlpha(0, 0, 132, 36, sprite::getReady, 160, 45, 0);
    }

    void renderGameOver(){
        drawSpriteAlpha(0, 0, 132, 34, sprite::gameOver, 160, 45, 0);
    }
}