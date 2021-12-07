/*
** EPITECH PROJECT, 2021
** my hunter
** File description:
** event manager
*/

#include "my_hunter.h"

void write_score(window_t *window)
{
    window->user.last_score += 1;
    my_printf("\033[FYour score: %d\n", window->user.last_score);
    switch (window->user.shoot_left) {
        case 3: my_printf("\x1B[32m"); break;
        case 2: my_printf("\x1B[33m"); break;
        case 1: my_printf("\x1B[31m"); break;
        default: my_printf("\x1B[36m");
    }
    my_printf("Life: %d\x1B[0m", window->user.shoot_left);
}

int check_cat_shooted(int hx, int hy, elements_t *objs, window_t *window)
{
    elements_t *tmp = objs;

    while (tmp != NULL) {
        if ((hx > tmp->obj->pos.x
            && hx < tmp->obj->pos.x + tmp->obj->block_width)
            && hy > tmp->obj->pos.y
            && hy < tmp->obj->pos.y + tmp->obj->block_height) {
            cat_die(tmp->obj);
            write_score(window);
            return 0;
        }
        tmp = tmp->next;
    }
    if (window->user.shoot_left - 1 <= 0)
        return player_loosed(window);
    window->user.shoot_left -= 1;
    write_score(window);
    return -1;
}

void manage_mouse_click(sfMouseButtonEvent event, elements_t *game_objects,
window_t *window)
{
    if (event.type == sfEvtMouseButtonPressed)
        check_cat_shooted(event.x, event.y, game_objects, window);
}

void close_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}

void analyse_events(window_t *window, sfEvent event, elements_t *objs)
{
    if (event.type == sfEvtMouseButtonPressed)
        manage_mouse_click(event.mouseButton, objs, window);
    if (event.type == sfEvtClosed)
        close_window(window->window);
}
