#include <stdio.h>
#include <math.h>
#include <SDL.h>
#undef main

int main(int argc, char *argv[])
{
    return initSdl();
}

int initSdl()
{
    int result = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    if (result) {
        perror("SHIT");
        return 1;
    }

    SDL_Window *window;
    SDL_Renderer *renderer;
    if (-1 == SDL_CreateWindowAndRenderer(600, 480, 0, &window, &renderer))
    {
        perror(SDL_GetError());
        return 1;
    }

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    SDL_Event event;
    while (SDL_WaitEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            return 0;
            break;
        }
    }
    perror(SDL_GetError());
    return 0;
}