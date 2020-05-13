#include "include.h"
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
    pictures[PIC_WIN] = loadTexture("images/winner.png");
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

            Tmap[c][d] = smap[r];
            r++;
        }
    }
}

void Gallery::renderer_card()
{
    int k=1;
    SDL_RenderClear( renderer );
    SDL_RenderCopy( renderer, pictures[PIC_BGD] , NULL, NULL );

    for(int c=0;c<4;c++)
    {
        for(int d=0;d<4;d++)
        {
            display_card[k].x=140+d*210;
            display_card[k].y=40+c*160;
            display_card[k].w=150;
            display_card[k].h=100;

            displayRect.x=140+c*210;
            displayRect.y=40+d*160;
            displayRect.w=150;
            displayRect.h=100;

            //SDL_RenderCopy(renderer, card[r], NULL, &display_card[k]);
            SDL_RenderCopy( renderer, card[9] , NULL, &displayRect );

            k++;

        }
    }

    SDL_RenderPresent(renderer);
}

void Gallery::render(int r)
{
    SDL_RenderCopy(renderer,card[smap[r-1]],NULL, &display_card[r]);
    //SDL_RenderCopy( renderer, card[9] , NULL, &display_card[r] );
    SDL_RenderPresent(renderer);
}

void Gallery::update(int* cardstatus)
{
    SDL_RenderClear( renderer );
    SDL_RenderCopy( renderer, pictures[PIC_BGD] , NULL, NULL );
    SDL_Delay(1000);
    for(int i=0;i<PIC_COUNT;i++)
    {
        if(cardstatus[i]==0)
        {
            SDL_RenderCopy(renderer, card[9] , NULL, &display_card[i+1] );
        }
        else
        {
            SDL_RenderCopy(renderer, card[smap[i]] , NULL, &display_card[i+1]);
        }
    }
    SDL_RenderPresent(renderer);

}


