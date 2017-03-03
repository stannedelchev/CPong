#include <stdio.h>
#include <math.h>
#include <SDL.h>
#include "game.h"
#undef main

int init_sdl(int width, int height, SDL_Window **window, SDL_Renderer **renderer);

int main(int argc, char *argv[])
{
    int width = 640;
    int height = 480;
    int paddle_width = 10;
    int p1_paddle_height = 50;
    int p2_paddle_height = 50;

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    if (init_sdl(width, height, &window, &renderer))
    {
        goto cleanup;
    }

    game_t game = game_new(width, height, paddle_width, p1_paddle_height, paddle_width, p2_paddle_height);
    game_loop(&game, renderer);

cleanup:
    SDL_Delay(5000);
    SDL_Quit();
}

int init_sdl(int width, int height, SDL_Window **window, SDL_Renderer **renderer)
{
    int result = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    if (result) {
        return 1;
    }

    if (-1 == SDL_CreateWindowAndRenderer(width, height, 0, window, renderer))
    {
        perror(SDL_GetError());
        return 1;
    }

    SDL_SetRenderDrawColor(*renderer, 255, 0, 0, 255);
    return 0;
}