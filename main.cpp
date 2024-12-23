#include <iostream>
#include "include/SDL.h"

using namespace std;

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

SDL_Window   *window   = nullptr;
SDL_Surface *screen = NULL;
SDL_Renderer *renderer = nullptr;

int init(){
    SDL_SetMainReady(); // tell SDL that we handle main function ourselves, comes with the SDL_MAIN_HANDLED macro
    if (SDL_Init(SDL_INIT_VIDEO)) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return -1;
    }
    
    if (SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_FOCUS, &window, &renderer)) {
        std::cerr << "Failed to create window and renderer: " << SDL_GetError() << std::endl;
        return -1;
    }
    SDL_SetWindowTitle(window, "SDL2 game blank");
    SDL_SetRenderDrawColor(renderer, 210, 255, 179, 255);
    return 0;
}

int quit(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

int main(int, char **){ 

    if (init() == 1) {
        return 1;
        
    }

    while (1) { // main game loop
        SDL_Event event; // handle window closing
        if (SDL_PollEvent(&event) && (SDL_QUIT==event.type || (SDL_KEYDOWN==event.type && SDLK_ESCAPE==event.key.keysym.sym)))
            break; // quit
        SDL_RenderClear(renderer); // re-draw the window
        SDL_RenderPresent(renderer);
    }

    quit();
    return 0;
}