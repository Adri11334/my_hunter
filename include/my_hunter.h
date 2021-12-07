/*
** EPITECH PROJECT, 2021
** my hunter
** File description:
** global include
*/

#ifndef MY_HUNTER_H_
    #define MY_HUNTER_H_
    #include <SFML/Graphics.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <window.h>
    #include "my.h"
    #include "my_printf.h"
    int set_window(int width, int height, elements_t *game_objects);
    int window_manager(window_t* window, elements_t *objs);
    void manage_mouse_click(sfMouseButtonEvent event, elements_t *game_objects,
    window_t *window);
    void close_window(sfRenderWindow *window);
    void analyse_events(window_t *wido, sfEvent evnt, elements_t *objs);
    elements_t *set_elements(char **elements, int length);
    element_t *set_obj(char *path, int ts, int ls, int tw, int th, int sw,
    int sh, char *name);
    element_t *get_object(elements_t *objects, char *name);
    char **string_division(char *str, char key, int *array_length);
    int display_element(window_t *window, elements_t *objs, char *name);
    void cat_animator(element_t *cat);
    int cat_die(element_t *cat);
    void move_cat(element_t *cat, int direction, window_t *window);
    int destroy_objects(elements_t *objs);
    void set_bg_mouse(window_t *window);
    window_t setup_window(int width, int height);
    user_t setup_user();
    int respawn(element_t *element);
    int player_loosed(window_t *window);
#endif/* !MY_HUNTER_H_ */
