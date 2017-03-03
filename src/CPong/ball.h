#pragma once
#include <stdbool.h>
#include "player.h"

typedef struct ball_t {
    int x;
    int y;
    int x_velocity;
    int y_velocity;
    int width;
    int height;
} ball_t;

void ball_increase_speed(ball_t *ball);

void ball_move(ball_t *ball);

bool ball_bounce_from_edge(ball_t *ball, int height);

bool ball_bounce_from_paddle(ball_t *ball, player_t *player1, player_t *player2);

bool ball_hits_player1_edge(ball_t * ball);

bool ball_hits_player2_edge(ball_t * ball, int width);
