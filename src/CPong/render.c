#include "render.h"

SDL_Rect rect_from_player(player_t *player) {
    SDL_Rect result = {
        .x = player->x,
        .y = player->y,
        .w = player->paddle_width,
        .h = player->paddle_height
    };
    return result;
}

void render(game_t *game, SDL_Renderer *renderer)
{
    SDL_Rect paddle1 = rect_from_player(&game->player1);
    SDL_Rect paddle2 = rect_from_player(&game->player2);
    SDL_Rect ball = {
        .x = game->ball.x,
        .y = game->ball.y,
        .w = game->ball.width,
        .h = game->ball.height
    };

    SDL_Rect rects[3] = { paddle1, paddle2, ball };

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

    SDL_RenderFillRects(renderer, rects, 3);
    SDL_RenderPresent(renderer);
}