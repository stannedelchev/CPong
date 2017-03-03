#pragma once

#include "SDL_render.h"
#include "player.h"
#include "ball.h"

typedef struct {
    player_t player1;
    player_t player2;
    ball_t ball;
    int width;
    int height;
    player_t *winner;
} game_t;


game_t game_new(int width, int height, int p1_paddle_width, int p1_paddle_height, int p2_paddle_width, int p2_paddle_height);
int game_loop(game_t *game, SDL_Renderer *renderer);