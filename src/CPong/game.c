#include <stdbool.h>
#include <stdio.h>
#include <SDL.h>
#include "game.h"
#include "player.h"
#include "ball.h"
#include "helpers.h"
#include "render.h"

paddle_direction_t get_direction(SDL_KeyboardEvent *ev);
bool check_victory(game_t *game, player_t **possible_victor);

game_t game_new(int width, int height, int p1_paddle_width, int p1_paddle_height, int p2_paddle_width, int p2_paddle_height)
{
    game_t game = {
        .player1 = {
            .name = "Player 1",
            .x = 0,
            .y = 0,
            .paddle_width = p1_paddle_width,
            .paddle_height = p1_paddle_height,
            .velocity = 0,
            .max_velocity = 20
        },
        .player2 = {
            .name = "P2",
            .x = width - p2_paddle_width,
            .y = 0,
            .paddle_width = p2_paddle_width,
            .paddle_height = p2_paddle_height,
            .velocity = 0,
            .max_velocity = 20
        },
        .ball = {
            .x = width / 2,
            .y = height / 2,
            .x_velocity = 2,
            .y_velocity = 2,
            .width = 10,
            .height = 10
        },
        .width = width,
        .height = height,
        .winner = NULL
    };

    return game;
}

int game_loop(game_t *game, SDL_Renderer *renderer)
{
    SDL_Delay(10000);
    SDL_Event event;
    bool should_exit = false;
    while (!should_exit)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                return 0;
                break;
            case SDL_KEYDOWN:
                paddle_direction_t direction = get_direction((SDL_KeyboardEvent *)&event);

                if (!direction) {
                    break;
                }

                player_push_paddle(&game->player1, direction, game->width, game->height);
                player_push_paddle(&game->player2, direction, game->width, game->height);
            }
        }

        ball_move(&game->ball);

        player_t *possible_winner;
        if (check_victory(game, &possible_winner)) {
            printf("%s is the winner!\n", possible_winner->name);
            game->winner = possible_winner;
            should_exit = true;
        }

        ball_bounce_from_edge(&game->ball, game->height);

        if (ball_bounce_from_paddle(&game->ball, &game->player1, &game->player2))
        {
            ball_increase_speed(&game->ball);
        }

        render(game, renderer);

        SDL_Delay(16);
    }

    return 0;
}

paddle_direction_t get_direction(SDL_KeyboardEvent *ev)
{
    SDL_Keycode keycode = ev->keysym.sym;
    switch (keycode)
    {
    case SDLK_UP: 
        return PDLD_UP;
    case SDLK_DOWN:
        return PDLD_DOWN;
    default:
        return PDLD_INVALID;
    }
}

bool check_victory(game_t *game, player_t **possible_winner)
{
    if (ball_hits_player1_edge(&game->ball))
    {
        *possible_winner = &game->player2;
        return true;
    }

    if (ball_hits_player2_edge(&game->ball, game->width))
    {
        *possible_winner = &game->player1;
        return true;
    }

    return false;
}
