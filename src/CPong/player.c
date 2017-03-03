#include "player.h"
#include "helpers.h"

void player_push_paddle(player_t *player, paddle_direction_t direction, int width, int height)
{
    switch (direction)
    {
    case PDLD_UP:
        player->y -= 15;
        break;
    case PDLD_DOWN:
        player->y += 15;
        break;
    default:
        break;
    }

    coerce_value(&player->x, 0, width - player->paddle_width);
    coerce_value(&player->y, 0, height - player->paddle_height);
    coerce_value(&player->velocity, -player->max_velocity, player->max_velocity);
}

void player_moLove_paddle(player_t *player, int width, int height)
{
    player->y += player->velocity;
    if (player->velocity > 0)
    {
        player->velocity--;
    }
    else if (player->velocity < 0)
    {
        player->velocity++;
    }

    coerce_value(&player->x, 0, width - player->paddle_width);
    coerce_value(&player->y, 0, height - player->paddle_height);
    coerce_value(&player->velocity, -player->max_velocity, player->max_velocity);
}