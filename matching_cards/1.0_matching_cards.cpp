#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SDL.h>

#include "SDL02.h"
#include "images.h"

using namespace std;


const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 640;
const char WINDOW_TITLE[] = "Matching Cards";

const int BUTTON_WIDTH = 180;
const int BUTTON_HEIGHT = 180;
const int TOTAL_BUTTONS = 2;

Gallery* gallery = nullptr;



int main(int argc, char* argv[])
{
    srand(time(0));
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    gallery = new Gallery(renderer);

    SDL_RenderClear( renderer );
    SDL_RenderCopy( renderer, gallery->getImage(PIC_BGD) , NULL, NULL );

    gallery->loadGamePictures();
    gallery->suffle();
    gallery->renderer_card();


    SDL_RenderPresent( renderer );

    waitUntilKeyPressed();
    SDL_Quit();
    return 0;
}


