#include <stdbool.h>
#include "ball.h"
#include "player.h"

void ball_increase_speed(ball_t *ball)
{
    if (ball->x_velocity > 0)
    {
        ball->x_velocity++;
    }
    else if (ball->x_velocity < 0)
    {
        ball->x_velocity--;
    }

    if (ball->y_velocity > 0)
    {
        ball->y_velocity++;
    }
    else if (ball->y_velocity < 0)
    {
        ball->y_velocity--;
    }
}

void ball_move(ball_t *ball)
{
    int new_x = ball->x + ball->x_velocity;
    int new_y = ball->y + ball->y_velocity;

    ball->x = new_x;
    ball->y = new_y;
}

bool ball_bounce_from_edge(ball_t *ball, int height)
{
    // Check top & bottom bounds
    if (ball->y + ball->height > height || ball->y < 0)
    {
        ball->y_velocity = -ball->y_velocity;
        return true;
    }

    return false;
}

bool ball_bounce_from_paddle(ball_t *ball, player_t *player1, player_t *player2) {
    

    int ball_bottom_right_x = ball->x + ball->width;
    int ball_bottom_right_y = ball->y + ball->height;
    int ball_bottom_left_x = ball->x;
    int ball_bottom_left_y = ball->y + ball->height;

    bool ball_hits_p1 = (ball->x + ball->width >= player2->x &&
        ball_bottom_right_y >= player2->y &&
        ball_bottom_right_y <= player2->y + player2->paddle_height);
    bool ball_hits_p2 = (ball->x <= player1->x + player1->paddle_width &&
        ball_bottom_left_y >= player1->y &&
        ball_bottom_left_y <= player1->y + player1->paddle_height);

    if (ball_hits_p1 || ball_hits_p2)
    {
        ball->x_velocity = -ball->x_velocity;
        return true;
    }

    return false;
}

bool ball_hits_player1_edge(ball_t *ball)
{
    if (ball->x < 0)
    {
        return true;
    }

    return false;
}

bool ball_hits_player2_edge(ball_t *ball, int width)
{
    if (ball->x + ball->width > width)
    {
        return true;
    }

    return false;
}