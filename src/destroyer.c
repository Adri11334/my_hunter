/*
** EPITECH PROJECT, 2021
** my hunter
** File description:
** destroyer
*/

#include "my_hunter.h"

int destroy_objects(elements_t *objs)
{
    while (objs->next != NULL) {
        if (objs->prev != NULL)
            free(objs->prev);
        sfTexture_destroy(objs->obj->texture);
        sfSprite_destroy(objs->obj->sprite);
        free(objs->obj->name);
        free(objs->obj->name);
        free(objs->obj);
        objs = objs->next;
    }
    sfTexture_destroy(objs->obj->texture);
    sfSprite_destroy(objs->obj->sprite);
    free(objs->obj->name);
    free(objs->obj->path);
    free(objs->obj);
    free(objs);
    return 0;
}
