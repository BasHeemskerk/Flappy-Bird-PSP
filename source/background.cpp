#include "background.hpp"

namespace background{

    int randomBackgroundNumber = 0;

    void renderBackground(){
        drawSpriteAlpha(0, 0, 144, 272, image::backgrounds[randomBackgroundNumber], 0, 0, 0);
        drawSpriteAlpha(0, 0, 144, 272, image::backgrounds[randomBackgroundNumber], 144, 0, 0);
        drawSpriteAlpha(0, 0, 144, 272, image::backgrounds[randomBackgroundNumber], 288, 0, 0);
        drawSpriteAlpha(0, 0, 144, 272, image::backgrounds[randomBackgroundNumber], 432, 0, 0);
    }
}