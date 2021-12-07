/*
** EPITECH PROJECT, 2021
** my hunter
** File description:
** game elements setup
*/

#include "my_hunter.h"
#include <stdio.h>

sfVector2f gen_start_pos(element_t *obj)
{
    float x_start = random_number(0, 1480);
    float y_start;

    x_start = -100;
    y_start = random_number(0, 500);
    obj->direction = 1;
    sfVector2f position;

    position.x = x_start;
    position.y = y_start;
    return position;
}

int respawn(element_t *element)
{
    sfVector2f pos = sfSprite_getPosition(element->sprite);
    sfVector2f new_pos = gen_start_pos(element);

    element->pos = new_pos;
    sfSprite_setPosition(element->sprite, new_pos);
    return 0;
}

element_t *set_obj(char *path, int ts, int ls, int tw, int th, int sw,
int sh, char *name)
{
    element_t *obj = malloc(sizeof(element_t));
    sfIntRect sf_rect = {.top = 0, .left = 0, .width = sw, .height = sh};
    const sfIntRect texture_rect = { ls, ts, tw, th };
    sfVector2f position = gen_start_pos(obj);

    obj->path = path;
    obj->name = name;
    obj->width = tw;
    obj->height = th;
    obj->block_width = sw;
    obj->block_height = sh;
    obj->dead = 0;
    obj->texture = sfTexture_createFromFile(path, &texture_rect);
    obj->sprite = sfSprite_create();
    sfSprite_setTexture(obj->sprite, obj->texture, sfFalse);
    obj->rect = sf_rect;
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    obj->pos = position;
    sfSprite_setPosition(obj->sprite, position);
    sfVector2f scale = { .x = 1.5, .y = 1.5 };
    sfSprite_setScale(obj->sprite, scale);
    return obj;
}

elements_t *set_elements(char **elements, int length)
{
    elements_t *last_insert;
    int lines;

    for (int i = 0; i < length; i++) {
        elements_t *my_obj = malloc(sizeof(elements_t));
        if (i == length - 1) {
            my_obj->next = NULL;
        } else if (i == 0) {
            my_obj->prev = NULL;
        } else {
            last_insert->prev = my_obj;
            my_obj->next = last_insert;
        }
        char **elements_texts = string_division(elements[i], '%', &lines);
        my_obj->obj = set_obj(elements_texts[0], 140, 1, 420, 50, 70, 50,
        elements_texts[1]);
        my_obj->obj->pos.x += i * 2;
        last_insert = my_obj;
    }
    return last_insert;
}
