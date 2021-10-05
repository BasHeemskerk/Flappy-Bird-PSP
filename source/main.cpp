#include "global.hpp"

//global
#include "image2.hpp"
#include "state.hpp"
#include "audio.hpp"
#include "collision.hpp"
#include "score.hpp"

//single
#include "background.hpp"
#include "ground.hpp"
#include "menu.hpp"
#include "bird.hpp"
#include "pipe.hpp"

using namespace std;

#define BUF_WIDTH (512)
#define SCR_WIDTH (480)
#define SCR_HEIGHT (272)
#define PIXEL_SIZE (4) 
#define FRAME_SIZE (BUF_WIDTH * SCR_HEIGHT * PIXEL_SIZE)
#define ZBUF_SIZE (BUF_WIDTH SCR_HEIGHT * 2)

PSP_MODULE_INFO("FNaF 1 Portable", 0, 1, 0);

PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER | THREAD_ATTR_VFPU);
PSP_HEAP_SIZE_KB(-1024);

#if _PSP_FW_VERSION >= 200
PSP_HEAP_SIZE_KB(20480);
#endif

static unsigned int __attribute__((aligned(16))) DisplayList[262144];

int exit_callback(int arg1, int arg2, void* common){
    sceKernelExitGame();
    return 0;
}

int callbackThread(SceSize args, void* argp){
    int cbid = sceKernelCreateCallback("Exit Callback", exit_callback, NULL);
    sceKernelRegisterExitCallback(cbid);

    sceKernelSleepThreadCB();
    return 0;
}

void setupCallbacks(){
    int thid = sceKernelCreateThread("update_thread", callbackThread, 0x11, 0xFA0, 0, NULL);
    if (thid >= 0){
        sceKernelStartThread(thid, 0, NULL);
    }
}

void* fbp0 = NULL;
void* fbp1 = NULL;
void* renderTarget = NULL;
void* zbp = NULL;

void InitGU(){    
    fbp0 = getStaticVramBuffer(BUF_WIDTH,SCR_HEIGHT,GU_PSM_8888);
    fbp1 = getStaticVramBuffer(BUF_WIDTH,SCR_HEIGHT,GU_PSM_8888);
    zbp = getStaticVramBuffer(BUF_WIDTH,SCR_HEIGHT,GU_PSM_4444);

    renderTarget = getStaticVramBuffer(BUF_WIDTH,SCR_HEIGHT,GU_PSM_8888);

    sceGuInit();
    sceGuStart(GU_DIRECT,DisplayList);

    sceGuDrawBuffer(GU_PSM_8888,fbp0,BUF_WIDTH);
    sceGuDispBuffer(SCR_WIDTH,SCR_HEIGHT,fbp1,BUF_WIDTH);
    sceGuDepthBuffer(zbp,BUF_WIDTH);

    sceGuDepthRange(65535,0);
    sceGuDepthMask(GU_FALSE);

    sceGuOffset(2048 - (SCR_WIDTH / 2),2048 - (SCR_HEIGHT / 2));

    sceGuViewport(2048,2048,SCR_WIDTH,SCR_HEIGHT);

    sceGuClear(GU_COLOR_BUFFER_BIT | GU_DEPTH_BUFFER_BIT);

    sceGuScissor(0,0,SCR_WIDTH,SCR_HEIGHT);
    sceGuEnable(GU_SCISSOR_TEST);

    sceGuAlphaFunc(GU_GREATER,0,0xff);
    sceGuEnable(GU_ALPHA_TEST);

    sceGuDepthFunc(GU_GEQUAL);
    sceGuEnable(GU_DEPTH_TEST);

    sceGuFrontFace(GU_CW);

    sceGuTexMode(GU_PSM_5650,0,0,0); 
    sceGuTexFunc(GU_TFX_REPLACE,GU_TCC_RGBA);
    sceGuTexFilter(GU_NEAREST,GU_NEAREST);

    sceGuEnable(GU_CULL_FACE);
    
    sceGuEnable(GU_TEXTURE_2D);

    sceGuEnable(GU_DITHER);

    sceGuEnable(GU_CLIP_PLANES);
    
    sceGuEnable(GU_LIGHTING);
    sceGuEnable(GU_LIGHT0);
    sceGuEnable(GU_LIGHT1);
    sceGuEnable(GU_LIGHT2);
    sceGuEnable(GU_LIGHT3);
    
    sceGuEnable(GU_FOG);

    sceGuEnable(GU_BLEND);
    sceGuBlendFunc(GU_ADD,GU_SRC_ALPHA,GU_ONE_MINUS_SRC_ALPHA,0,0);

    sceGuShadeModel(GU_SMOOTH); 

    sceGuFinish();

    sceGuSync(0,0);

    sceDisplayWaitVblankStart();

    sceGuDisplay(GU_TRUE);
}

void initEngine(){
    setupCallbacks();
    pspDebugScreenInit();

    sceCtrlSetSamplingCycle(0);
    sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);

    InitGU();

    //oslInit();
    VirtualFileInit();
    oslInitAudio();
}

void initGame(){
    image::loadBackground();
    image::loadGround();

    sprite::loadBird();
    sprite::loadLogo();
    sprite::loadCopyright();
    sprite::loadMainButtons();
    sprite::loadMedalContainer();
    sprite::loadMedals();
    sprite::loadTapTap();
    sprite::loadGetReady();
    sprite::loadGameOver();
    sprite::loadMusicState();

    number::loadNumbers();
    
    music::loadMusic();
    sfx::loadSfx();

    ground::setX();

    score::openScoresFile();
}


