#include "global.hpp"
#include "image2.hpp"

namespace score{

    extern int totalScore;

    extern int scoreOne;
    extern int scoreTwo;
    extern int scoreThree;
    extern int scoreFour;

    extern int wichMedal;

    void drawScore();
    void addScore();

    void renderMedalContainer();
    void renderMedals();
    void setmedal();

    void openScoresFile();
    void saveScore();
}