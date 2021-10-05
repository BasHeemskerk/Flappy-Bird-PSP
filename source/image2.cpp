#include "image2.hpp"

namespace image{
    Image *backgrounds[2];
    Image *ground;

    void loadBackground(){
        backgrounds[0] = loadPng("files/gfx/game/BackgroundDay_1piece.png");
        backgrounds[1] = loadPng("files/gfx/game/BackgroundNight_1piece.png");
    }
    void unloadBackground(){
        freeImage(backgrounds[0]);
        freeImage(backgrounds[1]);
    }

    void loadGround(){
        ground = loadPng("files/gfx/game/ground.png");
    }
    void unloadGround(){
        freeImage(ground);
    }
}

namespace sprite{
    Image *logo;
    Image *copyright;
    Image *musicState[2];

    Image *playButton[2];
    Image *statsButton[2];
    Image *pauseButton;

    Image *yellowBird[3];
    Image *redBird[3];
    Image *blueBird[3];

    Image *medals[4];
    Image *medalContainer;

    Image* tapTap;

    Image *bottomPipe;
    Image *topPipe;

    Image *getReady;
    Image *gameOver;

    void loadLogo(){
        logo = loadPng("files/gfx/menu/logo.png");
    }
    void unloadLogo(){
        freeImage(logo);
    }

    void loadCopyright(){
        copyright = loadPng("files/gfx/menu/copyright.png");
    }
    void unloadCopyright(){
        freeImage(copyright);
    }

    void loadBird(){
        yellowBird[0] = loadPng("files/gfx/game/bird/yellow/bird1.png");
        yellowBird[1] = loadPng("files/gfx/game/bird/yellow/bird2.png");
        yellowBird[2] = loadPng("files/gfx/game/bird/yellow/bird3.png");
        
        redBird[0] = loadPng("files/gfx/game/bird/red/bird1.png");
        redBird[1] = loadPng("files/gfx/game/bird/red/bird2.png");
        redBird[2] = loadPng("files/gfx/game/bird/red/bird3.png");

        blueBird[0] = loadPng("files/gfx/game/bird/blue/bird1.png");
        blueBird[1] = loadPng("files/gfx/game/bird/blue/bird2.png");
        blueBird[2] = loadPng("files/gfx/game/bird/blue/bird3.png");
        
    }
    void unloadBird(){
        freeImage(yellowBird[0]);
        freeImage(yellowBird[1]);
        freeImage(yellowBird[2]);

        freeImage(redBird[0]);
        freeImage(redBird[1]);
        freeImage(redBird[2]);

        freeImage(blueBird[0]);
        freeImage(blueBird[1]);
        freeImage(blueBird[2]);
    }

    void loadMedals(){
        medals[0] = loadPng("files/gfx/game/ui/medals/bronze.png");
        medals[1] = loadPng("files/gfx/game/ui/medals/silver.png");
        medals[2] = loadPng("files/gfx/game/ui/medals/gold.png");
        medals[3] = loadPng("files/gfx/game/ui/medals/platanium.png");
    }
    void unloadMedals(){
        freeImage(medals[0]);
        freeImage(medals[1]);
        freeImage(medals[2]);
        freeImage(medals[3]);
    }
    void loadMedalContainer(){
        medalContainer = loadPng("files/gfx/game/ui/medalContainer.png");
    }
    void unloadMedalContainer(){
        freeImage(medalContainer);
    }

    void loadTapTap(){
        tapTap = loadPng("files/gfx/game/ui/tap-tap.png");
    }
    void unloadTapTap(){
        freeImage(tapTap);
    }

    void loadPipe(){
        bottomPipe = loadPng("files/gfx/game/pipes/bottom.png");
        topPipe = loadPng("files/gfx/game/pipes/top.png");
    }
    void unloadPipe(){
        freeImage(bottomPipe);
        freeImage(topPipe);
    }