auto main() -> int{

    
    SceCtrlData ctrlData;

    initEngine();

    initGame();

    std::string prevState = "none";
    std::string prevState2 = "none";
    bool started = false;
    bool musicOn = false;
    float countDown = 1;
    float countDown2 = 1;
    float gameStartCountdown = 10;


    while(true){

        sceCtrlReadBufferPositive(&ctrlData, 1);

        sceDisplayWaitVblankStart();

        //running = isRunning();

        sceGuStart(GU_DIRECT,DisplayList);

        // clear screen

        sceGuClearColor(0x000000);
        sceGuClearDepth(0);
        sceGuClear(GU_COLOR_BUFFER_BIT | GU_DEPTH_BUFFER_BIT);

        // setup aspect ratio

        sceGumMatrixMode(GU_PROJECTION);
        sceGumLoadIdentity();
        sceGumPerspective(70.0f,16.0f/9.0f,0.5f,1000.0f);
            
            // setup camera
        sceGumMatrixMode(GU_VIEW);
        {
            ScePspFVector3 pos = {0, 0, 0};
            ScePspFVector3 rot = { 0, 0, 0 };

            sceGumLoadIdentity();
            sceGumTranslate(&pos);
            sceGumRotateXYZ(&rot);
        }

        if (state::menu){

            background::renderBackground();
            ground::renderGround();
            ground::moveGround();

            menuBird::renderBird();
            menuBird::animateBird();
            menuBird::moveBird();

            menu::renderLogo();
            menu::renderCopyright();
            menu::renderButtons();

            menu::renderMusicState();

            if (ctrlData.Buttons & PSP_CTRL_LEFT){
                menu::cursorPos -= 1;
                menu::moveCursor();
            }
            else if (ctrlData.Buttons & PSP_CTRL_RIGHT){
                menu::cursorPos += 1;
                menu::moveCursor();
            }

            if (ctrlData.Buttons & PSP_CTRL_CROSS){
                if (menu::cursorPos == 0){
                    state::menu = false;
                    sprite::unloadLogo();
                    sprite::unloadCopyright();
                    sprite::unloadMainButtons();

                    sprite::loadPipe();
                    
                    pipe::setX();
                    
                    music::unloadMusic();

                    state::game = true;
                }
                else if (menu::cursorPos == 1){

                }
            }

            if (ctrlData.Buttons & PSP_CTRL_RTRIGGER && prevState2 == "none"){
                if (musicOn == false){
                    music::playMusic();

                    menu::wichMusicState = 1;
                    musicOn = true;
                }
                else{
                    music::stopMusic();

                    menu::wichMusicState = 0;
                    musicOn = false;
                }

                prevState2 = "pressed";
                countDown2 = 15;
            }

            if (prevState2 == "pressed"){
                countDown2 -= 1;
            }

            if (countDown2 <= 0){
                prevState2 = "none";
            }

            pipe::setY();
        }

        if (state::game){

            background::renderBackground();

            pipe::renderPipe();
            ground::renderGround();

            bird::renderBird();
            bird::animateBird();

            if (started == true){

                if (gameStartCountdown <= 0){
                    if (bird::outOfBounds == false && bird::dead == false){
                        pipe::movePipe();
                        pipe::resetPipe();
                        ground::moveGround();
                        score::drawScore();
                        score::addScore();
                    }
                    else{
                        score::renderMedalContainer();
                        score::renderMedals();
                        gameMenu::renderGameOver();
                    }

                    bird::gravityBird();

                    collision::checkForCollision();

                    //controlls + delay
                    if (ctrlData.Buttons & PSP_CTRL_CROSS && prevState == "none"){
                        bird::moveBird();

                        prevState = "pressed";
                    }
                    else if (ctrlData.Buttons & PSP_CTRL_CROSS && bird::dead == true){
                        score::saveScore();
                        state::game = false;
                        state::reset = true;
                    }

                    if (ctrlData.Buttons & PSP_CTRL_START){
                        state::game = false;
                        initGame();
                        started = false;
                        gameStartCountdown = 30;
                        state::reset = true;
                        state::menu = true;
                    }
                    
                    if (prevState == "pressed"){
                        countDown -= 1;
                    }

                    if (countDown <= 0 && prevState == "pressed"){
                        prevState = "none";
                        countDown = 15;
                    }
                }
                else{
                    gameStartCountdown -= 1;

                    gameMenu::renderGetReady();
                }
            }
            else{
                gameMenu::renderTapTap();

                if (gameStartCountdown <= 0){
                    if (ctrlData.Buttons & PSP_CTRL_CROSS){
                        started = true;
                        gameStartCountdown = 60;
                    }
                }
                else{
                    gameStartCountdown -= 1;
                }
            }
        }

        if (state::reset){
            pipe::setX();
            bird::birdY = 120;
            bird::dead = false;
            bird::outOfBounds = false;
            started = false;
            gameStartCountdown = 30;
            bird::birdSpeed = 0;
            score::totalScore = 0;
            score::scoreOne = 0;
            score::scoreTwo = 0;
            score::scoreThree = 0;
            score::scoreFour = 0;
            state::game = true;
            state::reset = false;
        }

        state::checkState();
        
            
        sceGuFinish();
        sceGuSync(0,0);

        sceGuSwapBuffers();
    }
}