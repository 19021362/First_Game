#include "include.h"
#include "SDL02.h"
#include <SDL_image.h>

const int BUTTON_WIDTH = 150;
const int BUTTON_HEIGHT = 100;


void Button::setPosition(int x, int y)
{
        mPosition.x = x;
        mPosition.y = y;
}


void Button::handleEvent( SDL_Event* e ,int i)
{
	if( e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
	{
		int x, y;
		SDL_GetMouseState( &x, &y );

		bool inside = true;

		if( x < mPosition.x )
		{
			inside = false;
		}
		else if( x > mPosition.x + BUTTON_WIDTH )
		{
			inside = false;
		}
		else if( y < mPosition.y )
		{
			inside = false;
		}
		else if( y > mPosition.y + BUTTON_HEIGHT )
		{
			inside = false;
		}

		if(inside==true)
        {
            id = i;
        }

	}
}

