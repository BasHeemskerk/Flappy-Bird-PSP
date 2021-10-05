#include "ground.hpp"

namespace ground{
    float groundX[8];
    //float countDown = 0.2f;

    void renderGround(){
        drawSpriteAlpha(0, 0, 168, 56, image::ground, groundX[0], 216, 0);
        drawSpriteAlpha(0, 0, 168, 56, image::ground, groundX[1], 216, 0);
        drawSpriteAlpha(0, 0, 168, 56, image::ground, groundX[2], 216, 0);
        drawSpriteAlpha(0, 0, 168, 56, image::ground, groundX[3], 216, 0);

        drawSpriteAlpha(0, 0, 168, 56, image::ground, groundX[4], 216, 0);
        drawSpriteAlpha(0, 0, 168, 56, image::ground, groundX[5], 216, 0);
        drawSpriteAlpha(0, 0, 168, 56, image::ground, groundX[6], 216, 0);
        drawSpriteAlpha(0, 0, 168, 56, image::ground, groundX[7], 216, 0);
    }

    void setX(){
        groundX[0] = 0;
        groundX[1] = 168;
        groundX[2] = 336;
        groundX[3] = 504;
        groundX[4] = 672;
        groundX[5] = 840;
        groundX[6] = 1008;
        groundX[7] = 1176;
    }

    void moveGround(){
        groundX[0] -= 1;
        groundX[1] -= 1;
        groundX[2] -= 1;
        groundX[3] -= 1;
        groundX[4] -= 1;
        groundX[5] -= 1;
        groundX[6] -= 1;
        groundX[7] -= 1;

        if (groundX[7] == 480){
            setX();
        }
    }
}