    void loadMainButtons(){
        playButton[0] = loadPng("files/gfx/menu/play.png");
        playButton[1] = loadPng("files/gfx/menu/playSelected.png");

        statsButton[0] = loadPng("files/gfx/menu/stats.png");
        statsButton[1] = loadPng("files/gfx/menu/statsSelected.png");
    }
    void unloadMainButtons(){
        freeImage(playButton[0]);
        freeImage(playButton[1]);

        freeImage(statsButton[0]);
        freeImage(statsButton[1]);
    }

    void loadPauseButton(){
        pauseButton = loadPng("files/gfx/game/pause.png");
    }
    void unloadPauseButton(){
        freeImage(pauseButton);
    }


    void loadGetReady(){
        getReady = loadPng("files/gfx/game/ui/getReady.png");
    }
    void unloadGetReady(){
        freeImage(getReady);
    }

    void loadGameOver(){
        gameOver = loadPng("files/gfx/game/ui/gameOver.png");
    }
    void unloadGameOver(){
        freeImage(gameOver);
    }
    

    void loadMusicState(){
        musicState[0] = loadPng("files/gfx/menu/musicOff.png");
        musicState[1] = loadPng("files/gfx/menu/musicOn.png");
    }
    void unloadMusicState(){
        freeImage(musicState[0]);
        freeImage(musicState[1]);
    }
}

namespace number{
    Image *numbersSmall[10];
    Image *numbersBig[10];

    void loadNumbers(){
        numbersSmall[0] = loadPng("files/gfx/numbers/small30x30/0.png");
        numbersSmall[1] = loadPng("files/gfx/numbers/small30x30/1.png");
        numbersSmall[2] = loadPng("files/gfx/numbers/small30x30/2.png");
        numbersSmall[3] = loadPng("files/gfx/numbers/small30x30/3.png");
        numbersSmall[4] = loadPng("files/gfx/numbers/small30x30/4.png");
        numbersSmall[5] = loadPng("files/gfx/numbers/small30x30/5.png");
        numbersSmall[6] = loadPng("files/gfx/numbers/small30x30/6.png");
        numbersSmall[7] = loadPng("files/gfx/numbers/small30x30/7.png");
        numbersSmall[8] = loadPng("files/gfx/numbers/small30x30/8.png");
        numbersSmall[9] = loadPng("files/gfx/numbers/small30x30/9.png");

        numbersBig[0] = loadPng("files/gfx/numbers/big60x60/0.png");
        numbersBig[1] = loadPng("files/gfx/numbers/big60x60/1.png");
        numbersBig[2] = loadPng("files/gfx/numbers/big60x60/2.png");
        numbersBig[3] = loadPng("files/gfx/numbers/big60x60/3.png");
        numbersBig[4] = loadPng("files/gfx/numbers/big60x60/4.png");
        numbersBig[5] = loadPng("files/gfx/numbers/big60x60/5.png");
        numbersBig[6] = loadPng("files/gfx/numbers/big60x60/6.png");
        numbersBig[7] = loadPng("files/gfx/numbers/big60x60/7.png");
        numbersBig[8] = loadPng("files/gfx/numbers/big60x60/8.png");
        numbersBig[9] = loadPng("files/gfx/numbers/big60x60/9.png");
    }
    void unloadNumbers(){
        freeImage(numbersSmall[0]);
        freeImage(numbersSmall[1]);
        freeImage(numbersSmall[2]);
        freeImage(numbersSmall[3]);
        freeImage(numbersSmall[4]);
        freeImage(numbersSmall[5]);
        freeImage(numbersSmall[6]);
        freeImage(numbersSmall[7]);
        freeImage(numbersSmall[8]);
        freeImage(numbersSmall[9]);

        freeImage(numbersBig[0]);
        freeImage(numbersBig[1]);
        freeImage(numbersBig[2]);
        freeImage(numbersBig[3]);
        freeImage(numbersBig[4]);
        freeImage(numbersBig[5]);
        freeImage(numbersBig[6]);
        freeImage(numbersBig[7]);
        freeImage(numbersBig[8]);
        freeImage(numbersBig[9]);
    }
}