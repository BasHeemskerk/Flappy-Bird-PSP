#include "state.hpp"

namespace state{
    bool menu = true;
    bool game = false;
    bool reset = false;

    void checkState(){
        if (menu){
            menu = true;
            game = false;
        }

        if (game){
            menu = false;
            game = true;
        }
    }
}