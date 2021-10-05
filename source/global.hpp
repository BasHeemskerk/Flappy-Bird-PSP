#include <pspkernel.h>
#include <pspdebug.h>
#include <pspctrl.h>


#include <pspgu.h>
#include <pspgum.h>

#include <pspdisplay.h>
#include <stdint.h>

#include <pspmoduleinfo.h>

#include <fstream>
#include <iostream>
#include <string>

#include <cstdlib>

extern "C" {
    #include "graphics.h"
    #include "image.h"
    #include "vram.h"
    #include "include/oslib.h"
}

using namespace std;