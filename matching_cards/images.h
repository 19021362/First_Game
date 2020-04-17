#ifndef IMAGES_H
#define IMAGES_H

#include <vector>
#include <string>
#include <SDL.h>

enum PictureID {
    PIC_BGD = 0,one,two,three,four,five,six,seven,eight,
    PIC_SCRT = 9,
    PIC_COUNT = 16

};

class Gallery
{
    SDL_Texture* pictures[PIC_COUNT];
    SDL_Texture* card[PIC_COUNT];
    SDL_Renderer* renderer;
    SDL_Texture* loadTexture(std::string path);
    SDL_Rect* cards[PIC_COUNT];
    SDL_Rect displayRect;
    int Tmap[12][9];
public:
    Gallery(SDL_Renderer* renderer_);
    ~Gallery();

    void loadGamePictures();
    void renderer_card();
    void suffle();
    SDL_Texture* getImage(PictureID id) const { return pictures[id]; }
};

#endif // IMAGES_H
