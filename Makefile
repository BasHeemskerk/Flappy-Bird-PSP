TARGET = FNaF_1
OBJS = source/main.o 		\
source/image.o 				\
source/graphics.o 			\
source/vram.o				\
source/image2.o				\
source/state.o				\
source/audio.o				\
source/background.o			\
source/ground.o				\
source/menu.o				\
source/bird.o				\
source/pipe.o				\
source/collision.o			\
source/score.o


CFLAGS = -O2 -G0 -Wall -g -gdwarf-2
CXXFLAGS = $(CFLAGS) -std=c++14 -fno-rtti
ASFLAGS = $(CFLAGS)

# PSP stuff
BUILD_PRX = 1
#PSP_FW_VERSION = 500
#PSP_LARGE_MEMORY = 1

LIBDIR = ./ include lib $(PSPSDK)/../lib

LIBS += -lpng -lz -ljpeg -lpspgum_vfpu -lpspgu -lpspgum -lpspvfpu -lpspvram -lm	-losl -lpspaudiolib -lpspaudio -lpspaudiocodec -lpspmp3 -lstdc++

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = Flappy Bird PSP
PSP_EBOOT_ICON = ICON0.PNG

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak