#include "images.h"
#include "SDL02.h"
#include <SDL_image.h>


Gallery::Gallery(SDL_Renderer* renderer_)
    : renderer(renderer_)
{
    loadGamePictures();
}

Gallery::~Gallery()
{
    for (SDL_Texture* texture : pictures)
        SDL_DestroyTexture(texture);
}

SDL_Texture* Gallery::loadTexture(std::string path )
{
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if ( loadedSurface == NULL )
        logSDLError(std::cout, "Unable to load image " + path + " SDL_image Error: " + IMG_GetError());
    else {
        newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
        if( newTexture == NULL )
            logSDLError(std::cout, "Unable to create texture from " + path + " SDL Error: " + SDL_GetError());
        SDL_FreeSurface( loadedSurface );
    }
    return newTexture;
}

void Gallery::loadGamePictures()
{
    pictures[PIC_BGD] = loadTexture("images/background.png");
    card[1] = IMG_LoadTexture(renderer,"images/1.png");
    card[2] = IMG_LoadTexture(renderer,"images/2.png");
    card[3] = IMG_LoadTexture(renderer,"images/3.png");
    card[4] = IMG_LoadTexture(renderer,"images/4.png");
    card[5] = IMG_LoadTexture(renderer,"images/5.png");
    card[6] = IMG_LoadTexture(renderer,"images/6.png");
    card[7] = IMG_LoadTexture(renderer,"images/7.png");
    card[8] = IMG_LoadTexture(renderer,"images/8.png");
    card[9] = IMG_LoadTexture(renderer,"images/9.png");
}

void Gallery::suffle()
{
    int r=0;

    srand ((unsigned)time(NULL));
    int smap[16] = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8};
    for(int i=0;i<16;i++)
    {
        int s = rand() % 16;
        int temp=smap[s];
            smap[s]=smap[i];
            smap[i]=temp;
    }

    for(int c=0;c<4;c++)
    {
        for(int d=0;d<4;d++)
        {
            //srand (time(NULL)+(c+1)*(d+1));
            Tmap[c][d] = smap[r];
            r++;
        }
    }
}

void Gallery::renderer_card()
{

    //SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    //clears screen
    //SDL_RenderClear(renderer);

    int r;
    for(int c=0;c<4;c++)
    {
        for(int d=0;d<4;d++)
        {
            r=Tmap[c][d];

            displayRect.x=140+c*210;displayRect.y=40+d*160;displayRect.w=150;displayRect.h=100;

            SDL_RenderCopy(renderer, card[r], NULL, &displayRect);
            //SDL_RenderCopy(renderer, card[9], NULL, &displayRect);

        }
    }

    SDL_RenderPresent(renderer);
}


