#include <SDL.h>
#include "SDL02.h"
#include "include.h"

using namespace std;


const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 640;
const char WINDOW_TITLE[] = "Matching Cards";


Gallery* gallery = nullptr;
Button button[ 16 ];

int main(int argc, char* argv[])
{
    srand(time(0));
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    gallery = new Gallery(renderer);

    SDL_Event e;
    bool game_status = false;
    int cardstatus[16] = {0};
    int card1_id=0 , card2_id=0;
    int temp1=0, temp2=0, cnt=0;



    gallery->loadGamePictures();
    gallery->suffle();
    gallery->renderer_card();

    int x=0,y=0,k=1;
		for(int c=0;c<4;c++)
        {
            for(int d=0;d<4;d++)
            {
                x=140+d*210;
                y=40+c*160;
                button[ k ].setPosition(x,y);
                k++;
            }
        }
    while(!game_status)
    {
        if(SDL_PollEvent( &e )==0)continue;
            if(e.type == SDL_MOUSEBUTTONDOWN)
            {
                for( int i = 1; i <= 16; i++ )
                {
                    button[ i ].handleEvent( &e, i );
                    if(button[i].id!=0 && cnt%2==0)
                    {
                        gallery->render( button[i].id );
                        card1_id = gallery->smap[button[i].id-1] ;
                        temp1 = button[i].id;
                        button[i].id=0;
                        cnt++;
                    }
                    else if(button[i].id!=0 && cnt%2==1)
                    {
                        gallery->render( button[i].id );
                        card2_id = gallery->smap[button[i].id-1] ;
                        temp2 = button[i].id;
                        button[i].id=0;
                        cnt++;
                    }

                    if(card1_id == card2_id && temp1 != temp2)
                    {
                        cardstatus[ temp1-1 ] = 1;
                        cardstatus[ temp2-1 ] = 1;
                    }
                }
                if(cnt%2==0)
                {
                    gallery->update( cardstatus );
                }
            }


            if(e.type == SDL_QUIT){
                game_status = true;
                break;
            }
        game_status = true;
        for(int i=0;i<16;i++)
        {
            if(cardstatus[i]==0){
                game_status = false;
                break;
            }
        }
        if(game_status==true)
        {
            SDL_RenderCopy(renderer,gallery->getImage(PIC_WIN),NULL,NULL);
            SDL_RenderPresent(renderer);
            gallery->~Gallery();
        }

    }





    waitUntilKeyPressed();
    SDL_Quit();
    return 0;
}





