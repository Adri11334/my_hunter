/*
** EPITECH PROJECT, 2021
** my hunter
** File description:
** window manager
*/

#ifndef WINDOW_H_
#define WINDOW_H_

typedef struct user_s {
    int shoot_left;
    int last_score;
    int best_score;
    char *record_file_path;
} user_t;

typedef struct window_s {
    int width;
    int height;
    int fps;
    int clock_rate;
    sfRenderWindow* window;
    sfEvent event;
    sfSprite *bg;
    sfSprite *mouse;
    sfClock *anim_clock;
    sfClock *spawn_clock;
    sfClock *mouse_clock;
    sfVector2f mouse_pos;
    int cat_count;
    int game_status;
    user_t user;
} window_t;

typedef struct element_s {
    char *name;
    char *path;
    int width;
    int height;
    int block_width;
    int block_height;
    int dead;
    int direction;
    sfTexture* texture;
    sfSprite* sprite;
    sfIntRect rect;
    sfVector2f pos;
} element_t;

typedef struct elements_s {
    element_t *obj;
    struct elements_s *next;
    struct elements_s *prev;
} elements_t;
#endif/* !WINDOW_H_ */
