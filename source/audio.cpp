#include "audio.hpp"

namespace music{

    OSL_SOUND* music;

    void loadMusic(){
        music = oslLoadSoundFileWAV("files/music/music.wav", OSL_FMT_NONE);
    }
    void playMusic(){
        oslPlaySound(music, 5);

        oslSetSoundLoop(music, 1);
        if (oslGetSoundChannel(music) == -1){
            oslPlaySound(music, 5);
        }
    }
    void stopMusic(){
        oslPauseSound(music, -1);
    }
    void unloadMusic(){
        oslDeleteSound(music);
    }
}

namespace sfx{
    OSL_SOUND* flap;
    OSL_SOUND* hit;
    OSL_SOUND* die;
    OSL_SOUND* pass;
    OSL_SOUND* woosh;

    void loadSfx(){
        flap = oslLoadSoundFileWAV("files/sfx/game/flap.wav", OSL_FMT_NONE);
        hit = oslLoadSoundFileWAV("files/sfx/game/hit.wav", OSL_FMT_NONE);
        die = oslLoadSoundFileWAV("files/sfx/game/die.wav", OSL_FMT_NONE);
        pass = oslLoadSoundFileWAV("files/sfx/game/pass.wav", OSL_FMT_NONE);
        woosh = oslLoadSoundFileWAV("files/sfx/game/woosh.wav", OSL_FMT_NONE);
    }
    void playFlap(){
        oslPlaySound(flap, 0);
    }
    void playHit(){
        oslPlaySound(hit, 1);
    }
    void playDie(){
        oslPlaySound(die, 2);
    }
    void playPass(){
        oslPlaySound(pass, 3);
    }
    void playWoosh(){
        oslPlaySound(woosh, 4);
    }
    void unloadSfx(){
        oslDeleteSound(flap);
        oslDeleteSound(hit);
        oslDeleteSound(die);
        oslDeleteSound(pass);
        oslDeleteSound(woosh);
    }
}