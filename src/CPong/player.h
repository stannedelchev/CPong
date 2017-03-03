#pragma once

typedef struct player_t {
    const char *name;
    int x;
    int y;
    int paddle_width;
    int paddle_height;
    int velocity;
    int max_velocity;
} player_t;


typedef enum {
    PDLD_INVALID = 0,
    PDLD_UP = 1,
    PDLD_DOWN = 2
} paddle_direction_t;

void player_push_paddle(player_t * player, paddle_direction_t direction, int width, int height);

void player_move_paddle(player_t * player, int width, int height);
