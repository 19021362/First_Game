#ifndef SDL02_H
#define SDL02_H

#include<SDL.h>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>

using namespace std;

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer,
              int SCREEN_WIDTH, int SCREEN_HEIGHT, const string& WINDOW_TITLE);


void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal = false);

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

void waitUntilKeyPressed();


#endif // SDL02_H
