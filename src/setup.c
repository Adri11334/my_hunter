/*
** EPITECH PROJECT, 2021
** hunter
** File description:
** setup file
*/

#include "my_hunter.h"

void set_bg_mouse(window_t *window)
{
    sfTexture *texture_bg = sfTexture_createFromFile("resource/image/star_bkg.png", NULL);
    window->bg = sfSprite_create();
    sfSprite_setTexture(window->bg, texture_bg, sfFalse);
    int x_size = (window->width) / 600;
    int y_size = (window->height) / 451;
    sfVector2f bg_scale = { .x = 1 + x_size, .y = 1 + y_size };
    sfSprite_setScale(window->bg, bg_scale);
}
/* sfTexture *texture_mouse =
sfTexture_createFromFile("resource/image/cross.png", NULL);
window->mouse = sfSprite_create();
sfSprite_setTexture(window->mouse, texture_mouse, sfFalse); */

window_t setup_window(int width, int height)
{
    window_t window;

    sfVideoMode mode = { width, height, 32 };
    window.height = height;
    window.width = width;
    window.anim_clock = sfClock_create();
    window.spawn_clock = sfClock_create();
    window.mouse_clock = sfClock_create();
    window.window = sfRenderWindow_create(mode, "Nyan Invader", sfClose, NULL);
    window.game_status = 0;
    sfRenderWindow_setFramerateLimit(window.window, 30);
    set_bg_mouse(&window);
    return window;
}

user_t setup_user()
{
    user_t user;

    user.last_score = 0;
    user.best_score = 0;
    user.shoot_left = 3;
    return user;
}
/* user->record_file_path = malloc(11);
user->record_file_path = "../.record\0"; */
