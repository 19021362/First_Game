#include<iostream>
#include"SDL02.h"
#include"images.h"

using namespace std;



void renderer_card()
{

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    //clears screen
    SDL_RenderClear(renderer);

    int r;
    for(int c=0;c<2;c++)
    {
        for(int d=0;d<3;d++)
        {
            r=Tmap[c][d];
            //copies stored textures to render
            //displayRect.x=c*64;displayRect.y=d*64;displayRect.w=64;displayRect.h=64;
            //SDL_RenderCopy(renderer, colors, &clip[r],&displayRect );
            displayRect.x=c*128;displayRect.y=d*128;displayRect.w=128;displayRect.h=128;
            SDL_RenderCopy(renderer, textureList[r], NULL, &displayRect);

        }
    }

    SDL_RenderPresent(renderer);
}
