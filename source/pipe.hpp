#include "global.hpp"
#include "image2.hpp"

namespace pipe{

    extern float pipeY[5];
    extern float pipeX[5];
    extern float pipeDistance;
    extern float gapDistance;

    void renderPipe();
    void movePipe();
    void resetPipe();

    void setX();
    void setY();
}