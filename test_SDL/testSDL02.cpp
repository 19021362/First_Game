#include <iostream>
#include <SDL.h>
#include "testSDL02.h"

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const char WINDOW_TITLE[] = "Mouse in SDL";

void refreshScreen(SDL_Window* window, SDL_Renderer* renderer,
    const SDL_Rect& filled_rect, const bool leftMouse = false);

int main(int argc, char* argv[])
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

    SDL_Event e;

    SDL_Rect filled_rect;
    filled_rect.x = SCREEN_WIDTH / 2;
    filled_rect.y = SCREEN_HEIGHT / 2;
    filled_rect.w = 12;
    filled_rect.h = 12;

    refreshScreen(window, renderer, filled_rect);

    while (true) {

        SDL_Delay(10);


        if ( SDL_WaitEvent(&e) == 0) continue;

        if (e.type == SDL_QUIT) break;

        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) break;

        // Nếu chuột (mouse) được nhấn (xuống)
        if (e.type == SDL_MOUSEBUTTONDOWN) {
            filled_rect.x = e.button.x; // Lấy hoành độ x của chuột
            filled_rect.y = e.button.y; // Lấy tung độ y của chuột

            if (e.button.button == SDL_BUTTON_LEFT)
                refreshScreen(window, renderer, filled_rect, true);
            else
                refreshScreen(window, renderer, filled_rect, false);
        }
    }

    quitSDL(window, renderer);
    return 0;
}

void refreshScreen(SDL_Window* window, SDL_Renderer* renderer,
    const SDL_Rect& filled_rect, const bool leftMouse)
{
    // Đặt màu vẽ thành xanh lam (blue), xoá màn hình về màu xanh lam.
    SDL_SetRenderDrawColor(renderer, 252, 218, 213, 255);   // blue
    SDL_RenderClear(renderer) ;

    // Vẽ hình chữ nhật với màu tuỳ thuộc nút chuột trái hay phải được nhấn
    if (leftMouse)
        SDL_SetRenderDrawColor(renderer, 182, 41, 43, 255);
    else
        SDL_SetRenderDrawColor(renderer, 182, 41, 43, 255);
    SDL_RenderFillRect(renderer, &filled_rect);

   //Khi thông thường chạy với môi trường bình thường ở nhà
    SDL_RenderPresent(renderer);
   //Khi chạy ở máy thực hành WinXP ở trường (máy ảo)
   //SDL_UpdateWindowSurface(window);
}
