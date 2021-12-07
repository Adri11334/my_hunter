/*
** EPITECH PROJECT, 2021
** my hunter
** File description:
** cat animator
*/

#include "my_hunter.h"

void cat_animator(element_t *cat)
{
    if (cat->rect.left + cat->block_width < cat->width)
        cat->rect.left += cat->block_width;
    else
        cat->rect.left = 0;
    sfSprite_setTextureRect(cat->sprite, cat->rect);
}

void move_cat(element_t *cat, int direction, window_t *window)
{
    sfVector2f pos = sfSprite_getPosition(cat->sprite);
    sfVector2f new_pos = { .x = 0, .y = 0 };
    if (cat->direction == 1) {
        if ((pos.x + 10) < window->width - cat->block_width)
            new_pos.x = pos.x + 10;
        else
            new_pos.x = 0;
        if ((pos.y + 5) < window->height - cat->block_height)
            new_pos.y = pos.y + 5;
        else
            new_pos.y = 0;
    } else {
        if ((pos.x - 10) < window->width - cat->block_width)
            new_pos.x = pos.x - 10;
        else
            new_pos.x = 0;
        if ((pos.y -5) < window->height - cat->block_height)
            new_pos.y = pos.y - 5;
        else
            new_pos.y = 0;
    }
    cat->pos = new_pos;
    sfSprite_setPosition(cat->sprite, new_pos);
}

int cat_die(element_t *cat)
{
    return respawn(cat);
}
