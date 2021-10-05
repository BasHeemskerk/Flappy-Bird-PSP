#include "score.hpp"

namespace score{

    int totalScore;

    int scoreOne;
    int scoreTwo;
    int scoreThree;
    int scoreFour;

    int wichMedal;

    std::fstream scores;

    void drawScore(){
        if (totalScore >= 0 && totalScore <= 9){
            drawSpriteAlpha(0, 0, 60, 60, number::numbersBig[scoreOne], 200, 20, 0);
        }
        else if (totalScore >= 10 && totalScore <= 99){
        drawSpriteAlpha(0, 0, 60, 60, number::numbersBig[scoreTwo], 187.5f, 20, 0);
        drawSpriteAlpha(0, 0, 60, 60, number::numbersBig[scoreOne], 213.5f, 20, 0);
        }
        else if (totalScore >= 100 && totalScore <= 999){
            drawSpriteAlpha(0, 0, 60, 60, number::numbersBig[scoreThree], 185, 20, 0);
            drawSpriteAlpha(0, 0, 60, 60, number::numbersBig[scoreTwo], 215, 20, 0);
            drawSpriteAlpha(0, 0, 60, 60, number::numbersBig[scoreOne], 245, 20, 0);
        }
        else if (totalScore >= 1000){
            drawSpriteAlpha(0, 0, 60, 60, number::numbersBig[scoreFour], 165, 20, 0);
            drawSpriteAlpha(0, 0, 60, 60, number::numbersBig[scoreThree], 195, 20, 0);
            drawSpriteAlpha(0, 0, 60, 60, number::numbersBig[scoreTwo], 225, 20, 0);
            drawSpriteAlpha(0, 0, 60, 60, number::numbersBig[scoreOne], 255, 20, 0);
        }
    }

    void addScore(){
        if (scoreOne > 9){
            scoreOne = 0;
            scoreTwo += 1;
        }

        if (scoreTwo > 9){
            scoreTwo = 0;
            scoreThree += 1;
        }

        if (scoreThree > 9){
            scoreThree = 0;
            scoreFour += 1;
        }
    }

    void renderMedalContainer(){
        drawSpriteAlpha(0, 0, 200, 101, sprite::medalContainer, 130, 80, 0);
    }

    void renderMedals(){
        if (totalScore >= 10){
            drawSpriteAlpha(0, 0, 42, 42, sprite::medals[wichMedal], 150, 115, 0);
        }
    }

    void setmedal(){
        if (totalScore >= 10 && totalScore < 20){
            wichMedal = 0;
        }
        else if (totalScore >= 20 && totalScore < 30){
            wichMedal = 1;
        }
        else if (totalScore >= 30 && totalScore < 40){
            wichMedal = 2;
        }
        else if (totalScore > 40){
            wichMedal = 3;
        }
    }

    void openScoresFile(){
        std::ofstream scores("scores/scores.txt");
    }
    void saveScore(){
        scores.open("scores/scores.txt");

        scores << totalScore << std::endl;
    }
}