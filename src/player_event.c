/*
** EPITECH PROJECT, 2021
** hunter
** File description:
** player event
*/

#include "my_hunter.h"

int player_loosed(window_t *window)
{
    window->game_status = -1;
    my_printf("\033[FYour score: %d\nLife: 0\n", window->user.last_score);
    return -1;
}