#ifndef INCLUDE_H
#define INCLUDE_H

#include <vector>
#include <string>
#include <SDL.h>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>


enum PictureID {
    PIC_BGD = 0,
    PIC_SCRT = 9,
    PIC_WIN = 10,
    PIC_COUNT = 16

};

class Gallery
{
    SDL_Texture* pictures[PIC_COUNT];
    SDL_Renderer* renderer;
    SDL_Texture* loadTexture(std::string path);
    int Tmap[12][9];

public:

    SDL_Texture* card[PIC_COUNT];
    SDL_Rect display_card[PIC_COUNT];
    SDL_Rect displayRect;

    Gallery(SDL_Renderer* renderer_);
    ~Gallery();

    void loadGamePictures();
    void renderer_card();
    void render(int r);
    void suffle();
    void update(int *cardstatus);

    int smap[16] = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8};
    SDL_Texture* getImage(PictureID id) const { return pictures[id]; }
};

class Button
{
	public:
		void setPosition(int x, int y);
		void handleEvent( SDL_Event* e ,int i);
        int id=0;
	private:
		SDL_Point mPosition;
};


#endif // INCLUDE_H
