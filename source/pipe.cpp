#include "pipe.hpp"

namespace pipe{

    float pipeY[5];
    float pipeX[5];
    float pipeDistance = 120;
    float gapDistance = 245;

    void renderPipe(){
        drawSpriteAlpha(0, 0, 40, 246, sprite::bottomPipe, pipeX[0], pipeY[0] + 55, 0);
        drawSpriteAlpha(0, 0, 40, 246, sprite::bottomPipe, pipeX[1], pipeY[1] + 55, 0);
        drawSpriteAlpha(0, 0, 40, 246, sprite::bottomPipe, pipeX[2], pipeY[2] + 55, 0);
        drawSpriteAlpha(0, 0, 40, 246, sprite::bottomPipe, pipeX[3], pipeY[3] + 55, 0);
        drawSpriteAlpha(0, 0, 40, 246, sprite::bottomPipe, pipeX[4], pipeY[4] + 55, 0);
        //drawSpriteAlpha(0, 0, 40, 246, sprite::bottomPipe, pipeX[5], pipeY[5] + 55, 0);

        drawSpriteAlpha(0, 0, 40, 246, sprite::topPipe, pipeX[0], pipeY[0] - gapDistance, 0);
        drawSpriteAlpha(0, 0, 40, 246, sprite::topPipe, pipeX[1], pipeY[1] - gapDistance, 0);
        drawSpriteAlpha(0, 0, 40, 246, sprite::topPipe, pipeX[2], pipeY[2] - gapDistance, 0);
        drawSpriteAlpha(0, 0, 40, 246, sprite::topPipe, pipeX[3], pipeY[3] - gapDistance, 0);
        drawSpriteAlpha(0, 0, 40, 246, sprite::topPipe, pipeX[4], pipeY[4] - gapDistance, 0);
        //drawSpriteAlpha(0, 0, 40, 246, sprite::topPipe, pipeX[5], pipeY[5] - gapDistance, 0);
    }
    void movePipe(){
        pipeX[0] -= 1;
        pipeX[1] -= 1;
        pipeX[2] -= 1;
        pipeX[3] -= 1;
        pipeX[4] -= 1;
        //pipeX[5] -= 1;
    }
    void resetPipe(){
        if (pipeX[0] <= -120){
            pipeX[0] = 480;
            pipeY[0] = rand() % 130;
        }

        if (pipeX[1] <= -120){
            pipeX[1] = 480;
            pipeY[1] = rand() % 130;
        }

        if (pipeX[2] <= -120){
            pipeX[2] = 480;
            pipeY[2] = rand() % 130;
        }

        if (pipeX[3] <= -120){
            pipeX[3] = 480;
            pipeY[3] = rand() % 130;
        }

        if (pipeX[4] <= -120){
            pipeX[4] = 480;
            pipeY[4] = rand() % 130;
        }

        /*
        if (pipeX[5] <= -120){
            pipeX[5] = 480;
        }
        */
    }
    void setX(){
        pipeX[0] = 480;
        pipeX[1] = 480 + pipeDistance;
        pipeX[2] = 480 + pipeDistance + pipeDistance;
        pipeX[3] = 480 + pipeDistance + pipeDistance + pipeDistance;
        pipeX[4] = 480 + pipeDistance + pipeDistance + pipeDistance + pipeDistance;
        //pipeX[5] = 480 + pipeDistance + pipeDistance + pipeDistance + pipeDistance + pipeDistance;
    }
    void setY(){
        pipeY[0] = rand() % 130;
        pipeY[1] = rand() % 130;
        pipeY[2] = rand() % 130;
        pipeY[3] = rand() % 130;
        pipeY[4] = rand() % 130;
        //pipeY[5] = rand() % 120;
    }
}