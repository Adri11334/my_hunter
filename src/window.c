/*
** EPITECH PROJECT, 2021
** my hunter
** File description:
** window manager
*/

#include "my_hunter.h"

int display_element(window_t *window, elements_t *objs, char *name)
{
    element_t *temp_obj = get_object(objs, name);
    sfRenderWindow_drawSprite(window->window, window->bg, NULL);
    while (objs != NULL) {
        temp_obj = get_object(objs, name);
        sfRenderWindow_drawSprite(window->window, temp_obj->sprite, NULL);
        objs = objs->next;
    }
    return 0;
}

int window_manager(window_t* window, elements_t *objs)
{
    sfTime time;
    float milli_seconds;
    time = sfClock_getElapsedTime(window->anim_clock);
    milli_seconds = time.microseconds / 100000;
    if (milli_seconds > 0.3) {
        cat_animator(get_object(objs, "normal_cat"));
        move_cat(get_object(objs, "normal_cat"), 1, window);
        sfClock_restart(window->anim_clock);
    }
    while (sfRenderWindow_pollEvent(window->window, &window->event)) {
        analyse_events(window, window->event, objs);
    }
    return 0;
}

int set_window(int width, int height, elements_t *game_objects)
{
    window_t window = setup_window(width, height);

    window.user = setup_user();
    if (!window.window)
        return 84;
    my_printf("\x1B[32m[GAME START]\x1B[0m\nYour score: 0\nLife: 3");
    while (sfRenderWindow_isOpen(window.window) && window.game_status != -1) {
        window_manager(&window, game_objects);
        display_element(&window, game_objects, "normal_cat");
        sfRenderWindow_display(window.window);
    }
    my_printf("\x1B[31m[Game over]\x1B[0m\nYour final score: \x1B[35m");
    my_printf("%d\x1B[0m\n", window.user.last_score);
    destroy_objects(game_objects);
    sfRenderWindow_destroy(window.window);
    return 0;
}
