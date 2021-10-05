#include "collision.hpp"

namespace collision{
    void checkForCollision(){
        if (bird::dead == false){
            if (bird::birdY >= 195){
                bird::dead = true;
                sfx::playHit();
            }
        }
        
        if (bird::outOfBounds == false){
            if (bird::birdY <= -30){
                sfx::playWoosh();
                bird::outOfBounds = true;
            }

            
        }

        if (bird::dead == false && bird::outOfBounds == false){
            if (bird::birdX == pipe::pipeX[0] + 5){
                sfx::playPass();

                score::totalScore += 1;
                score::scoreOne += 1;
                score::setmedal();
            }
            else if (bird::birdX == pipe::pipeX[1] + 5){
                sfx::playPass();

                score::totalScore += 1;
                score::scoreOne += 1;
                score::setmedal();
            }
            else if (bird::birdX == pipe::pipeX[2] + 5){
                sfx::playPass();

                score::totalScore += 1;
                score::scoreOne += 1;
                score::setmedal();
            }
            else if (bird::birdX == pipe::pipeX[3] + 5){
                sfx::playPass();

                score::totalScore += 1;
                score::scoreOne += 1;
                score::setmedal();
            }
            else if (bird::birdX == pipe::pipeX[4] + 5){
                sfx::playPass();

                score::totalScore += 1;
                score::scoreOne += 1;
                score::setmedal();
            }
        }

        if (bird::dead == false && bird::outOfBounds == false){
            if (bird::birdX >= pipe::pipeX[0] - 20 && bird::birdX <= pipe::pipeX[0] + 40){
                if (bird::birdY < pipe::pipeY[0] || bird::birdY > pipe::pipeY[0] + 45){
                    bird::outOfBounds = true;

                    sfx::playHit();
                    sfx::playDie();
                }
            }
            else if (bird::birdX >= pipe::pipeX[1] - 20 && bird::birdX <= pipe::pipeX[1] + 40){
                if (bird::birdY < pipe::pipeY[1] || bird::birdY > pipe::pipeY[1] + 45){
                    bird::outOfBounds = true;

                    sfx::playHit();
                    sfx::playDie();
                }
            }
            else if (bird::birdX >= pipe::pipeX[2] - 20 && bird::birdX <= pipe::pipeX[2] + 40){
                if (bird::birdY < pipe::pipeY[2] || bird::birdY > pipe::pipeY[2] + 45){
                    bird::outOfBounds = true;

                    sfx::playHit();
                    sfx::playDie();
                }
            }
            else if (bird::birdX >= pipe::pipeX[3] - 20 && bird::birdX <= pipe::pipeX[3] + 40){
                if (bird::birdY < pipe::pipeY[3] || bird::birdY > pipe::pipeY[3] + 45){
                    bird::outOfBounds = true;

                    sfx::playHit();
                    sfx::playDie();
                }
            }
            else if (bird::birdX >= pipe::pipeX[4] - 20 && bird::birdX <= pipe::pipeX[4] + 40){
                if (bird::birdY < pipe::pipeY[4] || bird::birdY > pipe::pipeY[4] + 45){
                    bird::outOfBounds = true;

                    sfx::playHit();
                    sfx::playDie();
                }
            }
        }
    }
}